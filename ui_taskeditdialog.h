/********************************************************************************
** Form generated from reading UI file 'taskeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKEDITDIALOG_H
#define UI_TASKEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TaskEditDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QDialog *TaskEditDialog)
    {
        if (TaskEditDialog->objectName().isEmpty())
            TaskEditDialog->setObjectName(QString::fromUtf8("TaskEditDialog"));
        TaskEditDialog->resize(520, 423);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        TaskEditDialog->setFont(font);
        label = new QLabel(TaskEditDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 181, 41));
        lineEdit = new QLineEdit(TaskEditDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 140, 451, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font1.setPointSize(10);
        lineEdit->setFont(font1);
        pushButton = new QPushButton(TaskEditDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 340, 141, 41));
        checkBox = new QCheckBox(TaskEditDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 260, 130, 35));
        checkBox->setFont(font1);
        label_2 = new QLabel(TaskEditDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 441, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font2.setPointSize(14);
        font2.setBold(true);
        label_2->setFont(font2);
        label_3 = new QLabel(TaskEditDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 220, 201, 31));
        checkBox_2 = new QCheckBox(TaskEditDialog);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(130, 260, 130, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        checkBox_2->setFont(font3);
        checkBox_3 = new QCheckBox(TaskEditDialog);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(265, 260, 130, 35));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        checkBox_3->setFont(font4);
        checkBox_3->setStyleSheet(QString::fromUtf8(""));
        checkBox_4 = new QCheckBox(TaskEditDialog);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(360, 260, 161, 35));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        checkBox_4->setFont(font5);

        retranslateUi(TaskEditDialog);

        QMetaObject::connectSlotsByName(TaskEditDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskEditDialog)
    {
        TaskEditDialog->setWindowTitle(QCoreApplication::translate("TaskEditDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TaskEditDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Edit task</span></p></body></html>", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("TaskEditDialog", "Enter task item", nullptr));
        pushButton->setText(QCoreApplication::translate("TaskEditDialog", "Confirm", nullptr));
        checkBox->setText(QCoreApplication::translate("TaskEditDialog", "Finished", nullptr));
        label_2->setText(QCoreApplication::translate("TaskEditDialog", "Current : ", nullptr));
        label_3->setText(QCoreApplication::translate("TaskEditDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">Emergency\357\274\232</span></p></body></html>", nullptr));
        checkBox_2->setText(QCoreApplication::translate("TaskEditDialog", "Not urgent", nullptr));
        checkBox_3->setText(QCoreApplication::translate("TaskEditDialog", "Urgent", nullptr));
        checkBox_4->setText(QCoreApplication::translate("TaskEditDialog", "Very urgent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskEditDialog: public Ui_TaskEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKEDITDIALOG_H
