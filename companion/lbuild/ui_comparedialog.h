/********************************************************************************
** Form generated from reading UI file 'comparedialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREDIALOG_H
#define UI_COMPAREDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CompareDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_1;
    QLabel *label_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QPushButton *printButton;
    QPushButton *printFileButton;

    void setupUi(QDialog *CompareDialog)
    {
        if (CompareDialog->objectName().isEmpty())
            CompareDialog->setObjectName(QString::fromUtf8("CompareDialog"));
        CompareDialog->resize(800, 580);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CompareDialog->sizePolicy().hasHeightForWidth());
        CompareDialog->setSizePolicy(sizePolicy);
        CompareDialog->setMinimumSize(QSize(780, 0));
        CompareDialog->setAcceptDrops(false);
        gridLayout = new QGridLayout(CompareDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_1 = new QLabel(CompareDialog);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_1->setAcceptDrops(true);
        label_1->setStyleSheet(QString::fromUtf8("color:green;"));
        label_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_1);

        label_2 = new QLabel(CompareDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAcceptDrops(true);
        label_2->setStyleSheet(QString::fromUtf8("color:red;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        textEdit = new QTextEdit(CompareDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(CompareDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);

        printButton = new QPushButton(CompareDialog);
        printButton->setObjectName(QString::fromUtf8("printButton"));

        horizontalLayout->addWidget(printButton);

        printFileButton = new QPushButton(CompareDialog);
        printFileButton->setObjectName(QString::fromUtf8("printFileButton"));

        horizontalLayout->addWidget(printFileButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(CompareDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), CompareDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CompareDialog);
    } // setupUi

    void retranslateUi(QDialog *CompareDialog)
    {
        CompareDialog->setWindowTitle(QApplication::translate("CompareDialog", "Compare Models", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("CompareDialog", "Drag first model here", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CompareDialog", "Drag second model here", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("CompareDialog", "Close", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("CompareDialog", "Print", 0, QApplication::UnicodeUTF8));
        printFileButton->setText(QApplication::translate("CompareDialog", "Print to file", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CompareDialog: public Ui_CompareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREDIALOG_H
