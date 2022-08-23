#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timerselection.h"
#include "timeritem.h"
#include <iostream>

void MainWindow::addTimer()
{
    std::cout << "accepted";
}

void MainWindow::handleEditTimerButton()
{
    //TimerSelection *t = new TimerSelection(this);
    //t->exec();
    //connect(t, &QDialog::finished, this, &MainWindow::addTimer);
    TimerItem *newItem = new TimerItem(this);
    newItem->setParent(ui->scrollAreaWidgetContents);
    newItem->show();
    TimerItem *anewItem = new TimerItem(this);
    anewItem->setParent(ui->scrollAreaWidgetContents);
    anewItem->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleEditTimerButton);
}


MainWindow::~MainWindow()
{
    delete ui;
}
