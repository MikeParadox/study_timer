/********************************************************************************
** Form generated from reading UI file 'timerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERWIDGET_H
#define UI_TIMERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *time;
    QPushButton *pauseButton;
    QLabel *timerNameFieldOnTimer;
    QPushButton *resetButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *startButton;

    void setupUi(QWidget *TimerWidget)
    {
        if (TimerWidget->objectName().isEmpty())
            TimerWidget->setObjectName(QString::fromUtf8("TimerWidget"));
        TimerWidget->resize(600, 150);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TimerWidget->sizePolicy().hasHeightForWidth());
        TimerWidget->setSizePolicy(sizePolicy);
        TimerWidget->setMinimumSize(QSize(0, 150));
        TimerWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(TimerWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(TimerWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        time = new QLabel(frame);
        time->setObjectName(QString::fromUtf8("time"));
        QFont font;
        font.setPointSize(23);
        font.setBold(true);
        time->setFont(font);

        gridLayout->addWidget(time, 1, 0, 2, 1);

        pauseButton = new QPushButton(frame);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        gridLayout->addWidget(pauseButton, 0, 2, 3, 1);

        timerNameFieldOnTimer = new QLabel(frame);
        timerNameFieldOnTimer->setObjectName(QString::fromUtf8("timerNameFieldOnTimer"));

        gridLayout->addWidget(timerNameFieldOnTimer, 0, 0, 1, 1);

        resetButton = new QPushButton(frame);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout->addWidget(resetButton, 0, 4, 3, 1);

        editButton = new QPushButton(frame);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        gridLayout->addWidget(editButton, 0, 5, 3, 1);

        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 0, 6, 3, 1);

        startButton = new QPushButton(frame);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout->addWidget(startButton, 0, 1, 3, 1);


        verticalLayout->addWidget(frame);


        retranslateUi(TimerWidget);

        QMetaObject::connectSlotsByName(TimerWidget);
    } // setupUi

    void retranslateUi(QWidget *TimerWidget)
    {
        TimerWidget->setWindowTitle(QCoreApplication::translate("TimerWidget", "Form", nullptr));
        time->setText(QCoreApplication::translate("TimerWidget", "Set Time", nullptr));
        pauseButton->setText(QCoreApplication::translate("TimerWidget", "Pause", nullptr));
        timerNameFieldOnTimer->setText(QCoreApplication::translate("TimerWidget", "Timer Name", nullptr));
        resetButton->setText(QCoreApplication::translate("TimerWidget", "Reset", nullptr));
        editButton->setText(QCoreApplication::translate("TimerWidget", "Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("TimerWidget", "Delete", nullptr));
        startButton->setText(QCoreApplication::translate("TimerWidget", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerWidget: public Ui_TimerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWIDGET_H
