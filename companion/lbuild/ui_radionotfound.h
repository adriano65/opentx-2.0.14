/********************************************************************************
** Form generated from reading UI file 'radionotfound.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADIONOTFOUND_H
#define UI_RADIONOTFOUND_H

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
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RadioNotFoundDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *RadioNotFoundDialog)
    {
        if (RadioNotFoundDialog->objectName().isEmpty())
            RadioNotFoundDialog->setObjectName(QString::fromUtf8("RadioNotFoundDialog"));
        RadioNotFoundDialog->resize(367, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RadioNotFoundDialog->sizePolicy().hasHeightForWidth());
        RadioNotFoundDialog->setSizePolicy(sizePolicy);
        RadioNotFoundDialog->setMinimumSize(QSize(367, 350));
        RadioNotFoundDialog->setMaximumSize(QSize(367, 350));
        gridLayout = new QGridLayout(RadioNotFoundDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(RadioNotFoundDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(RadioNotFoundDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFrameShape(QFrame::Box);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/taranison.png")));

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK = new QPushButton(RadioNotFoundDialog);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout->addWidget(OK);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(RadioNotFoundDialog);

        QMetaObject::connectSlotsByName(RadioNotFoundDialog);
    } // setupUi

    void retranslateUi(QDialog *RadioNotFoundDialog)
    {
        RadioNotFoundDialog->setWindowTitle(QApplication::translate("RadioNotFoundDialog", "No Radio Found", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RadioNotFoundDialog", "<html><head/><body><p>No Radio was found!</p><p>Make sure that you hold the lower trim buttons towards the center while you turn it on.</p><p>Then connect the USB wire.</p><p><span style=\" font-family:'arial,sans-serif'; font-size:13px; font-style:italic; color:#222222; background-color:#ffffff;\">Note: if you have a Taranis that has not had the firmware upgraded to 2.0 then this version of Companion will not work.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        OK->setText(QApplication::translate("RadioNotFoundDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RadioNotFoundDialog: public Ui_RadioNotFoundDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADIONOTFOUND_H
