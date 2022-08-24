#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timerselection.h"
#include "timer.h"

#include <chrono>

void MainWindow::handleAddTimerButton()
{
    TimerSelection *t = new TimerSelection(this);
    //connect(t, &TimerSelection::accepted, this, &MainWindow::addTimer);
    if(t->exec())
    {
        Timer *newTimer = new Timer(this);
        newTimer->totalTime = t->getHours() + t->getMinutes();
        newTimer->setTime(newTimer->totalTime);
        ui->verticalLayout_2->addWidget(newTimer);
        newTimer->show();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTimerButton, &QPushButton::released, this, &MainWindow::handleAddTimerButton);
}


MainWindow::~MainWindow()
{
    delete ui;
}
