#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timerselection.h"
#include "timerwidget.h"

#include <chrono>
#include "includes/Timer.h"

void MainWindow::handleAddTimerButton()
{
    TimerSelection *timerSelection = new TimerSelection(this);
    connect(timerSelection, &TimerSelection::accepted, this, &MainWindow::addTimer);
    timerSelection->exec();
}

void MainWindow::addTimer()
{
    TimerSelection *timerSelection = qobject_cast<TimerSelection*>(sender());
    TimerWidget *timerWidget = new TimerWidget(this);
    timerWidget->initialize(timerSelection);

    ui->verticalLayout_2->addWidget(timerWidget);
    timerWidget->show();
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
