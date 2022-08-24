#include "timerwidget.h"
#include "ui_timerwidget.h"
#include "timerselection.h"

#include <QTime>
#include <chrono>

// Initialize totalTime with the time from the selection dialog
void TimerWidget::initialize(TimerSelection *t)
{
    totalTime = t->getHours() + t->getMinutes();
    setTime(totalTime);
}

// Set the time label to "secs" (std::chrono::seconds)
void TimerWidget::setTime(std::chrono::seconds secs)
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
}

TimerWidget::~TimerWidget()
{
    delete ui;
}
