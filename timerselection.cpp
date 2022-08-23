#include "timerselection.h"
#include "ui_timerselection.h"

TimerSelection::TimerSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSelection)
{
    ui->setupUi(this);
}

TimerSelection::~TimerSelection()
{
    delete ui;
}

int TimerSelection::getMinutes()
{
    return ui->spinBox->displayIntegerBase();
}

int TimerSelection::getSeconds()
{
    return ui->spinBox_2->displayIntegerBase();
}
