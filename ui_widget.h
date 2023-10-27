/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *sideBar;
    QHBoxLayout *horizontalLayout_4;
    QWidget *sideBarWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer1;
    QToolButton *calendarBtn;
    QSpacerItem *verticalSpacer;
    QToolButton *todoBtn;
    QSpacerItem *verticalSpacer_2;
    QToolButton *memoBtn;
    QSpacerItem *verticalSpacer2;
    QWidget *splitLine;
    QStackedWidget *stackedWidget;
    QWidget *calendarPage;
    QHBoxLayout *horizontalLayout_2;
    QWidget *calendarWidget;
    QWidget *eventWidget;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *eventlistWidget;
    QWidget *calendarFullPage;
    QWidget *todoPage;
    QWidget *memoPage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1400, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Calendar_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sideBar = new QWidget(Widget);
        sideBar->setObjectName(QString::fromUtf8("sideBar"));
        sizePolicy.setHeightForWidth(sideBar->sizePolicy().hasHeightForWidth());
        sideBar->setSizePolicy(sizePolicy);
        sideBar->setMinimumSize(QSize(100, 800));
        horizontalLayout_4 = new QHBoxLayout(sideBar);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        sideBarWidget = new QWidget(sideBar);
        sideBarWidget->setObjectName(QString::fromUtf8("sideBarWidget"));
        sizePolicy.setHeightForWidth(sideBarWidget->sizePolicy().hasHeightForWidth());
        sideBarWidget->setSizePolicy(sizePolicy);
        sideBarWidget->setMinimumSize(QSize(99, 800));
        verticalLayout = new QVBoxLayout(sideBarWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(15, 0, 0, 0);
        verticalSpacer1 = new QSpacerItem(20, 271, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer1);

        calendarBtn = new QToolButton(sideBarWidget);
        calendarBtn->setObjectName(QString::fromUtf8("calendarBtn"));
        sizePolicy.setHeightForWidth(calendarBtn->sizePolicy().hasHeightForWidth());
        calendarBtn->setSizePolicy(sizePolicy);
        calendarBtn->setMinimumSize(QSize(70, 70));
        calendarBtn->setMaximumSize(QSize(70, 70));
        calendarBtn->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/Calendar_icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        calendarBtn->setIcon(icon1);
        calendarBtn->setIconSize(QSize(55, 55));
        calendarBtn->setCheckable(false);
        calendarBtn->setChecked(false);
        calendarBtn->setAutoExclusive(false);

        verticalLayout->addWidget(calendarBtn);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        todoBtn = new QToolButton(sideBarWidget);
        todoBtn->setObjectName(QString::fromUtf8("todoBtn"));
        sizePolicy.setHeightForWidth(todoBtn->sizePolicy().hasHeightForWidth());
        todoBtn->setSizePolicy(sizePolicy);
        todoBtn->setMinimumSize(QSize(70, 70));
        todoBtn->setMaximumSize(QSize(70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/Todo_icon5.png"), QSize(), QIcon::Normal, QIcon::Off);
        todoBtn->setIcon(icon2);
        todoBtn->setIconSize(QSize(55, 55));

        verticalLayout->addWidget(todoBtn);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        memoBtn = new QToolButton(sideBarWidget);
        memoBtn->setObjectName(QString::fromUtf8("memoBtn"));
        sizePolicy.setHeightForWidth(memoBtn->sizePolicy().hasHeightForWidth());
        memoBtn->setSizePolicy(sizePolicy);
        memoBtn->setMinimumSize(QSize(70, 70));
        memoBtn->setMaximumSize(QSize(70, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/Memo_icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        memoBtn->setIcon(icon3);
        memoBtn->setIconSize(QSize(55, 55));

        verticalLayout->addWidget(memoBtn);

        verticalSpacer2 = new QSpacerItem(20, 94, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer2);


        horizontalLayout_4->addWidget(sideBarWidget);

        splitLine = new QWidget(sideBar);
        splitLine->setObjectName(QString::fromUtf8("splitLine"));
        sizePolicy.setHeightForWidth(splitLine->sizePolicy().hasHeightForWidth());
        splitLine->setSizePolicy(sizePolicy);
        splitLine->setMinimumSize(QSize(1, 700));

        horizontalLayout_4->addWidget(splitLine);


        horizontalLayout->addWidget(sideBar);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(1300, 800));
        calendarPage = new QWidget();
        calendarPage->setObjectName(QString::fromUtf8("calendarPage"));
        horizontalLayout_2 = new QHBoxLayout(calendarPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QWidget(calendarPage);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        calendarWidget->setMinimumSize(QSize(450, 800));

        horizontalLayout_2->addWidget(calendarWidget);

        eventWidget = new QWidget(calendarPage);
        eventWidget->setObjectName(QString::fromUtf8("eventWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(eventWidget->sizePolicy().hasHeightForWidth());
        eventWidget->setSizePolicy(sizePolicy1);
        eventWidget->setMinimumSize(QSize(0, 800));
        horizontalLayout_3 = new QHBoxLayout(eventWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(25, 25, 25, 25);
        eventlistWidget = new QListWidget(eventWidget);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(eventlistWidget);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        eventlistWidget->setObjectName(QString::fromUtf8("eventlistWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Cambria Math"));
        font.setPointSize(16);
        eventlistWidget->setFont(font);
        eventlistWidget->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(eventlistWidget);


        horizontalLayout_2->addWidget(eventWidget);

        stackedWidget->addWidget(calendarPage);
        calendarFullPage = new QWidget();
        calendarFullPage->setObjectName(QString::fromUtf8("calendarFullPage"));
        stackedWidget->addWidget(calendarFullPage);
        todoPage = new QWidget();
        todoPage->setObjectName(QString::fromUtf8("todoPage"));
        stackedWidget->addWidget(todoPage);
        memoPage = new QWidget();
        memoPage->setObjectName(QString::fromUtf8("memoPage"));
        stackedWidget->addWidget(memoPage);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Scheduling", nullptr));
        calendarBtn->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        todoBtn->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        memoBtn->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));

        const bool __sortingEnabled = eventlistWidget->isSortingEnabled();
        eventlistWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = eventlistWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Widget", "\346\265\213\350\257\225", nullptr));
        eventlistWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
