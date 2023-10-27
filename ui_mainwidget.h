/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <calendarwidget.h>
#include <memowidget.h>
#include <todowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *sideBar;
    QHBoxLayout *horizontalLayout_4;
    QWidget *sideBarWidget;
    QToolButton *calendarBtn;
    QToolButton *todoBtn;
    QToolButton *memoBtn;
    QPushButton *settingBtn;
    QWidget *splitLine;
    QStackedWidget *stackedWidget;
    QWidget *calendarPage;
    QHBoxLayout *horizontalLayout_2;
    CalendarWidget *calendarWidget;
    QLabel *mottoLabel;
    QLabel *celebrityLabel;
    QLabel *empty;
    QWidget *eventWidget;
    QListWidget *eventlistWidget;
    QPushButton *addBtn;
    QWidget *calendarFullPage;
    QWidget *todoPage;
    TodoWidget *todoWidget;
    QWidget *memoPage;
    MemoWidget *memoWidget;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1400, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        MainWidget->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(MainWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sideBar = new QWidget(MainWidget);
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
        calendarBtn = new QToolButton(sideBarWidget);
        calendarBtn->setObjectName(QString::fromUtf8("calendarBtn"));
        calendarBtn->setGeometry(QRect(15, 250, 70, 70));
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
        todoBtn = new QToolButton(sideBarWidget);
        todoBtn->setObjectName(QString::fromUtf8("todoBtn"));
        todoBtn->setGeometry(QRect(15, 370, 70, 70));
        sizePolicy.setHeightForWidth(todoBtn->sizePolicy().hasHeightForWidth());
        todoBtn->setSizePolicy(sizePolicy);
        todoBtn->setMinimumSize(QSize(70, 70));
        todoBtn->setMaximumSize(QSize(70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/Todo_icon5.png"), QSize(), QIcon::Normal, QIcon::Off);
        todoBtn->setIcon(icon2);
        todoBtn->setIconSize(QSize(55, 55));
        memoBtn = new QToolButton(sideBarWidget);
        memoBtn->setObjectName(QString::fromUtf8("memoBtn"));
        memoBtn->setGeometry(QRect(15, 490, 70, 70));
        sizePolicy.setHeightForWidth(memoBtn->sizePolicy().hasHeightForWidth());
        memoBtn->setSizePolicy(sizePolicy);
        memoBtn->setMinimumSize(QSize(70, 70));
        memoBtn->setMaximumSize(QSize(70, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/Memo_icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        memoBtn->setIcon(icon3);
        memoBtn->setIconSize(QSize(55, 55));
        settingBtn = new QPushButton(sideBarWidget);
        settingBtn->setObjectName(QString::fromUtf8("settingBtn"));
        settingBtn->setGeometry(QRect(31, 735, 37, 33));
        settingBtn->setFlat(true);

        horizontalLayout_4->addWidget(sideBarWidget);

        splitLine = new QWidget(sideBar);
        splitLine->setObjectName(QString::fromUtf8("splitLine"));
        sizePolicy.setHeightForWidth(splitLine->sizePolicy().hasHeightForWidth());
        splitLine->setSizePolicy(sizePolicy);
        splitLine->setMinimumSize(QSize(1, 700));

        horizontalLayout_4->addWidget(splitLine);


        horizontalLayout->addWidget(sideBar);

        stackedWidget = new QStackedWidget(MainWidget);
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
        calendarWidget = new CalendarWidget(calendarPage);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        calendarWidget->setMinimumSize(QSize(450, 800));
        mottoLabel = new QLabel(calendarWidget);
        mottoLabel->setObjectName(QString::fromUtf8("mottoLabel"));
        mottoLabel->setGeometry(QRect(30, 600, 400, 140));
        celebrityLabel = new QLabel(calendarWidget);
        celebrityLabel->setObjectName(QString::fromUtf8("celebrityLabel"));
        celebrityLabel->setGeometry(QRect(30, 740, 411, 35));
        celebrityLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        empty = new QLabel(calendarWidget);
        empty->setObjectName(QString::fromUtf8("empty"));
        empty->setGeometry(QRect(10, 600, 451, 181));
        sizePolicy.setHeightForWidth(empty->sizePolicy().hasHeightForWidth());
        empty->setSizePolicy(sizePolicy);
        empty->raise();
        mottoLabel->raise();
        celebrityLabel->raise();

        horizontalLayout_2->addWidget(calendarWidget);

        eventWidget = new QWidget(calendarPage);
        eventWidget->setObjectName(QString::fromUtf8("eventWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(eventWidget->sizePolicy().hasHeightForWidth());
        eventWidget->setSizePolicy(sizePolicy1);
        eventWidget->setMinimumSize(QSize(0, 800));
        eventlistWidget = new QListWidget(eventWidget);
        eventlistWidget->setObjectName(QString::fromUtf8("eventlistWidget"));
        eventlistWidget->setGeometry(QRect(25, 25, 800, 750));
        sizePolicy.setHeightForWidth(eventlistWidget->sizePolicy().hasHeightForWidth());
        eventlistWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Cambria Math"));
        font.setPointSize(16);
        eventlistWidget->setFont(font);
        eventlistWidget->setStyleSheet(QString::fromUtf8(""));
        eventlistWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        eventlistWidget->setProperty("showDropIndicator", QVariant(false));
        eventlistWidget->setDefaultDropAction(Qt::IgnoreAction);
        eventlistWidget->setSelectionMode(QAbstractItemView::NoSelection);
        addBtn = new QPushButton(eventWidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(710, 670, 80, 80));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addBtn->setIcon(icon4);
        addBtn->setIconSize(QSize(55, 55));

        horizontalLayout_2->addWidget(eventWidget);

        stackedWidget->addWidget(calendarPage);
        calendarFullPage = new QWidget();
        calendarFullPage->setObjectName(QString::fromUtf8("calendarFullPage"));
        stackedWidget->addWidget(calendarFullPage);
        todoPage = new QWidget();
        todoPage->setObjectName(QString::fromUtf8("todoPage"));
        todoWidget = new TodoWidget(todoPage);
        todoWidget->setObjectName(QString::fromUtf8("todoWidget"));
        todoWidget->setGeometry(QRect(0, 0, 1300, 800));
        stackedWidget->addWidget(todoPage);
        memoPage = new QWidget();
        memoPage->setObjectName(QString::fromUtf8("memoPage"));
        memoWidget = new MemoWidget(memoPage);
        memoWidget->setObjectName(QString::fromUtf8("memoWidget"));
        memoWidget->setGeometry(QRect(0, 0, 1300, 800));
        stackedWidget->addWidget(memoPage);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Scheduling", nullptr));
        calendarBtn->setText(QCoreApplication::translate("MainWidget", "PushButton", nullptr));
        todoBtn->setText(QCoreApplication::translate("MainWidget", "PushButton", nullptr));
        memoBtn->setText(QCoreApplication::translate("MainWidget", "PushButton", nullptr));
        settingBtn->setText(QString());
        mottoLabel->setText(QCoreApplication::translate("MainWidget", "Motto", nullptr));
        celebrityLabel->setText(QCoreApplication::translate("MainWidget", "TextLabel", nullptr));
        empty->setText(QString());
        addBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
