/********************************************************************************
** Form generated from reading UI file 'avroutputdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVROUTPUTDIALOG_H
#define UI_AVROUTPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_avrOutputDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QCheckBox *checkBox;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *avrOutputDialog)
    {
        if (avrOutputDialog->objectName().isEmpty())
            avrOutputDialog->setObjectName(QString::fromUtf8("avrOutputDialog"));
        avrOutputDialog->resize(700, 348);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(avrOutputDialog->sizePolicy().hasHeightForWidth());
        avrOutputDialog->setSizePolicy(sizePolicy);
        avrOutputDialog->setMinimumSize(QSize(700, 0));
        avrOutputDialog->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        avrOutputDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(avrOutputDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBar = new QProgressBar(avrOutputDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(480, 0));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        checkBox = new QCheckBox(avrOutputDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(avrOutputDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMinimumSize(QSize(0, 312));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(10);
        plainTextEdit->setFont(font);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);


        retranslateUi(avrOutputDialog);

        QMetaObject::connectSlotsByName(avrOutputDialog);
    } // setupUi

    void retranslateUi(QDialog *avrOutputDialog)
    {
        avrOutputDialog->setWindowTitle(QApplication::translate("avrOutputDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("avrOutputDialog", "Show Details", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class avrOutputDialog: public Ui_avrOutputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVROUTPUTDIALOG_H
