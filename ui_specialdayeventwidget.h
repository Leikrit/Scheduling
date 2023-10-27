/********************************************************************************
** Form generated from reading UI file 'specialdayeventwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIALDAYEVENTWIDGET_H
#define UI_SPECIALDAYEVENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpecialDayEventWidget
{
public:
    QWidget *widget;

    void setupUi(QWidget *SpecialDayEventWidget)
    {
        if (SpecialDayEventWidget->objectName().isEmpty())
            SpecialDayEventWidget->setObjectName(QString::fromUtf8("SpecialDayEventWidget"));
        SpecialDayEventWidget->resize(800, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpecialDayEventWidget->sizePolicy().hasHeightForWidth());
        SpecialDayEventWidget->setSizePolicy(sizePolicy);
        SpecialDayEventWidget->setMinimumSize(QSize(800, 100));
        SpecialDayEventWidget->setMaximumSize(QSize(16777215, 16777215));
        widget = new QWidget(SpecialDayEventWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(800, 100));
        widget->setMaximumSize(QSize(800, 100));

        retranslateUi(SpecialDayEventWidget);

        QMetaObject::connectSlotsByName(SpecialDayEventWidget);
    } // setupUi

    void retranslateUi(QWidget *SpecialDayEventWidget)
    {
        SpecialDayEventWidget->setWindowTitle(QCoreApplication::translate("SpecialDayEventWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpecialDayEventWidget: public Ui_SpecialDayEventWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECIALDAYEVENTWIDGET_H
