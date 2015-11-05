/********************************************************************************
** Form generated from reading UI file 'telemetry_analog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEMETRY_ANALOG_H
#define UI_TELEMETRY_ANALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelemetryAnalog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_11;
    QLabel *label_918;
    QLabel *label_Max;
    QLabel *alarm1Label;
    QComboBox *alarm1LevelCB;
    QComboBox *alarm1GreaterCB;
    QLabel *alarm2Label;
    QComboBox *alarm2LevelCB;
    QComboBox *alarm2GreaterCB;
    QDoubleSpinBox *RatioSB;
    QDoubleSpinBox *CalibSB;
    QDoubleSpinBox *alarm1ValueSB;
    QDoubleSpinBox *alarm2ValueSB;
    QLabel *CalibLabel;
    QComboBox *UnitCB;

    void setupUi(QWidget *TelemetryAnalog)
    {
        if (TelemetryAnalog->objectName().isEmpty())
            TelemetryAnalog->setObjectName(QString::fromUtf8("TelemetryAnalog"));
        TelemetryAnalog->resize(276, 138);
        verticalLayout = new QVBoxLayout(TelemetryAnalog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_918 = new QLabel(TelemetryAnalog);
        label_918->setObjectName(QString::fromUtf8("label_918"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_918->sizePolicy().hasHeightForWidth());
        label_918->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(label_918, 0, 0, 1, 1);

        label_Max = new QLabel(TelemetryAnalog);
        label_Max->setObjectName(QString::fromUtf8("label_Max"));
        sizePolicy.setHeightForWidth(label_Max->sizePolicy().hasHeightForWidth());
        label_Max->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(label_Max, 1, 0, 1, 1);

        alarm1Label = new QLabel(TelemetryAnalog);
        alarm1Label->setObjectName(QString::fromUtf8("alarm1Label"));
        sizePolicy.setHeightForWidth(alarm1Label->sizePolicy().hasHeightForWidth());
        alarm1Label->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(alarm1Label, 2, 0, 1, 1);

        alarm1LevelCB = new QComboBox(TelemetryAnalog);
        alarm1LevelCB->setObjectName(QString::fromUtf8("alarm1LevelCB"));
        sizePolicy.setHeightForWidth(alarm1LevelCB->sizePolicy().hasHeightForWidth());
        alarm1LevelCB->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(alarm1LevelCB, 2, 1, 1, 1);

        alarm1GreaterCB = new QComboBox(TelemetryAnalog);
        alarm1GreaterCB->setObjectName(QString::fromUtf8("alarm1GreaterCB"));
        sizePolicy.setHeightForWidth(alarm1GreaterCB->sizePolicy().hasHeightForWidth());
        alarm1GreaterCB->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(alarm1GreaterCB, 2, 2, 1, 1);

        alarm2Label = new QLabel(TelemetryAnalog);
        alarm2Label->setObjectName(QString::fromUtf8("alarm2Label"));
        sizePolicy.setHeightForWidth(alarm2Label->sizePolicy().hasHeightForWidth());
        alarm2Label->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(alarm2Label, 3, 0, 1, 1);

        alarm2LevelCB = new QComboBox(TelemetryAnalog);
        alarm2LevelCB->setObjectName(QString::fromUtf8("alarm2LevelCB"));
        sizePolicy.setHeightForWidth(alarm2LevelCB->sizePolicy().hasHeightForWidth());
        alarm2LevelCB->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(alarm2LevelCB, 3, 1, 1, 1);

        alarm2GreaterCB = new QComboBox(TelemetryAnalog);
        alarm2GreaterCB->setObjectName(QString::fromUtf8("alarm2GreaterCB"));
        sizePolicy.setHeightForWidth(alarm2GreaterCB->sizePolicy().hasHeightForWidth());
        alarm2GreaterCB->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(alarm2GreaterCB, 3, 2, 1, 1);

        RatioSB = new QDoubleSpinBox(TelemetryAnalog);
        RatioSB->setObjectName(QString::fromUtf8("RatioSB"));
        RatioSB->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RatioSB->sizePolicy().hasHeightForWidth());
        RatioSB->setSizePolicy(sizePolicy1);
        RatioSB->setDecimals(0);
        RatioSB->setMaximum(255);

        gridLayout_11->addWidget(RatioSB, 1, 1, 1, 1);

        CalibSB = new QDoubleSpinBox(TelemetryAnalog);
        CalibSB->setObjectName(QString::fromUtf8("CalibSB"));
        sizePolicy1.setHeightForWidth(CalibSB->sizePolicy().hasHeightForWidth());
        CalibSB->setSizePolicy(sizePolicy1);
        CalibSB->setDecimals(2);
        CalibSB->setMinimum(-12.8);
        CalibSB->setMaximum(12.7);
        CalibSB->setSingleStep(0.1);

        gridLayout_11->addWidget(CalibSB, 1, 3, 1, 1);

        alarm1ValueSB = new QDoubleSpinBox(TelemetryAnalog);
        alarm1ValueSB->setObjectName(QString::fromUtf8("alarm1ValueSB"));
        alarm1ValueSB->setEnabled(true);
        sizePolicy.setHeightForWidth(alarm1ValueSB->sizePolicy().hasHeightForWidth());
        alarm1ValueSB->setSizePolicy(sizePolicy);
        alarm1ValueSB->setDecimals(0);
        alarm1ValueSB->setMaximum(255);

        gridLayout_11->addWidget(alarm1ValueSB, 2, 3, 1, 1);

        alarm2ValueSB = new QDoubleSpinBox(TelemetryAnalog);
        alarm2ValueSB->setObjectName(QString::fromUtf8("alarm2ValueSB"));
        alarm2ValueSB->setEnabled(true);
        sizePolicy.setHeightForWidth(alarm2ValueSB->sizePolicy().hasHeightForWidth());
        alarm2ValueSB->setSizePolicy(sizePolicy);
        alarm2ValueSB->setDecimals(0);
        alarm2ValueSB->setMaximum(255);

        gridLayout_11->addWidget(alarm2ValueSB, 3, 3, 1, 1);

        CalibLabel = new QLabel(TelemetryAnalog);
        CalibLabel->setObjectName(QString::fromUtf8("CalibLabel"));
        sizePolicy.setHeightForWidth(CalibLabel->sizePolicy().hasHeightForWidth());
        CalibLabel->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(CalibLabel, 1, 2, 1, 1);

        UnitCB = new QComboBox(TelemetryAnalog);
        UnitCB->setObjectName(QString::fromUtf8("UnitCB"));
        sizePolicy1.setHeightForWidth(UnitCB->sizePolicy().hasHeightForWidth());
        UnitCB->setSizePolicy(sizePolicy1);

        gridLayout_11->addWidget(UnitCB, 0, 1, 1, 3);

        gridLayout_11->setColumnStretch(0, 1);
        gridLayout_11->setColumnStretch(1, 1);
        gridLayout_11->setColumnStretch(2, 1);
        gridLayout_11->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout_11);

        QWidget::setTabOrder(UnitCB, RatioSB);
        QWidget::setTabOrder(RatioSB, CalibSB);
        QWidget::setTabOrder(CalibSB, alarm1LevelCB);
        QWidget::setTabOrder(alarm1LevelCB, alarm1GreaterCB);
        QWidget::setTabOrder(alarm1GreaterCB, alarm1ValueSB);
        QWidget::setTabOrder(alarm1ValueSB, alarm2LevelCB);
        QWidget::setTabOrder(alarm2LevelCB, alarm2GreaterCB);
        QWidget::setTabOrder(alarm2GreaterCB, alarm2ValueSB);

        retranslateUi(TelemetryAnalog);

        QMetaObject::connectSlotsByName(TelemetryAnalog);
    } // setupUi

    void retranslateUi(QWidget *TelemetryAnalog)
    {
        TelemetryAnalog->setWindowTitle(QString());
        label_918->setText(QApplication::translate("TelemetryAnalog", "Unit", 0, QApplication::UnicodeUTF8));
        label_Max->setText(QApplication::translate("TelemetryAnalog", "Max Value", 0, QApplication::UnicodeUTF8));
        alarm1Label->setText(QApplication::translate("TelemetryAnalog", "Alarm 1    ", 0, QApplication::UnicodeUTF8));
        alarm1LevelCB->clear();
        alarm1LevelCB->insertItems(0, QStringList()
         << QApplication::translate("TelemetryAnalog", "----", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Orange", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Red", 0, QApplication::UnicodeUTF8)
        );
        alarm1GreaterCB->clear();
        alarm1GreaterCB->insertItems(0, QStringList()
         << QApplication::translate("TelemetryAnalog", "<", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", ">", 0, QApplication::UnicodeUTF8)
        );
        alarm2Label->setText(QApplication::translate("TelemetryAnalog", "Alarm 2", 0, QApplication::UnicodeUTF8));
        alarm2LevelCB->clear();
        alarm2LevelCB->insertItems(0, QStringList()
         << QApplication::translate("TelemetryAnalog", "----", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Orange", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Red", 0, QApplication::UnicodeUTF8)
        );
        alarm2GreaterCB->clear();
        alarm2GreaterCB->insertItems(0, QStringList()
         << QApplication::translate("TelemetryAnalog", "<", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", ">", 0, QApplication::UnicodeUTF8)
        );
        CalibLabel->setText(QApplication::translate("TelemetryAnalog", "Offset", 0, QApplication::UnicodeUTF8));
        UnitCB->clear();
        UnitCB->insertItems(0, QStringList()
         << QApplication::translate("TelemetryAnalog", "Volts (V)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Amps (A)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Speed (m/s or ft/s)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Raw (-)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Speed (km/h or miles/h)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Meters (m or ft)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Temp (\302\260)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "Fuel (%)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryAnalog", "mAmps (mA)", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class TelemetryAnalog: public Ui_TelemetryAnalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEMETRY_ANALOG_H
