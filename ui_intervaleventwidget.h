/********************************************************************************
** Form generated from reading UI file 'intervaleventwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERVALEVENTWIDGET_H
#define UI_INTERVALEVENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntervalEventWidget
{
public:
    QWidget *widget;
    QLabel *startTimeLabel;
    QLabel *endTimeLabel;

    void setupUi(QWidget *IntervalEventWidget)
    {
        if (IntervalEventWidget->objectName().isEmpty())
            IntervalEventWidget->setObjectName(QString::fromUtf8("IntervalEventWidget"));
        IntervalEventWidget->resize(800, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IntervalEventWidget->sizePolicy().hasHeightForWidth());
        IntervalEventWidget->setSizePolicy(sizePolicy);
        IntervalEventWidget->setMinimumSize(QSize(800, 100));
        IntervalEventWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(11);
        IntervalEventWidget->setFont(font);
        widget = new QWidget(IntervalEventWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(800, 100));
        startTimeLabel = new QLabel(widget);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));
        startTimeLabel->setGeometry(QRect(0, 0, 150, 50));
        sizePolicy1.setHeightForWidth(startTimeLabel->sizePolicy().hasHeightForWidth());
        startTimeLabel->setSizePolicy(sizePolicy1);
        startTimeLabel->setMinimumSize(QSize(150, 50));
        startTimeLabel->setMaximumSize(QSize(150, 50));
        startTimeLabel->setAlignment(Qt::AlignCenter);
        endTimeLabel = new QLabel(widget);
        endTimeLabel->setObjectName(QString::fromUtf8("endTimeLabel"));
        endTimeLabel->setGeometry(QRect(0, 50, 150, 50));
        sizePolicy1.setHeightForWidth(endTimeLabel->sizePolicy().hasHeightForWidth());
        endTimeLabel->setSizePolicy(sizePolicy1);
        endTimeLabel->setMinimumSize(QSize(150, 50));
        endTimeLabel->setMaximumSize(QSize(150, 50));
        endTimeLabel->setTextFormat(Qt::RichText);
        endTimeLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(IntervalEventWidget);

        QMetaObject::connectSlotsByName(IntervalEventWidget);
    } // setupUi

    void retranslateUi(QWidget *IntervalEventWidget)
    {
        IntervalEventWidget->setWindowTitle(QCoreApplication::translate("IntervalEventWidget", "Form", nullptr));
        startTimeLabel->setText(QCoreApplication::translate("IntervalEventWidget", "startTime", nullptr));
        endTimeLabel->setText(QCoreApplication::translate("IntervalEventWidget", "endTime", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntervalEventWidget: public Ui_IntervalEventWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERVALEVENTWIDGET_H
