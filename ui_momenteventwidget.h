/********************************************************************************
** Form generated from reading UI file 'momenteventwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOMENTEVENTWIDGET_H
#define UI_MOMENTEVENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MomentEventWidget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *startTimeLabel;

    void setupUi(QWidget *MomentEventWidget)
    {
        if (MomentEventWidget->objectName().isEmpty())
            MomentEventWidget->setObjectName(QString::fromUtf8("MomentEventWidget"));
        MomentEventWidget->resize(800, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MomentEventWidget->sizePolicy().hasHeightForWidth());
        MomentEventWidget->setSizePolicy(sizePolicy);
        MomentEventWidget->setMinimumSize(QSize(800, 100));
        MomentEventWidget->setMaximumSize(QSize(16777215, 16777215));
        widget = new QWidget(MomentEventWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(800, 100));
        widget->setMaximumSize(QSize(800, 100));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 650, 0);
        startTimeLabel = new QLabel(widget);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));
        sizePolicy1.setHeightForWidth(startTimeLabel->sizePolicy().hasHeightForWidth());
        startTimeLabel->setSizePolicy(sizePolicy1);
        startTimeLabel->setMinimumSize(QSize(150, 100));
        startTimeLabel->setMaximumSize(QSize(150, 100));
        startTimeLabel->setAlignment(Qt::AlignCenter);
        startTimeLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(startTimeLabel);


        retranslateUi(MomentEventWidget);

        QMetaObject::connectSlotsByName(MomentEventWidget);
    } // setupUi

    void retranslateUi(QWidget *MomentEventWidget)
    {
        MomentEventWidget->setWindowTitle(QCoreApplication::translate("MomentEventWidget", "Form", nullptr));
        startTimeLabel->setText(QCoreApplication::translate("MomentEventWidget", "startTime", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MomentEventWidget: public Ui_MomentEventWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOMENTEVENTWIDGET_H
