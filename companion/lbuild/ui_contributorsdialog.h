/********************************************************************************
** Form generated from reading UI file 'contributorsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRIBUTORSDIALOG_H
#define UI_CONTRIBUTORSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_contributorsDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEditor;

    void setupUi(QDialog *contributorsDialog)
    {
        if (contributorsDialog->objectName().isEmpty())
            contributorsDialog->setObjectName(QString::fromUtf8("contributorsDialog"));
        contributorsDialog->resize(788, 528);
        gridLayout = new QGridLayout(contributorsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditor = new QTextEdit(contributorsDialog);
        textEditor->setObjectName(QString::fromUtf8("textEditor"));
        textEditor->setReadOnly(true);

        gridLayout->addWidget(textEditor, 0, 0, 1, 1);


        retranslateUi(contributorsDialog);

        QMetaObject::connectSlotsByName(contributorsDialog);
    } // setupUi

    void retranslateUi(QDialog *contributorsDialog)
    {
        contributorsDialog->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class contributorsDialog: public Ui_contributorsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRIBUTORSDIALOG_H
