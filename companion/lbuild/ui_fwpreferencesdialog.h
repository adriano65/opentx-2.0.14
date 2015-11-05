/********************************************************************************
** Form generated from reading UI file 'fwpreferencesdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FWPREFERENCESDIALOG_H
#define UI_FWPREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FirmwarePreferencesDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *checkFWUpdates;
    QLabel *voiceLabel;
    QComboBox *voiceCombo;
    QPushButton *voice_dnld;
    QPushButton *fw_dnld;
    QSpacerItem *horizontalSpacer_2;
    QFrame *voiceLine;
    QFrame *line_6;
    QLabel *label_6;
    QLabel *fwTypeLbl;
    QLabel *lastRevisionLbl;
    QLabel *label;

    void setupUi(QDialog *FirmwarePreferencesDialog)
    {
        if (FirmwarePreferencesDialog->objectName().isEmpty())
            FirmwarePreferencesDialog->setObjectName(QString::fromUtf8("FirmwarePreferencesDialog"));
        FirmwarePreferencesDialog->resize(416, 154);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FirmwarePreferencesDialog->sizePolicy().hasHeightForWidth());
        FirmwarePreferencesDialog->setSizePolicy(sizePolicy);
        FirmwarePreferencesDialog->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(FirmwarePreferencesDialog);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        buttonBox = new QDialogButtonBox(FirmwarePreferencesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 24, 5, 1, 1);

        checkFWUpdates = new QPushButton(FirmwarePreferencesDialog);
        checkFWUpdates->setObjectName(QString::fromUtf8("checkFWUpdates"));
        checkFWUpdates->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(checkFWUpdates, 3, 5, 1, 1);

        voiceLabel = new QLabel(FirmwarePreferencesDialog);
        voiceLabel->setObjectName(QString::fromUtf8("voiceLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setBold(true);
        font.setWeight(75);
        voiceLabel->setFont(font);

        gridLayout->addWidget(voiceLabel, 7, 0, 1, 1);

        voiceCombo = new QComboBox(FirmwarePreferencesDialog);
        voiceCombo->setObjectName(QString::fromUtf8("voiceCombo"));
        voiceCombo->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(voiceCombo, 7, 2, 1, 1);

        voice_dnld = new QPushButton(FirmwarePreferencesDialog);
        voice_dnld->setObjectName(QString::fromUtf8("voice_dnld"));

        gridLayout->addWidget(voice_dnld, 7, 5, 1, 1);

        fw_dnld = new QPushButton(FirmwarePreferencesDialog);
        fw_dnld->setObjectName(QString::fromUtf8("fw_dnld"));

        gridLayout->addWidget(fw_dnld, 5, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 7, 3, 1, 1);

        voiceLine = new QFrame(FirmwarePreferencesDialog);
        voiceLine->setObjectName(QString::fromUtf8("voiceLine"));
        voiceLine->setFrameShape(QFrame::HLine);
        voiceLine->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(voiceLine, 6, 0, 1, 6);

        line_6 = new QFrame(FirmwarePreferencesDialog);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 23, 0, 1, 6);

        label_6 = new QLabel(FirmwarePreferencesDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        fwTypeLbl = new QLabel(FirmwarePreferencesDialog);
        fwTypeLbl->setObjectName(QString::fromUtf8("fwTypeLbl"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fwTypeLbl->sizePolicy().hasHeightForWidth());
        fwTypeLbl->setSizePolicy(sizePolicy2);
        fwTypeLbl->setText(QString::fromUtf8("FwType"));

        gridLayout->addWidget(fwTypeLbl, 0, 2, 1, 4);

        lastRevisionLbl = new QLabel(FirmwarePreferencesDialog);
        lastRevisionLbl->setObjectName(QString::fromUtf8("lastRevisionLbl"));
        lastRevisionLbl->setText(QString::fromUtf8("-"));

        gridLayout->addWidget(lastRevisionLbl, 3, 2, 1, 2);

        label = new QLabel(FirmwarePreferencesDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        QWidget::setTabOrder(checkFWUpdates, fw_dnld);
        QWidget::setTabOrder(fw_dnld, voiceCombo);
        QWidget::setTabOrder(voiceCombo, voice_dnld);
        QWidget::setTabOrder(voice_dnld, buttonBox);

        retranslateUi(FirmwarePreferencesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FirmwarePreferencesDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(FirmwarePreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *FirmwarePreferencesDialog)
    {
        FirmwarePreferencesDialog->setWindowTitle(QApplication::translate("FirmwarePreferencesDialog", "Downloads", 0, QApplication::UnicodeUTF8));
        checkFWUpdates->setText(QApplication::translate("FirmwarePreferencesDialog", "Check for updates", 0, QApplication::UnicodeUTF8));
        voiceLabel->setText(QApplication::translate("FirmwarePreferencesDialog", "Voice", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        voiceCombo->setToolTip(QApplication::translate("FirmwarePreferencesDialog", "Set voice language.\n"
"May be different from firmware language", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        voice_dnld->setText(QApplication::translate("FirmwarePreferencesDialog", "Download Voice", 0, QApplication::UnicodeUTF8));
        fw_dnld->setText(QApplication::translate("FirmwarePreferencesDialog", "Download FW", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FirmwarePreferencesDialog", "Firmware", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FirmwarePreferencesDialog", "Latest Download", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FirmwarePreferencesDialog: public Ui_FirmwarePreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWPREFERENCESDIALOG_H
