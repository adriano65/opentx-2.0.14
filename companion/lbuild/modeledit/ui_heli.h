/********************************************************************************
** Form generated from reading UI file 'heli.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELI_H
#define UI_HELI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Heli
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_21;
    QCheckBox *swashInvertELE;
    QCheckBox *swashInvertAIL;
    QCheckBox *swashInvertCOL;
    QLabel *label_108;
    QComboBox *swashTypeCB;
    QLabel *label_106;
    QComboBox *swashCollectiveCB;
    QLabel *label_103;
    QSpinBox *swashRingValSB;
    QLabel *label_107;
    QSpacerItem *verticalSpacer_21;

    void setupUi(QWidget *Heli)
    {
        if (Heli->objectName().isEmpty())
            Heli->setObjectName(QString::fromUtf8("Heli"));
        Heli->resize(795, 307);
        gridLayout = new QGridLayout(Heli);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        swashInvertELE = new QCheckBox(Heli);
        swashInvertELE->setObjectName(QString::fromUtf8("swashInvertELE"));

        gridLayout_21->addWidget(swashInvertELE, 0, 0, 1, 1);

        swashInvertAIL = new QCheckBox(Heli);
        swashInvertAIL->setObjectName(QString::fromUtf8("swashInvertAIL"));

        gridLayout_21->addWidget(swashInvertAIL, 0, 1, 1, 1);

        swashInvertCOL = new QCheckBox(Heli);
        swashInvertCOL->setObjectName(QString::fromUtf8("swashInvertCOL"));

        gridLayout_21->addWidget(swashInvertCOL, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_21, 3, 1, 1, 1);

        label_108 = new QLabel(Heli);
        label_108->setObjectName(QString::fromUtf8("label_108"));

        gridLayout->addWidget(label_108, 3, 0, 1, 1);

        swashTypeCB = new QComboBox(Heli);
        swashTypeCB->setObjectName(QString::fromUtf8("swashTypeCB"));

        gridLayout->addWidget(swashTypeCB, 0, 1, 1, 1);

        label_106 = new QLabel(Heli);
        label_106->setObjectName(QString::fromUtf8("label_106"));

        gridLayout->addWidget(label_106, 1, 0, 1, 1);

        swashCollectiveCB = new QComboBox(Heli);
        swashCollectiveCB->setObjectName(QString::fromUtf8("swashCollectiveCB"));

        gridLayout->addWidget(swashCollectiveCB, 1, 1, 1, 1);

        label_103 = new QLabel(Heli);
        label_103->setObjectName(QString::fromUtf8("label_103"));

        gridLayout->addWidget(label_103, 0, 0, 1, 1);

        swashRingValSB = new QSpinBox(Heli);
        swashRingValSB->setObjectName(QString::fromUtf8("swashRingValSB"));
        swashRingValSB->setMinimum(0);
        swashRingValSB->setMaximum(100);
        swashRingValSB->setSingleStep(1);
        swashRingValSB->setValue(0);

        gridLayout->addWidget(swashRingValSB, 2, 1, 1, 1);

        label_107 = new QLabel(Heli);
        label_107->setObjectName(QString::fromUtf8("label_107"));

        gridLayout->addWidget(label_107, 2, 0, 1, 1);

        verticalSpacer_21 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_21, 4, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnMinimumWidth(0, 100);

        retranslateUi(Heli);

        QMetaObject::connectSlotsByName(Heli);
    } // setupUi

    void retranslateUi(QWidget *Heli)
    {
        Heli->setWindowTitle(QString());
        swashInvertELE->setText(QApplication::translate("Heli", "Invert Elevator", 0, QApplication::UnicodeUTF8));
        swashInvertAIL->setText(QApplication::translate("Heli", "Invert Aileron", 0, QApplication::UnicodeUTF8));
        swashInvertCOL->setText(QApplication::translate("Heli", "Invert Collective", 0, QApplication::UnicodeUTF8));
        label_108->setText(QApplication::translate("Heli", "Invert", 0, QApplication::UnicodeUTF8));
        swashTypeCB->clear();
        swashTypeCB->insertItems(0, QStringList()
         << QApplication::translate("Heli", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Heli", "120", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Heli", "120X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Heli", "140", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Heli", "90", 0, QApplication::UnicodeUTF8)
        );
        label_106->setText(QApplication::translate("Heli", "Collective", 0, QApplication::UnicodeUTF8));
        label_103->setText(QApplication::translate("Heli", "Swash Type", 0, QApplication::UnicodeUTF8));
        swashRingValSB->setSuffix(QString());
        label_107->setText(QApplication::translate("Heli", "Swash Ring", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Heli: public Ui_Heli {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELI_H
