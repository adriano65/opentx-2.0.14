/********************************************************************************
** Form generated from reading UI file 'setup_timer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_TIMER_H
#define UI_SETUP_TIMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>
#include "qautocombobox.h"

QT_BEGIN_NAMESPACE

class Ui_Timer
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTimeEdit *value;
    QComboBox *mode;
    QLabel *countdownBeepLabel;
    QUnsignedAutoComboBox *countdownBeep;
    QCheckBox *minuteBeep;
    QUnsignedAutoComboBox *persistent;
    QLabel *persistentValue;
    QSpacerItem *spacer;

    void setupUi(QWidget *Timer)
    {
        if (Timer->objectName().isEmpty())
            Timer->setObjectName(QString::fromUtf8("Timer"));
        Timer->resize(586, 38);
        horizontalLayout_2 = new QHBoxLayout(Timer);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        value = new QTimeEdit(Timer);
        value->setObjectName(QString::fromUtf8("value"));
        value->setAccelerated(true);
        value->setCurrentSection(QDateTimeEdit::MinuteSection);
        value->setDisplayFormat(QString::fromUtf8("mm:ss"));

        horizontalLayout_2->addWidget(value);

        mode = new QComboBox(Timer);
        mode->setObjectName(QString::fromUtf8("mode"));

        horizontalLayout_2->addWidget(mode);

        countdownBeepLabel = new QLabel(Timer);
        countdownBeepLabel->setObjectName(QString::fromUtf8("countdownBeepLabel"));

        horizontalLayout_2->addWidget(countdownBeepLabel);

        countdownBeep = new QUnsignedAutoComboBox(Timer);
        countdownBeep->setObjectName(QString::fromUtf8("countdownBeep"));

        horizontalLayout_2->addWidget(countdownBeep);

        minuteBeep = new QCheckBox(Timer);
        minuteBeep->setObjectName(QString::fromUtf8("minuteBeep"));

        horizontalLayout_2->addWidget(minuteBeep);

        persistent = new QUnsignedAutoComboBox(Timer);
        persistent->setObjectName(QString::fromUtf8("persistent"));

        horizontalLayout_2->addWidget(persistent);

        persistentValue = new QLabel(Timer);
        persistentValue->setObjectName(QString::fromUtf8("persistentValue"));
        persistentValue->setText(QString::fromUtf8(" (00:00:00)"));

        horizontalLayout_2->addWidget(persistentValue);

        spacer = new QSpacerItem(255, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacer);


        retranslateUi(Timer);

        QMetaObject::connectSlotsByName(Timer);
    } // setupUi

    void retranslateUi(QWidget *Timer)
    {
        Timer->setWindowTitle(QString());
        countdownBeepLabel->setText(QApplication::translate("Timer", "Countdown", 0, QApplication::UnicodeUTF8));
        minuteBeep->setText(QApplication::translate("Timer", "Minute Call", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Timer: public Ui_Timer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_TIMER_H
