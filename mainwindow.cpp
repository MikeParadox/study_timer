#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timerselection.h"
#include "timerwidget.h"
#include <memory>

#include <chrono>
#include "Timer.h"

// Handle the "Add timer" button, creating a new timer selection dialog
void MainWindow::handleAddTimerButton()
{
    TimerSelection* timerSelection = new TimerSelection(this);
    // Connect the "Accept" button to addTimer
    connect(timerSelection, &TimerSelection::accepted, this, &MainWindow::addTimer);
    // Show the dialog
    timerSelection->exec();
}

// Create a new TimerWidget
void MainWindow::addTimer()
{
    // Get the TimerSelection from the sender() QObject
    TimerSelection *timerSelection = qobject_cast<TimerSelection*>(sender());

    // std::unique_ptr

    // New timerWidget
    TimerWidget *timerWidget = new TimerWidget(this);
    // Initialize timerWidget
    timerWidget->initialize(timerSelection);

    // Add it to the ScrollArea layout
    ui->verticalLayout_2->addWidget(timerWidget);
    // Show the widget
    timerWidget->show();
}

void MainWindow::delTimer(TimerWidget *t)
{
    ui->verticalLayout_2->removeWidget(t);
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
