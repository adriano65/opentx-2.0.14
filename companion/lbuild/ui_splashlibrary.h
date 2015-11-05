/********************************************************************************
** Form generated from reading UI file 'splashlibrary.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHLIBRARY_H
#define UI_SPLASHLIBRARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <splashlabel.h>

QT_BEGIN_NAMESPACE

class Ui_splashLibrary
{
public:
    QGridLayout *gridLayout_2;
    QToolButton *prevPage;
    QGridLayout *gridLayout;
    splashLabel *FwImage_01;
    splashLabel *FwImage_02;
    splashLabel *FwImage_04;
    splashLabel *FwImage_05;
    splashLabel *FwImage_06;
    splashLabel *FwImage_07;
    splashLabel *FwImage_08;
    splashLabel *FwImage_09;
    splashLabel *FwImage_10;
    splashLabel *FwImage_11;
    splashLabel *FwImage_12;
    splashLabel *FwImage_13;
    splashLabel *FwImage_14;
    splashLabel *FwImage_15;
    splashLabel *FwImage_16;
    splashLabel *FwImage_17;
    splashLabel *FwImage_18;
    splashLabel *FwImage_19;
    splashLabel *FwImage_20;
    splashLabel *FwImage_03;
    QToolButton *nextPage;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *splashLibrary)
    {
        if (splashLibrary->objectName().isEmpty())
            splashLibrary->setObjectName(QString::fromUtf8("splashLibrary"));
        splashLibrary->resize(650, 374);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splashLibrary->sizePolicy().hasHeightForWidth());
        splashLibrary->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(splashLibrary);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        prevPage = new QToolButton(splashLibrary);
        prevPage->setObjectName(QString::fromUtf8("prevPage"));
        prevPage->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(prevPage->sizePolicy().hasHeightForWidth());
        prevPage->setSizePolicy(sizePolicy1);
        prevPage->setMinimumSize(QSize(34, 0));
        prevPage->setMaximumSize(QSize(34, 16777215));
        prevPage->setIconSize(QSize(50, 50));

        gridLayout_2->addWidget(prevPage, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        FwImage_01 = new splashLabel(splashLibrary);
        FwImage_01->setObjectName(QString::fromUtf8("FwImage_01"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FwImage_01->sizePolicy().hasHeightForWidth());
        FwImage_01->setSizePolicy(sizePolicy2);
        FwImage_01->setMinimumSize(QSize(130, 66));
        FwImage_01->setMaximumSize(QSize(214, 66));
        FwImage_01->setMouseTracking(true);
        FwImage_01->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_01->setFrameShape(QFrame::Panel);
        FwImage_01->setFrameShadow(QFrame::Raised);
        FwImage_01->setLineWidth(0);
        FwImage_01->setMidLineWidth(0);
        FwImage_01->setScaledContents(true);

        gridLayout->addWidget(FwImage_01, 0, 0, 1, 1);

        FwImage_02 = new splashLabel(splashLibrary);
        FwImage_02->setObjectName(QString::fromUtf8("FwImage_02"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(FwImage_02->sizePolicy().hasHeightForWidth());
        FwImage_02->setSizePolicy(sizePolicy3);
        FwImage_02->setMinimumSize(QSize(130, 0));
        FwImage_02->setMaximumSize(QSize(214, 66));
        FwImage_02->setMouseTracking(true);
        FwImage_02->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_02->setFrameShape(QFrame::Panel);
        FwImage_02->setFrameShadow(QFrame::Plain);
        FwImage_02->setLineWidth(0);
        FwImage_02->setScaledContents(true);

        gridLayout->addWidget(FwImage_02, 0, 1, 1, 1);

        FwImage_04 = new splashLabel(splashLibrary);
        FwImage_04->setObjectName(QString::fromUtf8("FwImage_04"));
        sizePolicy3.setHeightForWidth(FwImage_04->sizePolicy().hasHeightForWidth());
        FwImage_04->setSizePolicy(sizePolicy3);
        FwImage_04->setMinimumSize(QSize(130, 0));
        FwImage_04->setMaximumSize(QSize(214, 66));
        FwImage_04->setMouseTracking(true);
        FwImage_04->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_04->setFrameShape(QFrame::Panel);
        FwImage_04->setFrameShadow(QFrame::Plain);
        FwImage_04->setLineWidth(0);
        FwImage_04->setScaledContents(true);

        gridLayout->addWidget(FwImage_04, 0, 3, 1, 1);

        FwImage_05 = new splashLabel(splashLibrary);
        FwImage_05->setObjectName(QString::fromUtf8("FwImage_05"));
        sizePolicy2.setHeightForWidth(FwImage_05->sizePolicy().hasHeightForWidth());
        FwImage_05->setSizePolicy(sizePolicy2);
        FwImage_05->setMinimumSize(QSize(0, 66));
        FwImage_05->setMaximumSize(QSize(214, 66));
        FwImage_05->setMouseTracking(true);
        FwImage_05->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_05->setFrameShape(QFrame::Panel);
        FwImage_05->setFrameShadow(QFrame::Plain);
        FwImage_05->setLineWidth(0);
        FwImage_05->setScaledContents(true);

        gridLayout->addWidget(FwImage_05, 1, 0, 1, 1);

        FwImage_06 = new splashLabel(splashLibrary);
        FwImage_06->setObjectName(QString::fromUtf8("FwImage_06"));
        sizePolicy3.setHeightForWidth(FwImage_06->sizePolicy().hasHeightForWidth());
        FwImage_06->setSizePolicy(sizePolicy3);
        FwImage_06->setMaximumSize(QSize(214, 66));
        FwImage_06->setMouseTracking(true);
        FwImage_06->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_06->setFrameShape(QFrame::Panel);
        FwImage_06->setFrameShadow(QFrame::Plain);
        FwImage_06->setLineWidth(0);
        FwImage_06->setScaledContents(true);

        gridLayout->addWidget(FwImage_06, 1, 1, 1, 1);

        FwImage_07 = new splashLabel(splashLibrary);
        FwImage_07->setObjectName(QString::fromUtf8("FwImage_07"));
        sizePolicy3.setHeightForWidth(FwImage_07->sizePolicy().hasHeightForWidth());
        FwImage_07->setSizePolicy(sizePolicy3);
        FwImage_07->setMaximumSize(QSize(214, 66));
        FwImage_07->setMouseTracking(true);
        FwImage_07->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_07->setFrameShape(QFrame::Panel);
        FwImage_07->setFrameShadow(QFrame::Plain);
        FwImage_07->setLineWidth(0);
        FwImage_07->setScaledContents(true);

        gridLayout->addWidget(FwImage_07, 1, 2, 1, 1);

        FwImage_08 = new splashLabel(splashLibrary);
        FwImage_08->setObjectName(QString::fromUtf8("FwImage_08"));
        sizePolicy3.setHeightForWidth(FwImage_08->sizePolicy().hasHeightForWidth());
        FwImage_08->setSizePolicy(sizePolicy3);
        FwImage_08->setMaximumSize(QSize(214, 66));
        FwImage_08->setMouseTracking(true);
        FwImage_08->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_08->setFrameShape(QFrame::Panel);
        FwImage_08->setFrameShadow(QFrame::Plain);
        FwImage_08->setLineWidth(0);
        FwImage_08->setScaledContents(true);

        gridLayout->addWidget(FwImage_08, 1, 3, 1, 1);

        FwImage_09 = new splashLabel(splashLibrary);
        FwImage_09->setObjectName(QString::fromUtf8("FwImage_09"));
        sizePolicy2.setHeightForWidth(FwImage_09->sizePolicy().hasHeightForWidth());
        FwImage_09->setSizePolicy(sizePolicy2);
        FwImage_09->setMinimumSize(QSize(0, 66));
        FwImage_09->setMaximumSize(QSize(214, 66));
        FwImage_09->setMouseTracking(true);
        FwImage_09->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_09->setFrameShape(QFrame::Panel);
        FwImage_09->setFrameShadow(QFrame::Plain);
        FwImage_09->setLineWidth(0);
        FwImage_09->setScaledContents(true);

        gridLayout->addWidget(FwImage_09, 2, 0, 1, 1);

        FwImage_10 = new splashLabel(splashLibrary);
        FwImage_10->setObjectName(QString::fromUtf8("FwImage_10"));
        sizePolicy3.setHeightForWidth(FwImage_10->sizePolicy().hasHeightForWidth());
        FwImage_10->setSizePolicy(sizePolicy3);
        FwImage_10->setMaximumSize(QSize(214, 66));
        FwImage_10->setMouseTracking(true);
        FwImage_10->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_10->setFrameShape(QFrame::Panel);
        FwImage_10->setFrameShadow(QFrame::Plain);
        FwImage_10->setLineWidth(0);
        FwImage_10->setScaledContents(true);

        gridLayout->addWidget(FwImage_10, 2, 1, 1, 1);

        FwImage_11 = new splashLabel(splashLibrary);
        FwImage_11->setObjectName(QString::fromUtf8("FwImage_11"));
        sizePolicy3.setHeightForWidth(FwImage_11->sizePolicy().hasHeightForWidth());
        FwImage_11->setSizePolicy(sizePolicy3);
        FwImage_11->setMaximumSize(QSize(214, 66));
        FwImage_11->setMouseTracking(true);
        FwImage_11->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_11->setFrameShape(QFrame::Panel);
        FwImage_11->setFrameShadow(QFrame::Plain);
        FwImage_11->setLineWidth(0);
        FwImage_11->setScaledContents(true);

        gridLayout->addWidget(FwImage_11, 2, 2, 1, 1);

        FwImage_12 = new splashLabel(splashLibrary);
        FwImage_12->setObjectName(QString::fromUtf8("FwImage_12"));
        sizePolicy3.setHeightForWidth(FwImage_12->sizePolicy().hasHeightForWidth());
        FwImage_12->setSizePolicy(sizePolicy3);
        FwImage_12->setMaximumSize(QSize(214, 66));
        FwImage_12->setMouseTracking(true);
        FwImage_12->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_12->setFrameShape(QFrame::Panel);
        FwImage_12->setFrameShadow(QFrame::Plain);
        FwImage_12->setLineWidth(0);
        FwImage_12->setScaledContents(true);

        gridLayout->addWidget(FwImage_12, 2, 3, 1, 1);

        FwImage_13 = new splashLabel(splashLibrary);
        FwImage_13->setObjectName(QString::fromUtf8("FwImage_13"));
        sizePolicy2.setHeightForWidth(FwImage_13->sizePolicy().hasHeightForWidth());
        FwImage_13->setSizePolicy(sizePolicy2);
        FwImage_13->setMinimumSize(QSize(0, 66));
        FwImage_13->setMaximumSize(QSize(214, 66));
        FwImage_13->setMouseTracking(true);
        FwImage_13->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_13->setFrameShape(QFrame::Panel);
        FwImage_13->setFrameShadow(QFrame::Plain);
        FwImage_13->setLineWidth(0);
        FwImage_13->setScaledContents(true);

        gridLayout->addWidget(FwImage_13, 3, 0, 1, 1);

        FwImage_14 = new splashLabel(splashLibrary);
        FwImage_14->setObjectName(QString::fromUtf8("FwImage_14"));
        sizePolicy3.setHeightForWidth(FwImage_14->sizePolicy().hasHeightForWidth());
        FwImage_14->setSizePolicy(sizePolicy3);
        FwImage_14->setMaximumSize(QSize(214, 66));
        FwImage_14->setMouseTracking(true);
        FwImage_14->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_14->setFrameShape(QFrame::Panel);
        FwImage_14->setFrameShadow(QFrame::Plain);
        FwImage_14->setLineWidth(0);
        FwImage_14->setScaledContents(true);

        gridLayout->addWidget(FwImage_14, 3, 1, 1, 1);

        FwImage_15 = new splashLabel(splashLibrary);
        FwImage_15->setObjectName(QString::fromUtf8("FwImage_15"));
        sizePolicy3.setHeightForWidth(FwImage_15->sizePolicy().hasHeightForWidth());
        FwImage_15->setSizePolicy(sizePolicy3);
        FwImage_15->setMaximumSize(QSize(214, 66));
        FwImage_15->setMouseTracking(true);
        FwImage_15->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_15->setFrameShape(QFrame::Panel);
        FwImage_15->setFrameShadow(QFrame::Plain);
        FwImage_15->setLineWidth(0);
        FwImage_15->setScaledContents(true);

        gridLayout->addWidget(FwImage_15, 3, 2, 1, 1);

        FwImage_16 = new splashLabel(splashLibrary);
        FwImage_16->setObjectName(QString::fromUtf8("FwImage_16"));
        sizePolicy3.setHeightForWidth(FwImage_16->sizePolicy().hasHeightForWidth());
        FwImage_16->setSizePolicy(sizePolicy3);
        FwImage_16->setMaximumSize(QSize(214, 66));
        FwImage_16->setMouseTracking(true);
        FwImage_16->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_16->setFrameShape(QFrame::Panel);
        FwImage_16->setFrameShadow(QFrame::Plain);
        FwImage_16->setLineWidth(0);
        FwImage_16->setScaledContents(true);

        gridLayout->addWidget(FwImage_16, 3, 3, 1, 1);

        FwImage_17 = new splashLabel(splashLibrary);
        FwImage_17->setObjectName(QString::fromUtf8("FwImage_17"));
        sizePolicy2.setHeightForWidth(FwImage_17->sizePolicy().hasHeightForWidth());
        FwImage_17->setSizePolicy(sizePolicy2);
        FwImage_17->setMinimumSize(QSize(0, 66));
        FwImage_17->setMaximumSize(QSize(214, 66));
        FwImage_17->setMouseTracking(true);
        FwImage_17->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_17->setFrameShape(QFrame::Panel);
        FwImage_17->setFrameShadow(QFrame::Plain);
        FwImage_17->setLineWidth(0);
        FwImage_17->setScaledContents(true);

        gridLayout->addWidget(FwImage_17, 4, 0, 1, 1);

        FwImage_18 = new splashLabel(splashLibrary);
        FwImage_18->setObjectName(QString::fromUtf8("FwImage_18"));
        sizePolicy3.setHeightForWidth(FwImage_18->sizePolicy().hasHeightForWidth());
        FwImage_18->setSizePolicy(sizePolicy3);
        FwImage_18->setMaximumSize(QSize(214, 66));
        FwImage_18->setMouseTracking(true);
        FwImage_18->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_18->setFrameShape(QFrame::Panel);
        FwImage_18->setFrameShadow(QFrame::Plain);
        FwImage_18->setLineWidth(0);
        FwImage_18->setScaledContents(true);

        gridLayout->addWidget(FwImage_18, 4, 1, 1, 1);

        FwImage_19 = new splashLabel(splashLibrary);
        FwImage_19->setObjectName(QString::fromUtf8("FwImage_19"));
        sizePolicy3.setHeightForWidth(FwImage_19->sizePolicy().hasHeightForWidth());
        FwImage_19->setSizePolicy(sizePolicy3);
        FwImage_19->setMaximumSize(QSize(214, 66));
        FwImage_19->setMouseTracking(true);
        FwImage_19->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_19->setFrameShape(QFrame::Panel);
        FwImage_19->setFrameShadow(QFrame::Plain);
        FwImage_19->setLineWidth(0);
        FwImage_19->setScaledContents(true);

        gridLayout->addWidget(FwImage_19, 4, 2, 1, 1);

        FwImage_20 = new splashLabel(splashLibrary);
        FwImage_20->setObjectName(QString::fromUtf8("FwImage_20"));
        sizePolicy3.setHeightForWidth(FwImage_20->sizePolicy().hasHeightForWidth());
        FwImage_20->setSizePolicy(sizePolicy3);
        FwImage_20->setMaximumSize(QSize(214, 66));
        FwImage_20->setMouseTracking(true);
        FwImage_20->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_20->setFrameShape(QFrame::Panel);
        FwImage_20->setFrameShadow(QFrame::Plain);
        FwImage_20->setLineWidth(0);
        FwImage_20->setScaledContents(true);

        gridLayout->addWidget(FwImage_20, 4, 3, 1, 1);

        FwImage_03 = new splashLabel(splashLibrary);
        FwImage_03->setObjectName(QString::fromUtf8("FwImage_03"));
        sizePolicy3.setHeightForWidth(FwImage_03->sizePolicy().hasHeightForWidth());
        FwImage_03->setSizePolicy(sizePolicy3);
        FwImage_03->setMinimumSize(QSize(130, 0));
        FwImage_03->setMaximumSize(QSize(214, 66));
        FwImage_03->setMouseTracking(true);
        FwImage_03->setStyleSheet(QString::fromUtf8("border:1px;"));
        FwImage_03->setFrameShape(QFrame::Panel);
        FwImage_03->setFrameShadow(QFrame::Plain);
        FwImage_03->setLineWidth(0);
        FwImage_03->setScaledContents(true);

        gridLayout->addWidget(FwImage_03, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 2, 1, 1);

        nextPage = new QToolButton(splashLibrary);
        nextPage->setObjectName(QString::fromUtf8("nextPage"));
        nextPage->setEnabled(false);
        sizePolicy1.setHeightForWidth(nextPage->sizePolicy().hasHeightForWidth());
        nextPage->setSizePolicy(sizePolicy1);
        nextPage->setMinimumSize(QSize(34, 0));
        nextPage->setMaximumSize(QSize(34, 16777215));
        nextPage->setIconSize(QSize(50, 50));

        gridLayout_2->addWidget(nextPage, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        retranslateUi(splashLibrary);

        QMetaObject::connectSlotsByName(splashLibrary);
    } // setupUi

    void retranslateUi(QDialog *splashLibrary)
    {
        splashLibrary->setWindowTitle(QString());
        prevPage->setText(QApplication::translate("splashLibrary", "...", 0, QApplication::UnicodeUTF8));
        FwImage_01->setText(QString());
        FwImage_02->setText(QString());
        FwImage_04->setText(QString());
        FwImage_05->setText(QString());
        FwImage_06->setText(QString());
        FwImage_07->setText(QString());
        FwImage_08->setText(QString());
        FwImage_09->setText(QString());
        FwImage_10->setText(QString());
        FwImage_11->setText(QString());
        FwImage_12->setText(QString());
        FwImage_13->setText(QString());
        FwImage_14->setText(QString());
        FwImage_15->setText(QString());
        FwImage_16->setText(QString());
        FwImage_17->setText(QString());
        FwImage_18->setText(QString());
        FwImage_19->setText(QString());
        FwImage_20->setText(QString());
        FwImage_03->setText(QString());
        nextPage->setText(QApplication::translate("splashLibrary", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class splashLibrary: public Ui_splashLibrary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHLIBRARY_H
