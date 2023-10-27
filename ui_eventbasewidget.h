/********************************************************************************
** Form generated from reading UI file 'eventbasewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTBASEWIDGET_H
#define UI_EVENTBASEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventBaseWidget
{
public:
    QLabel *eventIconWidget;
    QLabel *eventIcon;
    QLabel *eventNameLabel;
    QLabel *eventLocationLabel;
    QWidget *descriptionPoint;

    void setupUi(QWidget *EventBaseWidget)
    {
        if (EventBaseWidget->objectName().isEmpty())
            EventBaseWidget->setObjectName(QString::fromUtf8("EventBaseWidget"));
        EventBaseWidget->resize(800, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventBaseWidget->sizePolicy().hasHeightForWidth());
        EventBaseWidget->setSizePolicy(sizePolicy);
        EventBaseWidget->setMinimumSize(QSize(800, 100));
        EventBaseWidget->setStyleSheet(QString::fromUtf8("EventBaseWidget{border:0px; \n"
"                            background:white; \n"
"                            font:Microsoft YaHei UI 12px;}\n"
"                        EventBaseWidget:hover{background:rgb(245,246,246);}"));
        eventIconWidget = new QLabel(EventBaseWidget);
        eventIconWidget->setObjectName(QString::fromUtf8("eventIconWidget"));
        eventIconWidget->setGeometry(QRect(150, 0, 50, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(eventIconWidget->sizePolicy().hasHeightForWidth());
        eventIconWidget->setSizePolicy(sizePolicy1);
        eventIconWidget->setMinimumSize(QSize(50, 100));
        eventIconWidget->setMaximumSize(QSize(50, 16777215));
        eventIconWidget->setScaledContents(false);
        eventIconWidget->setAlignment(Qt::AlignCenter);
        eventIconWidget->setTextInteractionFlags(Qt::NoTextInteraction);
        eventIcon = new QLabel(EventBaseWidget);
        eventIcon->setObjectName(QString::fromUtf8("eventIcon"));
        eventIcon->setGeometry(QRect(155, 30, 40, 40));
        eventNameLabel = new QLabel(EventBaseWidget);
        eventNameLabel->setObjectName(QString::fromUtf8("eventNameLabel"));
        eventNameLabel->setGeometry(QRect(150, 13, 550, 29));
        sizePolicy1.setHeightForWidth(eventNameLabel->sizePolicy().hasHeightForWidth());
        eventNameLabel->setSizePolicy(sizePolicy1);
        eventNameLabel->setMinimumSize(QSize(500, 0));
        eventNameLabel->setMaximumSize(QSize(16777215, 16777215));
        eventLocationLabel = new QLabel(EventBaseWidget);
        eventLocationLabel->setObjectName(QString::fromUtf8("eventLocationLabel"));
        eventLocationLabel->setGeometry(QRect(150, 63, 650, 29));
        sizePolicy1.setHeightForWidth(eventLocationLabel->sizePolicy().hasHeightForWidth());
        eventLocationLabel->setSizePolicy(sizePolicy1);
        eventLocationLabel->setMinimumSize(QSize(500, 0));
        eventLocationLabel->setMaximumSize(QSize(16777215, 40));
        descriptionPoint = new QWidget(EventBaseWidget);
        descriptionPoint->setObjectName(QString::fromUtf8("descriptionPoint"));
        descriptionPoint->setGeometry(QRect(715, 45, 10, 10));

        retranslateUi(EventBaseWidget);

        QMetaObject::connectSlotsByName(EventBaseWidget);
    } // setupUi

    void retranslateUi(QWidget *EventBaseWidget)
    {
        EventBaseWidget->setWindowTitle(QCoreApplication::translate("EventBaseWidget", "Form", nullptr));
        eventIconWidget->setText(QString());
        eventIcon->setText(QString());
        eventNameLabel->setText(QCoreApplication::translate("EventBaseWidget", "EventName", nullptr));
        eventLocationLabel->setText(QCoreApplication::translate("EventBaseWidget", "Event Type / Event Location | Event Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventBaseWidget: public Ui_EventBaseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTBASEWIDGET_H
