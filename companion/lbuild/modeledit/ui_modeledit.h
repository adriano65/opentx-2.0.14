/********************************************************************************
** Form generated from reading UI file 'modeledit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELEDIT_H
#define UI_MODELEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelEdit
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *ModelEdit)
    {
        if (ModelEdit->objectName().isEmpty())
            ModelEdit->setObjectName(QString::fromUtf8("ModelEdit"));
        ModelEdit->resize(339, 385);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModelEdit->sizePolicy().hasHeightForWidth());
        ModelEdit->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ModelEdit->setWindowIcon(icon);
        ModelEdit->setSizeGripEnabled(true);
        verticalLayout_2 = new QVBoxLayout(ModelEdit);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        tabWidget = new QTabWidget(ModelEdit);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabPosition(QTabWidget::North);

        verticalLayout->addWidget(tabWidget);

        pushButton = new QPushButton(ModelEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ModelEdit);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ModelEdit);
    } // setupUi

    void retranslateUi(QDialog *ModelEdit)
    {
        ModelEdit->setWindowTitle(QApplication::translate("ModelEdit", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ModelEdit", "Simulate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModelEdit: public Ui_ModelEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELEDIT_H
