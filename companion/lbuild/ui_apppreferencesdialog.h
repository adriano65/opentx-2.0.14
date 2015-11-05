/********************************************************************************
** Form generated from reading UI file 'apppreferencesdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPPREFERENCESDIALOG_H
#define UI_APPPREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppPreferencesDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *profileTab;
    QGridLayout *gridLayout_2;
    QPushButton *sdPathButton;
    QLabel *label_13;
    QLabel *label_6;
    QLabel *langLabel;
    QLabel *label_14;
    QPushButton *SplashSelect;
    QLabel *lblGeneralSettings;
    QFrame *line_7;
    QGridLayout *optionsLayout;
    QLabel *label_8;
    QLabel *label_2;
    QPushButton *clearImageButton;
    QLabel *imageLabel;
    QLabel *label_7;
    QFrame *line_6;
    QFrame *line_8;
    QLabel *label;
    QLabel *label_4;
    QLabel *sdPathLabel;
    QHBoxLayout *horizontalLayout;
    QComboBox *langCombo;
    QLabel *voiceLabel;
    QComboBox *voiceCombo;
    QComboBox *downloadVerCB;
    QLineEdit *SplashFileName;
    QLineEdit *sdPath;
    QComboBox *stickmodeCB;
    QComboBox *channelorderCB;
    QLineEdit *profileNameLE;
    QPushButton *removeProfileButton;
    QCheckBox *renameFirmware;
    QCheckBox *burnFirmware;
    QSpacerItem *verticalSpacer_3;
    QWidget *applicationTab;
    QGridLayout *gridLayout_3;
    QCheckBox *showSplash;
    QCheckBox *startupCheck_companion9x;
    QCheckBox *backupEnable;
    QFrame *line;
    QFrame *line_2;
    QCheckBox *startupCheck_fw;
    QLineEdit *libraryPath;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QPushButton *backupPathButton;
    QLabel *label_10;
    QLabel *label_5;
    QPushButton *ge_pathButton;
    QFrame *line_4;
    QPushButton *libraryPathButton;
    QLineEdit *backupPath;
    QLabel *ge_label;
    QComboBox *splashincludeCB;
    QLabel *label_9;
    QSpinBox *historySize;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *ge_lineedit;
    QFrame *line_5;
    QCheckBox *modelWizard_CB;
    QWidget *simulatorTab;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QCheckBox *joystickChkB;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *snapshotPathButton;
    QComboBox *backLightColor;
    QLabel *label_11;
    QComboBox *joystickCB;
    QPushButton *joystickcalButton;
    QLabel *label_19;
    QSpacerItem *verticalSpacer;
    QLineEdit *snapshotPath;
    QCheckBox *snapshotClipboardCKB;
    QCheckBox *simuSW;

    void setupUi(QDialog *AppPreferencesDialog)
    {
        if (AppPreferencesDialog->objectName().isEmpty())
            AppPreferencesDialog->setObjectName(QString::fromUtf8("AppPreferencesDialog"));
        AppPreferencesDialog->resize(685, 550);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AppPreferencesDialog->sizePolicy().hasHeightForWidth());
        AppPreferencesDialog->setSizePolicy(sizePolicy);
        AppPreferencesDialog->setMinimumSize(QSize(685, 0));
        gridLayout = new QGridLayout(AppPreferencesDialog);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        buttonBox = new QDialogButtonBox(AppPreferencesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        tabWidget = new QTabWidget(AppPreferencesDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        profileTab = new QWidget();
        profileTab->setObjectName(QString::fromUtf8("profileTab"));
        gridLayout_2 = new QGridLayout(profileTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sdPathButton = new QPushButton(profileTab);
        sdPathButton->setObjectName(QString::fromUtf8("sdPathButton"));

        gridLayout_2->addWidget(sdPathButton, 21, 7, 1, 1);

        label_13 = new QLabel(profileTab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 25, 0, 1, 1);

        label_6 = new QLabel(profileTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(label_6, 9, 0, 1, 1);

        langLabel = new QLabel(profileTab);
        langLabel->setObjectName(QString::fromUtf8("langLabel"));
        langLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(langLabel, 7, 0, 1, 1);

        label_14 = new QLabel(profileTab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_14, 23, 0, 1, 1);

        SplashSelect = new QPushButton(profileTab);
        SplashSelect->setObjectName(QString::fromUtf8("SplashSelect"));

        gridLayout_2->addWidget(SplashSelect, 14, 7, 1, 1);

        lblGeneralSettings = new QLabel(profileTab);
        lblGeneralSettings->setObjectName(QString::fromUtf8("lblGeneralSettings"));
        lblGeneralSettings->setEnabled(true);
        lblGeneralSettings->setText(QString::fromUtf8("General Settings Label"));

        gridLayout_2->addWidget(lblGeneralSettings, 22, 1, 1, 1);

        line_7 = new QFrame(profileTab);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_7, 10, 0, 1, 8);

        optionsLayout = new QGridLayout();
        optionsLayout->setObjectName(QString::fromUtf8("optionsLayout"));

        gridLayout_2->addLayout(optionsLayout, 9, 1, 1, 7);

        label_8 = new QLabel(profileTab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 14, 0, 1, 1);

        label_2 = new QLabel(profileTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        clearImageButton = new QPushButton(profileTab);
        clearImageButton->setObjectName(QString::fromUtf8("clearImageButton"));

        gridLayout_2->addWidget(clearImageButton, 17, 7, 1, 1);

        imageLabel = new QLabel(profileTab);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);
        imageLabel->setMinimumSize(QSize(128, 64));
        imageLabel->setMaximumSize(QSize(212, 64));
        imageLabel->setFrameShape(QFrame::Panel);
        imageLabel->setFrameShadow(QFrame::Plain);
        imageLabel->setLineWidth(1);
        imageLabel->setScaledContents(true);

        gridLayout_2->addWidget(imageLabel, 17, 1, 1, 1);

        label_7 = new QLabel(profileTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 5, 0, 1, 1);

        line_6 = new QFrame(profileTab);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_6, 19, 0, 1, 8);

        line_8 = new QFrame(profileTab);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_8, 2, 0, 1, 8);

        label = new QLabel(profileTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 20, 0, 1, 1);

        label_4 = new QLabel(profileTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 22, 0, 1, 1);

        sdPathLabel = new QLabel(profileTab);
        sdPathLabel->setObjectName(QString::fromUtf8("sdPathLabel"));
        sizePolicy1.setHeightForWidth(sdPathLabel->sizePolicy().hasHeightForWidth());
        sdPathLabel->setSizePolicy(sizePolicy1);
        sdPathLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(sdPathLabel, 21, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        langCombo = new QComboBox(profileTab);
        langCombo->setObjectName(QString::fromUtf8("langCombo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(langCombo->sizePolicy().hasHeightForWidth());
        langCombo->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(langCombo);

        voiceLabel = new QLabel(profileTab);
        voiceLabel->setObjectName(QString::fromUtf8("voiceLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(voiceLabel->sizePolicy().hasHeightForWidth());
        voiceLabel->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans Serif"));
        font2.setBold(false);
        font2.setWeight(50);
        voiceLabel->setFont(font2);
        voiceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(voiceLabel);

        voiceCombo = new QComboBox(profileTab);
        voiceCombo->setObjectName(QString::fromUtf8("voiceCombo"));
        sizePolicy3.setHeightForWidth(voiceCombo->sizePolicy().hasHeightForWidth());
        voiceCombo->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(voiceCombo);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout, 7, 1, 1, 7);

        downloadVerCB = new QComboBox(profileTab);
        downloadVerCB->setObjectName(QString::fromUtf8("downloadVerCB"));
        downloadVerCB->setEnabled(true);

        gridLayout_2->addWidget(downloadVerCB, 5, 1, 1, 7);

        SplashFileName = new QLineEdit(profileTab);
        SplashFileName->setObjectName(QString::fromUtf8("SplashFileName"));
        SplashFileName->setEnabled(true);
        SplashFileName->setReadOnly(true);

        gridLayout_2->addWidget(SplashFileName, 14, 1, 1, 6);

        sdPath = new QLineEdit(profileTab);
        sdPath->setObjectName(QString::fromUtf8("sdPath"));
        sdPath->setEnabled(true);
        sdPath->setReadOnly(true);

        gridLayout_2->addWidget(sdPath, 21, 1, 1, 6);

        stickmodeCB = new QComboBox(profileTab);
        stickmodeCB->setObjectName(QString::fromUtf8("stickmodeCB"));
        stickmodeCB->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(stickmodeCB, 23, 1, 1, 6);

        channelorderCB = new QComboBox(profileTab);
        channelorderCB->setObjectName(QString::fromUtf8("channelorderCB"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(channelorderCB->sizePolicy().hasHeightForWidth());
        channelorderCB->setSizePolicy(sizePolicy5);
        channelorderCB->setMinimumSize(QSize(0, 0));
        channelorderCB->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(channelorderCB, 25, 1, 1, 6);

        profileNameLE = new QLineEdit(profileTab);
        profileNameLE->setObjectName(QString::fromUtf8("profileNameLE"));

        gridLayout_2->addWidget(profileNameLE, 1, 1, 1, 6);

        removeProfileButton = new QPushButton(profileTab);
        removeProfileButton->setObjectName(QString::fromUtf8("removeProfileButton"));

        gridLayout_2->addWidget(removeProfileButton, 1, 7, 1, 1);

        renameFirmware = new QCheckBox(profileTab);
        renameFirmware->setObjectName(QString::fromUtf8("renameFirmware"));

        gridLayout_2->addWidget(renameFirmware, 26, 1, 1, 7);

        burnFirmware = new QCheckBox(profileTab);
        burnFirmware->setObjectName(QString::fromUtf8("burnFirmware"));

        gridLayout_2->addWidget(burnFirmware, 27, 1, 1, 7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 28, 1, 1, 1);

        gridLayout_2->setColumnStretch(2, 1);
        tabWidget->addTab(profileTab, QString());
        applicationTab = new QWidget();
        applicationTab->setObjectName(QString::fromUtf8("applicationTab"));
        gridLayout_3 = new QGridLayout(applicationTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        showSplash = new QCheckBox(applicationTab);
        showSplash->setObjectName(QString::fromUtf8("showSplash"));
        showSplash->setChecked(true);

        gridLayout_3->addWidget(showSplash, 4, 1, 1, 4);

        startupCheck_companion9x = new QCheckBox(applicationTab);
        startupCheck_companion9x->setObjectName(QString::fromUtf8("startupCheck_companion9x"));
        startupCheck_companion9x->setChecked(true);

        gridLayout_3->addWidget(startupCheck_companion9x, 7, 1, 1, 4);

        backupEnable = new QCheckBox(applicationTab);
        backupEnable->setObjectName(QString::fromUtf8("backupEnable"));

        gridLayout_3->addWidget(backupEnable, 10, 1, 1, 4);

        line = new QFrame(applicationTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 3, 1, 1, 4);

        line_2 = new QFrame(applicationTab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 8, 1, 1, 4);

        startupCheck_fw = new QCheckBox(applicationTab);
        startupCheck_fw->setObjectName(QString::fromUtf8("startupCheck_fw"));
        startupCheck_fw->setChecked(true);

        gridLayout_3->addWidget(startupCheck_fw, 6, 1, 1, 4);

        libraryPath = new QLineEdit(applicationTab);
        libraryPath->setObjectName(QString::fromUtf8("libraryPath"));
        libraryPath->setEnabled(true);
        libraryPath->setReadOnly(true);

        gridLayout_3->addWidget(libraryPath, 13, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 15, 1, 1, 1);

        backupPathButton = new QPushButton(applicationTab);
        backupPathButton->setObjectName(QString::fromUtf8("backupPathButton"));

        gridLayout_3->addWidget(backupPathButton, 9, 4, 1, 1);

        label_10 = new QLabel(applicationTab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_10, 12, 0, 1, 1);

        label_5 = new QLabel(applicationTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        ge_pathButton = new QPushButton(applicationTab);
        ge_pathButton->setObjectName(QString::fromUtf8("ge_pathButton"));

        gridLayout_3->addWidget(ge_pathButton, 0, 4, 1, 1);

        line_4 = new QFrame(applicationTab);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_4, 1, 1, 1, 4);

        libraryPathButton = new QPushButton(applicationTab);
        libraryPathButton->setObjectName(QString::fromUtf8("libraryPathButton"));

        gridLayout_3->addWidget(libraryPathButton, 13, 4, 1, 1);

        backupPath = new QLineEdit(applicationTab);
        backupPath->setObjectName(QString::fromUtf8("backupPath"));
        backupPath->setMinimumSize(QSize(350, 0));
        backupPath->setReadOnly(true);

        gridLayout_3->addWidget(backupPath, 9, 1, 1, 1);

        ge_label = new QLabel(applicationTab);
        ge_label->setObjectName(QString::fromUtf8("ge_label"));

        gridLayout_3->addWidget(ge_label, 0, 0, 1, 1);

        splashincludeCB = new QComboBox(applicationTab);
        splashincludeCB->setObjectName(QString::fromUtf8("splashincludeCB"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(splashincludeCB->sizePolicy().hasHeightForWidth());
        splashincludeCB->setSizePolicy(sizePolicy6);

        gridLayout_3->addWidget(splashincludeCB, 12, 1, 1, 1);

        label_9 = new QLabel(applicationTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_9, 13, 0, 1, 1);

        historySize = new QSpinBox(applicationTab);
        historySize->setObjectName(QString::fromUtf8("historySize"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(40);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(historySize->sizePolicy().hasHeightForWidth());
        historySize->setSizePolicy(sizePolicy7);
        historySize->setMaximumSize(QSize(50, 16777215));
        historySize->setMaximum(15);
        historySize->setValue(10);

        gridLayout_3->addWidget(historySize, 2, 1, 1, 1);

        label_17 = new QLabel(applicationTab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 9, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        ge_lineedit = new QLineEdit(applicationTab);
        ge_lineedit->setObjectName(QString::fromUtf8("ge_lineedit"));
        ge_lineedit->setMinimumSize(QSize(350, 0));
        ge_lineedit->setReadOnly(true);

        gridLayout_3->addWidget(ge_lineedit, 0, 1, 1, 1);

        line_5 = new QFrame(applicationTab);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_5, 11, 1, 1, 4);

        modelWizard_CB = new QCheckBox(applicationTab);
        modelWizard_CB->setObjectName(QString::fromUtf8("modelWizard_CB"));

        gridLayout_3->addWidget(modelWizard_CB, 5, 1, 1, 4);

        tabWidget->addTab(applicationTab, QString());
        simulatorTab = new QWidget();
        simulatorTab->setObjectName(QString::fromUtf8("simulatorTab"));
        gridLayout_4 = new QGridLayout(simulatorTab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(simulatorTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        joystickChkB = new QCheckBox(simulatorTab);
        joystickChkB->setObjectName(QString::fromUtf8("joystickChkB"));

        gridLayout_4->addWidget(joystickChkB, 5, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        snapshotPathButton = new QPushButton(simulatorTab);
        snapshotPathButton->setObjectName(QString::fromUtf8("snapshotPathButton"));
        snapshotPathButton->setFlat(false);

        gridLayout_4->addWidget(snapshotPathButton, 0, 4, 1, 1);

        backLightColor = new QComboBox(simulatorTab);
        backLightColor->setObjectName(QString::fromUtf8("backLightColor"));
        backLightColor->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(backLightColor, 3, 1, 1, 1);

        label_11 = new QLabel(simulatorTab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy8);

        gridLayout_4->addWidget(label_11, 5, 0, 1, 1);

        joystickCB = new QComboBox(simulatorTab);
        joystickCB->setObjectName(QString::fromUtf8("joystickCB"));
        sizePolicy5.setHeightForWidth(joystickCB->sizePolicy().hasHeightForWidth());
        joystickCB->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(joystickCB, 5, 1, 1, 1);

        joystickcalButton = new QPushButton(simulatorTab);
        joystickcalButton->setObjectName(QString::fromUtf8("joystickcalButton"));

        gridLayout_4->addWidget(joystickcalButton, 5, 4, 1, 1);

        label_19 = new QLabel(simulatorTab);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 6, 1, 1, 1);

        snapshotPath = new QLineEdit(simulatorTab);
        snapshotPath->setObjectName(QString::fromUtf8("snapshotPath"));
        snapshotPath->setEnabled(true);
        snapshotPath->setMinimumSize(QSize(350, 0));
        snapshotPath->setReadOnly(true);

        gridLayout_4->addWidget(snapshotPath, 0, 1, 1, 2);

        snapshotClipboardCKB = new QCheckBox(simulatorTab);
        snapshotClipboardCKB->setObjectName(QString::fromUtf8("snapshotClipboardCKB"));

        gridLayout_4->addWidget(snapshotClipboardCKB, 1, 1, 1, 4);

        simuSW = new QCheckBox(simulatorTab);
        simuSW->setObjectName(QString::fromUtf8("simuSW"));

        gridLayout_4->addWidget(simuSW, 2, 1, 1, 4);

        tabWidget->addTab(simulatorTab, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 1);

        QWidget::setTabOrder(tabWidget, profileNameLE);
        QWidget::setTabOrder(profileNameLE, removeProfileButton);
        QWidget::setTabOrder(removeProfileButton, downloadVerCB);
        QWidget::setTabOrder(downloadVerCB, langCombo);
        QWidget::setTabOrder(langCombo, voiceCombo);
        QWidget::setTabOrder(voiceCombo, SplashFileName);
        QWidget::setTabOrder(SplashFileName, SplashSelect);
        QWidget::setTabOrder(SplashSelect, clearImageButton);
        QWidget::setTabOrder(clearImageButton, sdPath);
        QWidget::setTabOrder(sdPath, sdPathButton);
        QWidget::setTabOrder(sdPathButton, stickmodeCB);
        QWidget::setTabOrder(stickmodeCB, channelorderCB);
        QWidget::setTabOrder(channelorderCB, renameFirmware);
        QWidget::setTabOrder(renameFirmware, burnFirmware);
        QWidget::setTabOrder(burnFirmware, ge_lineedit);
        QWidget::setTabOrder(ge_lineedit, ge_pathButton);
        QWidget::setTabOrder(ge_pathButton, historySize);
        QWidget::setTabOrder(historySize, showSplash);
        QWidget::setTabOrder(showSplash, modelWizard_CB);
        QWidget::setTabOrder(modelWizard_CB, startupCheck_fw);
        QWidget::setTabOrder(startupCheck_fw, startupCheck_companion9x);
        QWidget::setTabOrder(startupCheck_companion9x, backupPath);
        QWidget::setTabOrder(backupPath, backupPathButton);
        QWidget::setTabOrder(backupPathButton, backupEnable);
        QWidget::setTabOrder(backupEnable, splashincludeCB);
        QWidget::setTabOrder(splashincludeCB, libraryPath);
        QWidget::setTabOrder(libraryPath, libraryPathButton);
        QWidget::setTabOrder(libraryPathButton, snapshotPath);
        QWidget::setTabOrder(snapshotPath, snapshotPathButton);
        QWidget::setTabOrder(snapshotPathButton, snapshotClipboardCKB);
        QWidget::setTabOrder(snapshotClipboardCKB, simuSW);
        QWidget::setTabOrder(simuSW, backLightColor);
        QWidget::setTabOrder(backLightColor, joystickCB);
        QWidget::setTabOrder(joystickCB, joystickChkB);
        QWidget::setTabOrder(joystickChkB, joystickcalButton);
        QWidget::setTabOrder(joystickcalButton, buttonBox);

        retranslateUi(AppPreferencesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AppPreferencesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AppPreferencesDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);
        stickmodeCB->setCurrentIndex(1);
        channelorderCB->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AppPreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *AppPreferencesDialog)
    {
        AppPreferencesDialog->setWindowTitle(QApplication::translate("AppPreferencesDialog", "Edit Settings", 0, QApplication::UnicodeUTF8));
        sdPathButton->setText(QApplication::translate("AppPreferencesDialog", "Open Folder", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("AppPreferencesDialog", "Default Channel Order", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AppPreferencesDialog", "Build Options", 0, QApplication::UnicodeUTF8));
        langLabel->setText(QApplication::translate("AppPreferencesDialog", "Menu Language", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("AppPreferencesDialog", "Default Stick Mode", 0, QApplication::UnicodeUTF8));
        SplashSelect->setText(QApplication::translate("AppPreferencesDialog", "Select Image", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AppPreferencesDialog", "Splash Screen", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AppPreferencesDialog", "Profile Name", 0, QApplication::UnicodeUTF8));
        clearImageButton->setText(QApplication::translate("AppPreferencesDialog", "Clear Image", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        label_7->setText(QApplication::translate("AppPreferencesDialog", "Radio Type", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AppPreferencesDialog", "Other Settings", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AppPreferencesDialog", "General Settings", 0, QApplication::UnicodeUTF8));
        sdPathLabel->setText(QApplication::translate("AppPreferencesDialog", "SD Structure path", 0, QApplication::UnicodeUTF8));
        voiceLabel->setText(QApplication::translate("AppPreferencesDialog", "Voice Language", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        voiceCombo->setToolTip(QApplication::translate("AppPreferencesDialog", "Set voice language.\n"
"May be different from firmware language", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        stickmodeCB->clear();
        stickmodeCB->insertItems(0, QStringList()
         << QApplication::translate("AppPreferencesDialog", "Mode 1 (RUD ELE THR AIL)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Mode 2 (RUD THR ELE AIL)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Mode 3 (AIL ELE THR RUD)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Mode 4 (AIL THR ELE RUD)", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        stickmodeCB->setWhatsThis(QApplication::translate("AppPreferencesDialog", "Mode selection:\n"
"\n"
"Mode 1:\n"
"  Left stick:  Elevator, Rudder\n"
"  Right stick:  Throttle, Aileron\n"
"\n"
"Mode 2:\n"
"  Left stick:  Throttle, Rudder\n"
"  Right stick:  Elevator, Aileron\n"
"\n"
"Mode 3:\n"
"  Left stick:  Elevator, Aileron\n"
"  Right stick:  Throttle, Rudder\n"
"\n"
"Mode 4:\n"
"  Left stick:  Throttle, Aileron\n"
"  Right stick:  Elevator, Rudder\n"
"\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        channelorderCB->clear();
        channelorderCB->insertItems(0, QStringList()
         << QApplication::translate("AppPreferencesDialog", "R E T A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "R E A T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "R T E A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "R T A E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "R A E T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "R A T E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "E R T A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "E R A T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "E T R A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "E T A R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "E A R T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "E A T R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "T R E A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "T R A E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "T E R A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "T E A R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "T A R E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "T A E R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "A R E T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "A R T E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "A E R T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "A E T R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "A T R E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "A T E R", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        channelorderCB->setWhatsThis(QApplication::translate("AppPreferencesDialog", "<html><head/><body><p>Channel order</p><p><br/></p><p>Defines the order of the default mixes created on a new model.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        removeProfileButton->setText(QApplication::translate("AppPreferencesDialog", "Remove Profile", 0, QApplication::UnicodeUTF8));
        renameFirmware->setText(QApplication::translate("AppPreferencesDialog", "Append version number to FW file name", 0, QApplication::UnicodeUTF8));
        burnFirmware->setText(QApplication::translate("AppPreferencesDialog", "Offer to write FW to Tx after download", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(profileTab), QApplication::translate("AppPreferencesDialog", "Radio Profile", 0, QApplication::UnicodeUTF8));
        showSplash->setText(QApplication::translate("AppPreferencesDialog", "Show splash screen when Companion starts", 0, QApplication::UnicodeUTF8));
        startupCheck_companion9x->setText(QApplication::translate("AppPreferencesDialog", "Automatic check for Companion updates", 0, QApplication::UnicodeUTF8));
        backupEnable->setText(QApplication::translate("AppPreferencesDialog", "Enable automatic backup before writing firmware", 0, QApplication::UnicodeUTF8));
        startupCheck_fw->setText(QApplication::translate("AppPreferencesDialog", "Automatic check for OpenTX firmware updates", 0, QApplication::UnicodeUTF8));
        backupPathButton->setText(QApplication::translate("AppPreferencesDialog", "Open Folder", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("AppPreferencesDialog", "Splash Screen Library", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AppPreferencesDialog", "Files to keep", 0, QApplication::UnicodeUTF8));
        ge_pathButton->setText(QApplication::translate("AppPreferencesDialog", "Find Executable", 0, QApplication::UnicodeUTF8));
        libraryPathButton->setText(QApplication::translate("AppPreferencesDialog", "Open Folder", 0, QApplication::UnicodeUTF8));
        ge_label->setText(QApplication::translate("AppPreferencesDialog", "Google Earth Executable", 0, QApplication::UnicodeUTF8));
        splashincludeCB->clear();
        splashincludeCB->insertItems(0, QStringList()
         << QApplication::translate("AppPreferencesDialog", "Only show user splash images", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Show user and companion splash images", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("AppPreferencesDialog", "User Splash Screens", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("AppPreferencesDialog", "Automatic Backup Folder", 0, QApplication::UnicodeUTF8));
        modelWizard_CB->setText(QApplication::translate("AppPreferencesDialog", "Use model wizard when creating a new model", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(applicationTab), QApplication::translate("AppPreferencesDialog", "Application Settings", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AppPreferencesDialog", "Simulator BackLight", 0, QApplication::UnicodeUTF8));
        joystickChkB->setText(QApplication::translate("AppPreferencesDialog", "Enable", 0, QApplication::UnicodeUTF8));
        snapshotPathButton->setText(QApplication::translate("AppPreferencesDialog", "Open Folder", 0, QApplication::UnicodeUTF8));
        backLightColor->clear();
        backLightColor->insertItems(0, QStringList()
         << QApplication::translate("AppPreferencesDialog", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Orange", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppPreferencesDialog", "Yellow", 0, QApplication::UnicodeUTF8)
        );
        label_11->setText(QApplication::translate("AppPreferencesDialog", "Joystick", 0, QApplication::UnicodeUTF8));
        joystickcalButton->setText(QApplication::translate("AppPreferencesDialog", "Calibrate", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("AppPreferencesDialog", "Simulator capture folder", 0, QApplication::UnicodeUTF8));
        snapshotClipboardCKB->setText(QApplication::translate("AppPreferencesDialog", "Only capture to clipboard", 0, QApplication::UnicodeUTF8));
        simuSW->setText(QApplication::translate("AppPreferencesDialog", "Remember simulator switch values", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(simulatorTab), QApplication::translate("AppPreferencesDialog", "Simulator Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AppPreferencesDialog: public Ui_AppPreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPPREFERENCESDIALOG_H
