/********************************************************************************
** Form generated from reading UI file 'eventitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTITEM_H
#define UI_EVENTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventItem
{
public:

    void setupUi(QWidget *EventItem)
    {
        if (EventItem->objectName().isEmpty())
            EventItem->setObjectName(QString::fromUtf8("EventItem"));
        EventItem->resize(800, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventItem->sizePolicy().hasHeightForWidth());
        EventItem->setSizePolicy(sizePolicy);
        EventItem->setMinimumSize(QSize(800, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(16);
        EventItem->setFont(font);

        retranslateUi(EventItem);

        QMetaObject::connectSlotsByName(EventItem);
    } // setupUi

    void retranslateUi(QWidget *EventItem)
    {
        EventItem->setWindowTitle(QCoreApplication::translate("EventItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventItem: public Ui_EventItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTITEM_H
