/********************************************************************************
** Form generated from reading UI file 'burndialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BURNDIALOG_H
#define UI_BURNDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_burnDialog
{
public:
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *hs2;
    QPushButton *cancelButton;
    QPushButton *BurnFlashButton;
    QGridLayout *gridLayout_4;
    QCheckBox *patchcalib_CB;
    QCheckBox *patchhw_CB;
    QFrame *FramFWInfo;
    QGridLayout *gridLayout_5;
    QLabel *dateLabel;
    QLineEdit *versionField;
    QLabel *buildLabel;
    QLineEdit *ModField;
    QLabel *versionLabel;
    QLineEdit *DateField;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *FWFileName;
    QPushButton *FlashLoadButton;
    QCheckBox *EEpromCB;
    QCheckBox *EEbackupCB;
    QLabel *profile_label;
    QFrame *SplashFrame;
    QGridLayout *gridLayout;
    QGridLayout *SplashLayout;
    QGridLayout *gridLayout_2;
    QLabel *imageLabel;
    QCheckBox *useFwImageCB;
    QCheckBox *useAnotherImageCB;
    QCheckBox *useProfileImageCB;
    QCheckBox *useLibraryImageCB;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *burnDialog)
    {
        if (burnDialog->objectName().isEmpty())
            burnDialog->setObjectName(QString::fromUtf8("burnDialog"));
        burnDialog->resize(399, 564);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(burnDialog->sizePolicy().hasHeightForWidth());
        burnDialog->setSizePolicy(sizePolicy);
        burnDialog->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        burnDialog->setWindowIcon(icon);
        gridLayout_7 = new QGridLayout(burnDialog);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        hs2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(hs2);

        cancelButton = new QPushButton(burnDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(90, 0));

        horizontalLayout_4->addWidget(cancelButton);

        BurnFlashButton = new QPushButton(burnDialog);
        BurnFlashButton->setObjectName(QString::fromUtf8("BurnFlashButton"));
        BurnFlashButton->setEnabled(false);
        BurnFlashButton->setMinimumSize(QSize(90, 0));

        horizontalLayout_4->addWidget(BurnFlashButton);


        gridLayout_7->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        patchcalib_CB = new QCheckBox(burnDialog);
        patchcalib_CB->setObjectName(QString::fromUtf8("patchcalib_CB"));

        gridLayout_4->addWidget(patchcalib_CB, 5, 0, 1, 1);

        patchhw_CB = new QCheckBox(burnDialog);
        patchhw_CB->setObjectName(QString::fromUtf8("patchhw_CB"));

        gridLayout_4->addWidget(patchhw_CB, 6, 0, 1, 1);

        FramFWInfo = new QFrame(burnDialog);
        FramFWInfo->setObjectName(QString::fromUtf8("FramFWInfo"));
        sizePolicy.setHeightForWidth(FramFWInfo->sizePolicy().hasHeightForWidth());
        FramFWInfo->setSizePolicy(sizePolicy);
        FramFWInfo->setFrameShape(QFrame::StyledPanel);
        FramFWInfo->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(FramFWInfo);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        dateLabel = new QLabel(FramFWInfo);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        gridLayout_5->addWidget(dateLabel, 3, 0, 1, 1);

        versionField = new QLineEdit(FramFWInfo);
        versionField->setObjectName(QString::fromUtf8("versionField"));
        versionField->setReadOnly(true);

        gridLayout_5->addWidget(versionField, 1, 1, 1, 1);

        buildLabel = new QLabel(FramFWInfo);
        buildLabel->setObjectName(QString::fromUtf8("buildLabel"));

        gridLayout_5->addWidget(buildLabel, 2, 0, 1, 1);

        ModField = new QLineEdit(FramFWInfo);
        ModField->setObjectName(QString::fromUtf8("ModField"));
        ModField->setReadOnly(true);

        gridLayout_5->addWidget(ModField, 2, 1, 1, 1);

        versionLabel = new QLabel(FramFWInfo);
        versionLabel->setObjectName(QString::fromUtf8("versionLabel"));

        gridLayout_5->addWidget(versionLabel, 1, 0, 1, 1);

        DateField = new QLineEdit(FramFWInfo);
        DateField->setObjectName(QString::fromUtf8("DateField"));
        DateField->setReadOnly(true);

        gridLayout_5->addWidget(DateField, 3, 1, 1, 1);


        gridLayout_4->addWidget(FramFWInfo, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        FWFileName = new QLineEdit(burnDialog);
        FWFileName->setObjectName(QString::fromUtf8("FWFileName"));
        FWFileName->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(FWFileName->sizePolicy().hasHeightForWidth());
        FWFileName->setSizePolicy(sizePolicy1);
        FWFileName->setMinimumSize(QSize(250, 0));
        FWFileName->setReadOnly(true);

        horizontalLayout_2->addWidget(FWFileName);

        FlashLoadButton = new QPushButton(burnDialog);
        FlashLoadButton->setObjectName(QString::fromUtf8("FlashLoadButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FlashLoadButton->sizePolicy().hasHeightForWidth());
        FlashLoadButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(FlashLoadButton);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        EEpromCB = new QCheckBox(burnDialog);
        EEpromCB->setObjectName(QString::fromUtf8("EEpromCB"));
        sizePolicy2.setHeightForWidth(EEpromCB->sizePolicy().hasHeightForWidth());
        EEpromCB->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(EEpromCB, 7, 0, 1, 1);

        EEbackupCB = new QCheckBox(burnDialog);
        EEbackupCB->setObjectName(QString::fromUtf8("EEbackupCB"));
        EEbackupCB->setEnabled(true);
        EEbackupCB->setTristate(false);

        gridLayout_4->addWidget(EEbackupCB, 3, 0, 1, 1);

        profile_label = new QLabel(burnDialog);
        profile_label->setObjectName(QString::fromUtf8("profile_label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        profile_label->setFont(font);
        profile_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(profile_label, 4, 0, 1, 1);

        SplashFrame = new QFrame(burnDialog);
        SplashFrame->setObjectName(QString::fromUtf8("SplashFrame"));
        sizePolicy.setHeightForWidth(SplashFrame->sizePolicy().hasHeightForWidth());
        SplashFrame->setSizePolicy(sizePolicy);
        SplashFrame->setFrameShape(QFrame::StyledPanel);
        SplashFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(SplashFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        SplashLayout = new QGridLayout();
        SplashLayout->setObjectName(QString::fromUtf8("SplashLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        imageLabel = new QLabel(SplashFrame);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);
        imageLabel->setMinimumSize(QSize(128, 64));
        imageLabel->setMaximumSize(QSize(214, 66));
        imageLabel->setFrameShape(QFrame::Panel);
        imageLabel->setFrameShadow(QFrame::Plain);
        imageLabel->setLineWidth(0);
        imageLabel->setScaledContents(true);

        gridLayout_2->addWidget(imageLabel, 0, 0, 1, 1);


        SplashLayout->addLayout(gridLayout_2, 0, 1, 7, 1);

        useFwImageCB = new QCheckBox(SplashFrame);
        useFwImageCB->setObjectName(QString::fromUtf8("useFwImageCB"));

        SplashLayout->addWidget(useFwImageCB, 2, 0, 1, 1);

        useAnotherImageCB = new QCheckBox(SplashFrame);
        useAnotherImageCB->setObjectName(QString::fromUtf8("useAnotherImageCB"));

        SplashLayout->addWidget(useAnotherImageCB, 4, 0, 1, 1);

        useProfileImageCB = new QCheckBox(SplashFrame);
        useProfileImageCB->setObjectName(QString::fromUtf8("useProfileImageCB"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(useProfileImageCB->sizePolicy().hasHeightForWidth());
        useProfileImageCB->setSizePolicy(sizePolicy3);

        SplashLayout->addWidget(useProfileImageCB, 1, 0, 1, 1);

        useLibraryImageCB = new QCheckBox(SplashFrame);
        useLibraryImageCB->setObjectName(QString::fromUtf8("useLibraryImageCB"));

        SplashLayout->addWidget(useLibraryImageCB, 3, 0, 1, 1);


        gridLayout->addLayout(SplashLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(SplashFrame, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 1, 0, 1, 1);

        QWidget::setTabOrder(FWFileName, FlashLoadButton);
        QWidget::setTabOrder(FlashLoadButton, versionField);
        QWidget::setTabOrder(versionField, ModField);
        QWidget::setTabOrder(ModField, DateField);
        QWidget::setTabOrder(DateField, useProfileImageCB);
        QWidget::setTabOrder(useProfileImageCB, useFwImageCB);
        QWidget::setTabOrder(useFwImageCB, useLibraryImageCB);
        QWidget::setTabOrder(useLibraryImageCB, useAnotherImageCB);
        QWidget::setTabOrder(useAnotherImageCB, EEbackupCB);
        QWidget::setTabOrder(EEbackupCB, patchcalib_CB);
        QWidget::setTabOrder(patchcalib_CB, patchhw_CB);
        QWidget::setTabOrder(patchhw_CB, EEpromCB);
        QWidget::setTabOrder(EEpromCB, cancelButton);
        QWidget::setTabOrder(cancelButton, BurnFlashButton);

        retranslateUi(burnDialog);

        QMetaObject::connectSlotsByName(burnDialog);
    } // setupUi

    void retranslateUi(QDialog *burnDialog)
    {
        burnDialog->setWindowTitle(QApplication::translate("burnDialog", "Customize Splash", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("burnDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        BurnFlashButton->setText(QApplication::translate("burnDialog", "Write to TX", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        patchcalib_CB->setToolTip(QApplication::translate("burnDialog", "<html><head/><body><p>Modify calibration parameters using settings from current profile</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        patchcalib_CB->setText(QApplication::translate("burnDialog", "Patch calibration setting from profile", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        patchhw_CB->setToolTip(QApplication::translate("burnDialog", "<html><head/><body><p>Modify HW parameters using settings from current profile</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        patchhw_CB->setText(QApplication::translate("burnDialog", "Patch HW setting from profile", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("burnDialog", "Date & Time", 0, QApplication::UnicodeUTF8));
        buildLabel->setText(QApplication::translate("burnDialog", "Variant", 0, QApplication::UnicodeUTF8));
        versionLabel->setText(QApplication::translate("burnDialog", "Version", 0, QApplication::UnicodeUTF8));
        FlashLoadButton->setText(QApplication::translate("burnDialog", "Browse for file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        EEpromCB->setToolTip(QApplication::translate("burnDialog", "Allows Companion to write to older version of the firmware", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        EEpromCB->setText(QApplication::translate("burnDialog", "Check Firmware compatibility", 0, QApplication::UnicodeUTF8));
        EEbackupCB->setText(QApplication::translate("burnDialog", "Backup and restore Models and Settings", 0, QApplication::UnicodeUTF8));
        profile_label->setText(QApplication::translate("burnDialog", "Current Profile", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        useFwImageCB->setText(QApplication::translate("burnDialog", "Use firmware start screen", 0, QApplication::UnicodeUTF8));
        useAnotherImageCB->setText(QApplication::translate("burnDialog", "Use another start screen", 0, QApplication::UnicodeUTF8));
        useProfileImageCB->setText(QApplication::translate("burnDialog", "Use profile start screen", 0, QApplication::UnicodeUTF8));
        useLibraryImageCB->setText(QApplication::translate("burnDialog", "Use library start screen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class burnDialog: public Ui_burnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BURNDIALOG_H
