/********************************************************************************
** Form generated from reading UI file 'expodialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPODIALOG_H
#define UI_EXPODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ExpoDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_phases;
    QLabel *inputNameLabel;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *weightGV;
    QSpinBox *weightSB;
    QComboBox *weightCB;
    QSpacerItem *horizontalSpacer;
    QLineEdit *inputName;
    QComboBox *sourceCB;
    QLabel *label_3;
    QGridLayout *gridLayout_4;
    QLabel *lb_FP0;
    QLabel *lb_FP1;
    QLabel *lb_FP2;
    QLabel *lb_FP3;
    QLabel *lb_FP4;
    QLabel *lb_FP5;
    QLabel *lb_FP6;
    QLabel *lb_FP7;
    QLabel *lb_FP8;
    QCheckBox *cb_FP0;
    QCheckBox *cb_FP1;
    QCheckBox *cb_FP2;
    QCheckBox *cb_FP3;
    QCheckBox *cb_FP4;
    QCheckBox *cb_FP5;
    QCheckBox *cb_FP6;
    QCheckBox *cb_FP7;
    QCheckBox *cb_FP8;
    QLabel *label_7;
    QComboBox *switchesCB;
    QLabel *sideLabel;
    QComboBox *sideCB;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *scale;
    QLabel *scaleLabel;
    QLabel *trimLabel;
    QComboBox *trimCB;
    QLabel *label_curves;
    QHBoxLayout *horizontalLayout;
    QComboBox *curveTypeCB;
    QCheckBox *curveGVarCB;
    QComboBox *curveValueCB;
    QSpinBox *curveValueSB;
    QLabel *sourceLabel;
    QLabel *lineNameLabel;
    QLineEdit *lineName;
    QLabel *offsetLabel;
    QHBoxLayout *offsetLayout;
    QCheckBox *offsetGV;
    QSpinBox *offsetSB;
    QComboBox *offsetCB;
    QSpacerItem *offsetSpacer;

    void setupUi(QDialog *ExpoDialog)
    {
        if (ExpoDialog->objectName().isEmpty())
            ExpoDialog->setObjectName(QString::fromUtf8("ExpoDialog"));
        ExpoDialog->resize(389, 488);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExpoDialog->sizePolicy().hasHeightForWidth());
        ExpoDialog->setSizePolicy(sizePolicy);
        ExpoDialog->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExpoDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ExpoDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_phases = new QLabel(ExpoDialog);
        label_phases->setObjectName(QString::fromUtf8("label_phases"));

        gridLayout->addWidget(label_phases, 9, 0, 1, 1);

        inputNameLabel = new QLabel(ExpoDialog);
        inputNameLabel->setObjectName(QString::fromUtf8("inputNameLabel"));

        gridLayout->addWidget(inputNameLabel, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        weightGV = new QCheckBox(ExpoDialog);
        weightGV->setObjectName(QString::fromUtf8("weightGV"));

        horizontalLayout_2->addWidget(weightGV);

        weightSB = new QSpinBox(ExpoDialog);
        weightSB->setObjectName(QString::fromUtf8("weightSB"));

        horizontalLayout_2->addWidget(weightSB);

        weightCB = new QComboBox(ExpoDialog);
        weightCB->setObjectName(QString::fromUtf8("weightCB"));

        horizontalLayout_2->addWidget(weightCB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_2, 6, 1, 1, 1);

        inputName = new QLineEdit(ExpoDialog);
        inputName->setObjectName(QString::fromUtf8("inputName"));
        inputName->setMaxLength(6);

        gridLayout->addWidget(inputName, 0, 1, 1, 1);

        sourceCB = new QComboBox(ExpoDialog);
        sourceCB->setObjectName(QString::fromUtf8("sourceCB"));

        gridLayout->addWidget(sourceCB, 2, 1, 1, 1);

        label_3 = new QLabel(ExpoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lb_FP0 = new QLabel(ExpoDialog);
        lb_FP0->setObjectName(QString::fromUtf8("lb_FP0"));
        lb_FP0->setText(QString::fromUtf8("0"));
        lb_FP0->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP0, 0, 0, 1, 1);

        lb_FP1 = new QLabel(ExpoDialog);
        lb_FP1->setObjectName(QString::fromUtf8("lb_FP1"));
        lb_FP1->setText(QString::fromUtf8("1"));
        lb_FP1->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP1, 0, 1, 1, 1);

        lb_FP2 = new QLabel(ExpoDialog);
        lb_FP2->setObjectName(QString::fromUtf8("lb_FP2"));
        lb_FP2->setText(QString::fromUtf8("2"));
        lb_FP2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP2, 0, 2, 1, 1);

        lb_FP3 = new QLabel(ExpoDialog);
        lb_FP3->setObjectName(QString::fromUtf8("lb_FP3"));
        lb_FP3->setText(QString::fromUtf8("3"));
        lb_FP3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP3, 0, 3, 1, 1);

        lb_FP4 = new QLabel(ExpoDialog);
        lb_FP4->setObjectName(QString::fromUtf8("lb_FP4"));
        lb_FP4->setText(QString::fromUtf8("4"));
        lb_FP4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP4, 0, 4, 1, 1);

        lb_FP5 = new QLabel(ExpoDialog);
        lb_FP5->setObjectName(QString::fromUtf8("lb_FP5"));
        lb_FP5->setText(QString::fromUtf8("5"));
        lb_FP5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP5, 0, 5, 1, 1);

        lb_FP6 = new QLabel(ExpoDialog);
        lb_FP6->setObjectName(QString::fromUtf8("lb_FP6"));
        lb_FP6->setText(QString::fromUtf8("6"));
        lb_FP6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP6, 0, 6, 1, 1);

        lb_FP7 = new QLabel(ExpoDialog);
        lb_FP7->setObjectName(QString::fromUtf8("lb_FP7"));
        lb_FP7->setText(QString::fromUtf8("7"));
        lb_FP7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP7, 0, 7, 1, 1);

        lb_FP8 = new QLabel(ExpoDialog);
        lb_FP8->setObjectName(QString::fromUtf8("lb_FP8"));
        lb_FP8->setText(QString::fromUtf8("8"));
        lb_FP8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP8, 0, 8, 1, 1);

        cb_FP0 = new QCheckBox(ExpoDialog);
        cb_FP0->setObjectName(QString::fromUtf8("cb_FP0"));

        gridLayout_4->addWidget(cb_FP0, 1, 0, 1, 1);

        cb_FP1 = new QCheckBox(ExpoDialog);
        cb_FP1->setObjectName(QString::fromUtf8("cb_FP1"));

        gridLayout_4->addWidget(cb_FP1, 1, 1, 1, 1);

        cb_FP2 = new QCheckBox(ExpoDialog);
        cb_FP2->setObjectName(QString::fromUtf8("cb_FP2"));

        gridLayout_4->addWidget(cb_FP2, 1, 2, 1, 1);

        cb_FP3 = new QCheckBox(ExpoDialog);
        cb_FP3->setObjectName(QString::fromUtf8("cb_FP3"));

        gridLayout_4->addWidget(cb_FP3, 1, 3, 1, 1);

        cb_FP4 = new QCheckBox(ExpoDialog);
        cb_FP4->setObjectName(QString::fromUtf8("cb_FP4"));

        gridLayout_4->addWidget(cb_FP4, 1, 4, 1, 1);

        cb_FP5 = new QCheckBox(ExpoDialog);
        cb_FP5->setObjectName(QString::fromUtf8("cb_FP5"));

        gridLayout_4->addWidget(cb_FP5, 1, 5, 1, 1);

        cb_FP6 = new QCheckBox(ExpoDialog);
        cb_FP6->setObjectName(QString::fromUtf8("cb_FP6"));

        gridLayout_4->addWidget(cb_FP6, 1, 6, 1, 1);

        cb_FP7 = new QCheckBox(ExpoDialog);
        cb_FP7->setObjectName(QString::fromUtf8("cb_FP7"));

        gridLayout_4->addWidget(cb_FP7, 1, 7, 1, 1);

        cb_FP8 = new QCheckBox(ExpoDialog);
        cb_FP8->setObjectName(QString::fromUtf8("cb_FP8"));

        gridLayout_4->addWidget(cb_FP8, 1, 8, 1, 1);


        gridLayout->addLayout(gridLayout_4, 9, 1, 1, 1);

        label_7 = new QLabel(ExpoDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 10, 0, 1, 1);

        switchesCB = new QComboBox(ExpoDialog);
        switchesCB->setObjectName(QString::fromUtf8("switchesCB"));

        gridLayout->addWidget(switchesCB, 10, 1, 1, 1);

        sideLabel = new QLabel(ExpoDialog);
        sideLabel->setObjectName(QString::fromUtf8("sideLabel"));

        gridLayout->addWidget(sideLabel, 12, 0, 1, 1);

        sideCB = new QComboBox(ExpoDialog);
        sideCB->setObjectName(QString::fromUtf8("sideCB"));

        gridLayout->addWidget(sideCB, 12, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ExpoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 14, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 2);

        scale = new QDoubleSpinBox(ExpoDialog);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scale->setDecimals(1);

        gridLayout->addWidget(scale, 3, 1, 1, 1);

        scaleLabel = new QLabel(ExpoDialog);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));

        gridLayout->addWidget(scaleLabel, 3, 0, 1, 1);

        trimLabel = new QLabel(ExpoDialog);
        trimLabel->setObjectName(QString::fromUtf8("trimLabel"));

        gridLayout->addWidget(trimLabel, 5, 0, 1, 1);

        trimCB = new QComboBox(ExpoDialog);
        trimCB->setObjectName(QString::fromUtf8("trimCB"));

        gridLayout->addWidget(trimCB, 5, 1, 1, 1);

        label_curves = new QLabel(ExpoDialog);
        label_curves->setObjectName(QString::fromUtf8("label_curves"));

        gridLayout->addWidget(label_curves, 8, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        curveTypeCB = new QComboBox(ExpoDialog);
        curveTypeCB->setObjectName(QString::fromUtf8("curveTypeCB"));

        horizontalLayout->addWidget(curveTypeCB);

        curveGVarCB = new QCheckBox(ExpoDialog);
        curveGVarCB->setObjectName(QString::fromUtf8("curveGVarCB"));

        horizontalLayout->addWidget(curveGVarCB);

        curveValueCB = new QComboBox(ExpoDialog);
        curveValueCB->setObjectName(QString::fromUtf8("curveValueCB"));

        horizontalLayout->addWidget(curveValueCB);

        curveValueSB = new QSpinBox(ExpoDialog);
        curveValueSB->setObjectName(QString::fromUtf8("curveValueSB"));

        horizontalLayout->addWidget(curveValueSB);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 8, 1, 1, 1);

        sourceLabel = new QLabel(ExpoDialog);
        sourceLabel->setObjectName(QString::fromUtf8("sourceLabel"));

        gridLayout->addWidget(sourceLabel, 2, 0, 1, 1);

        lineNameLabel = new QLabel(ExpoDialog);
        lineNameLabel->setObjectName(QString::fromUtf8("lineNameLabel"));

        gridLayout->addWidget(lineNameLabel, 1, 0, 1, 1);

        lineName = new QLineEdit(ExpoDialog);
        lineName->setObjectName(QString::fromUtf8("lineName"));
        lineName->setMaxLength(6);

        gridLayout->addWidget(lineName, 1, 1, 1, 1);

        offsetLabel = new QLabel(ExpoDialog);
        offsetLabel->setObjectName(QString::fromUtf8("offsetLabel"));

        gridLayout->addWidget(offsetLabel, 7, 0, 1, 1);

        offsetLayout = new QHBoxLayout();
        offsetLayout->setObjectName(QString::fromUtf8("offsetLayout"));
        offsetGV = new QCheckBox(ExpoDialog);
        offsetGV->setObjectName(QString::fromUtf8("offsetGV"));

        offsetLayout->addWidget(offsetGV);

        offsetSB = new QSpinBox(ExpoDialog);
        offsetSB->setObjectName(QString::fromUtf8("offsetSB"));

        offsetLayout->addWidget(offsetSB);

        offsetCB = new QComboBox(ExpoDialog);
        offsetCB->setObjectName(QString::fromUtf8("offsetCB"));

        offsetLayout->addWidget(offsetCB);

        offsetSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        offsetLayout->addItem(offsetSpacer);

        offsetLayout->setStretch(2, 1);

        gridLayout->addLayout(offsetLayout, 7, 1, 1, 1);

        QWidget::setTabOrder(inputName, lineName);
        QWidget::setTabOrder(lineName, sourceCB);
        QWidget::setTabOrder(sourceCB, scale);
        QWidget::setTabOrder(scale, trimCB);
        QWidget::setTabOrder(trimCB, weightGV);
        QWidget::setTabOrder(weightGV, weightSB);
        QWidget::setTabOrder(weightSB, weightCB);
        QWidget::setTabOrder(weightCB, offsetGV);
        QWidget::setTabOrder(offsetGV, offsetSB);
        QWidget::setTabOrder(offsetSB, offsetCB);
        QWidget::setTabOrder(offsetCB, curveTypeCB);
        QWidget::setTabOrder(curveTypeCB, curveGVarCB);
        QWidget::setTabOrder(curveGVarCB, curveValueCB);
        QWidget::setTabOrder(curveValueCB, curveValueSB);
        QWidget::setTabOrder(curveValueSB, cb_FP0);
        QWidget::setTabOrder(cb_FP0, cb_FP1);
        QWidget::setTabOrder(cb_FP1, cb_FP2);
        QWidget::setTabOrder(cb_FP2, cb_FP3);
        QWidget::setTabOrder(cb_FP3, cb_FP4);
        QWidget::setTabOrder(cb_FP4, cb_FP5);
        QWidget::setTabOrder(cb_FP5, cb_FP6);
        QWidget::setTabOrder(cb_FP6, cb_FP7);
        QWidget::setTabOrder(cb_FP7, cb_FP8);
        QWidget::setTabOrder(cb_FP8, switchesCB);
        QWidget::setTabOrder(switchesCB, sideCB);
        QWidget::setTabOrder(sideCB, buttonBox);

        retranslateUi(ExpoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExpoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExpoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExpoDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpoDialog)
    {
        ExpoDialog->setWindowTitle(QString());
        label_phases->setText(QApplication::translate("ExpoDialog", "Flight modes", 0, QApplication::UnicodeUTF8));
        inputNameLabel->setText(QApplication::translate("ExpoDialog", "Input name", 0, QApplication::UnicodeUTF8));
        weightGV->setText(QApplication::translate("ExpoDialog", "GV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        weightCB->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        sourceCB->setWhatsThis(QApplication::translate("ExpoDialog", "Source for the mixer.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("ExpoDialog", "Weight", 0, QApplication::UnicodeUTF8));
        cb_FP0->setText(QString());
        cb_FP1->setText(QString());
        cb_FP2->setText(QString());
        cb_FP3->setText(QString());
        cb_FP4->setText(QString());
        cb_FP5->setText(QString());
        cb_FP6->setText(QString());
        cb_FP7->setText(QString());
        cb_FP8->setText(QString());
        label_7->setText(QApplication::translate("ExpoDialog", "Switch", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        switchesCB->setWhatsThis(QApplication::translate("ExpoDialog", "Switch used to enable the line.\n"
"If blank then the input is considered to be \"ON\" all the time.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        sideLabel->setText(QApplication::translate("ExpoDialog", "Stick Side", 0, QApplication::UnicodeUTF8));
        sideCB->clear();
        sideCB->insertItems(0, QStringList()
         << QApplication::translate("ExpoDialog", "NEG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExpoDialog", "POS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExpoDialog", "ALL", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        scale->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        scaleLabel->setText(QApplication::translate("ExpoDialog", "Scale", 0, QApplication::UnicodeUTF8));
        trimLabel->setText(QApplication::translate("ExpoDialog", "Include Trim", 0, QApplication::UnicodeUTF8));
        trimCB->clear();
        trimCB->insertItems(0, QStringList()
         << QApplication::translate("ExpoDialog", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExpoDialog", "Yes", 0, QApplication::UnicodeUTF8)
        );
        label_curves->setText(QApplication::translate("ExpoDialog", "Curve", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        curveTypeCB->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        curveTypeCB->setWhatsThis(QApplication::translate("ExpoDialog", "Curve applied to the source.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        curveGVarCB->setText(QApplication::translate("ExpoDialog", "GV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        curveValueCB->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        sourceLabel->setText(QApplication::translate("ExpoDialog", "Source", 0, QApplication::UnicodeUTF8));
        lineNameLabel->setText(QApplication::translate("ExpoDialog", "Line name", 0, QApplication::UnicodeUTF8));
        offsetLabel->setText(QApplication::translate("ExpoDialog", "Offset", 0, QApplication::UnicodeUTF8));
        offsetGV->setText(QApplication::translate("ExpoDialog", "GV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        offsetCB->setWhatsThis(QApplication::translate("ExpoDialog", "The source for the mixer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class ExpoDialog: public Ui_ExpoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPODIALOG_H
