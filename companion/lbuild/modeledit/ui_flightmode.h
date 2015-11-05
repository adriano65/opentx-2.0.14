/********************************************************************************
** Form generated from reading UI file 'flightmode.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTMODE_H
#define UI_FLIGHTMODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightMode
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *paramsLayout;
    QLabel *label_3;
    QDoubleSpinBox *fadeIn;
    QDoubleSpinBox *fadeOut;
    QLabel *label_4;
    QLineEdit *name;
    QLabel *label;
    QSpacerItem *spacer_5;
    QLabel *label_2;
    QComboBox *swtch;
    QGridLayout *trimsLayout;
    QSlider *trim1Slider;
    QSlider *trim2Slider;
    QSlider *trim3Slider;
    QSlider *trim4Slider;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *leftTrims_3;
    QLabel *trim1Label;
    QVBoxLayout *verticalLayout_5c_3;
    QSpacerItem *verticalSpacer_3c_3;
    QComboBox *trim2Use;
    QSpinBox *trim2Value;
    QSpacerItem *verticalSpacer_4a_3;
    QVBoxLayout *verticalLayout_6b_3;
    QSpacerItem *verticalSpacer_5b_3;
    QComboBox *trim1Use;
    QSpinBox *trim1Value;
    QSpacerItem *verticalSpacer_6b_3;
    QLabel *trim2Label;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *righTrims_2;
    QLabel *trim4Label;
    QLabel *trim3Label;
    QVBoxLayout *verticalLayout_7b_2;
    QSpacerItem *verticalSpacer_7b_2;
    QComboBox *trim3Use;
    QSpinBox *trim3Value;
    QSpacerItem *verticalSpacer_8d_2;
    QVBoxLayout *verticalLayout_8d_2;
    QSpacerItem *verticalSpacer_9d_2;
    QComboBox *trim4Use;
    QSpinBox *trim4Value;
    QSpacerItem *verticalSpacer_10c_2;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QGridLayout *gvNreLayout;
    QGroupBox *gvGB;
    QGroupBox *reGB;

    void setupUi(QWidget *FlightMode)
    {
        if (FlightMode->objectName().isEmpty())
            FlightMode->setObjectName(QString::fromUtf8("FlightMode"));
        FlightMode->resize(610, 499);
        verticalLayout = new QVBoxLayout(FlightMode);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        paramsLayout = new QGridLayout();
        paramsLayout->setObjectName(QString::fromUtf8("paramsLayout"));
        label_3 = new QLabel(FlightMode);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        paramsLayout->addWidget(label_3, 0, 2, 1, 1);

        fadeIn = new QDoubleSpinBox(FlightMode);
        fadeIn->setObjectName(QString::fromUtf8("fadeIn"));
        fadeIn->setDecimals(1);

        paramsLayout->addWidget(fadeIn, 0, 3, 1, 1);

        fadeOut = new QDoubleSpinBox(FlightMode);
        fadeOut->setObjectName(QString::fromUtf8("fadeOut"));
        fadeOut->setDecimals(1);

        paramsLayout->addWidget(fadeOut, 1, 3, 1, 1);

        label_4 = new QLabel(FlightMode);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        paramsLayout->addWidget(label_4, 1, 2, 1, 1);

        name = new QLineEdit(FlightMode);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMaxLength(6);

        paramsLayout->addWidget(name, 0, 1, 1, 1);

        label = new QLabel(FlightMode);
        label->setObjectName(QString::fromUtf8("label"));

        paramsLayout->addWidget(label, 0, 0, 1, 1);

        spacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        paramsLayout->addItem(spacer_5, 0, 4, 2, 1);

        label_2 = new QLabel(FlightMode);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        paramsLayout->addWidget(label_2, 1, 0, 1, 1);

        swtch = new QComboBox(FlightMode);
        swtch->setObjectName(QString::fromUtf8("swtch"));

        paramsLayout->addWidget(swtch, 1, 1, 1, 1);


        verticalLayout->addLayout(paramsLayout);

        trimsLayout = new QGridLayout();
        trimsLayout->setObjectName(QString::fromUtf8("trimsLayout"));
        trim1Slider = new QSlider(FlightMode);
        trim1Slider->setObjectName(QString::fromUtf8("trim1Slider"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(trim1Slider->sizePolicy().hasHeightForWidth());
        trim1Slider->setSizePolicy(sizePolicy);
        trim1Slider->setOrientation(Qt::Horizontal);
        trim1Slider->setTickPosition(QSlider::TicksBothSides);
        trim1Slider->setTickInterval(25);

        trimsLayout->addWidget(trim1Slider, 2, 1, 1, 1);

        trim2Slider = new QSlider(FlightMode);
        trim2Slider->setObjectName(QString::fromUtf8("trim2Slider"));
        trim2Slider->setOrientation(Qt::Vertical);
        trim2Slider->setTickPosition(QSlider::TicksBothSides);
        trim2Slider->setTickInterval(25);

        trimsLayout->addWidget(trim2Slider, 0, 0, 1, 1);

        trim3Slider = new QSlider(FlightMode);
        trim3Slider->setObjectName(QString::fromUtf8("trim3Slider"));
        trim3Slider->setOrientation(Qt::Vertical);
        trim3Slider->setInvertedAppearance(false);
        trim3Slider->setInvertedControls(false);
        trim3Slider->setTickPosition(QSlider::TicksBothSides);
        trim3Slider->setTickInterval(25);

        trimsLayout->addWidget(trim3Slider, 0, 3, 1, 1);

        trim4Slider = new QSlider(FlightMode);
        trim4Slider->setObjectName(QString::fromUtf8("trim4Slider"));
        sizePolicy.setHeightForWidth(trim4Slider->sizePolicy().hasHeightForWidth());
        trim4Slider->setSizePolicy(sizePolicy);
        trim4Slider->setOrientation(Qt::Horizontal);
        trim4Slider->setTickPosition(QSlider::TicksBothSides);
        trim4Slider->setTickInterval(25);

        trimsLayout->addWidget(trim4Slider, 2, 2, 1, 1);

        frame = new QFrame(FlightMode);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        leftTrims_3 = new QGridLayout();
        leftTrims_3->setObjectName(QString::fromUtf8("leftTrims_3"));
        trim1Label = new QLabel(frame);
        trim1Label->setObjectName(QString::fromUtf8("trim1Label"));
        trim1Label->setText(QString::fromUtf8("trim1"));
        trim1Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        leftTrims_3->addWidget(trim1Label, 1, 0, 1, 1);

        verticalLayout_5c_3 = new QVBoxLayout();
        verticalLayout_5c_3->setObjectName(QString::fromUtf8("verticalLayout_5c_3"));
        verticalSpacer_3c_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5c_3->addItem(verticalSpacer_3c_3);

        trim2Use = new QComboBox(frame);
        trim2Use->setObjectName(QString::fromUtf8("trim2Use"));

        verticalLayout_5c_3->addWidget(trim2Use);

        trim2Value = new QSpinBox(frame);
        trim2Value->setObjectName(QString::fromUtf8("trim2Value"));
        trim2Value->setAlignment(Qt::AlignCenter);
        trim2Value->setAccelerated(true);
        trim2Value->setMinimum(-896);
        trim2Value->setMaximum(896);

        verticalLayout_5c_3->addWidget(trim2Value);

        verticalSpacer_4a_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5c_3->addItem(verticalSpacer_4a_3);


        leftTrims_3->addLayout(verticalLayout_5c_3, 0, 1, 1, 1);

        verticalLayout_6b_3 = new QVBoxLayout();
        verticalLayout_6b_3->setObjectName(QString::fromUtf8("verticalLayout_6b_3"));
        verticalSpacer_5b_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6b_3->addItem(verticalSpacer_5b_3);

        trim1Use = new QComboBox(frame);
        trim1Use->setObjectName(QString::fromUtf8("trim1Use"));

        verticalLayout_6b_3->addWidget(trim1Use);

        trim1Value = new QSpinBox(frame);
        trim1Value->setObjectName(QString::fromUtf8("trim1Value"));
        trim1Value->setAlignment(Qt::AlignCenter);
        trim1Value->setAccelerated(true);
        trim1Value->setMinimum(-896);
        trim1Value->setMaximum(896);

        verticalLayout_6b_3->addWidget(trim1Value);

        verticalSpacer_6b_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6b_3->addItem(verticalSpacer_6b_3);


        leftTrims_3->addLayout(verticalLayout_6b_3, 1, 1, 1, 1);

        trim2Label = new QLabel(frame);
        trim2Label->setObjectName(QString::fromUtf8("trim2Label"));
        trim2Label->setText(QString::fromUtf8("trim2"));
        trim2Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        leftTrims_3->addWidget(trim2Label, 0, 0, 1, 1);

        leftTrims_3->setColumnStretch(1, 1);

        verticalLayout_2->addLayout(leftTrims_3);


        trimsLayout->addWidget(frame, 0, 1, 1, 1);

        frame_2 = new QFrame(FlightMode);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        righTrims_2 = new QGridLayout();
        righTrims_2->setObjectName(QString::fromUtf8("righTrims_2"));
        trim4Label = new QLabel(frame_2);
        trim4Label->setObjectName(QString::fromUtf8("trim4Label"));
        trim4Label->setText(QString::fromUtf8("trim4"));
        trim4Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        righTrims_2->addWidget(trim4Label, 1, 0, 1, 1);

        trim3Label = new QLabel(frame_2);
        trim3Label->setObjectName(QString::fromUtf8("trim3Label"));
        trim3Label->setText(QString::fromUtf8("trim3"));
        trim3Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        righTrims_2->addWidget(trim3Label, 0, 0, 1, 1);

        verticalLayout_7b_2 = new QVBoxLayout();
        verticalLayout_7b_2->setObjectName(QString::fromUtf8("verticalLayout_7b_2"));
        verticalSpacer_7b_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7b_2->addItem(verticalSpacer_7b_2);

        trim3Use = new QComboBox(frame_2);
        trim3Use->setObjectName(QString::fromUtf8("trim3Use"));

        verticalLayout_7b_2->addWidget(trim3Use);

        trim3Value = new QSpinBox(frame_2);
        trim3Value->setObjectName(QString::fromUtf8("trim3Value"));
        trim3Value->setAlignment(Qt::AlignCenter);
        trim3Value->setAccelerated(true);
        trim3Value->setMinimum(-896);
        trim3Value->setMaximum(896);

        verticalLayout_7b_2->addWidget(trim3Value);

        verticalSpacer_8d_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7b_2->addItem(verticalSpacer_8d_2);


        righTrims_2->addLayout(verticalLayout_7b_2, 0, 1, 1, 1);

        verticalLayout_8d_2 = new QVBoxLayout();
        verticalLayout_8d_2->setObjectName(QString::fromUtf8("verticalLayout_8d_2"));
        verticalSpacer_9d_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8d_2->addItem(verticalSpacer_9d_2);

        trim4Use = new QComboBox(frame_2);
        trim4Use->setObjectName(QString::fromUtf8("trim4Use"));

        verticalLayout_8d_2->addWidget(trim4Use);

        trim4Value = new QSpinBox(frame_2);
        trim4Value->setObjectName(QString::fromUtf8("trim4Value"));
        trim4Value->setAlignment(Qt::AlignCenter);
        trim4Value->setAccelerated(true);
        trim4Value->setMinimum(-896);
        trim4Value->setMaximum(896);

        verticalLayout_8d_2->addWidget(trim4Value);

        verticalSpacer_10c_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8d_2->addItem(verticalSpacer_10c_2);


        righTrims_2->addLayout(verticalLayout_8d_2, 1, 1, 1, 1);

        righTrims_2->setColumnStretch(1, 1);

        verticalLayout_3->addLayout(righTrims_2);


        trimsLayout->addWidget(frame_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        trimsLayout->addItem(horizontalSpacer, 0, 4, 1, 1);


        verticalLayout->addLayout(trimsLayout);

        line = new QFrame(FlightMode);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gvNreLayout = new QGridLayout();
        gvNreLayout->setObjectName(QString::fromUtf8("gvNreLayout"));
        gvGB = new QGroupBox(FlightMode);
        gvGB->setObjectName(QString::fromUtf8("gvGB"));

        gvNreLayout->addWidget(gvGB, 0, 0, 1, 1);

        reGB = new QGroupBox(FlightMode);
        reGB->setObjectName(QString::fromUtf8("reGB"));

        gvNreLayout->addWidget(reGB, 0, 1, 1, 1);

        gvNreLayout->setColumnStretch(0, 1);
        gvNreLayout->setColumnStretch(1, 1);

        verticalLayout->addLayout(gvNreLayout);

        QWidget::setTabOrder(name, fadeIn);
        QWidget::setTabOrder(fadeIn, swtch);
        QWidget::setTabOrder(swtch, fadeOut);
        QWidget::setTabOrder(fadeOut, trim2Use);
        QWidget::setTabOrder(trim2Use, trim2Value);
        QWidget::setTabOrder(trim2Value, trim1Use);
        QWidget::setTabOrder(trim1Use, trim1Value);
        QWidget::setTabOrder(trim1Value, trim3Use);
        QWidget::setTabOrder(trim3Use, trim3Value);
        QWidget::setTabOrder(trim3Value, trim4Use);
        QWidget::setTabOrder(trim4Use, trim4Value);
        QWidget::setTabOrder(trim4Value, trim2Slider);
        QWidget::setTabOrder(trim2Slider, trim3Slider);
        QWidget::setTabOrder(trim3Slider, trim1Slider);
        QWidget::setTabOrder(trim1Slider, trim4Slider);

        retranslateUi(FlightMode);

        QMetaObject::connectSlotsByName(FlightMode);
    } // setupUi

    void retranslateUi(QWidget *FlightMode)
    {
        FlightMode->setWindowTitle(QString());
        label_3->setText(QApplication::translate("FlightMode", "Fade In", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FlightMode", "Fade Out", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FlightMode", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FlightMode", "Switch", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FlightMode: public Ui_FlightMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTMODE_H
