/********************************************************************************
** Form generated from reading UI file 'simulatordialog-taranis.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORDIALOG_2D_TARANIS_H
#define UI_SIMULATORDIALOG_2D_TARANIS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <myslider.h>
#include <xcursorwidget.h>
#include "lcdwidget.h"
#include "xmenuwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SimulatorDialogTaranis
{
public:
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QTabWidget *tabWidget;
    QWidget *simu;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    xcursorWidget *cursor;
    QWidget *top;
    xmenuWidget *menu;
    lcdWidget *lcd;
    QWidget *bottom;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QWidget *outputs;
    QGridLayout *gridLayout_7;
    QGridLayout *logicalSwitchesLayout;
    QGridLayout *channelsLayout;
    QWidget *outputs2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *logicalSwitchesLayout2;
    QGridLayout *channelsLayout2;
    QWidget *misc;
    QWidget *gridLayoutWidget;
    QGridLayout *gvarsLayout;
    QFrame *controlFrame;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *trimVL_U;
    mySlider *trimVLeft;
    QPushButton *trimVL_D;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QPushButton *holdLeftY;
    QPushButton *FixLeftY;
    QPushButton *FixLeftX;
    QPushButton *holdLeftX;
    QSpacerItem *horizontalSpacer_12;
    QDial *dialP_1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *leftXPerc;
    QLabel *leftYPerc;
    QSlider *switchB;
    QGraphicsView *leftStick;
    QSlider *switchA;
    QSlider *switchE;
    QLabel *label;
    QSlider *switchF;
    QDial *dialP_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *trimHL_L;
    mySlider *trimHLeft;
    QPushButton *trimHL_R;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_5;
    QPushButton *trimVR_U;
    mySlider *trimVRight;
    QPushButton *trimVR_D;
    QDial *dialP_2;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_8;
    QGraphicsView *rightStick;
    QVBoxLayout *verticalLayout_2;
    QPushButton *holdRightY;
    QPushButton *FixRightY;
    QPushButton *FixRightX;
    QPushButton *holdRightX;
    QSlider *switchD;
    QSlider *switchC;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_14;
    QSlider *switchG;
    QDial *dialP_4;
    QSlider *switchH;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_7;
    QLabel *rightXPerc;
    QLabel *rightYPerc;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *trimHR_L;
    mySlider *trimHRight;
    QPushButton *trimHR_R;

    void setupUi(QDialog *SimulatorDialogTaranis)
    {
        if (SimulatorDialogTaranis->objectName().isEmpty())
            SimulatorDialogTaranis->setObjectName(QString::fromUtf8("SimulatorDialogTaranis"));
        SimulatorDialogTaranis->resize(726, 688);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SimulatorDialogTaranis->sizePolicy().hasHeightForWidth());
        SimulatorDialogTaranis->setSizePolicy(sizePolicy);
        SimulatorDialogTaranis->setMaximumSize(QSize(739, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimulatorDialogTaranis->setWindowIcon(icon);
        gridLayout_6 = new QGridLayout(SimulatorDialogTaranis);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(570, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 0, 1, 2);

        tabWidget = new QTabWidget(SimulatorDialogTaranis);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        simu = new QWidget();
        simu->setObjectName(QString::fromUtf8("simu"));
        gridLayout_5 = new QGridLayout(simu);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        cursor = new xcursorWidget(simu);
        cursor->setObjectName(QString::fromUtf8("cursor"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cursor->sizePolicy().hasHeightForWidth());
        cursor->setSizePolicy(sizePolicy2);
        cursor->setMinimumSize(QSize(120, 208));
        cursor->setMouseTracking(true);
        cursor->setStyleSheet(QString::fromUtf8("background:url(:/images/x9l0.png);"));

        gridLayout_3->addWidget(cursor, 0, 0, 3, 1);

        top = new QWidget(simu);
        top->setObjectName(QString::fromUtf8("top"));
        sizePolicy2.setHeightForWidth(top->sizePolicy().hasHeightForWidth());
        top->setSizePolicy(sizePolicy2);
        top->setMinimumSize(QSize(424, 38));
        top->setStyleSheet(QString::fromUtf8("background:url(:/images/x9t0.png)"));

        gridLayout_3->addWidget(top, 0, 1, 1, 1);

        menu = new xmenuWidget(simu);
        menu->setObjectName(QString::fromUtf8("menu"));
        sizePolicy2.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy2);
        menu->setMinimumSize(QSize(120, 208));
        menu->setStyleSheet(QString::fromUtf8("background:url(:/images/x9r0.png)"));

        gridLayout_3->addWidget(menu, 0, 2, 3, 1);

        lcd = new lcdWidget(simu);
        lcd->setObjectName(QString::fromUtf8("lcd"));
        sizePolicy2.setHeightForWidth(lcd->sizePolicy().hasHeightForWidth());
        lcd->setSizePolicy(sizePolicy2);
        lcd->setMinimumSize(QSize(424, 128));

        gridLayout_3->addWidget(lcd, 1, 1, 1, 1);

        bottom = new QWidget(simu);
        bottom->setObjectName(QString::fromUtf8("bottom"));
        sizePolicy2.setHeightForWidth(bottom->sizePolicy().hasHeightForWidth());
        bottom->setSizePolicy(sizePolicy2);
        bottom->setMinimumSize(QSize(424, 42));
        bottom->setStyleSheet(QString::fromUtf8("background:url(:/images/x9b0.png)"));

        gridLayout_3->addWidget(bottom, 2, 1, 1, 1);

        gridLayout_3->setColumnMinimumWidth(0, 120);
        gridLayout_3->setColumnMinimumWidth(1, 424);
        gridLayout_3->setColumnMinimumWidth(2, 120);

        gridLayout_5->addLayout(gridLayout_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(438, 6, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        gridLayout_5->addLayout(horizontalLayout_8, 1, 1, 1, 1);

        tabWidget->addTab(simu, QString());
        outputs = new QWidget();
        outputs->setObjectName(QString::fromUtf8("outputs"));
        gridLayout_7 = new QGridLayout(outputs);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        logicalSwitchesLayout = new QGridLayout();
        logicalSwitchesLayout->setObjectName(QString::fromUtf8("logicalSwitchesLayout"));

        gridLayout_7->addLayout(logicalSwitchesLayout, 0, 0, 1, 1);

        channelsLayout = new QGridLayout();
        channelsLayout->setObjectName(QString::fromUtf8("channelsLayout"));

        gridLayout_7->addLayout(channelsLayout, 1, 0, 1, 1);

        tabWidget->addTab(outputs, QString());
        outputs2 = new QWidget();
        outputs2->setObjectName(QString::fromUtf8("outputs2"));
        verticalLayout_3 = new QVBoxLayout(outputs2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        logicalSwitchesLayout2 = new QGridLayout();
        logicalSwitchesLayout2->setObjectName(QString::fromUtf8("logicalSwitchesLayout2"));

        verticalLayout_3->addLayout(logicalSwitchesLayout2);

        channelsLayout2 = new QGridLayout();
        channelsLayout2->setObjectName(QString::fromUtf8("channelsLayout2"));

        verticalLayout_3->addLayout(channelsLayout2);

        tabWidget->addTab(outputs2, QString());
        misc = new QWidget();
        misc->setObjectName(QString::fromUtf8("misc"));
        gridLayoutWidget = new QWidget(misc);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 691, 231));
        gvarsLayout = new QGridLayout(gridLayoutWidget);
        gvarsLayout->setObjectName(QString::fromUtf8("gvarsLayout"));
        gvarsLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(misc, QString());

        gridLayout_6->addWidget(tabWidget, 3, 0, 1, 1);

        controlFrame = new QFrame(SimulatorDialogTaranis);
        controlFrame->setObjectName(QString::fromUtf8("controlFrame"));
        sizePolicy.setHeightForWidth(controlFrame->sizePolicy().hasHeightForWidth());
        controlFrame->setSizePolicy(sizePolicy);
        controlFrame->setMinimumSize(QSize(0, 0));
        controlFrame->setMaximumSize(QSize(16777215, 16777215));
        controlFrame->setFrameShape(QFrame::Panel);
        controlFrame->setFrameShadow(QFrame::Raised);
        controlFrame->setLineWidth(2);
        gridLayout_8 = new QGridLayout(controlFrame);
#ifndef Q_OS_MAC
        gridLayout_8->setSpacing(6);
#endif
        gridLayout_8->setContentsMargins(5, 5, 5, 5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        trimVL_U = new QPushButton(controlFrame);
        trimVL_U->setObjectName(QString::fromUtf8("trimVL_U"));
        sizePolicy2.setHeightForWidth(trimVL_U->sizePolicy().hasHeightForWidth());
        trimVL_U->setSizePolicy(sizePolicy2);
        trimVL_U->setMaximumSize(QSize(23, 23));
        trimVL_U->setText(QString::fromUtf8("^"));
        trimVL_U->setAutoDefault(false);

        verticalLayout_4->addWidget(trimVL_U);

        trimVLeft = new mySlider(controlFrame);
        trimVLeft->setObjectName(QString::fromUtf8("trimVLeft"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(trimVLeft->sizePolicy().hasHeightForWidth());
        trimVLeft->setSizePolicy(sizePolicy3);
        trimVLeft->setMinimum(-125);
        trimVLeft->setMaximum(125);
        trimVLeft->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(trimVLeft, 0, Qt::AlignHCenter);

        trimVL_D = new QPushButton(controlFrame);
        trimVL_D->setObjectName(QString::fromUtf8("trimVL_D"));
        sizePolicy2.setHeightForWidth(trimVL_D->sizePolicy().hasHeightForWidth());
        trimVL_D->setSizePolicy(sizePolicy2);
        trimVL_D->setMaximumSize(QSize(23, 23));
        trimVL_D->setText(QString::fromUtf8("v"));
        trimVL_D->setAutoDefault(false);

        verticalLayout_4->addWidget(trimVL_D);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 4, 11, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 2, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 4, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 9, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        holdLeftY = new QPushButton(controlFrame);
        holdLeftY->setObjectName(QString::fromUtf8("holdLeftY"));
        QFont font;
        font.setPointSize(8);
        holdLeftY->setFont(font);
        holdLeftY->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        holdLeftY->setCheckable(true);

        verticalLayout->addWidget(holdLeftY);

        FixLeftY = new QPushButton(controlFrame);
        FixLeftY->setObjectName(QString::fromUtf8("FixLeftY"));
        FixLeftY->setFont(font);
        FixLeftY->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        FixLeftY->setCheckable(true);

        verticalLayout->addWidget(FixLeftY);

        FixLeftX = new QPushButton(controlFrame);
        FixLeftX->setObjectName(QString::fromUtf8("FixLeftX"));
        FixLeftX->setFont(font);
        FixLeftX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        FixLeftX->setCheckable(true);

        verticalLayout->addWidget(FixLeftX);

        holdLeftX = new QPushButton(controlFrame);
        holdLeftX->setObjectName(QString::fromUtf8("holdLeftX"));
        holdLeftX->setFont(font);
        holdLeftX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        holdLeftX->setCheckable(true);

        verticalLayout->addWidget(holdLeftX);


        gridLayout->addLayout(verticalLayout, 4, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 2, 7, 1, 1);

        dialP_1 = new QDial(controlFrame);
        dialP_1->setObjectName(QString::fromUtf8("dialP_1"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dialP_1->sizePolicy().hasHeightForWidth());
        dialP_1->setSizePolicy(sizePolicy4);
        dialP_1->setMaximumSize(QSize(42, 42));
        dialP_1->setMinimum(-1024);
        dialP_1->setMaximum(1024);
        dialP_1->setPageStep(128);
        dialP_1->setNotchTarget(64);
        dialP_1->setNotchesVisible(true);

        gridLayout->addWidget(dialP_1, 2, 10, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(20, -1, 20, -1);
        leftXPerc = new QLabel(controlFrame);
        leftXPerc->setObjectName(QString::fromUtf8("leftXPerc"));
        leftXPerc->setText(QString::fromUtf8("TextLabel"));
        leftXPerc->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(leftXPerc);

        leftYPerc = new QLabel(controlFrame);
        leftYPerc->setObjectName(QString::fromUtf8("leftYPerc"));
        leftYPerc->setText(QString::fromUtf8("TextLabel"));
        leftYPerc->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(leftYPerc);


        gridLayout->addLayout(horizontalLayout_6, 11, 2, 1, 9);

        switchB = new QSlider(controlFrame);
        switchB->setObjectName(QString::fromUtf8("switchB"));
        sizePolicy2.setHeightForWidth(switchB->sizePolicy().hasHeightForWidth());
        switchB->setSizePolicy(sizePolicy2);
        switchB->setMaximumSize(QSize(16777215, 50));
        switchB->setMaximum(2);
        switchB->setPageStep(1);
        switchB->setValue(0);
        switchB->setOrientation(Qt::Vertical);
        switchB->setInvertedAppearance(true);
        switchB->setTickPosition(QSlider::TicksBothSides);
        switchB->setTickInterval(1);

        gridLayout->addWidget(switchB, 2, 8, 1, 1);

        leftStick = new QGraphicsView(controlFrame);
        leftStick->setObjectName(QString::fromUtf8("leftStick"));
        leftStick->setMinimumSize(QSize(245, 245));
        leftStick->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leftStick->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(leftStick, 4, 2, 1, 9);

        switchA = new QSlider(controlFrame);
        switchA->setObjectName(QString::fromUtf8("switchA"));
        sizePolicy2.setHeightForWidth(switchA->sizePolicy().hasHeightForWidth());
        switchA->setSizePolicy(sizePolicy2);
        switchA->setMaximumSize(QSize(16777215, 50));
        switchA->setMaximum(2);
        switchA->setPageStep(1);
        switchA->setValue(0);
        switchA->setOrientation(Qt::Vertical);
        switchA->setInvertedAppearance(true);
        switchA->setTickPosition(QSlider::TicksBothSides);
        switchA->setTickInterval(1);

        gridLayout->addWidget(switchA, 2, 6, 1, 1);

        switchE = new QSlider(controlFrame);
        switchE->setObjectName(QString::fromUtf8("switchE"));
        sizePolicy2.setHeightForWidth(switchE->sizePolicy().hasHeightForWidth());
        switchE->setSizePolicy(sizePolicy2);
        switchE->setMaximumSize(QSize(16777215, 50));
        switchE->setMaximum(2);
        switchE->setPageStep(1);
        switchE->setValue(0);
        switchE->setOrientation(Qt::Vertical);
        switchE->setInvertedAppearance(true);
        switchE->setTickPosition(QSlider::TicksBothSides);
        switchE->setTickInterval(1);

        gridLayout->addWidget(switchE, 2, 5, 1, 1);

        label = new QLabel(controlFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setText(QString::fromUtf8("SF"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        switchF = new QSlider(controlFrame);
        switchF->setObjectName(QString::fromUtf8("switchF"));
        sizePolicy2.setHeightForWidth(switchF->sizePolicy().hasHeightForWidth());
        switchF->setSizePolicy(sizePolicy2);
        switchF->setMaximumSize(QSize(16777215, 50));
        switchF->setMaximum(1);
        switchF->setPageStep(1);
        switchF->setValue(0);
        switchF->setSliderPosition(0);
        switchF->setOrientation(Qt::Vertical);
        switchF->setInvertedAppearance(true);
        switchF->setTickPosition(QSlider::TicksBothSides);
        switchF->setTickInterval(1);

        gridLayout->addWidget(switchF, 2, 0, 1, 1);

        dialP_3 = new QDial(controlFrame);
        dialP_3->setObjectName(QString::fromUtf8("dialP_3"));
        sizePolicy4.setHeightForWidth(dialP_3->sizePolicy().hasHeightForWidth());
        dialP_3->setSizePolicy(sizePolicy4);
        dialP_3->setMaximumSize(QSize(42, 42));
        dialP_3->setMinimum(-1024);
        dialP_3->setMaximum(1024);
        dialP_3->setPageStep(128);
        dialP_3->setNotchTarget(64);
        dialP_3->setNotchesVisible(true);

        gridLayout->addWidget(dialP_3, 2, 3, 1, 1);

        label_2 = new QLabel(controlFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setText(QString::fromUtf8("SA"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 3, 6, 1, 1);

        label_3 = new QLabel(controlFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setText(QString::fromUtf8("SB"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 8, 1, 1);

        label_5 = new QLabel(controlFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setText(QString::fromUtf8("SE"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 5, 1, 1);

        label_9 = new QLabel(controlFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setText(QString::fromUtf8("LS"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 3, 3, 1, 1);

        label_10 = new QLabel(controlFrame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setText(QString::fromUtf8("S1"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 3, 10, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        trimHL_L = new QPushButton(controlFrame);
        trimHL_L->setObjectName(QString::fromUtf8("trimHL_L"));
        sizePolicy2.setHeightForWidth(trimHL_L->sizePolicy().hasHeightForWidth());
        trimHL_L->setSizePolicy(sizePolicy2);
        trimHL_L->setMaximumSize(QSize(23, 23));
        trimHL_L->setText(QString::fromUtf8("<-"));
        trimHL_L->setAutoDefault(false);

        horizontalLayout_13->addWidget(trimHL_L);

        trimHLeft = new mySlider(controlFrame);
        trimHLeft->setObjectName(QString::fromUtf8("trimHLeft"));
        trimHLeft->setMinimum(-125);
        trimHLeft->setMaximum(125);
        trimHLeft->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(trimHLeft);

        trimHL_R = new QPushButton(controlFrame);
        trimHL_R->setObjectName(QString::fromUtf8("trimHL_R"));
        sizePolicy2.setHeightForWidth(trimHL_R->sizePolicy().hasHeightForWidth());
        trimHL_R->setSizePolicy(sizePolicy2);
        trimHL_R->setMaximumSize(QSize(23, 23));
        trimHL_R->setText(QString::fromUtf8("->"));
        trimHL_R->setAutoDefault(false);

        horizontalLayout_13->addWidget(trimHL_R);


        gridLayout->addLayout(horizontalLayout_13, 5, 2, 1, 9);


        gridLayout_8->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        trimVR_U = new QPushButton(controlFrame);
        trimVR_U->setObjectName(QString::fromUtf8("trimVR_U"));
        sizePolicy2.setHeightForWidth(trimVR_U->sizePolicy().hasHeightForWidth());
        trimVR_U->setSizePolicy(sizePolicy2);
        trimVR_U->setMaximumSize(QSize(23, 23));
        trimVR_U->setText(QString::fromUtf8("^"));
        trimVR_U->setAutoDefault(false);

        verticalLayout_5->addWidget(trimVR_U);

        trimVRight = new mySlider(controlFrame);
        trimVRight->setObjectName(QString::fromUtf8("trimVRight"));
        trimVRight->setMinimum(-125);
        trimVRight->setMaximum(125);
        trimVRight->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(trimVRight, 0, Qt::AlignHCenter);

        trimVR_D = new QPushButton(controlFrame);
        trimVR_D->setObjectName(QString::fromUtf8("trimVR_D"));
        sizePolicy2.setHeightForWidth(trimVR_D->sizePolicy().hasHeightForWidth());
        trimVR_D->setSizePolicy(sizePolicy2);
        trimVR_D->setMaximumSize(QSize(23, 23));
        trimVR_D->setText(QString::fromUtf8("v"));
        trimVR_D->setAutoDefault(false);

        verticalLayout_5->addWidget(trimVR_D);


        horizontalLayout_5->addLayout(verticalLayout_5);


        gridLayout_2->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        dialP_2 = new QDial(controlFrame);
        dialP_2->setObjectName(QString::fromUtf8("dialP_2"));
        sizePolicy4.setHeightForWidth(dialP_2->sizePolicy().hasHeightForWidth());
        dialP_2->setSizePolicy(sizePolicy4);
        dialP_2->setMaximumSize(QSize(42, 42));
        dialP_2->setMinimum(-1024);
        dialP_2->setMaximum(1024);
        dialP_2->setPageStep(128);
        dialP_2->setNotchTarget(64);
        dialP_2->setNotchesVisible(true);

        gridLayout_2->addWidget(dialP_2, 2, 1, 1, 1);

        label_11 = new QLabel(controlFrame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setText(QString::fromUtf8("S2"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 3, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_13, 2, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        rightStick = new QGraphicsView(controlFrame);
        rightStick->setObjectName(QString::fromUtf8("rightStick"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(rightStick->sizePolicy().hasHeightForWidth());
        rightStick->setSizePolicy(sizePolicy5);
        rightStick->setMinimumSize(QSize(245, 245));
        rightStick->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        rightStick->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_2->addWidget(rightStick, 4, 1, 1, 9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        holdRightY = new QPushButton(controlFrame);
        holdRightY->setObjectName(QString::fromUtf8("holdRightY"));
        holdRightY->setFont(font);
        holdRightY->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        holdRightY->setCheckable(true);

        verticalLayout_2->addWidget(holdRightY);

        FixRightY = new QPushButton(controlFrame);
        FixRightY->setObjectName(QString::fromUtf8("FixRightY"));
        FixRightY->setFont(font);
        FixRightY->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        FixRightY->setCheckable(true);

        verticalLayout_2->addWidget(FixRightY);

        FixRightX = new QPushButton(controlFrame);
        FixRightX->setObjectName(QString::fromUtf8("FixRightX"));
        FixRightX->setFont(font);
        FixRightX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        FixRightX->setCheckable(true);

        verticalLayout_2->addWidget(FixRightX);

        holdRightX = new QPushButton(controlFrame);
        holdRightX->setObjectName(QString::fromUtf8("holdRightX"));
        holdRightX->setFont(font);
        holdRightX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        holdRightX->setCheckable(true);

        verticalLayout_2->addWidget(holdRightX);


        gridLayout_2->addLayout(verticalLayout_2, 4, 11, 1, 1);

        switchD = new QSlider(controlFrame);
        switchD->setObjectName(QString::fromUtf8("switchD"));
        sizePolicy2.setHeightForWidth(switchD->sizePolicy().hasHeightForWidth());
        switchD->setSizePolicy(sizePolicy2);
        switchD->setMaximumSize(QSize(16777215, 50));
        switchD->setMaximum(2);
        switchD->setPageStep(1);
        switchD->setValue(0);
        switchD->setOrientation(Qt::Vertical);
        switchD->setInvertedAppearance(true);
        switchD->setTickPosition(QSlider::TicksBothSides);
        switchD->setTickInterval(1);

        gridLayout_2->addWidget(switchD, 2, 5, 1, 1);

        switchC = new QSlider(controlFrame);
        switchC->setObjectName(QString::fromUtf8("switchC"));
        sizePolicy2.setHeightForWidth(switchC->sizePolicy().hasHeightForWidth());
        switchC->setSizePolicy(sizePolicy2);
        switchC->setMaximumSize(QSize(16777215, 50));
        switchC->setMaximum(2);
        switchC->setPageStep(1);
        switchC->setValue(0);
        switchC->setOrientation(Qt::Vertical);
        switchC->setInvertedAppearance(true);
        switchC->setTickPosition(QSlider::TicksBothSides);
        switchC->setTickInterval(1);

        gridLayout_2->addWidget(switchC, 2, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 4, 10, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 2, 7, 1, 1);

        switchG = new QSlider(controlFrame);
        switchG->setObjectName(QString::fromUtf8("switchG"));
        sizePolicy2.setHeightForWidth(switchG->sizePolicy().hasHeightForWidth());
        switchG->setSizePolicy(sizePolicy2);
        switchG->setMaximumSize(QSize(16777215, 50));
        switchG->setMaximum(2);
        switchG->setPageStep(1);
        switchG->setValue(0);
        switchG->setOrientation(Qt::Vertical);
        switchG->setInvertedAppearance(true);
        switchG->setInvertedControls(false);
        switchG->setTickPosition(QSlider::TicksBothSides);
        switchG->setTickInterval(1);

        gridLayout_2->addWidget(switchG, 2, 6, 1, 1);

        dialP_4 = new QDial(controlFrame);
        dialP_4->setObjectName(QString::fromUtf8("dialP_4"));
        sizePolicy4.setHeightForWidth(dialP_4->sizePolicy().hasHeightForWidth());
        dialP_4->setSizePolicy(sizePolicy4);
        dialP_4->setMaximumSize(QSize(42, 42));
        dialP_4->setMinimum(-1024);
        dialP_4->setMaximum(1024);
        dialP_4->setPageStep(128);
        dialP_4->setNotchTarget(64);
        dialP_4->setNotchesVisible(true);

        gridLayout_2->addWidget(dialP_4, 2, 8, 1, 1);

        switchH = new QSlider(controlFrame);
        switchH->setObjectName(QString::fromUtf8("switchH"));
        sizePolicy2.setHeightForWidth(switchH->sizePolicy().hasHeightForWidth());
        switchH->setSizePolicy(sizePolicy2);
        switchH->setMaximumSize(QSize(16777215, 50));
        switchH->setStyleSheet(QString::fromUtf8(""));
        switchH->setMaximum(1);
        switchH->setPageStep(0);
        switchH->setValue(0);
        switchH->setOrientation(Qt::Vertical);
        switchH->setInvertedAppearance(true);
        switchH->setTickPosition(QSlider::TicksBothSides);
        switchH->setTickInterval(1);

        gridLayout_2->addWidget(switchH, 2, 11, 1, 1);

        label_4 = new QLabel(controlFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setText(QString::fromUtf8("SC"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 3, 3, 1, 1);

        label_6 = new QLabel(controlFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setText(QString::fromUtf8("SD"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 3, 5, 1, 1);

        label_7 = new QLabel(controlFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setText(QString::fromUtf8("SG"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 3, 6, 1, 1);

        label_8 = new QLabel(controlFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setText(QString::fromUtf8("SH"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 3, 11, 1, 1);

        label_12 = new QLabel(controlFrame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setText(QString::fromUtf8("RS"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 3, 8, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(20, -1, 20, -1);
        rightXPerc = new QLabel(controlFrame);
        rightXPerc->setObjectName(QString::fromUtf8("rightXPerc"));
        rightXPerc->setText(QString::fromUtf8("TextLabel"));
        rightXPerc->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(rightXPerc);

        rightYPerc = new QLabel(controlFrame);
        rightYPerc->setObjectName(QString::fromUtf8("rightYPerc"));
        rightYPerc->setText(QString::fromUtf8("TextLabel"));
        rightYPerc->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(rightYPerc);


        gridLayout_2->addLayout(horizontalLayout_7, 7, 1, 1, 9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        trimHR_L = new QPushButton(controlFrame);
        trimHR_L->setObjectName(QString::fromUtf8("trimHR_L"));
        sizePolicy2.setHeightForWidth(trimHR_L->sizePolicy().hasHeightForWidth());
        trimHR_L->setSizePolicy(sizePolicy2);
        trimHR_L->setMaximumSize(QSize(23, 23));
        trimHR_L->setText(QString::fromUtf8("<-"));
        trimHR_L->setAutoDefault(false);

        horizontalLayout_12->addWidget(trimHR_L);

        trimHRight = new mySlider(controlFrame);
        trimHRight->setObjectName(QString::fromUtf8("trimHRight"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(trimHRight->sizePolicy().hasHeightForWidth());
        trimHRight->setSizePolicy(sizePolicy6);
        trimHRight->setMinimum(-125);
        trimHRight->setMaximum(125);
        trimHRight->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(trimHRight);

        trimHR_R = new QPushButton(controlFrame);
        trimHR_R->setObjectName(QString::fromUtf8("trimHR_R"));
        sizePolicy2.setHeightForWidth(trimHR_R->sizePolicy().hasHeightForWidth());
        trimHR_R->setSizePolicy(sizePolicy2);
        trimHR_R->setMaximumSize(QSize(23, 23));
        trimHR_R->setText(QString::fromUtf8("->"));
        trimHR_R->setAutoDefault(false);

        horizontalLayout_12->addWidget(trimHR_R);


        gridLayout_2->addLayout(horizontalLayout_12, 5, 1, 1, 9);


        gridLayout_8->addLayout(gridLayout_2, 0, 1, 1, 1);


        gridLayout_6->addWidget(controlFrame, 0, 0, 1, 1);

        QWidget::setTabOrder(tabWidget, switchF);
        QWidget::setTabOrder(switchF, dialP_3);
        QWidget::setTabOrder(dialP_3, switchE);
        QWidget::setTabOrder(switchE, switchA);
        QWidget::setTabOrder(switchA, switchB);
        QWidget::setTabOrder(switchB, dialP_1);
        QWidget::setTabOrder(dialP_1, dialP_2);
        QWidget::setTabOrder(dialP_2, switchC);
        QWidget::setTabOrder(switchC, switchD);
        QWidget::setTabOrder(switchD, switchG);
        QWidget::setTabOrder(switchG, dialP_4);
        QWidget::setTabOrder(dialP_4, switchH);
        QWidget::setTabOrder(switchH, holdLeftY);
        QWidget::setTabOrder(holdLeftY, FixLeftY);
        QWidget::setTabOrder(FixLeftY, FixLeftX);
        QWidget::setTabOrder(FixLeftX, holdLeftX);
        QWidget::setTabOrder(holdLeftX, leftStick);
        QWidget::setTabOrder(leftStick, trimHL_L);
        QWidget::setTabOrder(trimHL_L, trimHLeft);
        QWidget::setTabOrder(trimHLeft, trimHL_R);
        QWidget::setTabOrder(trimHL_R, trimVL_D);
        QWidget::setTabOrder(trimVL_D, trimVLeft);
        QWidget::setTabOrder(trimVLeft, trimVL_U);
        QWidget::setTabOrder(trimVL_U, trimVR_U);
        QWidget::setTabOrder(trimVR_U, trimVRight);
        QWidget::setTabOrder(trimVRight, trimVR_D);
        QWidget::setTabOrder(trimVR_D, trimHR_L);
        QWidget::setTabOrder(trimHR_L, trimHRight);
        QWidget::setTabOrder(trimHRight, trimHR_R);
        QWidget::setTabOrder(trimHR_R, rightStick);
        QWidget::setTabOrder(rightStick, holdRightY);
        QWidget::setTabOrder(holdRightY, FixRightY);
        QWidget::setTabOrder(FixRightY, FixRightX);
        QWidget::setTabOrder(FixRightX, holdRightX);

        retranslateUi(SimulatorDialogTaranis);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SimulatorDialogTaranis);
    } // setupUi

    void retranslateUi(QDialog *SimulatorDialogTaranis)
    {
        SimulatorDialogTaranis->setWindowTitle(QApplication::translate("SimulatorDialogTaranis", "Companion Simulator", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(simu), QApplication::translate("SimulatorDialogTaranis", "Taranis Simulator", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(outputs), QApplication::translate("SimulatorDialogTaranis", "Outputs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(outputs2), QApplication::translate("SimulatorDialogTaranis", "Outputs2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(misc), QApplication::translate("SimulatorDialogTaranis", "Gvars", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        trimVLeft->setToolTip(QApplication::translate("SimulatorDialogTaranis", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        holdLeftY->setText(QApplication::translate("SimulatorDialogTaranis", "Hold Y", 0, QApplication::UnicodeUTF8));
        FixLeftY->setText(QApplication::translate("SimulatorDialogTaranis", "Fix Y", 0, QApplication::UnicodeUTF8));
        FixLeftX->setText(QApplication::translate("SimulatorDialogTaranis", "Fix X", 0, QApplication::UnicodeUTF8));
        holdLeftX->setText(QApplication::translate("SimulatorDialogTaranis", "Hold X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dialP_1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchB->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchA->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchE->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchF->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        switchF->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        dialP_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        trimHLeft->setToolTip(QApplication::translate("SimulatorDialogTaranis", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        trimVRight->setToolTip(QApplication::translate("SimulatorDialogTaranis", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        dialP_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        holdRightY->setText(QApplication::translate("SimulatorDialogTaranis", "Hold Y", 0, QApplication::UnicodeUTF8));
        FixRightY->setText(QApplication::translate("SimulatorDialogTaranis", "Fix Y", 0, QApplication::UnicodeUTF8));
        FixRightX->setText(QApplication::translate("SimulatorDialogTaranis", "Fix X", 0, QApplication::UnicodeUTF8));
        holdRightX->setText(QApplication::translate("SimulatorDialogTaranis", "Hold X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        switchD->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchC->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchG->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        dialP_4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        switchH->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        trimHRight->setToolTip(QApplication::translate("SimulatorDialogTaranis", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class SimulatorDialogTaranis: public Ui_SimulatorDialogTaranis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORDIALOG_2D_TARANIS_H
