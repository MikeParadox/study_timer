#include "timerwidget.h"
#include "ui_timerwidget.h"
#include "timerselection.h"

#include <QThread>
#include <thread>
#include <QTime>
#include <chrono>
#include <iostream>

#include "includes/Timer.h"

std::chrono::seconds TimerWidget::getTotalTime()
{
    return totalTime;
}

void TimerWidget::setTotalTime(std::chrono::seconds s)
{
    totalTime = s;
}

void TimerWidget::handlePauseButton()
{
    paused = !paused;
}

void TimerWidget::startTimer()
{
    Timer *timer = new Timer { totalTime };
    //timer(this);
    timer->start(this);
    delete timer;
}

// Initialize totalTime with the time from the selection dialog
void TimerWidget::initialize(TimerSelection *t)
{
    totalTime = t->getHours() + t->getMinutes();
    setTimeLabel(totalTime);

    std::thread myThread(&TimerWidget::startTimer, this);
    myThread.detach();
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
    connect(ui->pauseButton, &QPushButton::released, this, &TimerWidget::handlePauseButton);
}

TimerWidget::~TimerWidget()
{
    delete ui;
}
