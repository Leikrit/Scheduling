/********************************************************************************
** Form generated from reading UI file 'todowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOWIDGET_H
#define UI_TODOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TodoWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *GotoFinishedpageButton;
    QWidget *page_2;
    QListWidget *listWidget_2;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_6;
    QLabel *label_8;
    QPushButton *GotoUndonepageButton;
    QLabel *label;

    void setupUi(QWidget *TodoWidget)
    {
        if (TodoWidget->objectName().isEmpty())
            TodoWidget->setObjectName(QString::fromUtf8("TodoWidget"));
        TodoWidget->resize(1300, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TodoWidget->sizePolicy().hasHeightForWidth());
        TodoWidget->setSizePolicy(sizePolicy);
        TodoWidget->setMinimumSize(QSize(1300, 800));
        TodoWidget->setMaximumSize(QSize(1300, 800));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        TodoWidget->setFont(font);
        stackedWidget = new QStackedWidget(TodoWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1300, 800));
        stackedWidget->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget->setMouseTracking(true);
        stackedWidget->setTabletTracking(true);
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setFrameShadow(QFrame::Raised);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 130, 921, 50));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(150, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Palatino Linotype"));
        font1.setPointSize(12);
        lineEdit->setFont(font1);
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1040, 130, 101, 50));
        pushButton->setMinimumSize(QSize(10, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Palatino Linotype"));
        font2.setPointSize(12);
        font2.setBold(false);
        pushButton->setFont(font2);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../icon/toplion\345\233\276\346\240\207\345\272\223 _\346\267\273\345\212\240-71.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(30, 30));
        listWidget = new QListWidget(page);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(90, 200, 1061, 421));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(14);
        font3.setBold(true);
        listWidget->setFont(font3);
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listWidget->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 640, 221, 40));
        pushButton_3->setMinimumSize(QSize(200, 40));
        pushButton_3->setFont(font1);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/manage.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(30, 30));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 640, 200, 40));
        pushButton_2->setMinimumSize(QSize(200, 40));
        pushButton_2->setFont(font1);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(30, 30));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(90, 640, 201, 40));
        pushButton_4->setMinimumSize(QSize(200, 40));
        pushButton_4->setFont(font1);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(30, 30));
        GotoFinishedpageButton = new QPushButton(page);
        GotoFinishedpageButton->setObjectName(QString::fromUtf8("GotoFinishedpageButton"));
        GotoFinishedpageButton->setGeometry(QRect(950, 640, 201, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Palatino Linotype"));
        font4.setPointSize(10);
        GotoFinishedpageButton->setFont(font4);
        GotoFinishedpageButton->setCursor(QCursor(Qt::PointingHandCursor));
        GotoFinishedpageButton->setStyleSheet(QString::fromUtf8("GotoFinishedpage"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../icon/Chevron-Right 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        GotoFinishedpageButton->setIcon(icon4);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        listWidget_2 = new QListWidget(page_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setEnabled(true);
        listWidget_2->setGeometry(QRect(99, 110, 611, 511));
        listWidget_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Algerian\";\n"
"text-decoration: line-through;"));
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(749, 470, 421, 221));
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(750, 170, 400, 40));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Algerian"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(false);
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Algerian\";"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(750, 230, 400, 40));
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Algerian\";"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(750, 420, 400, 40));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Palatino Linotype"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setItalic(false);
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(299, 650, 181, 40));
        pushButton_5->setMinimumSize(QSize(150, 40));
        pushButton_5->setFont(font1);
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../icon/toplion\345\233\276\346\240\207\345\272\223 _\346\233\264\345\244\232\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);
        pushButton_5->setIconSize(QSize(30, 30));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(510, 650, 200, 40));
        pushButton_6->setMinimumSize(QSize(200, 40));
        pushButton_6->setFont(font1);
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../icon/toplion\345\233\276\346\240\207\345\272\223 _\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon6);
        pushButton_6->setIconSize(QSize(30, 30));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(750, 110, 400, 40));
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"Algerian\";"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(749, 280, 531, 141));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Arial"));
        font7.setPointSize(7);
        label_8->setFont(font7);
        label_8->setAlignment(Qt::AlignCenter);
        GotoUndonepageButton = new QPushButton(page_2);
        GotoUndonepageButton->setObjectName(QString::fromUtf8("GotoUndonepageButton"));
        GotoUndonepageButton->setGeometry(QRect(99, 650, 171, 41));
        GotoUndonepageButton->setFont(font);
        GotoUndonepageButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../icon/Chevron-Left 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        GotoUndonepageButton->setIcon(icon7);
        stackedWidget->addWidget(page_2);
        label = new QLabel(TodoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(10, 10, 1261, 781));
        label->raise();
        stackedWidget->raise();

        retranslateUi(TodoWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TodoWidget);
    } // setupUi

    void retranslateUi(QWidget *TodoWidget)
    {
        TodoWidget->setWindowTitle(QCoreApplication::translate("TodoWidget", "Widget", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("TodoWidget", "Enter a task item", nullptr));
        pushButton->setText(QCoreApplication::translate("TodoWidget", "Add", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TodoWidget", "Edit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TodoWidget", "Finish", nullptr));
        pushButton_4->setText(QCoreApplication::translate("TodoWidget", "Delete", nullptr));
        GotoFinishedpageButton->setText(QCoreApplication::translate("TodoWidget", "Finished Page", nullptr));
        label_2->setText(QCoreApplication::translate("TodoWidget", "Unfinished Tasks:", nullptr));
        label_3->setText(QCoreApplication::translate("TodoWidget", "Finished Tasks:", nullptr));
        label_5->setText(QCoreApplication::translate("TodoWidget", "Write your summary:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("TodoWidget", "Edit", nullptr));
        pushButton_6->setText(QCoreApplication::translate("TodoWidget", "Delete", nullptr));
        label_6->setText(QCoreApplication::translate("TodoWidget", "All Tasks:", nullptr));
        label_8->setText(QCoreApplication::translate("TodoWidget", "<html><head/><body><p><span style=\" color:#aa0000;\">Notice: All finished tasks will be auto cleared,</span></p><p><span style=\" color:#aa0000;\">try to finish all the task in your day!</span></p></body></html>", nullptr));
        GotoUndonepageButton->setText(QCoreApplication::translate("TodoWidget", "Undone Page", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TodoWidget: public Ui_TodoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOWIDGET_H
