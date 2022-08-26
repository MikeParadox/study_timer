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

#include "Timer.h"

bool TimerWidget::getDeleted()
{
    return toBeDeleted;
}
std::chrono::seconds TimerWidget::getTotalTime()
{
    return totalTime;
}

void TimerWidget::setTotalTime(std::chrono::seconds s)
{
    totalTime = s;
}

bool TimerWidget::getPauseState()
{
    return paused;
}

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
}

// TODO: Fix crash on delete
void TimerWidget::handleDeleteButton()
{
    //MainWindow *w = qobject_cast<MainWindow*>(this->topLevelWidget());
    //w->delTimer(this);
    //deleteLater();
    toBeDeleted = true;
    delete this;
}

void TimerWidget::startTimer()
{
    std::unique_ptr<Timer> timer{new Timer{ totalTime }};
    // Timer* timer = new Timer{ totalTime };
    //timer(this);
    // timer->start(this);
    (*timer)(this);
    // delete timer;
}

// Initialize totalTime with the time from the selection dialog
void TimerWidget::initialize(TimerSelection *t)
{
    initialTime = t->getHours() + t->getMinutes();
    totalTime = initialTime;
    setTimeLabel(totalTime);

    std::thread d(&TimerWidget::startTimer, this);
    d.detach();
}

// Set the time label to Finished
void TimerWidget::finished()
{
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
    connect(ui->pauseButton, &QPushButton::released, this, &TimerWidget::handlePauseButton);
    connect(ui->resetButton, &QPushButton::released, this, &TimerWidget::handleResetButton);
    connect(ui->editButton, &QPushButton::released, this, &TimerWidget::handleEditButton);
    connect(ui->deleteButton, &QPushButton::released, this, &TimerWidget::handleDeleteButton);
}

TimerWidget::~TimerWidget()
{
    delete ui;
}
