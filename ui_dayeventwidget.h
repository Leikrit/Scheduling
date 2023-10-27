/********************************************************************************
** Form generated from reading UI file 'dayeventwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYEVENTWIDGET_H
#define UI_DAYEVENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DayEventWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *alldayLabel;

    void setupUi(QWidget *DayEventWidget)
    {
        if (DayEventWidget->objectName().isEmpty())
            DayEventWidget->setObjectName(QString::fromUtf8("DayEventWidget"));
        DayEventWidget->resize(800, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DayEventWidget->sizePolicy().hasHeightForWidth());
        DayEventWidget->setSizePolicy(sizePolicy);
        DayEventWidget->setMinimumSize(QSize(800, 100));
        widget = new QWidget(DayEventWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(800, 100));
        widget->setMaximumSize(QSize(800, 100));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        alldayLabel = new QLabel(widget);
        alldayLabel->setObjectName(QString::fromUtf8("alldayLabel"));
        sizePolicy1.setHeightForWidth(alldayLabel->sizePolicy().hasHeightForWidth());
        alldayLabel->setSizePolicy(sizePolicy1);
        alldayLabel->setMinimumSize(QSize(150, 100));
        alldayLabel->setMaximumSize(QSize(150, 100));
        alldayLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(alldayLabel);


        retranslateUi(DayEventWidget);

        QMetaObject::connectSlotsByName(DayEventWidget);
    } // setupUi

    void retranslateUi(QWidget *DayEventWidget)
    {
        DayEventWidget->setWindowTitle(QCoreApplication::translate("DayEventWidget", "Form", nullptr));
        alldayLabel->setText(QCoreApplication::translate("DayEventWidget", "All day", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DayEventWidget: public Ui_DayEventWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYEVENTWIDGET_H
