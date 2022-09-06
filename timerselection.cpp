#include "timerselection.h"
#include "ui_timerselection.h"

TimerSelection::TimerSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSelection)
{
    ui->setupUi(this);
    //connect(ui->canc, &QPushButton::released, this, &QDialog::reject);
    //connect(ui->save, &QPushButton::released, this, &QDialog::accept);
}

TimerSelection::~TimerSelection()
{
    delete ui;
}

// Get the user input in std::chrono::hours
std::chrono::hours TimerSelection::getHours()
{
    ui->hours->setRange(0, 23);
    return std::chrono::hours(ui->hours->value());
}

QString TimerSelection::getTimerName()
{
    return QString(ui->timerNameSelection->text());
}

// Get the user input in std::chrono::minutes
std::chrono::minutes TimerSelection::getMinutes()
{
    ui->mins->setRange(0, 59);
    return std::chrono::minutes(ui->mins->value());
}


void TimerSelection::setTime(std::chrono::seconds s)
{
    int seconds = s.count();
    int hours = seconds / 60 / 60;
    int minutes = seconds / 60 - hours * 60;
    ui->hours->setRange(0, 23);
    ui->mins->setRange(0, 59);
    ui->hours->setValue(hours);
    ui->mins->setValue(minutes);
}

void TimerSelection::setTimerName(QString n)
{
    ui->timerNameSelection->setText(n);
}
