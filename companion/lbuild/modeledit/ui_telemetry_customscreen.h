/********************************************************************************
** Form generated from reading UI file 'telemetry_customscreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEMETRY_CUSTOMSCREEN_H
#define UI_TELEMETRY_CUSTOMSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelemetryCustomScreen
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *screenTypeLabel;
    QComboBox *screenType;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout;
    QGroupBox *screenNums;
    QGridLayout *screenNumsLayout;
    QGroupBox *screenBars;
    QGridLayout *screenBarsLayout;
    QLabel *label_266;
    QLabel *label_265;
    QLabel *label_267;
    QLabel *label_268;

    void setupUi(QWidget *TelemetryCustomScreen)
    {
        if (TelemetryCustomScreen->objectName().isEmpty())
            TelemetryCustomScreen->setObjectName(QString::fromUtf8("TelemetryCustomScreen"));
        TelemetryCustomScreen->resize(650, 393);
        verticalLayout = new QVBoxLayout(TelemetryCustomScreen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        screenTypeLabel = new QLabel(TelemetryCustomScreen);
        screenTypeLabel->setObjectName(QString::fromUtf8("screenTypeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(screenTypeLabel->sizePolicy().hasHeightForWidth());
        screenTypeLabel->setSizePolicy(sizePolicy);
        screenTypeLabel->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(screenTypeLabel);

        screenType = new QComboBox(TelemetryCustomScreen);
        screenType->setObjectName(QString::fromUtf8("screenType"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(screenType->sizePolicy().hasHeightForWidth());
        screenType->setSizePolicy(sizePolicy1);
        screenType->setMinimumSize(QSize(90, 0));

        horizontalLayout_5->addWidget(screenType);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_16);

        horizontalLayout_5->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        screenNums = new QGroupBox(TelemetryCustomScreen);
        screenNums->setObjectName(QString::fromUtf8("screenNums"));
        screenNumsLayout = new QGridLayout(screenNums);
        screenNumsLayout->setObjectName(QString::fromUtf8("screenNumsLayout"));

        horizontalLayout->addWidget(screenNums);

        screenBars = new QGroupBox(TelemetryCustomScreen);
        screenBars->setObjectName(QString::fromUtf8("screenBars"));
        screenBarsLayout = new QGridLayout(screenBars);
        screenBarsLayout->setObjectName(QString::fromUtf8("screenBarsLayout"));
        label_266 = new QLabel(screenBars);
        label_266->setObjectName(QString::fromUtf8("label_266"));
        label_266->setAlignment(Qt::AlignCenter);

        screenBarsLayout->addWidget(label_266, 0, 1, 1, 1);

        label_265 = new QLabel(screenBars);
        label_265->setObjectName(QString::fromUtf8("label_265"));
        label_265->setAlignment(Qt::AlignCenter);

        screenBarsLayout->addWidget(label_265, 0, 0, 1, 1);

        label_267 = new QLabel(screenBars);
        label_267->setObjectName(QString::fromUtf8("label_267"));
        label_267->setAlignment(Qt::AlignCenter);

        screenBarsLayout->addWidget(label_267, 0, 2, 1, 1);

        label_268 = new QLabel(screenBars);
        label_268->setObjectName(QString::fromUtf8("label_268"));
        label_268->setAlignment(Qt::AlignCenter);

        screenBarsLayout->addWidget(label_268, 0, 3, 1, 1);

        screenBarsLayout->setColumnStretch(0, 1);
        screenBarsLayout->setColumnStretch(2, 1);

        horizontalLayout->addWidget(screenBars);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TelemetryCustomScreen);

        QMetaObject::connectSlotsByName(TelemetryCustomScreen);
    } // setupUi

    void retranslateUi(QWidget *TelemetryCustomScreen)
    {
        TelemetryCustomScreen->setWindowTitle(QString());
        screenTypeLabel->setText(QApplication::translate("TelemetryCustomScreen", "Custom Screen Type", 0, QApplication::UnicodeUTF8));
        screenType->clear();
        screenType->insertItems(0, QStringList()
         << QApplication::translate("TelemetryCustomScreen", "Nums", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TelemetryCustomScreen", "Bars", 0, QApplication::UnicodeUTF8)
        );
        label_266->setText(QApplication::translate("TelemetryCustomScreen", "Min", 0, QApplication::UnicodeUTF8));
        label_265->setText(QApplication::translate("TelemetryCustomScreen", "Source", 0, QApplication::UnicodeUTF8));
        label_267->setText(QApplication::translate("TelemetryCustomScreen", "Gauge", 0, QApplication::UnicodeUTF8));
        label_268->setText(QApplication::translate("TelemetryCustomScreen", "Max", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TelemetryCustomScreen: public Ui_TelemetryCustomScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEMETRY_CUSTOMSCREEN_H
