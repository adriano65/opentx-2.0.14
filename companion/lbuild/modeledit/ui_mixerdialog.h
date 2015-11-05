/********************************************************************************
** Form generated from reading UI file 'mixerdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIXERDIALOG_H
#define UI_MIXERDIALOG_H

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

class Ui_MixerDialog
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_11;
    QDoubleSpinBox *slowUpSB;
    QDoubleSpinBox *slowDownSB;
    QDoubleSpinBox *delayUpSB;
    QDoubleSpinBox *delayDownSB;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout_2;
    QLabel *trimLabel;
    QLabel *label_4;
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
    QLabel *label_name;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_8;
    QComboBox *curveTypeCB;
    QLabel *label_MixDR;
    QLabel *label_phases;
    QLabel *label_7;
    QCheckBox *MixDR_CB;
    QComboBox *warningCB;
    QComboBox *trimCB;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *offsetGV;
    QComboBox *offsetCB;
    QSpinBox *offsetSB;
    QSpacerItem *horizontalSpacer;
    QComboBox *mltpxCB;
    QComboBox *sourceCB;
    QLabel *label_curve;
    QHBoxLayout *horizontalLayout;
    QCheckBox *weightGV;
    QComboBox *weightCB;
    QSpinBox *weightSB;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *switchesCB;
    QLineEdit *mixerName;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *curveGVarCB;
    QComboBox *curveValueCB;
    QSpinBox *curveValueSB;

    void setupUi(QDialog *MixerDialog)
    {
        if (MixerDialog->objectName().isEmpty())
            MixerDialog->setObjectName(QString::fromUtf8("MixerDialog"));
        MixerDialog->resize(412, 541);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MixerDialog->sizePolicy().hasHeightForWidth());
        MixerDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MixerDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(MixerDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_13 = new QLabel(MixerDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 0, 1, 1, 1);

        label_14 = new QLabel(MixerDialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 0, 2, 1, 1);

        label_12 = new QLabel(MixerDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        label_11 = new QLabel(MixerDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        slowUpSB = new QDoubleSpinBox(MixerDialog);
        slowUpSB->setObjectName(QString::fromUtf8("slowUpSB"));
        slowUpSB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        slowUpSB->setDecimals(1);
        slowUpSB->setMaximum(7.5);
        slowUpSB->setSingleStep(0.5);

        gridLayout->addWidget(slowUpSB, 1, 2, 1, 1);

        slowDownSB = new QDoubleSpinBox(MixerDialog);
        slowDownSB->setObjectName(QString::fromUtf8("slowDownSB"));
        slowDownSB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        slowDownSB->setDecimals(1);
        slowDownSB->setMaximum(7.5);
        slowDownSB->setSingleStep(0.5);

        gridLayout->addWidget(slowDownSB, 2, 2, 1, 1);

        delayUpSB = new QDoubleSpinBox(MixerDialog);
        delayUpSB->setObjectName(QString::fromUtf8("delayUpSB"));
        delayUpSB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        delayUpSB->setDecimals(1);

        gridLayout->addWidget(delayUpSB, 1, 1, 1, 1);

        delayDownSB = new QDoubleSpinBox(MixerDialog);
        delayDownSB->setObjectName(QString::fromUtf8("delayDownSB"));
        delayDownSB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        delayDownSB->setDecimals(1);

        gridLayout->addWidget(delayDownSB, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MixerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        trimLabel = new QLabel(MixerDialog);
        trimLabel->setObjectName(QString::fromUtf8("trimLabel"));

        gridLayout_2->addWidget(trimLabel, 5, 0, 1, 1);

        label_4 = new QLabel(MixerDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(MixerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lb_FP0 = new QLabel(MixerDialog);
        lb_FP0->setObjectName(QString::fromUtf8("lb_FP0"));
        lb_FP0->setText(QString::fromUtf8("0"));
        lb_FP0->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP0, 0, 0, 1, 1);

        lb_FP1 = new QLabel(MixerDialog);
        lb_FP1->setObjectName(QString::fromUtf8("lb_FP1"));
        lb_FP1->setText(QString::fromUtf8("1"));
        lb_FP1->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP1, 0, 1, 1, 1);

        lb_FP2 = new QLabel(MixerDialog);
        lb_FP2->setObjectName(QString::fromUtf8("lb_FP2"));
        lb_FP2->setText(QString::fromUtf8("2"));
        lb_FP2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP2, 0, 2, 1, 1);

        lb_FP3 = new QLabel(MixerDialog);
        lb_FP3->setObjectName(QString::fromUtf8("lb_FP3"));
        lb_FP3->setText(QString::fromUtf8("3"));
        lb_FP3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP3, 0, 3, 1, 1);

        lb_FP4 = new QLabel(MixerDialog);
        lb_FP4->setObjectName(QString::fromUtf8("lb_FP4"));
        lb_FP4->setText(QString::fromUtf8("4"));
        lb_FP4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP4, 0, 4, 1, 1);

        lb_FP5 = new QLabel(MixerDialog);
        lb_FP5->setObjectName(QString::fromUtf8("lb_FP5"));
        lb_FP5->setText(QString::fromUtf8("5"));
        lb_FP5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP5, 0, 5, 1, 1);

        lb_FP6 = new QLabel(MixerDialog);
        lb_FP6->setObjectName(QString::fromUtf8("lb_FP6"));
        lb_FP6->setText(QString::fromUtf8("6"));
        lb_FP6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP6, 0, 6, 1, 1);

        lb_FP7 = new QLabel(MixerDialog);
        lb_FP7->setObjectName(QString::fromUtf8("lb_FP7"));
        lb_FP7->setText(QString::fromUtf8("7"));
        lb_FP7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP7, 0, 7, 1, 1);

        lb_FP8 = new QLabel(MixerDialog);
        lb_FP8->setObjectName(QString::fromUtf8("lb_FP8"));
        lb_FP8->setText(QString::fromUtf8("8"));
        lb_FP8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lb_FP8, 0, 8, 1, 1);

        cb_FP0 = new QCheckBox(MixerDialog);
        cb_FP0->setObjectName(QString::fromUtf8("cb_FP0"));

        gridLayout_4->addWidget(cb_FP0, 1, 0, 1, 1);

        cb_FP1 = new QCheckBox(MixerDialog);
        cb_FP1->setObjectName(QString::fromUtf8("cb_FP1"));

        gridLayout_4->addWidget(cb_FP1, 1, 1, 1, 1);

        cb_FP2 = new QCheckBox(MixerDialog);
        cb_FP2->setObjectName(QString::fromUtf8("cb_FP2"));

        gridLayout_4->addWidget(cb_FP2, 1, 2, 1, 1);

        cb_FP3 = new QCheckBox(MixerDialog);
        cb_FP3->setObjectName(QString::fromUtf8("cb_FP3"));

        gridLayout_4->addWidget(cb_FP3, 1, 3, 1, 1);

        cb_FP4 = new QCheckBox(MixerDialog);
        cb_FP4->setObjectName(QString::fromUtf8("cb_FP4"));

        gridLayout_4->addWidget(cb_FP4, 1, 4, 1, 1);

        cb_FP5 = new QCheckBox(MixerDialog);
        cb_FP5->setObjectName(QString::fromUtf8("cb_FP5"));

        gridLayout_4->addWidget(cb_FP5, 1, 5, 1, 1);

        cb_FP6 = new QCheckBox(MixerDialog);
        cb_FP6->setObjectName(QString::fromUtf8("cb_FP6"));

        gridLayout_4->addWidget(cb_FP6, 1, 6, 1, 1);

        cb_FP7 = new QCheckBox(MixerDialog);
        cb_FP7->setObjectName(QString::fromUtf8("cb_FP7"));

        gridLayout_4->addWidget(cb_FP7, 1, 7, 1, 1);

        cb_FP8 = new QCheckBox(MixerDialog);
        cb_FP8->setObjectName(QString::fromUtf8("cb_FP8"));

        gridLayout_4->addWidget(cb_FP8, 1, 8, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 7, 1, 1, 2);

        label_name = new QLabel(MixerDialog);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        gridLayout_2->addWidget(label_name, 0, 0, 1, 1);

        label_2 = new QLabel(MixerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_9 = new QLabel(MixerDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 10, 0, 1, 1);

        label_8 = new QLabel(MixerDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 9, 0, 1, 1);

        curveTypeCB = new QComboBox(MixerDialog);
        curveTypeCB->setObjectName(QString::fromUtf8("curveTypeCB"));

        gridLayout_2->addWidget(curveTypeCB, 4, 1, 1, 1);

        label_MixDR = new QLabel(MixerDialog);
        label_MixDR->setObjectName(QString::fromUtf8("label_MixDR"));

        gridLayout_2->addWidget(label_MixDR, 6, 0, 1, 1);

        label_phases = new QLabel(MixerDialog);
        label_phases->setObjectName(QString::fromUtf8("label_phases"));

        gridLayout_2->addWidget(label_phases, 7, 0, 1, 1);

        label_7 = new QLabel(MixerDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 8, 0, 1, 1);

        MixDR_CB = new QCheckBox(MixerDialog);
        MixDR_CB->setObjectName(QString::fromUtf8("MixDR_CB"));

        gridLayout_2->addWidget(MixDR_CB, 6, 1, 1, 1);

        warningCB = new QComboBox(MixerDialog);
        warningCB->setObjectName(QString::fromUtf8("warningCB"));

        gridLayout_2->addWidget(warningCB, 9, 1, 1, 2);

        trimCB = new QComboBox(MixerDialog);
        trimCB->setObjectName(QString::fromUtf8("trimCB"));

        gridLayout_2->addWidget(trimCB, 5, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        offsetGV = new QCheckBox(MixerDialog);
        offsetGV->setObjectName(QString::fromUtf8("offsetGV"));

        horizontalLayout_2->addWidget(offsetGV);

        offsetCB = new QComboBox(MixerDialog);
        offsetCB->setObjectName(QString::fromUtf8("offsetCB"));

        horizontalLayout_2->addWidget(offsetCB);

        offsetSB = new QSpinBox(MixerDialog);
        offsetSB->setObjectName(QString::fromUtf8("offsetSB"));

        horizontalLayout_2->addWidget(offsetSB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(3, 1);

        gridLayout_2->addLayout(horizontalLayout_2, 3, 1, 1, 2);

        mltpxCB = new QComboBox(MixerDialog);
        mltpxCB->setObjectName(QString::fromUtf8("mltpxCB"));

        gridLayout_2->addWidget(mltpxCB, 10, 1, 1, 2);

        sourceCB = new QComboBox(MixerDialog);
        sourceCB->setObjectName(QString::fromUtf8("sourceCB"));

        gridLayout_2->addWidget(sourceCB, 1, 1, 1, 2);

        label_curve = new QLabel(MixerDialog);
        label_curve->setObjectName(QString::fromUtf8("label_curve"));

        gridLayout_2->addWidget(label_curve, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        weightGV = new QCheckBox(MixerDialog);
        weightGV->setObjectName(QString::fromUtf8("weightGV"));

        horizontalLayout->addWidget(weightGV);

        weightCB = new QComboBox(MixerDialog);
        weightCB->setObjectName(QString::fromUtf8("weightCB"));

        horizontalLayout->addWidget(weightCB);

        weightSB = new QSpinBox(MixerDialog);
        weightSB->setObjectName(QString::fromUtf8("weightSB"));

        horizontalLayout->addWidget(weightSB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(3, 1);

        gridLayout_2->addLayout(horizontalLayout, 2, 1, 1, 2);

        switchesCB = new QComboBox(MixerDialog);
        switchesCB->setObjectName(QString::fromUtf8("switchesCB"));

        gridLayout_2->addWidget(switchesCB, 8, 1, 1, 2);

        mixerName = new QLineEdit(MixerDialog);
        mixerName->setObjectName(QString::fromUtf8("mixerName"));
        mixerName->setMaxLength(6);

        gridLayout_2->addWidget(mixerName, 0, 1, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        curveGVarCB = new QCheckBox(MixerDialog);
        curveGVarCB->setObjectName(QString::fromUtf8("curveGVarCB"));

        horizontalLayout_3->addWidget(curveGVarCB);

        curveValueCB = new QComboBox(MixerDialog);
        curveValueCB->setObjectName(QString::fromUtf8("curveValueCB"));

        horizontalLayout_3->addWidget(curveValueCB);

        curveValueSB = new QSpinBox(MixerDialog);
        curveValueSB->setObjectName(QString::fromUtf8("curveValueSB"));

        horizontalLayout_3->addWidget(curveValueSB);


        gridLayout_2->addLayout(horizontalLayout_3, 4, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        QWidget::setTabOrder(mixerName, sourceCB);
        QWidget::setTabOrder(sourceCB, weightGV);
        QWidget::setTabOrder(weightGV, weightCB);
        QWidget::setTabOrder(weightCB, weightSB);
        QWidget::setTabOrder(weightSB, offsetGV);
        QWidget::setTabOrder(offsetGV, offsetCB);
        QWidget::setTabOrder(offsetCB, offsetSB);
        QWidget::setTabOrder(offsetSB, curveTypeCB);
        QWidget::setTabOrder(curveTypeCB, curveGVarCB);
        QWidget::setTabOrder(curveGVarCB, curveValueCB);
        QWidget::setTabOrder(curveValueCB, curveValueSB);
        QWidget::setTabOrder(curveValueSB, trimCB);
        QWidget::setTabOrder(trimCB, MixDR_CB);
        QWidget::setTabOrder(MixDR_CB, cb_FP0);
        QWidget::setTabOrder(cb_FP0, cb_FP1);
        QWidget::setTabOrder(cb_FP1, cb_FP2);
        QWidget::setTabOrder(cb_FP2, cb_FP3);
        QWidget::setTabOrder(cb_FP3, cb_FP4);
        QWidget::setTabOrder(cb_FP4, cb_FP5);
        QWidget::setTabOrder(cb_FP5, cb_FP6);
        QWidget::setTabOrder(cb_FP6, cb_FP7);
        QWidget::setTabOrder(cb_FP7, cb_FP8);
        QWidget::setTabOrder(cb_FP8, switchesCB);
        QWidget::setTabOrder(switchesCB, warningCB);
        QWidget::setTabOrder(warningCB, mltpxCB);
        QWidget::setTabOrder(mltpxCB, delayUpSB);
        QWidget::setTabOrder(delayUpSB, slowUpSB);
        QWidget::setTabOrder(slowUpSB, delayDownSB);
        QWidget::setTabOrder(delayDownSB, slowDownSB);
        QWidget::setTabOrder(slowDownSB, buttonBox);

        retranslateUi(MixerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MixerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MixerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MixerDialog);
    } // setupUi

    void retranslateUi(QDialog *MixerDialog)
    {
        MixerDialog->setWindowTitle(QApplication::translate("MixerDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MixerDialog", "Delay", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MixerDialog", "Slow", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MixerDialog", "Up", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MixerDialog", "Down", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        slowUpSB->setWhatsThis(QApplication::translate("MixerDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; text-decoration: underline;\">Delay and slow</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; text-decoration: underline;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">These values control the speed and delay of the output of the mix.  </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Delay is not zero the actuation of the mix will be delayed by the specified amount of seconds.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Slow is not zero then the speed of the mix will be set by the value specified -&gt; the value states the number of seconds it takes to transit from -100 to 100.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        slowDownSB->setWhatsThis(QApplication::translate("MixerDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; text-decoration: underline;\">Delay and slow</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; text-decoration: underline;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">These values control the speed and delay of the output of the mix.  </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Delay is not zero the actuation of the mix will be delayed by the specified amount of seconds.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Slow is not zero then the speed of the mix will be set by the value specified -&gt; the value states the number of seconds it takes to transit from -100 to 100.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        delayUpSB->setWhatsThis(QApplication::translate("MixerDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; text-decoration: underline;\">Delay and slow</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; text-decoration: underline;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">These values control the speed and delay of the output of the mix.  </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Delay is not zero the actuation of the mix will be delayed by the specified amount of seconds.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Slow is not zero then the speed of the mix will be set by the value specified -&gt; the value states the number of seconds it takes to transit from -100 to 100.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        delayDownSB->setWhatsThis(QApplication::translate("MixerDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; text-decoration: underline;\">Delay and slow</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; text-decoration: underline;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">These values control the speed and delay of the output of the mix.  </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Delay is not zero the actuation of the mix will be delayed by the specified amount of seconds.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If Slow is not zero then the speed of the mix will be set by the value specified -&gt; the value states the number of seconds it takes to transit from -100 to 100.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        trimLabel->setText(QApplication::translate("MixerDialog", "Include Trim", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MixerDialog", "Offset", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MixerDialog", "Weight", 0, QApplication::UnicodeUTF8));
        cb_FP0->setText(QString());
        cb_FP1->setText(QString());
        cb_FP2->setText(QString());
        cb_FP3->setText(QString());
        cb_FP4->setText(QString());
        cb_FP5->setText(QString());
        cb_FP6->setText(QString());
        cb_FP7->setText(QString());
        cb_FP8->setText(QString());
        label_name->setText(QApplication::translate("MixerDialog", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MixerDialog", "Source", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MixerDialog", "Multiplex", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MixerDialog", "Warning", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        curveTypeCB->setWhatsThis(QApplication::translate("MixerDialog", "The curve used by the mix", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_MixDR->setText(QApplication::translate("MixerDialog", "Include DR/Expo", 0, QApplication::UnicodeUTF8));
        label_phases->setText(QApplication::translate("MixerDialog", "Flight modes", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MixerDialog", "Switch", 0, QApplication::UnicodeUTF8));
        MixDR_CB->setText(QString());
        warningCB->clear();
        warningCB->insertItems(0, QStringList()
         << QApplication::translate("MixerDialog", "OFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixerDialog", "1 Beep", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixerDialog", "2 Beep", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixerDialog", "3 Beep", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        warningCB->setWhatsThis(QApplication::translate("MixerDialog", "Mixer warning.\n"
"Setting this value will cause a beep to be emmitted when this value is active.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        trimCB->clear();
        trimCB->insertItems(0, QStringList()
         << QApplication::translate("MixerDialog", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixerDialog", "Yes", 0, QApplication::UnicodeUTF8)
        );
        offsetGV->setText(QApplication::translate("MixerDialog", "GV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        offsetCB->setWhatsThis(QApplication::translate("MixerDialog", "The source for the mixer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        mltpxCB->clear();
        mltpxCB->insertItems(0, QStringList()
         << QApplication::translate("MixerDialog", "ADD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixerDialog", "MULTIPLY", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixerDialog", "REPLACE", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        mltpxCB->setWhatsThis(QApplication::translate("MixerDialog", "Multiplexer\n"
"\n"
"This determines how mixer values are added.\n"
"\n"
"\"+\" means the value of the current mix is added to the previous mixes in the same channel.\n"
"\"*\" means the value of the current mix is amultiplied with the previous mixes in the same channel.\n"
"\"R\" means the value replaces the previous values.  If the switch is off the value will be ignored.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        sourceCB->setWhatsThis(QApplication::translate("MixerDialog", "The source for the mixer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_curve->setText(QApplication::translate("MixerDialog", "Curve", 0, QApplication::UnicodeUTF8));
        weightGV->setText(QApplication::translate("MixerDialog", "GV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        weightCB->setWhatsThis(QApplication::translate("MixerDialog", "The source for the mixer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        switchesCB->setWhatsThis(QApplication::translate("MixerDialog", "Switch used by the mix.\n"
"If blank then the mix is considered to be \"ON\" all the time.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        curveGVarCB->setText(QApplication::translate("MixerDialog", "GV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        curveValueCB->setWhatsThis(QApplication::translate("MixerDialog", "The source for the mixer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class MixerDialog: public Ui_MixerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIXERDIALOG_H
