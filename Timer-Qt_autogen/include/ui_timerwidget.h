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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *time;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *TimerWidget)
    {
        if (TimerWidget->objectName().isEmpty())
            TimerWidget->setObjectName(QString::fromUtf8("TimerWidget"));
        TimerWidget->resize(660, 266);
        horizontalLayout = new QHBoxLayout(TimerWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(TimerWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        time = new QLabel(frame);
        time->setObjectName(QString::fromUtf8("time"));
        QFont font;
        font.setPointSize(23);
        font.setBold(true);
        time->setFont(font);

        horizontalLayout_2->addWidget(time);

        pauseButton = new QPushButton(frame);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_2->addWidget(pauseButton);

        resetButton = new QPushButton(frame);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        horizontalLayout_2->addWidget(resetButton);

        editButton = new QPushButton(frame);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout_2->addWidget(editButton);

        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);


        horizontalLayout->addWidget(frame);


        retranslateUi(TimerWidget);

        QMetaObject::connectSlotsByName(TimerWidget);
    } // setupUi

    void retranslateUi(QWidget *TimerWidget)
    {
        TimerWidget->setWindowTitle(QCoreApplication::translate("TimerWidget", "Form", nullptr));
        time->setText(QCoreApplication::translate("TimerWidget", "Set Time", nullptr));
        pauseButton->setText(QCoreApplication::translate("TimerWidget", "Pause (Toggle)", nullptr));
        resetButton->setText(QCoreApplication::translate("TimerWidget", "Reset", nullptr));
        editButton->setText(QCoreApplication::translate("TimerWidget", "Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("TimerWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerWidget: public Ui_TimerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWIDGET_H
