/********************************************************************************
** Form generated from reading UI file 'simulatordialog-9x.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORDIALOG_2D_9X_H
#define UI_SIMULATORDIALOG_2D_9X_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <myslider.h>
#include "cursorwidget.h"
#include "lcdwidget.h"
#include "menuwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SimulatorDialog9X
{
public:
    QGridLayout *gridLayout_6;
    QFrame *controlFrame;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout;
    QGraphicsView *leftStick;
    QVBoxLayout *verticalLayout;
    QPushButton *switchTHR;
    QPushButton *switchRUD;
    QPushButton *switchELE;
    QPushButton *switchAIL;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *holdLeftX;
    QPushButton *FixLeftX;
    QPushButton *FixLeftY;
    QPushButton *holdLeftY;
    QHBoxLayout *horizontalLayout_6;
    QLabel *leftXPerc;
    QLabel *leftYPerc;
    QHBoxLayout *horizontalLayout;
    QPushButton *trimHL_L;
    mySlider *trimHLeft;
    QPushButton *trimHL_R;
    QVBoxLayout *verticalLayout_3;
    QPushButton *trimVL_U;
    mySlider *trimVLeft;
    QPushButton *trimVL_D;
    QGridLayout *gridLayout_2;
    QGraphicsView *rightStick;
    QVBoxLayout *verticalLayout_2;
    QPushButton *switchTRN;
    QPushButton *switchGEA;
    QPushButton *switchID0;
    QPushButton *switchID1;
    QPushButton *switchID2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *holdRightX;
    QPushButton *FixRightX;
    QPushButton *FixRightY;
    QPushButton *holdRightY;
    QHBoxLayout *horizontalLayout_7;
    QLabel *rightXPerc;
    QLabel *rightYPerc;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *trimHR_L;
    mySlider *trimHRight;
    QPushButton *trimHR_R;
    QVBoxLayout *verticalLayout_4;
    QPushButton *trimVR_U;
    mySlider *trimVRight;
    QPushButton *trimVR_D;
    QVBoxLayout *verticalLayout_9;
    QFrame *beep_frame;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_beep;
    QSpacerItem *verticalSpacer_4;
    QDial *dialP_1;
    QLabel *dialP_1value;
    QSpacerItem *verticalSpacer;
    QDial *dialP_2;
    QLabel *dialP_2value;
    QSpacerItem *verticalSpacer_2;
    QDial *dialP_3;
    QLabel *dialP_3value;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QTabWidget *tabWidget;
    QWidget *simu;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QWidget *top;
    QWidget *left;
    menuWidget *menu;
    lcdWidget *lcd;
    QWidget *bottom;
    cursorWidget *cursor;
    QWidget *right;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QWidget *outputs;
    QGridLayout *gridLayout_9;
    QGridLayout *logicalSwitchesLayout;
    QGridLayout *channelsLayout;
    QWidget *outputs2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *logicalSwitchesLayout2;
    QGridLayout *channelsLayout2;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gvarsLayout;

    void setupUi(QDialog *SimulatorDialog9X)
    {
        if (SimulatorDialog9X->objectName().isEmpty())
            SimulatorDialog9X->setObjectName(QString::fromUtf8("SimulatorDialog9X"));
        SimulatorDialog9X->resize(739, 613);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SimulatorDialog9X->sizePolicy().hasHeightForWidth());
        SimulatorDialog9X->setSizePolicy(sizePolicy);
        SimulatorDialog9X->setMaximumSize(QSize(739, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimulatorDialog9X->setWindowIcon(icon);
        gridLayout_6 = new QGridLayout(SimulatorDialog9X);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        controlFrame = new QFrame(SimulatorDialog9X);
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
        leftStick = new QGraphicsView(controlFrame);
        leftStick->setObjectName(QString::fromUtf8("leftStick"));
        leftStick->setMinimumSize(QSize(220, 220));
        leftStick->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leftStick->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(leftStick, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        switchTHR = new QPushButton(controlFrame);
        switchTHR->setObjectName(QString::fromUtf8("switchTHR"));
        QFont font;
        font.setPointSize(8);
        switchTHR->setFont(font);
        switchTHR->setAutoFillBackground(false);
        switchTHR->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchTHR->setText(QString::fromUtf8("THR"));
        switchTHR->setCheckable(true);

        verticalLayout->addWidget(switchTHR);

        switchRUD = new QPushButton(controlFrame);
        switchRUD->setObjectName(QString::fromUtf8("switchRUD"));
        switchRUD->setFont(font);
        switchRUD->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchRUD->setText(QString::fromUtf8("RUD"));
        switchRUD->setCheckable(true);

        verticalLayout->addWidget(switchRUD);

        switchELE = new QPushButton(controlFrame);
        switchELE->setObjectName(QString::fromUtf8("switchELE"));
        switchELE->setFont(font);
        switchELE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchELE->setText(QString::fromUtf8("ELE"));
        switchELE->setCheckable(true);

        verticalLayout->addWidget(switchELE);

        switchAIL = new QPushButton(controlFrame);
        switchAIL->setObjectName(QString::fromUtf8("switchAIL"));
        switchAIL->setFont(font);
        switchAIL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchAIL->setText(QString::fromUtf8("AIL"));
        switchAIL->setCheckable(true);

        verticalLayout->addWidget(switchAIL);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
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

        horizontalLayout_3->addWidget(holdLeftX);

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

        horizontalLayout_3->addWidget(FixLeftX);

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

        horizontalLayout_3->addWidget(FixLeftY);

        holdLeftY = new QPushButton(controlFrame);
        holdLeftY->setObjectName(QString::fromUtf8("holdLeftY"));
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

        horizontalLayout_3->addWidget(holdLeftY);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

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


        gridLayout->addLayout(horizontalLayout_6, 8, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        trimHL_L = new QPushButton(controlFrame);
        trimHL_L->setObjectName(QString::fromUtf8("trimHL_L"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(trimHL_L->sizePolicy().hasHeightForWidth());
        trimHL_L->setSizePolicy(sizePolicy1);
        trimHL_L->setMaximumSize(QSize(23, 23));
        trimHL_L->setText(QString::fromUtf8("<-"));
        trimHL_L->setAutoDefault(false);

        horizontalLayout->addWidget(trimHL_L);

        trimHLeft = new mySlider(controlFrame);
        trimHLeft->setObjectName(QString::fromUtf8("trimHLeft"));
        trimHLeft->setMinimum(-125);
        trimHLeft->setMaximum(125);
        trimHLeft->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(trimHLeft);

        trimHL_R = new QPushButton(controlFrame);
        trimHL_R->setObjectName(QString::fromUtf8("trimHL_R"));
        sizePolicy1.setHeightForWidth(trimHL_R->sizePolicy().hasHeightForWidth());
        trimHL_R->setSizePolicy(sizePolicy1);
        trimHL_R->setMaximumSize(QSize(23, 23));
        trimHL_R->setText(QString::fromUtf8("->"));
        trimHL_R->setAutoDefault(false);

        horizontalLayout->addWidget(trimHL_R);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        trimVL_U = new QPushButton(controlFrame);
        trimVL_U->setObjectName(QString::fromUtf8("trimVL_U"));
        sizePolicy1.setHeightForWidth(trimVL_U->sizePolicy().hasHeightForWidth());
        trimVL_U->setSizePolicy(sizePolicy1);
        trimVL_U->setMaximumSize(QSize(23, 23));
        trimVL_U->setText(QString::fromUtf8("^"));
        trimVL_U->setAutoDefault(false);

        verticalLayout_3->addWidget(trimVL_U);

        trimVLeft = new mySlider(controlFrame);
        trimVLeft->setObjectName(QString::fromUtf8("trimVLeft"));
        trimVLeft->setMinimum(-125);
        trimVLeft->setMaximum(125);
        trimVLeft->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(trimVLeft);

        trimVL_D = new QPushButton(controlFrame);
        trimVL_D->setObjectName(QString::fromUtf8("trimVL_D"));
        sizePolicy1.setHeightForWidth(trimVL_D->sizePolicy().hasHeightForWidth());
        trimVL_D->setSizePolicy(sizePolicy1);
        trimVL_D->setMaximumSize(QSize(23, 23));
        trimVL_D->setText(QString::fromUtf8("v"));
        trimVL_D->setAutoDefault(false);

        verticalLayout_3->addWidget(trimVL_D);


        gridLayout->addLayout(verticalLayout_3, 1, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rightStick = new QGraphicsView(controlFrame);
        rightStick->setObjectName(QString::fromUtf8("rightStick"));
        rightStick->setMinimumSize(QSize(220, 220));
        rightStick->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        rightStick->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_2->addWidget(rightStick, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        switchTRN = new QPushButton(controlFrame);
        switchTRN->setObjectName(QString::fromUtf8("switchTRN"));
        switchTRN->setFont(font);
        switchTRN->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
" } \n"
"\n"
"QPushButton:pressed {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        switchTRN->setText(QString::fromUtf8("TRN"));

        verticalLayout_2->addWidget(switchTRN);

        switchGEA = new QPushButton(controlFrame);
        switchGEA->setObjectName(QString::fromUtf8("switchGEA"));
        switchGEA->setFont(font);
        switchGEA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchGEA->setText(QString::fromUtf8("GEA"));
        switchGEA->setCheckable(true);
        switchGEA->setChecked(false);

        verticalLayout_2->addWidget(switchGEA);

        switchID0 = new QPushButton(controlFrame);
        switchID0->setObjectName(QString::fromUtf8("switchID0"));
        switchID0->setFont(font);
        switchID0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchID0->setText(QString::fromUtf8("ID0"));
        switchID0->setCheckable(true);
        switchID0->setChecked(true);
        switchID0->setAutoExclusive(true);

        verticalLayout_2->addWidget(switchID0);

        switchID1 = new QPushButton(controlFrame);
        switchID1->setObjectName(QString::fromUtf8("switchID1"));
        switchID1->setFont(font);
        switchID1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #EEEEEE;\n"
"     border-style: outset;\n"
"     border-width: 1px;\n"
"     border-radius: 4px;\n"
"     border-color: black;\n"
"     padding: 2px;\n"
"\n"
" } \n"
"\n"
"QPushButton:checked {\n"
"     background-color: #4CC417;\n"
"     border-style: inset;\n"
" }"));
        switchID1->setText(QString::fromUtf8("ID1"));
        switchID1->setCheckable(true);
        switchID1->setAutoExclusive(true);

        verticalLayout_2->addWidget(switchID1);

        switchID2 = new QPushButton(controlFrame);
        switchID2->setObjectName(QString::fromUtf8("switchID2"));
        switchID2->setFont(font);
        switchID2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        switchID2->setText(QString::fromUtf8("ID2"));
        switchID2->setCheckable(true);
        switchID2->setAutoExclusive(true);

        verticalLayout_2->addWidget(switchID2);


        gridLayout_2->addLayout(verticalLayout_2, 1, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
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

        horizontalLayout_4->addWidget(holdRightX);

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

        horizontalLayout_4->addWidget(FixRightX);

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

        horizontalLayout_4->addWidget(FixRightY);

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

        horizontalLayout_4->addWidget(holdRightY);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 2, 1, 1);

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


        gridLayout_2->addLayout(horizontalLayout_7, 4, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        trimHR_L = new QPushButton(controlFrame);
        trimHR_L->setObjectName(QString::fromUtf8("trimHR_L"));
        sizePolicy1.setHeightForWidth(trimHR_L->sizePolicy().hasHeightForWidth());
        trimHR_L->setSizePolicy(sizePolicy1);
        trimHR_L->setMaximumSize(QSize(23, 23));
        trimHR_L->setText(QString::fromUtf8("<-"));
        trimHR_L->setAutoDefault(false);

        horizontalLayout_2->addWidget(trimHR_L);

        trimHRight = new mySlider(controlFrame);
        trimHRight->setObjectName(QString::fromUtf8("trimHRight"));
        trimHRight->setMinimum(-125);
        trimHRight->setMaximum(125);
        trimHRight->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(trimHRight);

        trimHR_R = new QPushButton(controlFrame);
        trimHR_R->setObjectName(QString::fromUtf8("trimHR_R"));
        sizePolicy1.setHeightForWidth(trimHR_R->sizePolicy().hasHeightForWidth());
        trimHR_R->setSizePolicy(sizePolicy1);
        trimHR_R->setMaximumSize(QSize(23, 23));
        trimHR_R->setText(QString::fromUtf8("->"));
        trimHR_R->setAutoDefault(false);

        horizontalLayout_2->addWidget(trimHR_R);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        trimVR_U = new QPushButton(controlFrame);
        trimVR_U->setObjectName(QString::fromUtf8("trimVR_U"));
        sizePolicy1.setHeightForWidth(trimVR_U->sizePolicy().hasHeightForWidth());
        trimVR_U->setSizePolicy(sizePolicy1);
        trimVR_U->setMaximumSize(QSize(23, 23));
        trimVR_U->setText(QString::fromUtf8("^"));
        trimVR_U->setAutoDefault(false);

        verticalLayout_4->addWidget(trimVR_U);

        trimVRight = new mySlider(controlFrame);
        trimVRight->setObjectName(QString::fromUtf8("trimVRight"));
        trimVRight->setMinimum(-125);
        trimVRight->setMaximum(125);
        trimVRight->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(trimVRight);

        trimVR_D = new QPushButton(controlFrame);
        trimVR_D->setObjectName(QString::fromUtf8("trimVR_D"));
        sizePolicy1.setHeightForWidth(trimVR_D->sizePolicy().hasHeightForWidth());
        trimVR_D->setSizePolicy(sizePolicy1);
        trimVR_D->setMaximumSize(QSize(23, 23));
        trimVR_D->setText(QString::fromUtf8("v"));
        trimVR_D->setAutoDefault(false);

        verticalLayout_4->addWidget(trimVR_D);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 2, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        beep_frame = new QFrame(controlFrame);
        beep_frame->setObjectName(QString::fromUtf8("beep_frame"));
        beep_frame->setAutoFillBackground(true);
        beep_frame->setFrameShape(QFrame::Panel);
        beep_frame->setFrameShadow(QFrame::Raised);
        beep_frame->setLineWidth(2);
        verticalLayout_10 = new QVBoxLayout(beep_frame);
        verticalLayout_10->setContentsMargins(2, 2, 2, 2);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_beep = new QLabel(beep_frame);
        label_beep->setObjectName(QString::fromUtf8("label_beep"));
        label_beep->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_beep);


        verticalLayout_9->addWidget(beep_frame);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);

        dialP_1 = new QDial(controlFrame);
        dialP_1->setObjectName(QString::fromUtf8("dialP_1"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dialP_1->sizePolicy().hasHeightForWidth());
        dialP_1->setSizePolicy(sizePolicy2);
        dialP_1->setMaximumSize(QSize(50, 50));
#ifndef QT_NO_TOOLTIP
        dialP_1->setToolTip(QString::fromUtf8("P1"));
#endif // QT_NO_TOOLTIP
        dialP_1->setMinimum(-1024);
        dialP_1->setMaximum(1024);
        dialP_1->setPageStep(128);
        dialP_1->setNotchTarget(64);
        dialP_1->setNotchesVisible(true);

        verticalLayout_9->addWidget(dialP_1);

        dialP_1value = new QLabel(controlFrame);
        dialP_1value->setObjectName(QString::fromUtf8("dialP_1value"));
        dialP_1value->setText(QString::fromUtf8("0 %"));
        dialP_1value->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(dialP_1value);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        dialP_2 = new QDial(controlFrame);
        dialP_2->setObjectName(QString::fromUtf8("dialP_2"));
        sizePolicy2.setHeightForWidth(dialP_2->sizePolicy().hasHeightForWidth());
        dialP_2->setSizePolicy(sizePolicy2);
        dialP_2->setMaximumSize(QSize(50, 50));
#ifndef QT_NO_TOOLTIP
        dialP_2->setToolTip(QString::fromUtf8("P2"));
#endif // QT_NO_TOOLTIP
        dialP_2->setMinimum(-1024);
        dialP_2->setMaximum(1024);
        dialP_2->setPageStep(128);
        dialP_2->setInvertedAppearance(false);
        dialP_2->setNotchTarget(64);
        dialP_2->setNotchesVisible(true);

        verticalLayout_9->addWidget(dialP_2);

        dialP_2value = new QLabel(controlFrame);
        dialP_2value->setObjectName(QString::fromUtf8("dialP_2value"));
        dialP_2value->setText(QString::fromUtf8("0 %"));
        dialP_2value->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(dialP_2value);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        dialP_3 = new QDial(controlFrame);
        dialP_3->setObjectName(QString::fromUtf8("dialP_3"));
        sizePolicy2.setHeightForWidth(dialP_3->sizePolicy().hasHeightForWidth());
        dialP_3->setSizePolicy(sizePolicy2);
        dialP_3->setMaximumSize(QSize(50, 50));
#ifndef QT_NO_TOOLTIP
        dialP_3->setToolTip(QString::fromUtf8("P3"));
#endif // QT_NO_TOOLTIP
        dialP_3->setMinimum(-1024);
        dialP_3->setMaximum(1024);
        dialP_3->setPageStep(128);
        dialP_3->setNotchTarget(64);
        dialP_3->setNotchesVisible(true);

        verticalLayout_9->addWidget(dialP_3);

        dialP_3value = new QLabel(controlFrame);
        dialP_3value->setObjectName(QString::fromUtf8("dialP_3value"));
        dialP_3value->setText(QString::fromUtf8("0 %"));
        dialP_3value->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(dialP_3value);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(4, 1);
        verticalLayout_9->setStretch(7, 1);
        verticalLayout_9->setStretch(10, 1);

        gridLayout_8->addLayout(verticalLayout_9, 0, 1, 1, 1);


        gridLayout_6->addWidget(controlFrame, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(570, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 0, 1, 2);

        tabWidget = new QTabWidget(SimulatorDialog9X);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        simu = new QWidget();
        simu->setObjectName(QString::fromUtf8("simu"));
        gridLayout_5 = new QGridLayout(simu);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        top = new QWidget(simu);
        top->setObjectName(QString::fromUtf8("top"));
        sizePolicy1.setHeightForWidth(top->sizePolicy().hasHeightForWidth());
        top->setSizePolicy(sizePolicy1);
        top->setMinimumSize(QSize(256, 29));
        top->setStyleSheet(QString::fromUtf8("background:url(:/images/9xdt.png)"));

        gridLayout_3->addWidget(top, 0, 2, 1, 1);

        left = new QWidget(simu);
        left->setObjectName(QString::fromUtf8("left"));
        sizePolicy1.setHeightForWidth(left->sizePolicy().hasHeightForWidth());
        left->setSizePolicy(sizePolicy1);
        left->setMinimumSize(QSize(41, 186));
        left->setStyleSheet(QString::fromUtf8("background:url(:/images/9xdl.png)"));

        gridLayout_3->addWidget(left, 0, 1, 3, 1);

        menu = new menuWidget(simu);
        menu->setObjectName(QString::fromUtf8("menu"));
        sizePolicy1.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy1);
        menu->setMinimumSize(QSize(89, 186));
        menu->setStyleSheet(QString::fromUtf8("background:url(:/images/9xmenu.png)"));

        gridLayout_3->addWidget(menu, 0, 4, 3, 1);

        lcd = new lcdWidget(simu);
        lcd->setObjectName(QString::fromUtf8("lcd"));
        sizePolicy1.setHeightForWidth(lcd->sizePolicy().hasHeightForWidth());
        lcd->setSizePolicy(sizePolicy1);
        lcd->setMinimumSize(QSize(256, 128));

        gridLayout_3->addWidget(lcd, 1, 2, 1, 1);

        bottom = new QWidget(simu);
        bottom->setObjectName(QString::fromUtf8("bottom"));
        sizePolicy1.setHeightForWidth(bottom->sizePolicy().hasHeightForWidth());
        bottom->setSizePolicy(sizePolicy1);
        bottom->setMinimumSize(QSize(256, 29));
        bottom->setStyleSheet(QString::fromUtf8("background:url(:/images/9xdb.png)"));

        gridLayout_3->addWidget(bottom, 2, 2, 1, 1);

        cursor = new cursorWidget(simu);
        cursor->setObjectName(QString::fromUtf8("cursor"));
        sizePolicy1.setHeightForWidth(cursor->sizePolicy().hasHeightForWidth());
        cursor->setSizePolicy(sizePolicy1);
        cursor->setMinimumSize(QSize(128, 186));
        cursor->setMouseTracking(true);
        cursor->setStyleSheet(QString::fromUtf8("background:url(:/images/9xcurs.png);"));

        gridLayout_3->addWidget(cursor, 0, 0, 3, 1);

        right = new QWidget(simu);
        right->setObjectName(QString::fromUtf8("right"));
        sizePolicy1.setHeightForWidth(right->sizePolicy().hasHeightForWidth());
        right->setSizePolicy(sizePolicy1);
        right->setMinimumSize(QSize(55, 186));
        right->setStyleSheet(QString::fromUtf8("background:url(:/images/9xdr.png)"));

        gridLayout_3->addWidget(right, 0, 3, 3, 1);


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
        gridLayout_9 = new QGridLayout(outputs);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        logicalSwitchesLayout = new QGridLayout();
        logicalSwitchesLayout->setObjectName(QString::fromUtf8("logicalSwitchesLayout"));

        gridLayout_9->addLayout(logicalSwitchesLayout, 0, 0, 1, 1);

        channelsLayout = new QGridLayout();
        channelsLayout->setObjectName(QString::fromUtf8("channelsLayout"));

        gridLayout_9->addLayout(channelsLayout, 1, 0, 1, 1);

        tabWidget->addTab(outputs, QString());
        outputs2 = new QWidget();
        outputs2->setObjectName(QString::fromUtf8("outputs2"));
        verticalLayout_5 = new QVBoxLayout(outputs2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        logicalSwitchesLayout2 = new QGridLayout();
        logicalSwitchesLayout2->setObjectName(QString::fromUtf8("logicalSwitchesLayout2"));

        verticalLayout_5->addLayout(logicalSwitchesLayout2);

        channelsLayout2 = new QGridLayout();
        channelsLayout2->setObjectName(QString::fromUtf8("channelsLayout2"));

        verticalLayout_5->addLayout(channelsLayout2);

        tabWidget->addTab(outputs2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 711, 211));
        gvarsLayout = new QGridLayout(gridLayoutWidget);
        gvarsLayout->setObjectName(QString::fromUtf8("gvarsLayout"));
        gvarsLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());

        gridLayout_6->addWidget(tabWidget, 3, 0, 1, 1);


        retranslateUi(SimulatorDialog9X);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SimulatorDialog9X);
    } // setupUi

    void retranslateUi(QDialog *SimulatorDialog9X)
    {
        SimulatorDialog9X->setWindowTitle(QApplication::translate("SimulatorDialog9X", "Companion Simulator", 0, QApplication::UnicodeUTF8));
        holdLeftX->setText(QApplication::translate("SimulatorDialog9X", "Hold X", 0, QApplication::UnicodeUTF8));
        FixLeftX->setText(QApplication::translate("SimulatorDialog9X", "Fix X", 0, QApplication::UnicodeUTF8));
        FixLeftY->setText(QApplication::translate("SimulatorDialog9X", "Fix Y", 0, QApplication::UnicodeUTF8));
        holdLeftY->setText(QApplication::translate("SimulatorDialog9X", "Hold Y", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        trimHLeft->setToolTip(QApplication::translate("SimulatorDialog9X", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        trimVLeft->setToolTip(QApplication::translate("SimulatorDialog9X", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        holdRightX->setText(QApplication::translate("SimulatorDialog9X", "Hold X", 0, QApplication::UnicodeUTF8));
        FixRightX->setText(QApplication::translate("SimulatorDialog9X", "Fix X", 0, QApplication::UnicodeUTF8));
        FixRightY->setText(QApplication::translate("SimulatorDialog9X", "Fix Y", 0, QApplication::UnicodeUTF8));
        holdRightY->setText(QApplication::translate("SimulatorDialog9X", "Hold Y", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        trimHRight->setToolTip(QApplication::translate("SimulatorDialog9X", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        trimVRight->setToolTip(QApplication::translate("SimulatorDialog9X", "Right Double Click to Reset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_beep->setText(QApplication::translate("SimulatorDialog9X", "BEEP", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(simu), QApplication::translate("SimulatorDialog9X", "9x Simulator", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(outputs), QApplication::translate("SimulatorDialog9X", "Outputs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(outputs2), QApplication::translate("SimulatorDialog9X", "Outputs2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SimulatorDialog9X", "Gvars", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimulatorDialog9X: public Ui_SimulatorDialog9X {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORDIALOG_2D_9X_H
