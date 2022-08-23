#include "timerselection.h"
#include "ui_timerselection.h"

TimerSelection::TimerSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSelection)
{
    ui->setupUi(this);
    connect(ui->canc, &QPushButton::released, this, &QDialog::reject);
    connect(ui->save, &QPushButton::released, this, &QDialog::accept);
}

TimerSelection::~TimerSelection()
{
    delete ui;
}

int TimerSelection::getMinutes()
{
    return ui->mins->displayIntegerBase();
}

int TimerSelection::getSeconds()
{
    return ui->secs->displayIntegerBase();
}
