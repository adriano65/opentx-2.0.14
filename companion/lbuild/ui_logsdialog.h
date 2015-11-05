/********************************************************************************
** Form generated from reading UI file 'logsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGSDIALOG_H
#define UI_LOGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include "./qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_logsDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *FileName_LE;
    QPushButton *fileOpen_BT;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QCheckBox *ZoomX_ChkB;
    QCheckBox *ZoomY_ChkB;
    QPushButton *Reset_PB;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *sessions_CB;
    QSpacerItem *horizontalSpacer;
    QTableWidget *logTable;
    QTableWidget *FieldsTW;
    QPushButton *mapsButton;

    void setupUi(QDialog *logsDialog)
    {
        if (logsDialog->objectName().isEmpty())
            logsDialog->setObjectName(QString::fromUtf8("logsDialog"));
        logsDialog->resize(883, 653);
        logsDialog->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(logsDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(logsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        FileName_LE = new QLineEdit(logsDialog);
        FileName_LE->setObjectName(QString::fromUtf8("FileName_LE"));
        FileName_LE->setReadOnly(true);

        horizontalLayout->addWidget(FileName_LE);

        fileOpen_BT = new QPushButton(logsDialog);
        fileOpen_BT->setObjectName(QString::fromUtf8("fileOpen_BT"));

        horizontalLayout->addWidget(fileOpen_BT);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        frame_2 = new QFrame(logsDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(1);
        frame_2->setMidLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        customPlot = new QCustomPlot(frame_2);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(customPlot);


        gridLayout->addWidget(frame_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(logsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        ZoomX_ChkB = new QCheckBox(logsDialog);
        ZoomX_ChkB->setObjectName(QString::fromUtf8("ZoomX_ChkB"));

        horizontalLayout_3->addWidget(ZoomX_ChkB);

        ZoomY_ChkB = new QCheckBox(logsDialog);
        ZoomY_ChkB->setObjectName(QString::fromUtf8("ZoomY_ChkB"));

        horizontalLayout_3->addWidget(ZoomY_ChkB);

        Reset_PB = new QPushButton(logsDialog);
        Reset_PB->setObjectName(QString::fromUtf8("Reset_PB"));

        horizontalLayout_3->addWidget(Reset_PB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(logsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        sessions_CB = new QComboBox(logsDialog);
        sessions_CB->setObjectName(QString::fromUtf8("sessions_CB"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sessions_CB->sizePolicy().hasHeightForWidth());
        sessions_CB->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(sessions_CB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 3, 1, 1, 1);

        logTable = new QTableWidget(logsDialog);
        logTable->setObjectName(QString::fromUtf8("logTable"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(logTable->sizePolicy().hasHeightForWidth());
        logTable->setSizePolicy(sizePolicy3);
        logTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        logTable->setProperty("showDropIndicator", QVariant(false));
        logTable->setDragDropOverwriteMode(false);
        logTable->setAlternatingRowColors(true);
        logTable->setTextElideMode(Qt::ElideNone);
        logTable->setRowCount(0);
        logTable->setColumnCount(0);
        logTable->verticalHeader()->setVisible(false);
        logTable->verticalHeader()->setDefaultSectionSize(18);
        logTable->verticalHeader()->setHighlightSections(true);
        logTable->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(logTable, 4, 1, 4, 1);

        FieldsTW = new QTableWidget(logsDialog);
        FieldsTW->setObjectName(QString::fromUtf8("FieldsTW"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(FieldsTW->sizePolicy().hasHeightForWidth());
        FieldsTW->setSizePolicy(sizePolicy4);
        FieldsTW->setMaximumSize(QSize(120, 16777215));
        FieldsTW->setAutoScrollMargin(0);
        FieldsTW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FieldsTW->setShowGrid(false);
        FieldsTW->setSortingEnabled(false);
        FieldsTW->setColumnCount(0);
        FieldsTW->horizontalHeader()->setStretchLastSection(true);
        FieldsTW->verticalHeader()->setVisible(false);

        gridLayout->addWidget(FieldsTW, 1, 0, 6, 1);

        mapsButton = new QPushButton(logsDialog);
        mapsButton->setObjectName(QString::fromUtf8("mapsButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(mapsButton->sizePolicy().hasHeightForWidth());
        mapsButton->setSizePolicy(sizePolicy5);
        mapsButton->setMinimumSize(QSize(0, 0));
        mapsButton->setMaximumSize(QSize(120, 57));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/maps.png"), QSize(), QIcon::Normal, QIcon::Off);
        mapsButton->setIcon(icon);
        mapsButton->setIconSize(QSize(120, 57));

        gridLayout->addWidget(mapsButton, 7, 0, 1, 1);

        gridLayout->setRowStretch(1, 1);
        QWidget::setTabOrder(FileName_LE, fileOpen_BT);
        QWidget::setTabOrder(fileOpen_BT, FieldsTW);
        QWidget::setTabOrder(FieldsTW, ZoomX_ChkB);
        QWidget::setTabOrder(ZoomX_ChkB, ZoomY_ChkB);
        QWidget::setTabOrder(ZoomY_ChkB, Reset_PB);
        QWidget::setTabOrder(Reset_PB, sessions_CB);
        QWidget::setTabOrder(sessions_CB, logTable);
        QWidget::setTabOrder(logTable, mapsButton);

        retranslateUi(logsDialog);

        QMetaObject::connectSlotsByName(logsDialog);
    } // setupUi

    void retranslateUi(QDialog *logsDialog)
    {
        logsDialog->setWindowTitle(QApplication::translate("logsDialog", "Companion Log Viewer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("logsDialog", "Filename", 0, QApplication::UnicodeUTF8));
        fileOpen_BT->setText(QApplication::translate("logsDialog", "Open LogFile", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("logsDialog", "Zoom", 0, QApplication::UnicodeUTF8));
        ZoomX_ChkB->setText(QApplication::translate("logsDialog", "X", 0, QApplication::UnicodeUTF8));
        ZoomY_ChkB->setText(QApplication::translate("logsDialog", "Y", 0, QApplication::UnicodeUTF8));
        Reset_PB->setText(QApplication::translate("logsDialog", "Reset", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("logsDialog", "Fly sessions", 0, QApplication::UnicodeUTF8));
        mapsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class logsDialog: public Ui_logsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGSDIALOG_H
