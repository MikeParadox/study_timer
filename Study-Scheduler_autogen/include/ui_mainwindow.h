/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *timerTab;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *addTimerButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *somethingElseTab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1042, 641);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        timerTab = new QWidget();
        timerTab->setObjectName(QString::fromUtf8("timerTab"));
        gridLayout = new QGridLayout(timerTab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(timerTab);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(23);
        font.setBold(true);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        addTimerButton = new QPushButton(timerTab);
        addTimerButton->setObjectName(QString::fromUtf8("addTimerButton"));

        gridLayout->addWidget(addTimerButton, 0, 1, 1, 1);

        scrollArea = new QScrollArea(timerTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1002, 480));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 2);

        tabWidget->addTab(timerTab, QString());
        somethingElseTab = new QWidget();
        somethingElseTab->setObjectName(QString::fromUtf8("somethingElseTab"));
        tabWidget->addTab(somethingElseTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1042, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Study Scheduler", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Timers", nullptr));
        addTimerButton->setText(QCoreApplication::translate("MainWindow", "Add new timer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(timerTab), QCoreApplication::translate("MainWindow", "Timers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(somethingElseTab), QCoreApplication::translate("MainWindow", "Something Else", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
