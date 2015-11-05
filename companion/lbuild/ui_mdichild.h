/********************************************************************************
** Form generated from reading UI file 'mdichild.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDICHILD_H
#define UI_MDICHILD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <modelslist.h>

QT_BEGIN_NAMESPACE

class Ui_mdiChild
{
public:
    QVBoxLayout *verticalLayout;
    ModelsListWidget *modelsList;
    QPushButton *SimulateTxButton;

    void setupUi(QWidget *mdiChild)
    {
        if (mdiChild->objectName().isEmpty())
            mdiChild->setObjectName(QString::fromUtf8("mdiChild"));
        mdiChild->resize(468, 414);
        verticalLayout = new QVBoxLayout(mdiChild);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        modelsList = new ModelsListWidget(mdiChild);
        modelsList->setObjectName(QString::fromUtf8("modelsList"));

        verticalLayout->addWidget(modelsList);

        SimulateTxButton = new QPushButton(mdiChild);
        SimulateTxButton->setObjectName(QString::fromUtf8("SimulateTxButton"));

        verticalLayout->addWidget(SimulateTxButton);


        retranslateUi(mdiChild);

        QMetaObject::connectSlotsByName(mdiChild);
    } // setupUi

    void retranslateUi(QWidget *mdiChild)
    {
        mdiChild->setWindowTitle(QString());
        SimulateTxButton->setText(QApplication::translate("mdiChild", "Simulate Tx", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mdiChild: public Ui_mdiChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDICHILD_H
