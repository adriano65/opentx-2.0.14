/********************************************************************************
** Form generated from reading UI file 'burnconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BURNCONFIGDIALOG_H
#define UI_BURNCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_burnConfigDialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout;
    QLineEdit *dfu_location;
    QLabel *label_dfu1;
    QLineEdit *avrdude_location;
    QPushButton *pushButton;
    QLabel *label_av2;
    QComboBox *avrdude_programmer;
    QPushButton *pushButton_3;
    QLineEdit *avrArgs;
    QLabel *label_av5;
    QPushButton *pushButton_4;
    QComboBox *avrdude_port;
    QLabel *label_av4;
    QLabel *label_av1;
    QLabel *label_av3;
    QComboBox *avrdude_mcu;
    QComboBox *arm_mcu;
    QLabel *label_sb1;
    QLineEdit *samba_location;
    QLabel *label_sb2;
    QLabel *label_sb3;
    QLineEdit *samba_port;
    QLabel *label_dfu2;
    QLineEdit *dfuArgs;
    QPushButton *sb_browse;
    QPushButton *dfu_browse;
    QCheckBox *advCtrChkB;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *burnConfigDialog)
    {
        if (burnConfigDialog->objectName().isEmpty())
            burnConfigDialog->setObjectName(QString::fromUtf8("burnConfigDialog"));
        burnConfigDialog->resize(531, 422);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(burnConfigDialog->sizePolicy().hasHeightForWidth());
        burnConfigDialog->setSizePolicy(sizePolicy);
        burnConfigDialog->setMinimumSize(QSize(531, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        burnConfigDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(burnConfigDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(burnConfigDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dfu_location = new QLineEdit(burnConfigDialog);
        dfu_location->setObjectName(QString::fromUtf8("dfu_location"));
        dfu_location->setText(QString::fromUtf8("dfu-util"));

        gridLayout->addWidget(dfu_location, 9, 2, 1, 1);

        label_dfu1 = new QLabel(burnConfigDialog);
        label_dfu1->setObjectName(QString::fromUtf8("label_dfu1"));

        gridLayout->addWidget(label_dfu1, 9, 0, 1, 1);

        avrdude_location = new QLineEdit(burnConfigDialog);
        avrdude_location->setObjectName(QString::fromUtf8("avrdude_location"));
        avrdude_location->setText(QString::fromUtf8(""));

        gridLayout->addWidget(avrdude_location, 0, 2, 1, 1);

        pushButton = new QPushButton(burnConfigDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 4, 2, 1);

        label_av2 = new QLabel(burnConfigDialog);
        label_av2->setObjectName(QString::fromUtf8("label_av2"));
        label_av2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_av2, 2, 0, 1, 1);

        avrdude_programmer = new QComboBox(burnConfigDialog);
        avrdude_programmer->insertItems(0, QStringList()
         << QString::fromUtf8("c2n232i")
         << QString::fromUtf8("dasa3")
         << QString::fromUtf8("dasa")
         << QString::fromUtf8("siprog")
         << QString::fromUtf8("ponyser")
         << QString::fromUtf8("89isp")
         << QString::fromUtf8("frank-stk200")
         << QString::fromUtf8("blaster")
         << QString::fromUtf8("ere-isp-avr")
         << QString::fromUtf8("atisp")
         << QString::fromUtf8("dapa")
         << QString::fromUtf8("xil")
         << QString::fromUtf8("futurlec")
         << QString::fromUtf8("abcmini")
         << QString::fromUtf8("picoweb")
         << QString::fromUtf8("sp12")
         << QString::fromUtf8("alf")
         << QString::fromUtf8("bascom")
         << QString::fromUtf8("dt006")
         << QString::fromUtf8("pony-stk200")
         << QString::fromUtf8("stk200")
         << QString::fromUtf8("bsd")
         << QString::fromUtf8("pavr")
         << QString::fromUtf8("dragon_pdi")
         << QString::fromUtf8("dragon_dw")
         << QString::fromUtf8("dragon_hvsp")
         << QString::fromUtf8("dragon_pp")
         << QString::fromUtf8("dragon_isp")
         << QString::fromUtf8("dragon_jtag")
         << QString::fromUtf8("jtag2pdi")
         << QString::fromUtf8("jtag2avr32")
         << QString::fromUtf8("jtagmkII_avr32")
         << QString::fromUtf8("jtag2dw")
         << QString::fromUtf8("jtag2isp")
         << QString::fromUtf8("jtag2")
         << QString::fromUtf8("jtag2fast")
         << QString::fromUtf8("jtag2slow")
         << QString::fromUtf8("jtagmkII")
         << QString::fromUtf8("jtag1slow")
         << QString::fromUtf8("jtag1")
         << QString::fromUtf8("jtagmkI")
         << QString::fromUtf8("avr911")
         << QString::fromUtf8("avr109")
         << QString::fromUtf8("butterfly")
         << QString::fromUtf8("usbtiny")
         << QString::fromUtf8("usbasp")
         << QString::fromUtf8("avr910")
         << QString::fromUtf8("stk600hvsp")
         << QString::fromUtf8("stk600pp")
         << QString::fromUtf8("stk600")
         << QString::fromUtf8("stk500hvsp")
         << QString::fromUtf8("stk500pp")
         << QString::fromUtf8("stk500v2")
         << QString::fromUtf8("mib510")
         << QString::fromUtf8("stk500v1")
         << QString::fromUtf8("stk500")
         << QString::fromUtf8("buspirate")
         << QString::fromUtf8("avrisp2")
         << QString::fromUtf8("avrispmkII")
         << QString::fromUtf8("avrispv2")
         << QString::fromUtf8("avrisp")
         << QString::fromUtf8("arduino")
        );
        avrdude_programmer->setObjectName(QString::fromUtf8("avrdude_programmer"));
        avrdude_programmer->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(avrdude_programmer, 2, 2, 1, 1);

        pushButton_3 = new QPushButton(burnConfigDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 4, 1, 1);

        avrArgs = new QLineEdit(burnConfigDialog);
        avrArgs->setObjectName(QString::fromUtf8("avrArgs"));
        avrArgs->setText(QString::fromUtf8(""));

        gridLayout->addWidget(avrArgs, 5, 2, 1, 1);

        label_av5 = new QLabel(burnConfigDialog);
        label_av5->setObjectName(QString::fromUtf8("label_av5"));
        label_av5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_av5, 5, 0, 1, 1);

        pushButton_4 = new QPushButton(burnConfigDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 5, 4, 1, 1);

        avrdude_port = new QComboBox(burnConfigDialog);
        avrdude_port->insertItems(0, QStringList()
         << QString::fromUtf8("")
         << QString::fromUtf8("usb")
         << QString::fromUtf8("com1")
         << QString::fromUtf8("com2")
         << QString::fromUtf8("com3")
         << QString::fromUtf8("com4")
         << QString::fromUtf8("com5")
         << QString::fromUtf8("com6")
         << QString::fromUtf8("com7")
         << QString::fromUtf8("com8")
         << QString::fromUtf8("com9")
         << QString::fromUtf8("com10")
         << QString::fromUtf8("com11")
         << QString::fromUtf8("com12")
         << QString::fromUtf8("com13")
         << QString::fromUtf8("com14")
         << QString::fromUtf8("com15")
         << QString::fromUtf8("lpt1")
         << QString::fromUtf8("lpt2")
         << QString::fromUtf8("lpt3")
         << QString::fromUtf8("lpt4")
         << QString::fromUtf8("avrdoper")
         << QString::fromUtf8("/dev/ttyUSB0")
         << QString::fromUtf8("/dev/ttyUSB1")
        );
        avrdude_port->setObjectName(QString::fromUtf8("avrdude_port"));

        gridLayout->addWidget(avrdude_port, 4, 2, 1, 1);

        label_av4 = new QLabel(burnConfigDialog);
        label_av4->setObjectName(QString::fromUtf8("label_av4"));
        label_av4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_av4, 4, 0, 1, 1);

        label_av1 = new QLabel(burnConfigDialog);
        label_av1->setObjectName(QString::fromUtf8("label_av1"));
        label_av1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_av1, 0, 0, 1, 1);

        label_av3 = new QLabel(burnConfigDialog);
        label_av3->setObjectName(QString::fromUtf8("label_av3"));
        label_av3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_av3, 3, 0, 1, 1);

        avrdude_mcu = new QComboBox(burnConfigDialog);
        avrdude_mcu->insertItems(0, QStringList()
         << QString::fromUtf8("m64")
         << QString::fromUtf8("m128")
         << QString::fromUtf8("m2560")
        );
        avrdude_mcu->setObjectName(QString::fromUtf8("avrdude_mcu"));
        avrdude_mcu->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(avrdude_mcu, 3, 2, 1, 1);

        arm_mcu = new QComboBox(burnConfigDialog);
        arm_mcu->addItem(QString::fromUtf8("at91sam3s4-9x"));
        arm_mcu->addItem(QString());
        arm_mcu->setObjectName(QString::fromUtf8("arm_mcu"));
        arm_mcu->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(arm_mcu, 7, 2, 1, 1);

        label_sb1 = new QLabel(burnConfigDialog);
        label_sb1->setObjectName(QString::fromUtf8("label_sb1"));
        label_sb1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_sb1, 6, 0, 1, 1);

        samba_location = new QLineEdit(burnConfigDialog);
        samba_location->setObjectName(QString::fromUtf8("samba_location"));
        samba_location->setText(QString::fromUtf8("sam-ba.exe"));

        gridLayout->addWidget(samba_location, 6, 2, 1, 1);

        label_sb2 = new QLabel(burnConfigDialog);
        label_sb2->setObjectName(QString::fromUtf8("label_sb2"));
        label_sb2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_sb2, 7, 0, 1, 1);

        label_sb3 = new QLabel(burnConfigDialog);
        label_sb3->setObjectName(QString::fromUtf8("label_sb3"));
        label_sb3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_sb3, 8, 0, 1, 1);

        samba_port = new QLineEdit(burnConfigDialog);
        samba_port->setObjectName(QString::fromUtf8("samba_port"));
        samba_port->setText(QString::fromUtf8("\\USBserial\\COM23"));

        gridLayout->addWidget(samba_port, 8, 2, 1, 1);

        label_dfu2 = new QLabel(burnConfigDialog);
        label_dfu2->setObjectName(QString::fromUtf8("label_dfu2"));

        gridLayout->addWidget(label_dfu2, 10, 0, 1, 1);

        dfuArgs = new QLineEdit(burnConfigDialog);
        dfuArgs->setObjectName(QString::fromUtf8("dfuArgs"));
        dfuArgs->setText(QString::fromUtf8("0"));

        gridLayout->addWidget(dfuArgs, 10, 2, 1, 1);

        sb_browse = new QPushButton(burnConfigDialog);
        sb_browse->setObjectName(QString::fromUtf8("sb_browse"));

        gridLayout->addWidget(sb_browse, 6, 4, 1, 1);

        dfu_browse = new QPushButton(burnConfigDialog);
        dfu_browse->setObjectName(QString::fromUtf8("dfu_browse"));

        gridLayout->addWidget(dfu_browse, 9, 4, 1, 1);

        advCtrChkB = new QCheckBox(burnConfigDialog);
        advCtrChkB->setObjectName(QString::fromUtf8("advCtrChkB"));

        gridLayout->addWidget(advCtrChkB, 11, 2, 1, 1);

        label = new QLabel(burnConfigDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 11, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        QWidget::setTabOrder(avrdude_location, pushButton);
        QWidget::setTabOrder(pushButton, avrdude_programmer);
        QWidget::setTabOrder(avrdude_programmer, pushButton_3);
        QWidget::setTabOrder(pushButton_3, avrdude_mcu);
        QWidget::setTabOrder(avrdude_mcu, avrdude_port);
        QWidget::setTabOrder(avrdude_port, avrArgs);
        QWidget::setTabOrder(avrArgs, pushButton_4);
        QWidget::setTabOrder(pushButton_4, samba_location);
        QWidget::setTabOrder(samba_location, sb_browse);
        QWidget::setTabOrder(sb_browse, arm_mcu);
        QWidget::setTabOrder(arm_mcu, samba_port);
        QWidget::setTabOrder(samba_port, dfu_location);
        QWidget::setTabOrder(dfu_location, dfu_browse);
        QWidget::setTabOrder(dfu_browse, dfuArgs);
        QWidget::setTabOrder(dfuArgs, advCtrChkB);
        QWidget::setTabOrder(advCtrChkB, buttonBox);

        retranslateUi(burnConfigDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), burnConfigDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), burnConfigDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(burnConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *burnConfigDialog)
    {
        burnConfigDialog->setWindowTitle(QApplication::translate("burnConfigDialog", "Programmer Configuration", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dfu_location->setToolTip(QApplication::translate("burnConfigDialog", "Location of sam-ba executable", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        dfu_location->setWhatsThis(QApplication::translate("burnConfigDialog", "The location of the AVRDUDE executable.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_dfu1->setText(QApplication::translate("burnConfigDialog", "DFU-Util Location", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        avrdude_location->setToolTip(QApplication::translate("burnConfigDialog", "Location of AVRDUDE executable", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        avrdude_location->setWhatsThis(QApplication::translate("burnConfigDialog", "The location of the AVRDUDE executable.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("burnConfigDialog", "Use this button to browse and look for the AVRDUDE executable file.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("burnConfigDialog", "Browse...", 0, QApplication::UnicodeUTF8));
        label_av2->setText(QApplication::translate("burnConfigDialog", "Programmer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        avrdude_programmer->setWhatsThis(QApplication::translate("burnConfigDialog", "Programmer used for communicating with the controller.\n"
"Please consult the programmer's documentation and the AVRDUDE documentation to select the appropriate programmer.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("burnConfigDialog", "List all available programmers.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("burnConfigDialog", "List Available", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        avrArgs->setToolTip(QApplication::translate("burnConfigDialog", "Extra arguments that will be passed to AVRDUDE on every call", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        avrArgs->setWhatsThis(QApplication::translate("burnConfigDialog", "Extra arguments used in AVRDUDE.\n"
"This can be used for providing extra information to AVRDUDE.\n"
"\n"
"Please only use this if you know what you are doing.  There are no error checks and you could cripple your controller.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_av5->setText(QApplication::translate("burnConfigDialog", "Extra Arguments", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("burnConfigDialog", "Show AVRDUDE help", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("burnConfigDialog", "Show Help", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        avrdude_port->setWhatsThis(QApplication::translate("burnConfigDialog", "Communication port to the programmer.\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_av4->setText(QApplication::translate("burnConfigDialog", "Port", 0, QApplication::UnicodeUTF8));
        label_av1->setText(QApplication::translate("burnConfigDialog", "AVRDUDE Location", 0, QApplication::UnicodeUTF8));
        label_av3->setText(QApplication::translate("burnConfigDialog", "MCU", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        avrdude_mcu->setToolTip(QApplication::translate("burnConfigDialog", "CPU of your TX", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        avrdude_mcu->setWhatsThis(QApplication::translate("burnConfigDialog", "CPU present on your 9x radio\n"
"Should be m64 for stock radios\n"
"m2560 for v4.1 boards", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        arm_mcu->setItemText(1, QApplication::translate("burnConfigDialog", "at91sam3s8-9xr", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
        arm_mcu->setToolTip(QApplication::translate("burnConfigDialog", "CPU of your TX", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        arm_mcu->setWhatsThis(QApplication::translate("burnConfigDialog", "CPU present on your 9x radio\n"
"Should be m64 for stock radios\n"
"m2560 for v4.1 boards", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_sb1->setText(QApplication::translate("burnConfigDialog", "SAM-BA Location", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        samba_location->setToolTip(QApplication::translate("burnConfigDialog", "Location of sam-ba executable", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        samba_location->setWhatsThis(QApplication::translate("burnConfigDialog", "The location of the AVRDUDE executable.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_sb2->setText(QApplication::translate("burnConfigDialog", "ARM MCU", 0, QApplication::UnicodeUTF8));
        label_sb3->setText(QApplication::translate("burnConfigDialog", "Port", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        samba_port->setToolTip(QApplication::translate("burnConfigDialog", "sam-ba serial port", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        samba_port->setWhatsThis(QApplication::translate("burnConfigDialog", "The location of the AVRDUDE executable.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_dfu2->setText(QApplication::translate("burnConfigDialog", "Alternate device", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dfuArgs->setToolTip(QApplication::translate("burnConfigDialog", "Extra arguments that will be passed to AVRDUDE on every call", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        dfuArgs->setWhatsThis(QApplication::translate("burnConfigDialog", "Extra arguments used in AVRDUDE.\n"
"This can be used for providing extra information to AVRDUDE.\n"
"\n"
"Please only use this if you know what you are doing.  There are no error checks and you could cripple your controller.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        sb_browse->setWhatsThis(QApplication::translate("burnConfigDialog", "Use this button to browse and look for the AVRDUDE executable file.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        sb_browse->setText(QApplication::translate("burnConfigDialog", "Browse...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        dfu_browse->setWhatsThis(QApplication::translate("burnConfigDialog", "Use this button to browse and look for the AVRDUDE executable file.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        dfu_browse->setText(QApplication::translate("burnConfigDialog", "Browse...", 0, QApplication::UnicodeUTF8));
        advCtrChkB->setText(QString());
        label->setText(QApplication::translate("burnConfigDialog", "Use advanced controls", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class burnConfigDialog: public Ui_burnConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BURNCONFIGDIALOG_H
