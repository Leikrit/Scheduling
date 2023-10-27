/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QLabel *settingLabel;
    QLabel *splitLine1;
    QLabel *designedByLabel;
    QLabel *jyjLabel;
    QPushButton *tryAnotherBtn;
    QCheckBox *mottoCheckBox;
    QLabel *ljyLabel;
    QLabel *lysLabel;
    QLabel *lylLabel;
    QLabel *splitLine2;

    void setupUi(QWidget *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QString::fromUtf8("SettingDialog"));
        SettingDialog->resize(540, 360);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingDialog->sizePolicy().hasHeightForWidth());
        SettingDialog->setSizePolicy(sizePolicy);
        SettingDialog->setMinimumSize(QSize(540, 360));
        SettingDialog->setMaximumSize(QSize(540, 360));
        settingLabel = new QLabel(SettingDialog);
        settingLabel->setObjectName(QString::fromUtf8("settingLabel"));
        settingLabel->setGeometry(QRect(30, 35, 150, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font.setPointSize(13);
        settingLabel->setFont(font);
        settingLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitLine1 = new QLabel(SettingDialog);
        splitLine1->setObjectName(QString::fromUtf8("splitLine1"));
        splitLine1->setGeometry(QRect(200, 40, 16, 22));
        splitLine1->setFont(font);
        designedByLabel = new QLabel(SettingDialog);
        designedByLabel->setObjectName(QString::fromUtf8("designedByLabel"));
        designedByLabel->setGeometry(QRect(30, 150, 150, 30));
        designedByLabel->setFont(font);
        designedByLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        jyjLabel = new QLabel(SettingDialog);
        jyjLabel->setObjectName(QString::fromUtf8("jyjLabel"));
        jyjLabel->setGeometry(QRect(250, 155, 150, 30));
        jyjLabel->setFont(font);
        tryAnotherBtn = new QPushButton(SettingDialog);
        tryAnotherBtn->setObjectName(QString::fromUtf8("tryAnotherBtn"));
        tryAnotherBtn->setGeometry(QRect(250, 80, 240, 35));
        tryAnotherBtn->setFont(font);
        mottoCheckBox = new QCheckBox(SettingDialog);
        mottoCheckBox->setObjectName(QString::fromUtf8("mottoCheckBox"));
        mottoCheckBox->setGeometry(QRect(250, 35, 251, 30));
        mottoCheckBox->setFont(font);
        ljyLabel = new QLabel(SettingDialog);
        ljyLabel->setObjectName(QString::fromUtf8("ljyLabel"));
        ljyLabel->setGeometry(QRect(250, 195, 150, 30));
        ljyLabel->setFont(font);
        lysLabel = new QLabel(SettingDialog);
        lysLabel->setObjectName(QString::fromUtf8("lysLabel"));
        lysLabel->setGeometry(QRect(250, 235, 150, 30));
        lysLabel->setFont(font);
        lylLabel = new QLabel(SettingDialog);
        lylLabel->setObjectName(QString::fromUtf8("lylLabel"));
        lylLabel->setGeometry(QRect(250, 275, 150, 30));
        lylLabel->setFont(font);
        splitLine2 = new QLabel(SettingDialog);
        splitLine2->setObjectName(QString::fromUtf8("splitLine2"));
        splitLine2->setGeometry(QRect(200, 155, 16, 22));
        splitLine2->setFont(font);

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QWidget *SettingDialog)
    {
        SettingDialog->setWindowTitle(QCoreApplication::translate("SettingDialog", "Form", nullptr));
        settingLabel->setText(QCoreApplication::translate("SettingDialog", "Setting", nullptr));
        splitLine1->setText(QCoreApplication::translate("SettingDialog", "|", nullptr));
        designedByLabel->setText(QCoreApplication::translate("SettingDialog", "Designed by", nullptr));
        jyjLabel->setText(QCoreApplication::translate("SettingDialog", "<html><head/><body><p>Jiang Yingjin</p></body></html>", nullptr));
        tryAnotherBtn->setText(QCoreApplication::translate("SettingDialog", "Try another one", nullptr));
        mottoCheckBox->setText(QCoreApplication::translate("SettingDialog", "Turn off the motto", nullptr));
        ljyLabel->setText(QCoreApplication::translate("SettingDialog", "Leikrit Li", nullptr));
        lysLabel->setText(QCoreApplication::translate("SettingDialog", "Yusheng Lin", nullptr));
        lylLabel->setText(QCoreApplication::translate("SettingDialog", "Yulong Li", nullptr));
        splitLine2->setText(QCoreApplication::translate("SettingDialog", "|", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
