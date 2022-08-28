#include "timerwidget.h"
#include "mainwindow.h"
#include "ui_timerwidget.h"
#include "timerselection.h"

#include <QSoundEffect>
#include <thread>
#include <QTime>
#include <chrono>
#include <iostream>
#include <memory>


using namespace std::literals; // for using literals like 10s


void TimerWidget::handlePauseButton()
{
    paused = !paused;
}

void TimerWidget::handleResetButton()
{
    totalTime = initialTime;
}

void TimerWidget::handleEditButton()
{
    TimerSelection *timerSelection = new TimerSelection(this);
    // Connect the "Accept" button to addTimer
    connect(timerSelection, &TimerSelection::accepted, this, &TimerWidget::editTimer);
    // Show the dialog
    timerSelection->exec();
}


void TimerWidget::editTimer()
{
    // Get the TimerSelection from the sender() QObject
    TimerSelection *t = qobject_cast<TimerSelection*>(sender());

    totalTime = t->getHours() + t->getMinutes();

    initialTime = totalTime;

}

// TODO: Fix crash on delete
void TimerWidget::handleDeleteButton()
{
    //MainWindow *w = qobject_cast<MainWindow*>(this->topLevelWidget());
    //w->delTimer(this);

    if (isFinished)
    {
        delete this;
    } else {
        toBeDeleted = true;
    }
}

int TimerWidget::timerLoop()
{
    while (totalTime >= 0s)
    {
        if (toBeDeleted)
        {
            delete this;
            return 0;
        }
        if (totalTime == 0s)
        {
            finished();
            return 0;
        }
        if (!paused)
        {
            totalTime -= 1s;
            setTimeLabel(totalTime);
            std::this_thread::sleep_for(1s);
        }
    }

    return 0; // TODO implement status code control
}

// Initialize totalTime with the time from the selection dialog
void TimerWidget::initialize(TimerSelection *t)
{
    initialTime = t->getHours() + t->getMinutes();
    totalTime = initialTime;
    setTimeLabel(totalTime);
    ui->timerNameFieldOnTimer->setText(t->getTimerName());
    ui->timerNameFieldOnTimer->setReadOnly(true);

    std::thread d(&TimerWidget::timerLoop, this);
    d.detach();
}

// Set the time label to Finished
void TimerWidget::finished()
{
    isFinished = true;
    ui->time->setText("Finished!");
    QSoundEffect effect;
    effect.setSource(QUrl("qrc:/sounds/alarm.wav"));
    effect.setVolume(0.25f);
    effect.play();

    QEventLoop loop;
    loop.exec();
}


// Set the time label to "secs" (std::chrono::seconds)
void TimerWidget::setTimeLabel(std::chrono::seconds secs)
{
    QTime *time = new QTime(0, 0, 0, 0);
    QString formattedTime = time->addSecs(secs.count()).toString("hh:mm:ss");
    ui->time->setText(formattedTime);
}

TimerWidget::TimerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerWidget)
{
    ui->setupUi(this);
    paused = false;
    toBeDeleted = false;
    isFinished = false;
    connect(ui->pauseButton, &QPushButton::released, this, &TimerWidget::handlePauseButton);
    connect(ui->resetButton, &QPushButton::released, this, &TimerWidget::handleResetButton);
    connect(ui->editButton, &QPushButton::released, this, &TimerWidget::handleEditButton);
    connect(ui->deleteButton, &QPushButton::released, this, &TimerWidget::handleDeleteButton);
}

TimerWidget::~TimerWidget()
{
    delete ui;
}
