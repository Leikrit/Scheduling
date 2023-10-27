#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QWidget>
#include <QDialog>
#include"eventfull.h"
#include "detectareaallday.h"
#include"eventfull.h"
#include"eventbasewidget.h"
#include<QPushButton>
#include<QButtonGroup>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    SettingDialog(QWidget *parent,bool mottoOff=false);
    ~SettingDialog();
    Ui::SettingDialog *ui;


};

#endif // SETTINGDIALOG_H




