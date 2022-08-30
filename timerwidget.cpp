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

void TimerWidget::handleStartButton()
{
    if (paused == false)
    {
        ui->startButton->setEnabled(false);
        ui->pauseButton->setEnabled(true);
        ui->resetButton->setEnabled(true);
        isStarted = true;
        std::thread d(&TimerWidget::timerLoop, this);
        d.detach();
    }
    else
    {
        paused = false;
        ui->pauseButton->setEnabled(true);
        ui->resetButton->setEnabled(true);
        ui->startButton->setDisabled(true);
    }
}

void TimerWidget::handlePauseButton()
{
    if (!paused)
    {
        paused = true;
        ui->startButton->setEnabled(true);
        ui->pauseButton->setDisabled(true);
    }
}

void TimerWidget::handleResetButton()
{
    totalTime = initialTime;
    setTimeLabel(totalTime);
    ui->startButton->setEnabled(true);
    ui->pauseButton->setDisabled(true);
    ui->resetButton->setDisabled(true);
    ui->editButton->setEnabled(true);
    paused = true;
}

void TimerWidget::handleEditButton()
{
    // The problem in deleting timer after editing it is that it's another
    //  timer
    TimerSelection *t = new TimerSelection(this);
    t->setTime(initialTime); // in my VS Code it's line 61
    t->setTimerName(timerName);
    // Connect the "Accept" button to addTimer
    connect(t, &TimerSelection::accepted, this, &TimerWidget::editTimer);
    // Show the dialog
    t->exec();
    setTimeLabel(totalTime);
}

// TODO: Fix crash on delete
void TimerWidget::handleDeleteButton()
{
    // MainWindow *w = qobject_cast<MainWindow*>(this->topLevelWidget());
    // w->delTimer(this);

    if (!isStarted)
    {
        delete this;
    }
    else
    {
        toBeDeleted = true;
    }
}

void TimerWidget::editTimer()
{
    // Get the TimerSelection from the sender() QObject
    TimerSelection *t = qobject_cast<TimerSelection *>(sender());

    totalTime = t->getHours() + t->getMinutes();

    initialTime = totalTime;

    timerName = t->getTimerName();
    ui->timerNameFieldOnTimer->setText(timerName);
    paused = true;
    ui->pauseButton->setDisabled(true);
    ui->resetButton->setDisabled(true);
    ui->startButton->setEnabled(true);
}

int TimerWidget::timerLoop()
{
    while (totalTime > 0s && !toBeDeleted)
    {
        // if (totalTime == 0s)
        // {
        //     finished();
        //     return 0;
        // }
        if (!paused)
        {
            totalTime -= 1s;
            setTimeLabel(totalTime);
            std::this_thread::sleep_for(1s);
        }
    }
    // When timer is done it shouldn't be deleted
    if (toBeDeleted)
    {
        delete this;
    }

    return 0; // TODO implement status code control
}

// Initialize totalTime with the time from the selection dialog
void TimerWidget::initialize(TimerSelection *t)
{
    initialTime = t->getHours() + t->getMinutes();
    totalTime = initialTime;
    setTimeLabel(totalTime);
    timerName = t->getTimerName();
    ui->timerNameFieldOnTimer->setText(timerName);
    ui->pauseButton->setDisabled(true);
    ui->resetButton->setDisabled(true);
}

// Set the time label to Finished
void TimerWidget::finished()
{
    isStarted = false;
    ui->pauseButton->setEnabled(false);
    ui->resetButton->setEnabled(false);
    ui->editButton->setEnabled(false);
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

TimerWidget::TimerWidget(QWidget *parent) : QWidget(parent),
                                            ui(new Ui::TimerWidget)
{
    ui->setupUi(this);
    paused = false;
    toBeDeleted = false;
    isStarted = false;
    connect(ui->startButton, &QPushButton::released, this, &TimerWidget::handleStartButton);
    connect(ui->pauseButton, &QPushButton::released, this, &TimerWidget::handlePauseButton);
    connect(ui->resetButton, &QPushButton::released, this, &TimerWidget::handleResetButton);
    connect(ui->editButton, &QPushButton::released, this, &TimerWidget::handleEditButton);
    connect(ui->deleteButton, &QPushButton::released, this, &TimerWidget::handleDeleteButton);
}

TimerWidget::~TimerWidget()
{
    delete ui;
}
