/********************************************************************************
** Form generated from reading UI file 'telemetry.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEMETRY_H
#define UI_TELEMETRY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qautocombobox.h"

QT_BEGIN_NAMESPACE

class Ui_Telemetry
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *telemetryProtocolLabel;
    QComboBox *telemetryProtocol;
    QGridLayout *gridLayout_2;
    QGroupBox *A1GB;
    QVBoxLayout *A1Layout;
    QLabel *label_7;
    QGroupBox *A4GB;
    QVBoxLayout *A4Layout;
    QLabel *label_9;
    QGroupBox *A3GB;
    QVBoxLayout *A3Layout;
    QLabel *label_8;
    QGroupBox *A2GB;
    QVBoxLayout *A2Layout;
    QLabel *label_6;
    QGroupBox *altimetryGB;
    QGridLayout *gridLayout_39;
    QGridLayout *gridLayout_40;
    QUnsignedAutoComboBox *varioSourceCB;
    QGridLayout *gridLayout_66;
    QLabel *VarioLabel_1;
    QDoubleSpinBox *varioLimitCenterMin_DSB;
    QDoubleSpinBox *varioLimitCenterMax_DSB;
    QDoubleSpinBox *varioLimitMax_DSB;
    QDoubleSpinBox *varioLimitMin_DSB;
    QLabel *VarioLabel_2;
    QLabel *VarioLabel_3;
    QLabel *VarioLabel_4;
    QLabel *varioSource_label;
    QLabel *varioLimit_label;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *AltitudeGPS_ChkB;
    QCheckBox *AltitudeToolbar_ChkB;
    QLabel *label_2;
    QGroupBox *variousGB;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QUnsignedAutoComboBox *frskyVoltCB;
    QLabel *label_4;
    QUnsignedAutoComboBox *frskyCurrentCB;
    QSpacerItem *horizontalSpacer;
    QLabel *current_label;
    QDoubleSpinBox *bladesCount;
    QLabel *blades_label;
    QLabel *mahCount_label;
    QSpinBox *mahCount_SB;
    QDoubleSpinBox *fasOffset_DSB;
    QLabel *fasOffset_label;
    QCheckBox *mahCount_ChkB;
    QLabel *label_3;
    QLabel *label;
    QComboBox *frskyProtoCB;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *RSSIGB;
    QGridLayout *gridLayout_7;
    QLabel *rssiAlarm1Label;
    QComboBox *rssiAlarm1CB;
    QSpinBox *rssiAlarm1SB;
    QLabel *rssiAlarm2Label;
    QComboBox *rssiAlarm2CB;
    QSpinBox *rssiAlarm2SB;
    QLabel *rssiLabel;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QTabWidget *customScreens;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Telemetry)
    {
        if (Telemetry->objectName().isEmpty())
            Telemetry->setObjectName(QString::fromUtf8("Telemetry"));
        Telemetry->resize(850, 521);
        verticalLayout = new QVBoxLayout(Telemetry);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        telemetryProtocolLabel = new QLabel(Telemetry);
        telemetryProtocolLabel->setObjectName(QString::fromUtf8("telemetryProtocolLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(telemetryProtocolLabel->sizePolicy().hasHeightForWidth());
        telemetryProtocolLabel->setSizePolicy(sizePolicy);
        telemetryProtocolLabel->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(telemetryProtocolLabel);

        telemetryProtocol = new QComboBox(Telemetry);
        telemetryProtocol->setObjectName(QString::fromUtf8("telemetryProtocol"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(telemetryProtocol->sizePolicy().hasHeightForWidth());
        telemetryProtocol->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(telemetryProtocol);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        A1GB = new QGroupBox(Telemetry);
        A1GB->setObjectName(QString::fromUtf8("A1GB"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(A1GB->sizePolicy().hasHeightForWidth());
        A1GB->setSizePolicy(sizePolicy2);
        A1GB->setAutoFillBackground(true);
        A1GB->setStyleSheet(QString::fromUtf8(""));
        A1GB->setFlat(false);
        A1Layout = new QVBoxLayout(A1GB);
        A1Layout->setObjectName(QString::fromUtf8("A1Layout"));
        A1Layout->setContentsMargins(0, 0, 3, 3);
        label_7 = new QLabel(A1GB);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        A1Layout->addWidget(label_7);


        gridLayout_2->addWidget(A1GB, 1, 0, 1, 1);

        A4GB = new QGroupBox(Telemetry);
        A4GB->setObjectName(QString::fromUtf8("A4GB"));
        A4GB->setFlat(false);
        A4Layout = new QVBoxLayout(A4GB);
        A4Layout->setObjectName(QString::fromUtf8("A4Layout"));
        A4Layout->setContentsMargins(0, 0, 3, 3);
        label_9 = new QLabel(A4GB);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        A4Layout->addWidget(label_9);


        gridLayout_2->addWidget(A4GB, 2, 1, 1, 1);

        A3GB = new QGroupBox(Telemetry);
        A3GB->setObjectName(QString::fromUtf8("A3GB"));
        sizePolicy2.setHeightForWidth(A3GB->sizePolicy().hasHeightForWidth());
        A3GB->setSizePolicy(sizePolicy2);
        A3GB->setAutoFillBackground(true);
        A3GB->setStyleSheet(QString::fromUtf8(""));
        A3GB->setFlat(false);
        A3Layout = new QVBoxLayout(A3GB);
        A3Layout->setObjectName(QString::fromUtf8("A3Layout"));
        A3Layout->setContentsMargins(0, 0, 3, 3);
        label_8 = new QLabel(A3GB);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        A3Layout->addWidget(label_8);


        gridLayout_2->addWidget(A3GB, 2, 0, 1, 1);

        A2GB = new QGroupBox(Telemetry);
        A2GB->setObjectName(QString::fromUtf8("A2GB"));
        A2GB->setFlat(false);
        A2Layout = new QVBoxLayout(A2GB);
        A2Layout->setObjectName(QString::fromUtf8("A2Layout"));
        A2Layout->setContentsMargins(0, 0, 3, 3);
        label_6 = new QLabel(A2GB);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        A2Layout->addWidget(label_6);


        gridLayout_2->addWidget(A2GB, 1, 1, 1, 1);

        altimetryGB = new QGroupBox(Telemetry);
        altimetryGB->setObjectName(QString::fromUtf8("altimetryGB"));
        sizePolicy.setHeightForWidth(altimetryGB->sizePolicy().hasHeightForWidth());
        altimetryGB->setSizePolicy(sizePolicy);
        gridLayout_39 = new QGridLayout(altimetryGB);
        gridLayout_39->setSpacing(0);
        gridLayout_39->setObjectName(QString::fromUtf8("gridLayout_39"));
        gridLayout_39->setContentsMargins(0, 0, 3, 3);
        gridLayout_40 = new QGridLayout();
        gridLayout_40->setObjectName(QString::fromUtf8("gridLayout_40"));
        gridLayout_40->setHorizontalSpacing(9);
        varioSourceCB = new QUnsignedAutoComboBox(altimetryGB);
        varioSourceCB->setObjectName(QString::fromUtf8("varioSourceCB"));
        sizePolicy1.setHeightForWidth(varioSourceCB->sizePolicy().hasHeightForWidth());
        varioSourceCB->setSizePolicy(sizePolicy1);

        gridLayout_40->addWidget(varioSourceCB, 1, 1, 1, 1);

        gridLayout_66 = new QGridLayout();
        gridLayout_66->setObjectName(QString::fromUtf8("gridLayout_66"));
        VarioLabel_1 = new QLabel(altimetryGB);
        VarioLabel_1->setObjectName(QString::fromUtf8("VarioLabel_1"));
        sizePolicy.setHeightForWidth(VarioLabel_1->sizePolicy().hasHeightForWidth());
        VarioLabel_1->setSizePolicy(sizePolicy);
        VarioLabel_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_66->addWidget(VarioLabel_1, 0, 0, 1, 1);

        varioLimitCenterMin_DSB = new QDoubleSpinBox(altimetryGB);
        varioLimitCenterMin_DSB->setObjectName(QString::fromUtf8("varioLimitCenterMin_DSB"));
        sizePolicy1.setHeightForWidth(varioLimitCenterMin_DSB->sizePolicy().hasHeightForWidth());
        varioLimitCenterMin_DSB->setSizePolicy(sizePolicy1);
        varioLimitCenterMin_DSB->setDecimals(1);
        varioLimitCenterMin_DSB->setMinimum(-2.1);
        varioLimitCenterMin_DSB->setMaximum(1);
        varioLimitCenterMin_DSB->setSingleStep(0.1);
        varioLimitCenterMin_DSB->setValue(-0.5);

        gridLayout_66->addWidget(varioLimitCenterMin_DSB, 1, 1, 1, 1);

        varioLimitCenterMax_DSB = new QDoubleSpinBox(altimetryGB);
        varioLimitCenterMax_DSB->setObjectName(QString::fromUtf8("varioLimitCenterMax_DSB"));
        sizePolicy1.setHeightForWidth(varioLimitCenterMax_DSB->sizePolicy().hasHeightForWidth());
        varioLimitCenterMax_DSB->setSizePolicy(sizePolicy1);
        varioLimitCenterMax_DSB->setDecimals(1);
        varioLimitCenterMax_DSB->setMinimum(-1);
        varioLimitCenterMax_DSB->setMaximum(2);
        varioLimitCenterMax_DSB->setSingleStep(0.1);
        varioLimitCenterMax_DSB->setValue(0.5);

        gridLayout_66->addWidget(varioLimitCenterMax_DSB, 1, 2, 1, 1);

        varioLimitMax_DSB = new QDoubleSpinBox(altimetryGB);
        varioLimitMax_DSB->setObjectName(QString::fromUtf8("varioLimitMax_DSB"));
        sizePolicy1.setHeightForWidth(varioLimitMax_DSB->sizePolicy().hasHeightForWidth());
        varioLimitMax_DSB->setSizePolicy(sizePolicy1);
        varioLimitMax_DSB->setDecimals(0);
        varioLimitMax_DSB->setMinimum(3);
        varioLimitMax_DSB->setMaximum(17);
        varioLimitMax_DSB->setValue(10);

        gridLayout_66->addWidget(varioLimitMax_DSB, 1, 3, 1, 1);

        varioLimitMin_DSB = new QDoubleSpinBox(altimetryGB);
        varioLimitMin_DSB->setObjectName(QString::fromUtf8("varioLimitMin_DSB"));
        sizePolicy1.setHeightForWidth(varioLimitMin_DSB->sizePolicy().hasHeightForWidth());
        varioLimitMin_DSB->setSizePolicy(sizePolicy1);
        varioLimitMin_DSB->setDecimals(0);
        varioLimitMin_DSB->setMinimum(-17);
        varioLimitMin_DSB->setMaximum(-3);
        varioLimitMin_DSB->setValue(-10);

        gridLayout_66->addWidget(varioLimitMin_DSB, 1, 0, 1, 1);

        VarioLabel_2 = new QLabel(altimetryGB);
        VarioLabel_2->setObjectName(QString::fromUtf8("VarioLabel_2"));
        sizePolicy.setHeightForWidth(VarioLabel_2->sizePolicy().hasHeightForWidth());
        VarioLabel_2->setSizePolicy(sizePolicy);
        VarioLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_66->addWidget(VarioLabel_2, 0, 3, 1, 1);

        VarioLabel_3 = new QLabel(altimetryGB);
        VarioLabel_3->setObjectName(QString::fromUtf8("VarioLabel_3"));
        sizePolicy.setHeightForWidth(VarioLabel_3->sizePolicy().hasHeightForWidth());
        VarioLabel_3->setSizePolicy(sizePolicy);
        VarioLabel_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_66->addWidget(VarioLabel_3, 0, 1, 1, 1);

        VarioLabel_4 = new QLabel(altimetryGB);
        VarioLabel_4->setObjectName(QString::fromUtf8("VarioLabel_4"));
        sizePolicy.setHeightForWidth(VarioLabel_4->sizePolicy().hasHeightForWidth());
        VarioLabel_4->setSizePolicy(sizePolicy);
        VarioLabel_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_66->addWidget(VarioLabel_4, 0, 2, 1, 1);

        gridLayout_66->setColumnStretch(0, 1);

        gridLayout_40->addLayout(gridLayout_66, 2, 1, 1, 1);

        varioSource_label = new QLabel(altimetryGB);
        varioSource_label->setObjectName(QString::fromUtf8("varioSource_label"));

        gridLayout_40->addWidget(varioSource_label, 1, 0, 1, 1);

        varioLimit_label = new QLabel(altimetryGB);
        varioLimit_label->setObjectName(QString::fromUtf8("varioLimit_label"));

        gridLayout_40->addWidget(varioLimit_label, 2, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        AltitudeGPS_ChkB = new QCheckBox(altimetryGB);
        AltitudeGPS_ChkB->setObjectName(QString::fromUtf8("AltitudeGPS_ChkB"));
        sizePolicy1.setHeightForWidth(AltitudeGPS_ChkB->sizePolicy().hasHeightForWidth());
        AltitudeGPS_ChkB->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(AltitudeGPS_ChkB);

        AltitudeToolbar_ChkB = new QCheckBox(altimetryGB);
        AltitudeToolbar_ChkB->setObjectName(QString::fromUtf8("AltitudeToolbar_ChkB"));
        sizePolicy1.setHeightForWidth(AltitudeToolbar_ChkB->sizePolicy().hasHeightForWidth());
        AltitudeToolbar_ChkB->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(AltitudeToolbar_ChkB);


        gridLayout_40->addLayout(horizontalLayout_16, 3, 0, 1, 2);

        label_2 = new QLabel(altimetryGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_40->addWidget(label_2, 0, 0, 1, 1);

        gridLayout_40->setRowStretch(0, 1);

        gridLayout_39->addLayout(gridLayout_40, 0, 0, 1, 1);


        gridLayout_2->addWidget(altimetryGB, 3, 1, 1, 1);

        variousGB = new QGroupBox(Telemetry);
        variousGB->setObjectName(QString::fromUtf8("variousGB"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(variousGB->sizePolicy().hasHeightForWidth());
        variousGB->setSizePolicy(sizePolicy3);
        gridLayout_6 = new QGridLayout(variousGB);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 3, 9);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(0);
        frskyVoltCB = new QUnsignedAutoComboBox(variousGB);
        frskyVoltCB->setObjectName(QString::fromUtf8("frskyVoltCB"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frskyVoltCB->sizePolicy().hasHeightForWidth());
        frskyVoltCB->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(frskyVoltCB, 3, 1, 1, 1);

        label_4 = new QLabel(variousGB);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        frskyCurrentCB = new QUnsignedAutoComboBox(variousGB);
        frskyCurrentCB->setObjectName(QString::fromUtf8("frskyCurrentCB"));
        sizePolicy4.setHeightForWidth(frskyCurrentCB->sizePolicy().hasHeightForWidth());
        frskyCurrentCB->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(frskyCurrentCB, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 5, 1, 1);

        current_label = new QLabel(variousGB);
        current_label->setObjectName(QString::fromUtf8("current_label"));
        sizePolicy3.setHeightForWidth(current_label->sizePolicy().hasHeightForWidth());
        current_label->setSizePolicy(sizePolicy3);
        current_label->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(current_label, 3, 2, 1, 1);

        bladesCount = new QDoubleSpinBox(variousGB);
        bladesCount->setObjectName(QString::fromUtf8("bladesCount"));
        sizePolicy1.setHeightForWidth(bladesCount->sizePolicy().hasHeightForWidth());
        bladesCount->setSizePolicy(sizePolicy1);
        bladesCount->setDecimals(0);
        bladesCount->setMinimum(2);
        bladesCount->setMaximum(5);
        bladesCount->setValue(2);

        gridLayout->addWidget(bladesCount, 4, 1, 1, 1);

        blades_label = new QLabel(variousGB);
        blades_label->setObjectName(QString::fromUtf8("blades_label"));
        sizePolicy3.setHeightForWidth(blades_label->sizePolicy().hasHeightForWidth());
        blades_label->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(blades_label, 4, 0, 1, 1);

        mahCount_label = new QLabel(variousGB);
        mahCount_label->setObjectName(QString::fromUtf8("mahCount_label"));

        gridLayout->addWidget(mahCount_label, 2, 2, 1, 1);

        mahCount_SB = new QSpinBox(variousGB);
        mahCount_SB->setObjectName(QString::fromUtf8("mahCount_SB"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(mahCount_SB->sizePolicy().hasHeightForWidth());
        mahCount_SB->setSizePolicy(sizePolicy5);
        mahCount_SB->setMaximum(32767);

        gridLayout->addWidget(mahCount_SB, 2, 3, 1, 1);

        fasOffset_DSB = new QDoubleSpinBox(variousGB);
        fasOffset_DSB->setObjectName(QString::fromUtf8("fasOffset_DSB"));
        sizePolicy5.setHeightForWidth(fasOffset_DSB->sizePolicy().hasHeightForWidth());
        fasOffset_DSB->setSizePolicy(sizePolicy5);
        fasOffset_DSB->setDecimals(1);
        fasOffset_DSB->setMinimum(-12);
        fasOffset_DSB->setMaximum(12);
        fasOffset_DSB->setSingleStep(0.1);

        gridLayout->addWidget(fasOffset_DSB, 2, 1, 1, 1);

        fasOffset_label = new QLabel(variousGB);
        fasOffset_label->setObjectName(QString::fromUtf8("fasOffset_label"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(fasOffset_label->sizePolicy().hasHeightForWidth());
        fasOffset_label->setSizePolicy(sizePolicy6);

        gridLayout->addWidget(fasOffset_label, 2, 0, 1, 1);

        mahCount_ChkB = new QCheckBox(variousGB);
        mahCount_ChkB->setObjectName(QString::fromUtf8("mahCount_ChkB"));

        gridLayout->addWidget(mahCount_ChkB, 2, 4, 1, 1);

        label_3 = new QLabel(variousGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy7);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(variousGB);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        frskyProtoCB = new QComboBox(variousGB);
        frskyProtoCB->setObjectName(QString::fromUtf8("frskyProtoCB"));
        sizePolicy1.setHeightForWidth(frskyProtoCB->sizePolicy().hasHeightForWidth());
        frskyProtoCB->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(frskyProtoCB, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 1, 0, 1, 1);


        gridLayout_2->addWidget(variousGB, 4, 1, 1, 1);

        RSSIGB = new QGroupBox(Telemetry);
        RSSIGB->setObjectName(QString::fromUtf8("RSSIGB"));
        sizePolicy2.setHeightForWidth(RSSIGB->sizePolicy().hasHeightForWidth());
        RSSIGB->setSizePolicy(sizePolicy2);
        RSSIGB->setFlat(false);
        gridLayout_7 = new QGridLayout(RSSIGB);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 3, 3);
        rssiAlarm1Label = new QLabel(RSSIGB);
        rssiAlarm1Label->setObjectName(QString::fromUtf8("rssiAlarm1Label"));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(rssiAlarm1Label->sizePolicy().hasHeightForWidth());
        rssiAlarm1Label->setSizePolicy(sizePolicy8);
        rssiAlarm1Label->setMinimumSize(QSize(0, 0));
        rssiAlarm1Label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_7->addWidget(rssiAlarm1Label, 1, 0, 1, 1);

        rssiAlarm1CB = new QComboBox(RSSIGB);
        rssiAlarm1CB->setObjectName(QString::fromUtf8("rssiAlarm1CB"));
        sizePolicy.setHeightForWidth(rssiAlarm1CB->sizePolicy().hasHeightForWidth());
        rssiAlarm1CB->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(rssiAlarm1CB, 1, 1, 1, 1);

        rssiAlarm1SB = new QSpinBox(RSSIGB);
        rssiAlarm1SB->setObjectName(QString::fromUtf8("rssiAlarm1SB"));
        rssiAlarm1SB->setEnabled(true);
        sizePolicy.setHeightForWidth(rssiAlarm1SB->sizePolicy().hasHeightForWidth());
        rssiAlarm1SB->setSizePolicy(sizePolicy);
        rssiAlarm1SB->setMinimum(20);
        rssiAlarm1SB->setMaximum(80);
        rssiAlarm1SB->setSingleStep(1);
        rssiAlarm1SB->setValue(50);

        gridLayout_7->addWidget(rssiAlarm1SB, 1, 2, 1, 1);

        rssiAlarm2Label = new QLabel(RSSIGB);
        rssiAlarm2Label->setObjectName(QString::fromUtf8("rssiAlarm2Label"));
        sizePolicy8.setHeightForWidth(rssiAlarm2Label->sizePolicy().hasHeightForWidth());
        rssiAlarm2Label->setSizePolicy(sizePolicy8);
        rssiAlarm2Label->setMinimumSize(QSize(0, 0));

        gridLayout_7->addWidget(rssiAlarm2Label, 2, 0, 1, 1);

        rssiAlarm2CB = new QComboBox(RSSIGB);
        rssiAlarm2CB->setObjectName(QString::fromUtf8("rssiAlarm2CB"));
        sizePolicy.setHeightForWidth(rssiAlarm2CB->sizePolicy().hasHeightForWidth());
        rssiAlarm2CB->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(rssiAlarm2CB, 2, 1, 1, 1);

        rssiAlarm2SB = new QSpinBox(RSSIGB);
        rssiAlarm2SB->setObjectName(QString::fromUtf8("rssiAlarm2SB"));
        rssiAlarm2SB->setEnabled(true);
        sizePolicy.setHeightForWidth(rssiAlarm2SB->sizePolicy().hasHeightForWidth());
        rssiAlarm2SB->setSizePolicy(sizePolicy);
        rssiAlarm2SB->setMinimum(20);
        rssiAlarm2SB->setMaximum(80);
        rssiAlarm2SB->setSingleStep(1);
        rssiAlarm2SB->setValue(50);

        gridLayout_7->addWidget(rssiAlarm2SB, 2, 2, 1, 1);

        rssiLabel = new QLabel(RSSIGB);
        rssiLabel->setObjectName(QString::fromUtf8("rssiLabel"));
        rssiLabel->setFont(font);

        gridLayout_7->addWidget(rssiLabel, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 3, 0, 1, 1);


        gridLayout_2->addWidget(RSSIGB, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        line = new QFrame(Telemetry);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        customScreens = new QTabWidget(Telemetry);
        customScreens->setObjectName(QString::fromUtf8("customScreens"));
        sizePolicy3.setHeightForWidth(customScreens->sizePolicy().hasHeightForWidth());
        customScreens->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(customScreens);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(telemetryProtocol, rssiAlarm1CB);
        QWidget::setTabOrder(rssiAlarm1CB, rssiAlarm1SB);
        QWidget::setTabOrder(rssiAlarm1SB, rssiAlarm2CB);
        QWidget::setTabOrder(rssiAlarm2CB, rssiAlarm2SB);
        QWidget::setTabOrder(rssiAlarm2SB, varioSourceCB);
        QWidget::setTabOrder(varioSourceCB, varioLimitMin_DSB);
        QWidget::setTabOrder(varioLimitMin_DSB, varioLimitCenterMin_DSB);
        QWidget::setTabOrder(varioLimitCenterMin_DSB, varioLimitCenterMax_DSB);
        QWidget::setTabOrder(varioLimitCenterMax_DSB, varioLimitMax_DSB);
        QWidget::setTabOrder(varioLimitMax_DSB, AltitudeGPS_ChkB);
        QWidget::setTabOrder(AltitudeGPS_ChkB, AltitudeToolbar_ChkB);
        QWidget::setTabOrder(AltitudeToolbar_ChkB, frskyProtoCB);
        QWidget::setTabOrder(frskyProtoCB, fasOffset_DSB);
        QWidget::setTabOrder(fasOffset_DSB, mahCount_SB);
        QWidget::setTabOrder(mahCount_SB, mahCount_ChkB);
        QWidget::setTabOrder(mahCount_ChkB, frskyVoltCB);
        QWidget::setTabOrder(frskyVoltCB, frskyCurrentCB);
        QWidget::setTabOrder(frskyCurrentCB, bladesCount);
        QWidget::setTabOrder(bladesCount, customScreens);

        retranslateUi(Telemetry);

        customScreens->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Telemetry);
    } // setupUi

    void retranslateUi(QWidget *Telemetry)
    {
        Telemetry->setWindowTitle(QString());
        telemetryProtocolLabel->setText(QApplication::translate("Telemetry", "Protocol", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Telemetry", "A1", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Telemetry", "A4", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Telemetry", "A3", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Telemetry", "A2", 0, QApplication::UnicodeUTF8));
        VarioLabel_1->setText(QApplication::translate("Telemetry", "Sink Max", 0, QApplication::UnicodeUTF8));
        VarioLabel_2->setText(QApplication::translate("Telemetry", "Climb Max", 0, QApplication::UnicodeUTF8));
        VarioLabel_3->setText(QApplication::translate("Telemetry", "Sink Min", 0, QApplication::UnicodeUTF8));
        VarioLabel_4->setText(QApplication::translate("Telemetry", "Climb Min", 0, QApplication::UnicodeUTF8));
        varioSource_label->setText(QApplication::translate("Telemetry", "Vario source", 0, QApplication::UnicodeUTF8));
        varioLimit_label->setText(QApplication::translate("Telemetry", "Vario limits", 0, QApplication::UnicodeUTF8));
        AltitudeGPS_ChkB->setText(QApplication::translate("Telemetry", "Use GPS as altitude source", 0, QApplication::UnicodeUTF8));
        AltitudeToolbar_ChkB->setText(QApplication::translate("Telemetry", "Display altitude in toolbar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Telemetry", "Altimetry", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Telemetry", "Volt source", 0, QApplication::UnicodeUTF8));
        current_label->setText(QApplication::translate("Telemetry", "Current source", 0, QApplication::UnicodeUTF8));
        blades_label->setText(QApplication::translate("Telemetry", "Blades", 0, QApplication::UnicodeUTF8));
        mahCount_label->setText(QApplication::translate("Telemetry", "mAh count", 0, QApplication::UnicodeUTF8));
        mahCount_SB->setSuffix(QApplication::translate("Telemetry", " mAh", 0, QApplication::UnicodeUTF8));
        fasOffset_DSB->setSuffix(QApplication::translate("Telemetry", " A", 0, QApplication::UnicodeUTF8));
        fasOffset_label->setText(QApplication::translate("Telemetry", "FAS Offset", 0, QApplication::UnicodeUTF8));
        mahCount_ChkB->setText(QApplication::translate("Telemetry", "Persistent mAh", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Telemetry", "Various", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Telemetry", "Serial Protocol", 0, QApplication::UnicodeUTF8));
        frskyProtoCB->clear();
        frskyProtoCB->insertItems(0, QStringList()
         << QApplication::translate("Telemetry", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "FrSky Sensor Hub", 0, QApplication::UnicodeUTF8)
        );
        rssiAlarm1Label->setText(QApplication::translate("Telemetry", "Alarm 1", 0, QApplication::UnicodeUTF8));
        rssiAlarm1CB->clear();
        rssiAlarm1CB->insertItems(0, QStringList()
         << QApplication::translate("Telemetry", "----", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "Orange", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "Red", 0, QApplication::UnicodeUTF8)
        );
        rssiAlarm1SB->setSuffix(QString());
        rssiAlarm2Label->setText(QApplication::translate("Telemetry", "Alarm 2", 0, QApplication::UnicodeUTF8));
        rssiAlarm2CB->clear();
        rssiAlarm2CB->insertItems(0, QStringList()
         << QApplication::translate("Telemetry", "----", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "Orange", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Telemetry", "Red", 0, QApplication::UnicodeUTF8)
        );
        rssiAlarm2SB->setSuffix(QString());
        rssiLabel->setText(QApplication::translate("Telemetry", "RSSI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Telemetry: public Ui_Telemetry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEMETRY_H
