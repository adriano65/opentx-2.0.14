/********************************************************************************
** Form generated from reading UI file 'joystickdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOYSTICKDIALOG_H
#define UI_JOYSTICKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_joystickDialog
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSlider *Ch_3;
    QComboBox *jsmapCB_2;
    QLabel *label;
    QComboBox *jsmapCB_3;
    QSlider *Ch_2;
    QComboBox *jsmapCB_1;
    QLabel *label_4;
    QSlider *Ch_5;
    QLabel *label_6;
    QLabel *label_3;
    QComboBox *jsmapCB_5;
    QSlider *Ch_4;
    QComboBox *jsmapCB_4;
    QSlider *Ch_6;
    QComboBox *jsmapCB_6;
    QLabel *label_5;
    QLabel *label_7;
    QSlider *Ch_7;
    QComboBox *jsmapCB_7;
    QLabel *label_8;
    QSlider *Ch_8;
    QComboBox *jsmapCB_8;
    QSlider *Ch_1;
    QCheckBox *ChInv_1;
    QCheckBox *ChInv_2;
    QCheckBox *ChInv_3;
    QCheckBox *ChInv_4;
    QCheckBox *ChInv_5;
    QCheckBox *ChInv_6;
    QCheckBox *ChInv_7;
    QCheckBox *ChInv_8;
    QLabel *howtoLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *joystickDialog)
    {
        if (joystickDialog->objectName().isEmpty())
            joystickDialog->setObjectName(QString::fromUtf8("joystickDialog"));
        joystickDialog->resize(505, 398);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(joystickDialog->sizePolicy().hasHeightForWidth());
        joystickDialog->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(joystickDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(joystickDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Ch_3 = new QSlider(joystickDialog);
        Ch_3->setObjectName(QString::fromUtf8("Ch_3"));
        Ch_3->setMinimum(-32767);
        Ch_3->setMaximum(32676);
        Ch_3->setOrientation(Qt::Horizontal);
        Ch_3->setInvertedAppearance(false);
        Ch_3->setInvertedControls(false);
        Ch_3->setTickPosition(QSlider::NoTicks);
        Ch_3->setTickInterval(0);

        gridLayout->addWidget(Ch_3, 2, 1, 1, 1);

        jsmapCB_2 = new QComboBox(joystickDialog);
        jsmapCB_2->setObjectName(QString::fromUtf8("jsmapCB_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(jsmapCB_2->sizePolicy().hasHeightForWidth());
        jsmapCB_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_2, 1, 3, 1, 1);

        label = new QLabel(joystickDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        jsmapCB_3 = new QComboBox(joystickDialog);
        jsmapCB_3->setObjectName(QString::fromUtf8("jsmapCB_3"));
        sizePolicy1.setHeightForWidth(jsmapCB_3->sizePolicy().hasHeightForWidth());
        jsmapCB_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_3, 2, 3, 1, 1);

        Ch_2 = new QSlider(joystickDialog);
        Ch_2->setObjectName(QString::fromUtf8("Ch_2"));
        Ch_2->setMinimum(-32767);
        Ch_2->setMaximum(32676);
        Ch_2->setOrientation(Qt::Horizontal);
        Ch_2->setInvertedAppearance(false);
        Ch_2->setInvertedControls(false);
        Ch_2->setTickPosition(QSlider::NoTicks);
        Ch_2->setTickInterval(0);

        gridLayout->addWidget(Ch_2, 1, 1, 1, 1);

        jsmapCB_1 = new QComboBox(joystickDialog);
        jsmapCB_1->setObjectName(QString::fromUtf8("jsmapCB_1"));
        sizePolicy1.setHeightForWidth(jsmapCB_1->sizePolicy().hasHeightForWidth());
        jsmapCB_1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_1, 0, 3, 1, 1);

        label_4 = new QLabel(joystickDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        Ch_5 = new QSlider(joystickDialog);
        Ch_5->setObjectName(QString::fromUtf8("Ch_5"));
        Ch_5->setMinimum(-32767);
        Ch_5->setMaximum(32676);
        Ch_5->setOrientation(Qt::Horizontal);
        Ch_5->setInvertedAppearance(false);
        Ch_5->setInvertedControls(false);
        Ch_5->setTickPosition(QSlider::NoTicks);
        Ch_5->setTickInterval(0);

        gridLayout->addWidget(Ch_5, 4, 1, 1, 1);

        label_6 = new QLabel(joystickDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_3 = new QLabel(joystickDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        jsmapCB_5 = new QComboBox(joystickDialog);
        jsmapCB_5->setObjectName(QString::fromUtf8("jsmapCB_5"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(jsmapCB_5->sizePolicy().hasHeightForWidth());
        jsmapCB_5->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(jsmapCB_5, 4, 3, 1, 1);

        Ch_4 = new QSlider(joystickDialog);
        Ch_4->setObjectName(QString::fromUtf8("Ch_4"));
        Ch_4->setMinimum(-32767);
        Ch_4->setMaximum(32676);
        Ch_4->setOrientation(Qt::Horizontal);
        Ch_4->setInvertedAppearance(false);
        Ch_4->setInvertedControls(false);
        Ch_4->setTickPosition(QSlider::NoTicks);
        Ch_4->setTickInterval(0);

        gridLayout->addWidget(Ch_4, 3, 1, 1, 1);

        jsmapCB_4 = new QComboBox(joystickDialog);
        jsmapCB_4->setObjectName(QString::fromUtf8("jsmapCB_4"));
        sizePolicy1.setHeightForWidth(jsmapCB_4->sizePolicy().hasHeightForWidth());
        jsmapCB_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_4, 3, 3, 1, 1);

        Ch_6 = new QSlider(joystickDialog);
        Ch_6->setObjectName(QString::fromUtf8("Ch_6"));
        Ch_6->setMinimum(-32767);
        Ch_6->setMaximum(32676);
        Ch_6->setOrientation(Qt::Horizontal);
        Ch_6->setInvertedAppearance(false);
        Ch_6->setInvertedControls(false);
        Ch_6->setTickPosition(QSlider::NoTicks);
        Ch_6->setTickInterval(0);

        gridLayout->addWidget(Ch_6, 5, 1, 1, 1);

        jsmapCB_6 = new QComboBox(joystickDialog);
        jsmapCB_6->setObjectName(QString::fromUtf8("jsmapCB_6"));
        sizePolicy1.setHeightForWidth(jsmapCB_6->sizePolicy().hasHeightForWidth());
        jsmapCB_6->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_6, 5, 3, 1, 1);

        label_5 = new QLabel(joystickDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_7 = new QLabel(joystickDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        Ch_7 = new QSlider(joystickDialog);
        Ch_7->setObjectName(QString::fromUtf8("Ch_7"));
        Ch_7->setMinimum(-32767);
        Ch_7->setMaximum(32676);
        Ch_7->setOrientation(Qt::Horizontal);
        Ch_7->setInvertedAppearance(false);
        Ch_7->setInvertedControls(false);
        Ch_7->setTickPosition(QSlider::NoTicks);
        Ch_7->setTickInterval(0);

        gridLayout->addWidget(Ch_7, 6, 1, 1, 1);

        jsmapCB_7 = new QComboBox(joystickDialog);
        jsmapCB_7->setObjectName(QString::fromUtf8("jsmapCB_7"));
        sizePolicy1.setHeightForWidth(jsmapCB_7->sizePolicy().hasHeightForWidth());
        jsmapCB_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_7, 6, 3, 1, 1);

        label_8 = new QLabel(joystickDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        Ch_8 = new QSlider(joystickDialog);
        Ch_8->setObjectName(QString::fromUtf8("Ch_8"));
        Ch_8->setMinimum(-32767);
        Ch_8->setMaximum(32676);
        Ch_8->setOrientation(Qt::Horizontal);
        Ch_8->setInvertedAppearance(false);
        Ch_8->setInvertedControls(false);
        Ch_8->setTickPosition(QSlider::NoTicks);
        Ch_8->setTickInterval(0);

        gridLayout->addWidget(Ch_8, 7, 1, 1, 1);

        jsmapCB_8 = new QComboBox(joystickDialog);
        jsmapCB_8->setObjectName(QString::fromUtf8("jsmapCB_8"));
        sizePolicy1.setHeightForWidth(jsmapCB_8->sizePolicy().hasHeightForWidth());
        jsmapCB_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(jsmapCB_8, 7, 3, 1, 1);

        Ch_1 = new QSlider(joystickDialog);
        Ch_1->setObjectName(QString::fromUtf8("Ch_1"));
        Ch_1->setMinimum(-32767);
        Ch_1->setMaximum(32676);
        Ch_1->setOrientation(Qt::Horizontal);
        Ch_1->setInvertedAppearance(false);
        Ch_1->setInvertedControls(false);
        Ch_1->setTickPosition(QSlider::NoTicks);
        Ch_1->setTickInterval(0);

        gridLayout->addWidget(Ch_1, 0, 1, 1, 1);

        ChInv_1 = new QCheckBox(joystickDialog);
        ChInv_1->setObjectName(QString::fromUtf8("ChInv_1"));
        ChInv_1->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_1, 0, 2, 1, 1);

        ChInv_2 = new QCheckBox(joystickDialog);
        ChInv_2->setObjectName(QString::fromUtf8("ChInv_2"));
        ChInv_2->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_2, 1, 2, 1, 1);

        ChInv_3 = new QCheckBox(joystickDialog);
        ChInv_3->setObjectName(QString::fromUtf8("ChInv_3"));
        ChInv_3->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_3, 2, 2, 1, 1);

        ChInv_4 = new QCheckBox(joystickDialog);
        ChInv_4->setObjectName(QString::fromUtf8("ChInv_4"));
        ChInv_4->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_4, 3, 2, 1, 1);

        ChInv_5 = new QCheckBox(joystickDialog);
        ChInv_5->setObjectName(QString::fromUtf8("ChInv_5"));
        ChInv_5->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_5, 4, 2, 1, 1);

        ChInv_6 = new QCheckBox(joystickDialog);
        ChInv_6->setObjectName(QString::fromUtf8("ChInv_6"));
        ChInv_6->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_6, 5, 2, 1, 1);

        ChInv_7 = new QCheckBox(joystickDialog);
        ChInv_7->setObjectName(QString::fromUtf8("ChInv_7"));
        ChInv_7->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_7, 6, 2, 1, 1);

        ChInv_8 = new QCheckBox(joystickDialog);
        ChInv_8->setObjectName(QString::fromUtf8("ChInv_8"));
        ChInv_8->setText(QString::fromUtf8(""));

        gridLayout->addWidget(ChInv_8, 7, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        howtoLabel = new QLabel(joystickDialog);
        howtoLabel->setObjectName(QString::fromUtf8("howtoLabel"));
        sizePolicy2.setHeightForWidth(howtoLabel->sizePolicy().hasHeightForWidth());
        howtoLabel->setSizePolicy(sizePolicy2);
        howtoLabel->setMinimumSize(QSize(400, 40));
        howtoLabel->setAutoFillBackground(false);
        howtoLabel->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0);"));
        howtoLabel->setFrameShape(QFrame::Box);
        howtoLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(howtoLabel, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(joystickDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer_2 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton = new QPushButton(joystickDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        sizePolicy2.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(nextButton);

        okButton = new QPushButton(joystickDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        sizePolicy2.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(okButton);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 2);

        QWidget::setTabOrder(Ch_1, ChInv_1);
        QWidget::setTabOrder(ChInv_1, jsmapCB_1);
        QWidget::setTabOrder(jsmapCB_1, Ch_2);
        QWidget::setTabOrder(Ch_2, ChInv_2);
        QWidget::setTabOrder(ChInv_2, jsmapCB_2);
        QWidget::setTabOrder(jsmapCB_2, Ch_3);
        QWidget::setTabOrder(Ch_3, ChInv_3);
        QWidget::setTabOrder(ChInv_3, jsmapCB_3);
        QWidget::setTabOrder(jsmapCB_3, Ch_4);
        QWidget::setTabOrder(Ch_4, ChInv_4);
        QWidget::setTabOrder(ChInv_4, jsmapCB_4);
        QWidget::setTabOrder(jsmapCB_4, Ch_5);
        QWidget::setTabOrder(Ch_5, ChInv_5);
        QWidget::setTabOrder(ChInv_5, jsmapCB_5);
        QWidget::setTabOrder(jsmapCB_5, Ch_6);
        QWidget::setTabOrder(Ch_6, ChInv_6);
        QWidget::setTabOrder(ChInv_6, jsmapCB_6);
        QWidget::setTabOrder(jsmapCB_6, Ch_7);
        QWidget::setTabOrder(Ch_7, ChInv_7);
        QWidget::setTabOrder(ChInv_7, jsmapCB_7);
        QWidget::setTabOrder(jsmapCB_7, Ch_8);
        QWidget::setTabOrder(Ch_8, ChInv_8);
        QWidget::setTabOrder(ChInv_8, jsmapCB_8);
        QWidget::setTabOrder(jsmapCB_8, cancelButton);
        QWidget::setTabOrder(cancelButton, nextButton);
        QWidget::setTabOrder(nextButton, okButton);

        retranslateUi(joystickDialog);

        QMetaObject::connectSlotsByName(joystickDialog);
    } // setupUi

    void retranslateUi(QDialog *joystickDialog)
    {
        joystickDialog->setWindowTitle(QApplication::translate("joystickDialog", "Configure Joystick", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("joystickDialog", "Ch2", 0, QApplication::UnicodeUTF8));
        jsmapCB_2->clear();
        jsmapCB_2->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("joystickDialog", "Ch1", 0, QApplication::UnicodeUTF8));
        jsmapCB_3->clear();
        jsmapCB_3->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        jsmapCB_1->clear();
        jsmapCB_1->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("joystickDialog", "Ch4", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("joystickDialog", "Ch6", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("joystickDialog", "Ch3", 0, QApplication::UnicodeUTF8));
        jsmapCB_5->clear();
        jsmapCB_5->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        jsmapCB_4->clear();
        jsmapCB_4->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        jsmapCB_6->clear();
        jsmapCB_6->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("joystickDialog", "Ch5", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("joystickDialog", "Ch7", 0, QApplication::UnicodeUTF8));
        jsmapCB_7->clear();
        jsmapCB_7->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("joystickDialog", "Ch8", 0, QApplication::UnicodeUTF8));
        jsmapCB_8->clear();
        jsmapCB_8->insertItems(0, QStringList()
         << QApplication::translate("joystickDialog", "Not  Assigned", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Right Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "Left Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "P3/LS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("joystickDialog", "RS", 0, QApplication::UnicodeUTF8)
        );
        howtoLabel->setText(QApplication::translate("joystickDialog", "Instructions", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("joystickDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("joystickDialog", "Next", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("joystickDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class joystickDialog: public Ui_joystickDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOYSTICKDIALOG_H
