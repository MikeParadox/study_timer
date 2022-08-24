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
    return std::chrono::hours(ui->hours->value());
}

// Get the user input in std::chrono::minutes
std::chrono::minutes TimerSelection::getMinutes()
{
    return std::chrono::minutes(ui->mins->value());
}
