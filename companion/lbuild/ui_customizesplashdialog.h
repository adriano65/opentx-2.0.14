/********************************************************************************
** Form generated from reading UI file 'customizesplashdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMIZESPLASHDIALOG_H
#define UI_CUSTOMIZESPLASHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_customizeSplashDialog
{
public:
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_6;
    QFrame *line_13;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *leftFileNameEdit;
    QSpacerItem *horizontalSpacer_12;
    QFrame *line_11;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_6;
    QLabel *leftImageLabel;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *leftInvertButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *leftLibraryButton;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *leftLoadProfileButton;
    QPushButton *leftLoadFwButton;
    QPushButton *leftLoadPictButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *leftSaveButton;
    QFrame *line_9;
    QFrame *line;
    QVBoxLayout *verticalLayout_7;
    QToolButton *copyRightToLeftButton;
    QToolButton *copyLeftToRightButton;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_8;
    QFrame *line_14;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *rightFileNameEdit;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line_12;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_8;
    QLabel *rightImageLabel;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *rightInvertButton;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *rightLibraryButton;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *rightLoadProfileButton;
    QPushButton *rightLoadFwButton;
    QPushButton *rightLoadPictButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *rightSaveButton;
    QFrame *line_10;
    QFrame *line_6;

    void setupUi(QDialog *customizeSplashDialog)
    {
        if (customizeSplashDialog->objectName().isEmpty())
            customizeSplashDialog->setObjectName(QString::fromUtf8("customizeSplashDialog"));
        customizeSplashDialog->setEnabled(true);
        customizeSplashDialog->resize(1087, 298);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customizeSplashDialog->sizePolicy().hasHeightForWidth());
        customizeSplashDialog->setSizePolicy(sizePolicy);
        horizontalLayout_13 = new QHBoxLayout(customizeSplashDialog);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(3, 0, 3, 3);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        line_3 = new QFrame(customizeSplashDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        line_13 = new QFrame(customizeSplashDialog);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        leftFileNameEdit = new QLineEdit(customizeSplashDialog);
        leftFileNameEdit->setObjectName(QString::fromUtf8("leftFileNameEdit"));
        leftFileNameEdit->setEnabled(true);
        leftFileNameEdit->setMinimumSize(QSize(424, 0));
        leftFileNameEdit->setMaximumSize(QSize(426, 16777215));
        leftFileNameEdit->setReadOnly(true);

        horizontalLayout_11->addWidget(leftFileNameEdit);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);


        verticalLayout_6->addLayout(horizontalLayout_11);

        line_11 = new QFrame(customizeSplashDialog);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        leftImageLabel = new QLabel(customizeSplashDialog);
        leftImageLabel->setObjectName(QString::fromUtf8("leftImageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftImageLabel->sizePolicy().hasHeightForWidth());
        leftImageLabel->setSizePolicy(sizePolicy1);
        leftImageLabel->setMinimumSize(QSize(424, 128));
        leftImageLabel->setMaximumSize(QSize(424, 128));
        leftImageLabel->setFrameShape(QFrame::Panel);
        leftImageLabel->setFrameShadow(QFrame::Plain);
        leftImageLabel->setLineWidth(0);
        leftImageLabel->setScaledContents(true);

        horizontalLayout_9->addWidget(leftImageLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_9);

        line_7 = new QFrame(customizeSplashDialog);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        leftInvertButton = new QPushButton(customizeSplashDialog);
        leftInvertButton->setObjectName(QString::fromUtf8("leftInvertButton"));
        leftInvertButton->setEnabled(false);

        horizontalLayout_4->addWidget(leftInvertButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        leftLibraryButton = new QToolButton(customizeSplashDialog);
        leftLibraryButton->setObjectName(QString::fromUtf8("leftLibraryButton"));
        leftLibraryButton->setEnabled(false);
        leftLibraryButton->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(leftLibraryButton);


        verticalLayout_6->addLayout(horizontalLayout_4);

        line_4 = new QFrame(customizeSplashDialog);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        leftLoadProfileButton = new QPushButton(customizeSplashDialog);
        leftLoadProfileButton->setObjectName(QString::fromUtf8("leftLoadProfileButton"));
        leftLoadProfileButton->setEnabled(true);
        leftLoadProfileButton->setCheckable(true);

        horizontalLayout_5->addWidget(leftLoadProfileButton);

        leftLoadFwButton = new QPushButton(customizeSplashDialog);
        leftLoadFwButton->setObjectName(QString::fromUtf8("leftLoadFwButton"));
        leftLoadFwButton->setCheckable(true);

        horizontalLayout_5->addWidget(leftLoadFwButton);

        leftLoadPictButton = new QPushButton(customizeSplashDialog);
        leftLoadPictButton->setObjectName(QString::fromUtf8("leftLoadPictButton"));
        leftLoadPictButton->setCheckable(true);

        horizontalLayout_5->addWidget(leftLoadPictButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        leftSaveButton = new QPushButton(customizeSplashDialog);
        leftSaveButton->setObjectName(QString::fromUtf8("leftSaveButton"));
        leftSaveButton->setEnabled(false);

        horizontalLayout_5->addWidget(leftSaveButton);


        verticalLayout_6->addLayout(horizontalLayout_5);

        line_9 = new QFrame(customizeSplashDialog);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_9);


        horizontalLayout_3->addLayout(verticalLayout_6);

        line = new QFrame(customizeSplashDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        copyRightToLeftButton = new QToolButton(customizeSplashDialog);
        copyRightToLeftButton->setObjectName(QString::fromUtf8("copyRightToLeftButton"));
        copyRightToLeftButton->setArrowType(Qt::LeftArrow);

        verticalLayout_7->addWidget(copyRightToLeftButton);

        copyLeftToRightButton = new QToolButton(customizeSplashDialog);
        copyLeftToRightButton->setObjectName(QString::fromUtf8("copyLeftToRightButton"));
        copyLeftToRightButton->setArrowType(Qt::RightArrow);

        verticalLayout_7->addWidget(copyLeftToRightButton);


        horizontalLayout_3->addLayout(verticalLayout_7);

        line_2 = new QFrame(customizeSplashDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        line_14 = new QFrame(customizeSplashDialog);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        rightFileNameEdit = new QLineEdit(customizeSplashDialog);
        rightFileNameEdit->setObjectName(QString::fromUtf8("rightFileNameEdit"));
        rightFileNameEdit->setEnabled(true);
        rightFileNameEdit->setMinimumSize(QSize(426, 0));
        rightFileNameEdit->setMaximumSize(QSize(424, 16777215));
        rightFileNameEdit->setReadOnly(true);

        horizontalLayout_12->addWidget(rightFileNameEdit);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);


        verticalLayout_8->addLayout(horizontalLayout_12);

        line_12 = new QFrame(customizeSplashDialog);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        rightImageLabel = new QLabel(customizeSplashDialog);
        rightImageLabel->setObjectName(QString::fromUtf8("rightImageLabel"));
        sizePolicy1.setHeightForWidth(rightImageLabel->sizePolicy().hasHeightForWidth());
        rightImageLabel->setSizePolicy(sizePolicy1);
        rightImageLabel->setMinimumSize(QSize(424, 128));
        rightImageLabel->setMaximumSize(QSize(424, 128));
        rightImageLabel->setFrameShape(QFrame::Panel);
        rightImageLabel->setFrameShadow(QFrame::Plain);
        rightImageLabel->setLineWidth(0);
        rightImageLabel->setScaledContents(true);

        horizontalLayout_10->addWidget(rightImageLabel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        verticalLayout_8->addLayout(horizontalLayout_10);

        line_8 = new QFrame(customizeSplashDialog);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rightInvertButton = new QPushButton(customizeSplashDialog);
        rightInvertButton->setObjectName(QString::fromUtf8("rightInvertButton"));
        rightInvertButton->setEnabled(false);

        horizontalLayout_6->addWidget(rightInvertButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        rightLibraryButton = new QToolButton(customizeSplashDialog);
        rightLibraryButton->setObjectName(QString::fromUtf8("rightLibraryButton"));
        rightLibraryButton->setEnabled(false);
        rightLibraryButton->setIconSize(QSize(24, 24));

        horizontalLayout_6->addWidget(rightLibraryButton);


        verticalLayout_8->addLayout(horizontalLayout_6);

        line_5 = new QFrame(customizeSplashDialog);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rightLoadProfileButton = new QPushButton(customizeSplashDialog);
        rightLoadProfileButton->setObjectName(QString::fromUtf8("rightLoadProfileButton"));
        rightLoadProfileButton->setEnabled(true);
        rightLoadProfileButton->setCheckable(true);

        horizontalLayout_7->addWidget(rightLoadProfileButton);

        rightLoadFwButton = new QPushButton(customizeSplashDialog);
        rightLoadFwButton->setObjectName(QString::fromUtf8("rightLoadFwButton"));
        rightLoadFwButton->setEnabled(true);
        rightLoadFwButton->setCheckable(true);

        horizontalLayout_7->addWidget(rightLoadFwButton);

        rightLoadPictButton = new QPushButton(customizeSplashDialog);
        rightLoadPictButton->setObjectName(QString::fromUtf8("rightLoadPictButton"));
        rightLoadPictButton->setCheckable(true);

        horizontalLayout_7->addWidget(rightLoadPictButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        rightSaveButton = new QPushButton(customizeSplashDialog);
        rightSaveButton->setObjectName(QString::fromUtf8("rightSaveButton"));
        rightSaveButton->setEnabled(false);

        horizontalLayout_7->addWidget(rightSaveButton);


        verticalLayout_8->addLayout(horizontalLayout_7);

        line_10 = new QFrame(customizeSplashDialog);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_10);


        horizontalLayout_3->addLayout(verticalLayout_8);

        line_6 = new QFrame(customizeSplashDialog);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);


        horizontalLayout_13->addLayout(horizontalLayout_3);

        QWidget::setTabOrder(leftFileNameEdit, leftInvertButton);
        QWidget::setTabOrder(leftInvertButton, leftLibraryButton);
        QWidget::setTabOrder(leftLibraryButton, leftLoadProfileButton);
        QWidget::setTabOrder(leftLoadProfileButton, leftLoadFwButton);
        QWidget::setTabOrder(leftLoadFwButton, leftLoadPictButton);
        QWidget::setTabOrder(leftLoadPictButton, leftSaveButton);
        QWidget::setTabOrder(leftSaveButton, copyLeftToRightButton);
        QWidget::setTabOrder(copyLeftToRightButton, copyRightToLeftButton);
        QWidget::setTabOrder(copyRightToLeftButton, rightFileNameEdit);
        QWidget::setTabOrder(rightFileNameEdit, rightInvertButton);
        QWidget::setTabOrder(rightInvertButton, rightLibraryButton);
        QWidget::setTabOrder(rightLibraryButton, rightLoadProfileButton);
        QWidget::setTabOrder(rightLoadProfileButton, rightLoadFwButton);
        QWidget::setTabOrder(rightLoadFwButton, rightLoadPictButton);
        QWidget::setTabOrder(rightLoadPictButton, rightSaveButton);

        retranslateUi(customizeSplashDialog);

        QMetaObject::connectSlotsByName(customizeSplashDialog);
    } // setupUi

    void retranslateUi(QDialog *customizeSplashDialog)
    {
        customizeSplashDialog->setWindowTitle(QApplication::translate("customizeSplashDialog", "Transmitter Splash Screen Editor", 0, QApplication::UnicodeUTF8));
        leftImageLabel->setText(QString());
        leftInvertButton->setText(QApplication::translate("customizeSplashDialog", "Invert", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leftLibraryButton->setToolTip(QApplication::translate("customizeSplashDialog", "Open Splash Library", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        leftLibraryButton->setText(QApplication::translate("customizeSplashDialog", "...", 0, QApplication::UnicodeUTF8));
        leftLoadProfileButton->setText(QApplication::translate("customizeSplashDialog", "Load Profile", 0, QApplication::UnicodeUTF8));
        leftLoadFwButton->setText(QApplication::translate("customizeSplashDialog", "Load FW", 0, QApplication::UnicodeUTF8));
        leftLoadPictButton->setText(QApplication::translate("customizeSplashDialog", "Load Pict", 0, QApplication::UnicodeUTF8));
        leftSaveButton->setText(QApplication::translate("customizeSplashDialog", "Save", 0, QApplication::UnicodeUTF8));
        copyRightToLeftButton->setText(QApplication::translate("customizeSplashDialog", "...", 0, QApplication::UnicodeUTF8));
        copyLeftToRightButton->setText(QApplication::translate("customizeSplashDialog", "...", 0, QApplication::UnicodeUTF8));
        rightImageLabel->setText(QString());
        rightInvertButton->setText(QApplication::translate("customizeSplashDialog", "Invert", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rightLibraryButton->setToolTip(QApplication::translate("customizeSplashDialog", "Open Splash Library", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        rightLibraryButton->setText(QApplication::translate("customizeSplashDialog", "...", 0, QApplication::UnicodeUTF8));
        rightLoadProfileButton->setText(QApplication::translate("customizeSplashDialog", "Load Profile", 0, QApplication::UnicodeUTF8));
        rightLoadFwButton->setText(QApplication::translate("customizeSplashDialog", "Load FW", 0, QApplication::UnicodeUTF8));
        rightLoadPictButton->setText(QApplication::translate("customizeSplashDialog", "Load Pict", 0, QApplication::UnicodeUTF8));
        rightSaveButton->setText(QApplication::translate("customizeSplashDialog", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class customizeSplashDialog: public Ui_customizeSplashDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMIZESPLASHDIALOG_H
