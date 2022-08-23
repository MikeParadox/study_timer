#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timerselection.h"
#include <iostream>

void MainWindow::handleNewTimerButton()
{
    TimerSelection *t = new TimerSelection(this);
    t->exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleNewTimerButton);
}


MainWindow::~MainWindow()
{
    delete ui;
}
