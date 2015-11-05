/********************************************************************************
** Form generated from reading UI file 'setup_module.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_MODULE_H
#define UI_SETUP_MODULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Module
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label_module;
    QGroupBox *moduleGB;
    QGridLayout *gridLayout_69;
    QSpinBox *channelsStart;
    QFrame *failsafesFrame;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *failsafesLayout;
    QLabel *label_failsafeMode;
    QLabel *label_channelsStart;
    QComboBox *protocol;
    QLabel *label_ppmDelay;
    QSpinBox *ppmDelay;
    QComboBox *ppmPolarity;
    QComboBox *trainerMode;
    QLabel *label_ppmPolarity;
    QLabel *label_trainerMode;
    QDoubleSpinBox *ppmFrameLength;
    QSpinBox *channelsCount;
    QLabel *label_ppmFrameLength;
    QLabel *label_channelsCount;
    QComboBox *failsafeMode;
    QLabel *failsafesLayoutLabel;
    QLabel *label_protocol;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpinBox *rxNumber;
    QLabel *label_rxNumber;

    void setupUi(QWidget *Module)
    {
        if (Module->objectName().isEmpty())
            Module->setObjectName(QString::fromUtf8("Module"));
        Module->resize(628, 300);
        verticalLayout = new QVBoxLayout(Module);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(6);
#endif
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(Module);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_module = new QLabel(Module);
        label_module->setObjectName(QString::fromUtf8("label_module"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_module->sizePolicy().hasHeightForWidth());
        label_module->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_module->setFont(font);
        label_module->setText(QString::fromUtf8("Label"));

        verticalLayout->addWidget(label_module);

        moduleGB = new QGroupBox(Module);
        moduleGB->setObjectName(QString::fromUtf8("moduleGB"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(moduleGB->sizePolicy().hasHeightForWidth());
        moduleGB->setSizePolicy(sizePolicy1);
        moduleGB->setMaximumSize(QSize(16777215, 16777215));
        moduleGB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gridLayout_69 = new QGridLayout(moduleGB);
        gridLayout_69->setContentsMargins(0, 0, 0, 0);
        gridLayout_69->setObjectName(QString::fromUtf8("gridLayout_69"));
        gridLayout_69->setVerticalSpacing(6);
        channelsStart = new QSpinBox(moduleGB);
        channelsStart->setObjectName(QString::fromUtf8("channelsStart"));
        channelsStart->setMaximumSize(QSize(125, 16777215));
        channelsStart->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        channelsStart->setMinimum(1);
        channelsStart->setMaximum(32);
        channelsStart->setSingleStep(1);
        channelsStart->setValue(1);

        gridLayout_69->addWidget(channelsStart, 2, 3, 1, 1, Qt::AlignLeft);

        failsafesFrame = new QFrame(moduleGB);
        failsafesFrame->setObjectName(QString::fromUtf8("failsafesFrame"));
        failsafesFrame->setMaximumSize(QSize(700, 16777215));
        failsafesFrame->setFrameShape(QFrame::StyledPanel);
        failsafesFrame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(failsafesFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        failsafesLayout = new QGridLayout();
        failsafesLayout->setObjectName(QString::fromUtf8("failsafesLayout"));

        verticalLayout_2->addLayout(failsafesLayout);


        gridLayout_69->addWidget(failsafesFrame, 6, 1, 1, 5);

        label_failsafeMode = new QLabel(moduleGB);
        label_failsafeMode->setObjectName(QString::fromUtf8("label_failsafeMode"));
        label_failsafeMode->setMaximumSize(QSize(16777215, 16777215));
        label_failsafeMode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_failsafeMode, 5, 0, 1, 1);

        label_channelsStart = new QLabel(moduleGB);
        label_channelsStart->setObjectName(QString::fromUtf8("label_channelsStart"));
        label_channelsStart->setMaximumSize(QSize(16777215, 16777215));
        label_channelsStart->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_channelsStart, 2, 2, 1, 1, Qt::AlignRight);

        protocol = new QComboBox(moduleGB);
        protocol->setObjectName(QString::fromUtf8("protocol"));
        protocol->setMaximumSize(QSize(125, 16777215));

        gridLayout_69->addWidget(protocol, 2, 1, 1, 1);

        label_ppmDelay = new QLabel(moduleGB);
        label_ppmDelay->setObjectName(QString::fromUtf8("label_ppmDelay"));
        label_ppmDelay->setMaximumSize(QSize(16777215, 16777215));
        label_ppmDelay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_ppmDelay, 3, 4, 1, 1, Qt::AlignRight);

        ppmDelay = new QSpinBox(moduleGB);
        ppmDelay->setObjectName(QString::fromUtf8("ppmDelay"));
        ppmDelay->setMaximumSize(QSize(125, 16777215));
        ppmDelay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ppmDelay->setMinimum(100);
        ppmDelay->setMaximum(800);
        ppmDelay->setSingleStep(50);
        ppmDelay->setValue(300);

        gridLayout_69->addWidget(ppmDelay, 3, 5, 1, 1);

        ppmPolarity = new QComboBox(moduleGB);
        ppmPolarity->setObjectName(QString::fromUtf8("ppmPolarity"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ppmPolarity->sizePolicy().hasHeightForWidth());
        ppmPolarity->setSizePolicy(sizePolicy2);
        ppmPolarity->setMaximumSize(QSize(125, 16777215));

        gridLayout_69->addWidget(ppmPolarity, 3, 3, 1, 1, Qt::AlignLeft);

        trainerMode = new QComboBox(moduleGB);
        trainerMode->setObjectName(QString::fromUtf8("trainerMode"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(trainerMode->sizePolicy().hasHeightForWidth());
        trainerMode->setSizePolicy(sizePolicy3);
        trainerMode->setMaximumSize(QSize(125, 16777215));

        gridLayout_69->addWidget(trainerMode, 0, 1, 1, 1);

        label_ppmPolarity = new QLabel(moduleGB);
        label_ppmPolarity->setObjectName(QString::fromUtf8("label_ppmPolarity"));
        label_ppmPolarity->setMaximumSize(QSize(16777215, 16777215));
        label_ppmPolarity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_ppmPolarity, 3, 2, 1, 1, Qt::AlignRight);

        label_trainerMode = new QLabel(moduleGB);
        label_trainerMode->setObjectName(QString::fromUtf8("label_trainerMode"));
        label_trainerMode->setMaximumSize(QSize(16777215, 16777215));
        label_trainerMode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_trainerMode, 0, 0, 1, 1, Qt::AlignRight);

        ppmFrameLength = new QDoubleSpinBox(moduleGB);
        ppmFrameLength->setObjectName(QString::fromUtf8("ppmFrameLength"));
        sizePolicy3.setHeightForWidth(ppmFrameLength->sizePolicy().hasHeightForWidth());
        ppmFrameLength->setSizePolicy(sizePolicy3);
        ppmFrameLength->setMaximumSize(QSize(125, 16777215));
        ppmFrameLength->setDecimals(1);
        ppmFrameLength->setMinimum(12.5);
        ppmFrameLength->setMaximum(32.5);
        ppmFrameLength->setSingleStep(0.5);
        ppmFrameLength->setValue(22.5);

        gridLayout_69->addWidget(ppmFrameLength, 3, 1, 1, 1);

        channelsCount = new QSpinBox(moduleGB);
        channelsCount->setObjectName(QString::fromUtf8("channelsCount"));
        channelsCount->setMaximumSize(QSize(125, 16777215));
        channelsCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        channelsCount->setMinimum(1);
        channelsCount->setMaximum(16);
        channelsCount->setSingleStep(2);
        channelsCount->setValue(8);

        gridLayout_69->addWidget(channelsCount, 2, 5, 1, 1, Qt::AlignLeft);

        label_ppmFrameLength = new QLabel(moduleGB);
        label_ppmFrameLength->setObjectName(QString::fromUtf8("label_ppmFrameLength"));
        label_ppmFrameLength->setMaximumSize(QSize(16777215, 16777215));
        label_ppmFrameLength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_ppmFrameLength, 3, 0, 1, 1, Qt::AlignRight);

        label_channelsCount = new QLabel(moduleGB);
        label_channelsCount->setObjectName(QString::fromUtf8("label_channelsCount"));
        sizePolicy1.setHeightForWidth(label_channelsCount->sizePolicy().hasHeightForWidth());
        label_channelsCount->setSizePolicy(sizePolicy1);
        label_channelsCount->setMaximumSize(QSize(16777215, 16777215));
        label_channelsCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_channelsCount, 2, 4, 1, 1, Qt::AlignRight);

        failsafeMode = new QComboBox(moduleGB);
        failsafeMode->setObjectName(QString::fromUtf8("failsafeMode"));
        sizePolicy3.setHeightForWidth(failsafeMode->sizePolicy().hasHeightForWidth());
        failsafeMode->setSizePolicy(sizePolicy3);
        failsafeMode->setMaximumSize(QSize(125, 16777215));

        gridLayout_69->addWidget(failsafeMode, 5, 1, 1, 1, Qt::AlignLeft);

        failsafesLayoutLabel = new QLabel(moduleGB);
        failsafesLayoutLabel->setObjectName(QString::fromUtf8("failsafesLayoutLabel"));
        failsafesLayoutLabel->setMaximumSize(QSize(16777215, 16777215));
        failsafesLayoutLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(failsafesLayoutLabel, 6, 0, 1, 1, Qt::AlignRight);

        label_protocol = new QLabel(moduleGB);
        label_protocol->setObjectName(QString::fromUtf8("label_protocol"));
        label_protocol->setMaximumSize(QSize(16777215, 16777215));
        label_protocol->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_protocol, 2, 0, 1, 1, Qt::AlignRight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_69->addItem(horizontalSpacer_2, 2, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_69->addItem(verticalSpacer, 8, 0, 1, 1);

        rxNumber = new QSpinBox(moduleGB);
        rxNumber->setObjectName(QString::fromUtf8("rxNumber"));
        sizePolicy3.setHeightForWidth(rxNumber->sizePolicy().hasHeightForWidth());
        rxNumber->setSizePolicy(sizePolicy3);
        rxNumber->setMaximumSize(QSize(125, 16777215));
        rxNumber->setMinimum(0);
        rxNumber->setMaximum(63);
        rxNumber->setSingleStep(1);
        rxNumber->setValue(0);

        gridLayout_69->addWidget(rxNumber, 5, 5, 1, 1);

        label_rxNumber = new QLabel(moduleGB);
        label_rxNumber->setObjectName(QString::fromUtf8("label_rxNumber"));
        label_rxNumber->setMaximumSize(QSize(16777215, 16777215));
        label_rxNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_69->addWidget(label_rxNumber, 5, 4, 1, 1);


        verticalLayout->addWidget(moduleGB);

        QWidget::setTabOrder(trainerMode, protocol);
        QWidget::setTabOrder(protocol, channelsStart);
        QWidget::setTabOrder(channelsStart, channelsCount);
        QWidget::setTabOrder(channelsCount, ppmFrameLength);
        QWidget::setTabOrder(ppmFrameLength, ppmPolarity);
        QWidget::setTabOrder(ppmPolarity, ppmDelay);
        QWidget::setTabOrder(ppmDelay, failsafeMode);
        QWidget::setTabOrder(failsafeMode, rxNumber);

        retranslateUi(Module);

        QMetaObject::connectSlotsByName(Module);
    } // setupUi

    void retranslateUi(QWidget *Module)
    {
        Module->setWindowTitle(QString());
        moduleGB->setTitle(QString());
        channelsStart->setSuffix(QString());
        channelsStart->setPrefix(QApplication::translate("Module", "CH ", 0, QApplication::UnicodeUTF8));
        label_failsafeMode->setText(QApplication::translate("Module", "Failsafe Mode", 0, QApplication::UnicodeUTF8));
        label_channelsStart->setText(QApplication::translate("Module", "Start", 0, QApplication::UnicodeUTF8));
        label_ppmDelay->setText(QApplication::translate("Module", "PPM delay", 0, QApplication::UnicodeUTF8));
        ppmDelay->setSuffix(QApplication::translate("Module", " us", 0, QApplication::UnicodeUTF8));
        ppmPolarity->clear();
        ppmPolarity->insertItems(0, QStringList()
         << QApplication::translate("Module", "Negative", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Module", "Positive", 0, QApplication::UnicodeUTF8)
        );
        trainerMode->clear();
        trainerMode->insertItems(0, QStringList()
         << QApplication::translate("Module", "Master", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Module", "Slave", 0, QApplication::UnicodeUTF8)
        );
        label_ppmPolarity->setText(QApplication::translate("Module", "Polarity", 0, QApplication::UnicodeUTF8));
        label_trainerMode->setText(QApplication::translate("Module", "Trainer Mode", 0, QApplication::UnicodeUTF8));
        ppmFrameLength->setSuffix(QApplication::translate("Module", " ms", 0, QApplication::UnicodeUTF8));
        channelsCount->setSuffix(QString());
        label_ppmFrameLength->setText(QApplication::translate("Module", "PPM Frame Length", 0, QApplication::UnicodeUTF8));
        label_channelsCount->setText(QApplication::translate("Module", "Channels", 0, QApplication::UnicodeUTF8));
        failsafeMode->clear();
        failsafeMode->insertItems(0, QStringList()
         << QApplication::translate("Module", "Hold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Module", "Custom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Module", "No Pulses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Module", "Receiver", 0, QApplication::UnicodeUTF8)
        );
        failsafesLayoutLabel->setText(QApplication::translate("Module", "Failsafe Positions", 0, QApplication::UnicodeUTF8));
        label_protocol->setText(QApplication::translate("Module", "Protocol", 0, QApplication::UnicodeUTF8));
        rxNumber->setSuffix(QString());
        label_rxNumber->setText(QApplication::translate("Module", "Receiver No.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Module: public Ui_Module {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_MODULE_H
