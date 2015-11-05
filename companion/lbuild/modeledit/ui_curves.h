/********************************************************************************
** Form generated from reading UI file 'curves.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVES_H
#define UI_CURVES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Curves
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *curvesLayout;
    QVBoxLayout *verticalLayout_1;
    QGraphicsView *curvePreview;
    QGridLayout *gridLayout;
    QLabel *curveNameLabel;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *curvePoints;
    QComboBox *curveCustom;
    QComboBox *curveSmooth;
    QLineEdit *curveName;
    QLabel *curveTypeLabel;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *pointsLayout;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *curveCreator;
    QGridLayout *gridLayout_76;
    QLabel *yMidLabel;
    QSpinBox *yMax;
    QLabel *yMaxLabel;
    QSpinBox *curveCoeff;
    QComboBox *curveSide;
    QSpinBox *yMin;
    QPushButton *curveApply;
    QLabel *curveSideLabel;
    QSpinBox *yMid;
    QComboBox *curveType;
    QLabel *curveTypeLabel_2;
    QLabel *yMinLabel;
    QLabel *curveCoeffLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Curves)
    {
        if (Curves->objectName().isEmpty())
            Curves->setObjectName(QString::fromUtf8("Curves"));
        Curves->resize(718, 539);
        horizontalLayout = new QHBoxLayout(Curves);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        curvesLayout = new QGridLayout();
        curvesLayout->setObjectName(QString::fromUtf8("curvesLayout"));

        horizontalLayout->addLayout(curvesLayout);

        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(-1, -1, 10, -1);
        curvePreview = new QGraphicsView(Curves);
        curvePreview->setObjectName(QString::fromUtf8("curvePreview"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(curvePreview->sizePolicy().hasHeightForWidth());
        curvePreview->setSizePolicy(sizePolicy);
        curvePreview->setMinimumSize(QSize(400, 400));
        curvePreview->setAlignment(Qt::AlignCenter);

        verticalLayout_1->addWidget(curvePreview);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        curveNameLabel = new QLabel(Curves);
        curveNameLabel->setObjectName(QString::fromUtf8("curveNameLabel"));
        curveNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(curveNameLabel, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        curvePoints = new QComboBox(Curves);
        curvePoints->setObjectName(QString::fromUtf8("curvePoints"));

        horizontalLayout_2->addWidget(curvePoints);

        curveCustom = new QComboBox(Curves);
        curveCustom->setObjectName(QString::fromUtf8("curveCustom"));

        horizontalLayout_2->addWidget(curveCustom);

        curveSmooth = new QComboBox(Curves);
        curveSmooth->setObjectName(QString::fromUtf8("curveSmooth"));

        horizontalLayout_2->addWidget(curveSmooth);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        curveName = new QLineEdit(Curves);
        curveName->setObjectName(QString::fromUtf8("curveName"));
        curveName->setMaxLength(6);

        gridLayout->addWidget(curveName, 1, 1, 1, 1);

        curveTypeLabel = new QLabel(Curves);
        curveTypeLabel->setObjectName(QString::fromUtf8("curveTypeLabel"));
        curveTypeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(curveTypeLabel, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        verticalLayout_1->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout_1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pointsLayout = new QGridLayout();
        pointsLayout->setObjectName(QString::fromUtf8("pointsLayout"));
        pointsLayout->setHorizontalSpacing(0);
        pointsLayout->setVerticalSpacing(2);
        pointsLayout->setContentsMargins(-1, 0, -1, 0);

        verticalLayout_2->addLayout(pointsLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        curveCreator = new QGroupBox(Curves);
        curveCreator->setObjectName(QString::fromUtf8("curveCreator"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        curveCreator->setFont(font);
        curveCreator->setAutoFillBackground(false);
        gridLayout_76 = new QGridLayout(curveCreator);
        gridLayout_76->setObjectName(QString::fromUtf8("gridLayout_76"));
        yMidLabel = new QLabel(curveCreator);
        yMidLabel->setObjectName(QString::fromUtf8("yMidLabel"));

        gridLayout_76->addWidget(yMidLabel, 3, 0, 1, 1);

        yMax = new QSpinBox(curveCreator);
        yMax->setObjectName(QString::fromUtf8("yMax"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(yMax->sizePolicy().hasHeightForWidth());
        yMax->setSizePolicy(sizePolicy1);
        yMax->setMinimum(-100);
        yMax->setMaximum(100);

        gridLayout_76->addWidget(yMax, 4, 1, 1, 3);

        yMaxLabel = new QLabel(curveCreator);
        yMaxLabel->setObjectName(QString::fromUtf8("yMaxLabel"));

        gridLayout_76->addWidget(yMaxLabel, 4, 0, 1, 1);

        curveCoeff = new QSpinBox(curveCreator);
        curveCoeff->setObjectName(QString::fromUtf8("curveCoeff"));
        sizePolicy1.setHeightForWidth(curveCoeff->sizePolicy().hasHeightForWidth());
        curveCoeff->setSizePolicy(sizePolicy1);
        curveCoeff->setMinimum(-100);
        curveCoeff->setMaximum(100);

        gridLayout_76->addWidget(curveCoeff, 1, 1, 1, 3);

        curveSide = new QComboBox(curveCreator);
        curveSide->setObjectName(QString::fromUtf8("curveSide"));

        gridLayout_76->addWidget(curveSide, 5, 1, 1, 3);

        yMin = new QSpinBox(curveCreator);
        yMin->setObjectName(QString::fromUtf8("yMin"));
        sizePolicy1.setHeightForWidth(yMin->sizePolicy().hasHeightForWidth());
        yMin->setSizePolicy(sizePolicy1);
        yMin->setMinimum(-100);
        yMin->setMaximum(100);

        gridLayout_76->addWidget(yMin, 2, 1, 1, 3);

        curveApply = new QPushButton(curveCreator);
        curveApply->setObjectName(QString::fromUtf8("curveApply"));

        gridLayout_76->addWidget(curveApply, 6, 0, 1, 4);

        curveSideLabel = new QLabel(curveCreator);
        curveSideLabel->setObjectName(QString::fromUtf8("curveSideLabel"));

        gridLayout_76->addWidget(curveSideLabel, 5, 0, 1, 1);

        yMid = new QSpinBox(curveCreator);
        yMid->setObjectName(QString::fromUtf8("yMid"));
        sizePolicy1.setHeightForWidth(yMid->sizePolicy().hasHeightForWidth());
        yMid->setSizePolicy(sizePolicy1);
        yMid->setMinimum(-100);
        yMid->setMaximum(100);

        gridLayout_76->addWidget(yMid, 3, 1, 1, 3);

        curveType = new QComboBox(curveCreator);
        curveType->setObjectName(QString::fromUtf8("curveType"));

        gridLayout_76->addWidget(curveType, 0, 1, 1, 3);

        curveTypeLabel_2 = new QLabel(curveCreator);
        curveTypeLabel_2->setObjectName(QString::fromUtf8("curveTypeLabel_2"));

        gridLayout_76->addWidget(curveTypeLabel_2, 0, 0, 1, 1);

        yMinLabel = new QLabel(curveCreator);
        yMinLabel->setObjectName(QString::fromUtf8("yMinLabel"));

        gridLayout_76->addWidget(yMinLabel, 2, 0, 1, 1);

        curveCoeffLabel = new QLabel(curveCreator);
        curveCoeffLabel->setObjectName(QString::fromUtf8("curveCoeffLabel"));

        gridLayout_76->addWidget(curveCoeffLabel, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_76->addItem(verticalSpacer_3, 7, 0, 1, 1);


        horizontalLayout->addWidget(curveCreator);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        QWidget::setTabOrder(curvePreview, curvePoints);
        QWidget::setTabOrder(curvePoints, curveCustom);
        QWidget::setTabOrder(curveCustom, curveSmooth);
        QWidget::setTabOrder(curveSmooth, curveName);
        QWidget::setTabOrder(curveName, curveType);
        QWidget::setTabOrder(curveType, curveCoeff);
        QWidget::setTabOrder(curveCoeff, yMin);
        QWidget::setTabOrder(yMin, yMid);
        QWidget::setTabOrder(yMid, yMax);
        QWidget::setTabOrder(yMax, curveSide);
        QWidget::setTabOrder(curveSide, curveApply);

        retranslateUi(Curves);

        QMetaObject::connectSlotsByName(Curves);
    } // setupUi

    void retranslateUi(QWidget *Curves)
    {
        Curves->setWindowTitle(QString());
        curveNameLabel->setText(QApplication::translate("Curves", "Curve name", 0, QApplication::UnicodeUTF8));
        curveCustom->clear();
        curveCustom->insertItems(0, QStringList()
         << QApplication::translate("Curves", "Fixed X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Curves", "Custom X", 0, QApplication::UnicodeUTF8)
        );
        curveSmooth->clear();
        curveSmooth->insertItems(0, QStringList()
         << QApplication::translate("Curves", "Lines", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Curves", "Smooth", 0, QApplication::UnicodeUTF8)
        );
        curveTypeLabel->setText(QApplication::translate("Curves", "Curve type", 0, QApplication::UnicodeUTF8));
        curveCreator->setTitle(QApplication::translate("Curves", "Curve Creator", 0, QApplication::UnicodeUTF8));
        yMidLabel->setText(QApplication::translate("Curves", "Y at X=0", 0, QApplication::UnicodeUTF8));
        yMaxLabel->setText(QApplication::translate("Curves", "Y at X=100", 0, QApplication::UnicodeUTF8));
        curveSide->clear();
        curveSide->insertItems(0, QStringList()
         << QApplication::translate("Curves", "Both", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Curves", "x>0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Curves", "x<0", 0, QApplication::UnicodeUTF8)
        );
        curveApply->setText(QApplication::translate("Curves", "Apply", 0, QApplication::UnicodeUTF8));
        curveSideLabel->setText(QApplication::translate("Curves", "Side", 0, QApplication::UnicodeUTF8));
        curveTypeLabel_2->setText(QApplication::translate("Curves", "Curve type", 0, QApplication::UnicodeUTF8));
        yMinLabel->setText(QApplication::translate("Curves", "Y at X=-100", 0, QApplication::UnicodeUTF8));
        curveCoeffLabel->setText(QApplication::translate("Curves", "Coefficient", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Curves: public Ui_Curves {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVES_H
