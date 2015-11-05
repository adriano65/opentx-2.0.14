/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QCheckBox *throttleReverse;
    QCheckBox *extendedLimits;
    QComboBox *throttleSource;
    QCheckBox *extendedTrims;
    QCheckBox *throttleTrim;
    QCheckBox *throttleWarning;
    QSpacerItem *horizontalSpacer;
    QComboBox *trimIncrement;
    QCheckBox *displayText;
    QLabel *label_timer2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ttrace;
    QLabel *label_10;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *centerBeepLayout;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_3;
    QLabel *label_12;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *name;
    QSpacerItem *horizontalSpacer_2;
    QLabel *modelImage_label;
    QLabel *imagePreview;
    QComboBox *image;
    QSpacerItem *horizontalSpacer_26;
    QFrame *line;
    QLabel *swwarn_label;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QGridLayout *switchesStartupLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_potWarning;
    QGridLayout *potWarningLayout;
    QComboBox *potWarningMode;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QVBoxLayout *modulesLayout;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Setup)
    {
        if (Setup->objectName().isEmpty())
            Setup->setObjectName(QString::fromUtf8("Setup"));
        Setup->resize(840, 520);
        verticalLayout = new QVBoxLayout(Setup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        throttleReverse = new QCheckBox(Setup);
        throttleReverse->setObjectName(QString::fromUtf8("throttleReverse"));
        throttleReverse->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(throttleReverse, 0, 3, 1, 1);

        extendedLimits = new QCheckBox(Setup);
        extendedLimits->setObjectName(QString::fromUtf8("extendedLimits"));
        extendedLimits->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(extendedLimits, 1, 1, 1, 1);

        throttleSource = new QComboBox(Setup);
        throttleSource->setObjectName(QString::fromUtf8("throttleSource"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(throttleSource->sizePolicy().hasHeightForWidth());
        throttleSource->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(throttleSource, 0, 0, 1, 1);

        extendedTrims = new QCheckBox(Setup);
        extendedTrims->setObjectName(QString::fromUtf8("extendedTrims"));
        extendedTrims->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(extendedTrims, 1, 2, 1, 1);

        throttleTrim = new QCheckBox(Setup);
        throttleTrim->setObjectName(QString::fromUtf8("throttleTrim"));
        throttleTrim->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(throttleTrim, 0, 1, 1, 1);

        throttleWarning = new QCheckBox(Setup);
        throttleWarning->setObjectName(QString::fromUtf8("throttleWarning"));
        throttleWarning->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(throttleWarning, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        trimIncrement = new QComboBox(Setup);
        trimIncrement->setObjectName(QString::fromUtf8("trimIncrement"));
        sizePolicy.setHeightForWidth(trimIncrement->sizePolicy().hasHeightForWidth());
        trimIncrement->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(trimIncrement, 1, 0, 1, 1);

        displayText = new QCheckBox(Setup);
        displayText->setObjectName(QString::fromUtf8("displayText"));
        displayText->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(displayText, 1, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 1, 1, 1);

        label_timer2 = new QLabel(Setup);
        label_timer2->setObjectName(QString::fromUtf8("label_timer2"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label_timer2->setFont(font);
        label_timer2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_timer2, 2, 0, 1, 1, Qt::AlignRight|Qt::AlignVCenter);

        label_2 = new QLabel(Setup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignRight|Qt::AlignVCenter);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_ttrace = new QLabel(Setup);
        label_ttrace->setObjectName(QString::fromUtf8("label_ttrace"));
        label_ttrace->setFont(font);
        label_ttrace->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_ttrace, 0, Qt::AlignRight);

        label_10 = new QLabel(Setup);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_10, 0, Qt::AlignRight);


        gridLayout->addLayout(verticalLayout_2, 4, 0, 1, 1);

        line_2 = new QFrame(Setup);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        centerBeepLayout = new QGridLayout();
        centerBeepLayout->setObjectName(QString::fromUtf8("centerBeepLayout"));

        horizontalLayout_7->addLayout(centerBeepLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_7, 6, 1, 1, 1);

        line_3 = new QFrame(Setup);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 7, 0, 1, 2);

        label_12 = new QLabel(Setup);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 6, 0, 1, 1);

        line_4 = new QFrame(Setup);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 5, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name = new QLineEdit(Setup);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMaxLength(10);

        horizontalLayout->addWidget(name);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        modelImage_label = new QLabel(Setup);
        modelImage_label->setObjectName(QString::fromUtf8("modelImage_label"));

        horizontalLayout->addWidget(modelImage_label);

        imagePreview = new QLabel(Setup);
        imagePreview->setObjectName(QString::fromUtf8("imagePreview"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imagePreview->sizePolicy().hasHeightForWidth());
        imagePreview->setSizePolicy(sizePolicy1);
        imagePreview->setMinimumSize(QSize(64, 32));
        imagePreview->setMaximumSize(QSize(64, 32));
        imagePreview->setFrameShape(QFrame::Panel);
        imagePreview->setFrameShadow(QFrame::Raised);
        imagePreview->setScaledContents(true);

        horizontalLayout->addWidget(imagePreview);

        image = new QComboBox(Setup);
        image->setObjectName(QString::fromUtf8("image"));

        horizontalLayout->addWidget(image);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_26);


        verticalLayout_5->addLayout(horizontalLayout);

        line = new QFrame(Setup);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);

        swwarn_label = new QLabel(Setup);
        swwarn_label->setObjectName(QString::fromUtf8("swwarn_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(swwarn_label->sizePolicy().hasHeightForWidth());
        swwarn_label->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        swwarn_label->setFont(font1);
        swwarn_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(swwarn_label, 8, 0, 1, 1, Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_3 = new QLabel(Setup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_6->addWidget(label_3);

        switchesStartupLayout = new QGridLayout();
        switchesStartupLayout->setObjectName(QString::fromUtf8("switchesStartupLayout"));
        switchesStartupLayout->setSizeConstraint(QLayout::SetMinimumSize);
        switchesStartupLayout->setVerticalSpacing(6);
        switchesStartupLayout->setContentsMargins(-1, 0, -1, 6);

        verticalLayout_6->addLayout(switchesStartupLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_potWarning = new QLabel(Setup);
        label_potWarning->setObjectName(QString::fromUtf8("label_potWarning"));

        verticalLayout_7->addWidget(label_potWarning, 0, Qt::AlignTop);

        potWarningLayout = new QGridLayout();
        potWarningLayout->setObjectName(QString::fromUtf8("potWarningLayout"));
        potWarningMode = new QComboBox(Setup);
        potWarningMode->setObjectName(QString::fromUtf8("potWarningMode"));

        potWarningLayout->addWidget(potWarningMode, 0, 0, 1, 1, Qt::AlignTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        potWarningLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        verticalLayout_7->addLayout(potWarningLayout);


        horizontalLayout_8->addLayout(verticalLayout_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_8, 8, 1, 1, 1);

        label = new QLabel(Setup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft|Qt::AlignTop);


        verticalLayout->addLayout(gridLayout);

        modulesLayout = new QVBoxLayout();
        modulesLayout->setObjectName(QString::fromUtf8("modulesLayout"));

        verticalLayout->addLayout(modulesLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        QWidget::setTabOrder(name, image);
        QWidget::setTabOrder(image, throttleSource);
        QWidget::setTabOrder(throttleSource, throttleTrim);
        QWidget::setTabOrder(throttleTrim, throttleWarning);
        QWidget::setTabOrder(throttleWarning, throttleReverse);
        QWidget::setTabOrder(throttleReverse, trimIncrement);
        QWidget::setTabOrder(trimIncrement, extendedLimits);
        QWidget::setTabOrder(extendedLimits, extendedTrims);
        QWidget::setTabOrder(extendedTrims, displayText);
        QWidget::setTabOrder(displayText, potWarningMode);

        retranslateUi(Setup);

        QMetaObject::connectSlotsByName(Setup);
    } // setupUi

    void retranslateUi(QWidget *Setup)
    {
        Setup->setWindowTitle(QString());
#ifndef QT_NO_WHATSTHIS
        throttleReverse->setWhatsThis(QApplication::translate("Setup", "Reverse throttle operation.\n"
"If this is checked the throttle will be reversed.  Idle will be forward, trim will also be reversed and the throttle warning will be reversed as well.\n"
"\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        throttleReverse->setText(QApplication::translate("Setup", "Reverse Throttle", 0, QApplication::UnicodeUTF8));
        extendedLimits->setText(QApplication::translate("Setup", "Extended Limits", 0, QApplication::UnicodeUTF8));
        extendedTrims->setText(QApplication::translate("Setup", "Extended Trims", 0, QApplication::UnicodeUTF8));
        throttleTrim->setText(QApplication::translate("Setup", "Throttle Trim Idle Only", 0, QApplication::UnicodeUTF8));
        throttleWarning->setText(QApplication::translate("Setup", "Throttle Warning", 0, QApplication::UnicodeUTF8));
        trimIncrement->clear();
        trimIncrement->insertItems(0, QStringList()
         << QApplication::translate("Setup", "Exponential", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Setup", "Extra Fine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Setup", "Fine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Setup", "Medium", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Setup", "Coarse", 0, QApplication::UnicodeUTF8)
        );
        displayText->setText(QApplication::translate("Setup", "Display Checklist", 0, QApplication::UnicodeUTF8));
        label_timer2->setText(QApplication::translate("Setup", "Timer 2", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Setup", "Timer 1", 0, QApplication::UnicodeUTF8));
        label_ttrace->setText(QApplication::translate("Setup", "Throttle Source", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Setup", "Trim Step", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Setup", "Center beep", 0, QApplication::UnicodeUTF8));
        modelImage_label->setText(QApplication::translate("Setup", "Model Image", 0, QApplication::UnicodeUTF8));
        imagePreview->setText(QString());
        swwarn_label->setText(QApplication::translate("Setup", "Warnings", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Setup", "Switch Warnings", 0, QApplication::UnicodeUTF8));
        label_potWarning->setText(QApplication::translate("Setup", "Pot Warnings", 0, QApplication::UnicodeUTF8));
        potWarningMode->clear();
        potWarningMode->insertItems(0, QStringList()
         << QApplication::translate("Setup", "OFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Setup", "Manual", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Setup", "Auto", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("Setup", "Model", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Setup: public Ui_Setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
