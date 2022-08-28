/********************************************************************************
** Form generated from reading UI file 'timerselection.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERSELECTION_H
#define UI_TIMERSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_TimerSelection
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *mins;
    QSpinBox *hours;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *canc;
    QPushButton *save;

    void setupUi(QDialog *TimerSelection)
    {
        if (TimerSelection->objectName().isEmpty())
            TimerSelection->setObjectName(QString::fromUtf8("TimerSelection"));
        TimerSelection->resize(400, 300);
        gridLayout = new QGridLayout(TimerSelection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(TimerSelection);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        mins = new QSpinBox(TimerSelection);
        mins->setObjectName(QString::fromUtf8("mins"));

        gridLayout_2->addWidget(mins, 1, 1, 1, 1);

        hours = new QSpinBox(TimerSelection);
        hours->setObjectName(QString::fromUtf8("hours"));

        gridLayout_2->addWidget(hours, 1, 0, 1, 1);

        label = new QLabel(TimerSelection);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        canc = new QPushButton(TimerSelection);
        canc->setObjectName(QString::fromUtf8("canc"));

        horizontalLayout_2->addWidget(canc);

        save = new QPushButton(TimerSelection);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_2->addWidget(save);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(TimerSelection);
        QObject::connect(save, &QPushButton::released, TimerSelection, qOverload<>(&QDialog::accept));
        QObject::connect(canc, &QPushButton::released, TimerSelection, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TimerSelection);
    } // setupUi

    void retranslateUi(QDialog *TimerSelection)
    {
        TimerSelection->setWindowTitle(QCoreApplication::translate("TimerSelection", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("TimerSelection", "Minutes", nullptr));
        label->setText(QCoreApplication::translate("TimerSelection", "Hours", nullptr));
        canc->setText(QCoreApplication::translate("TimerSelection", "Cancel", nullptr));
        save->setText(QCoreApplication::translate("TimerSelection", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerSelection: public Ui_TimerSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERSELECTION_H
