#include "settingdialog.h"
#include "eventeditdialog.h"
#include "ui_settingdialog.h"
#include"eventfull.h"
#include"eventbasewidget.h"
#include"global.h"
#include <QIcon>
#include<QPixmap>
#include<QString>
#include<QDate>
#include<QTime>
#include<QDateTime>
#include<QDebug>
#include<QDataStream>
#include<QCheckBox>
#include<QPoint>
#include<QIcon>
#include"detectarea.h"
#include<QRect>
#include<QPushButton>
#include<QButtonGroup>


SettingDialog::SettingDialog(QWidget *parent,bool mottoOff)
    :QDialog(parent),
      ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    //设置界面和样式表
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    this->setWindowFlag(Qt::WindowCloseButtonHint,true);
    this->setWindowFlag(Qt::FramelessWindowHint,false);

    this->move(QPoint(710,330));

    this->setStyleSheet(
                "QDialog{background:white; border:0px;"
                        "border-radius:0px;}"
                "QLabel#splitLine1,QLabel#splitLine2{color:rgba(0,0,0,0.3);}");

    this->setWindowTitle("Setting & About");

    if(mottoOff)
        ui->mottoCheckBox->setChecked(true);

    //把这个组件中的CheckBox改变和全局中的中转CheckBox连接起来
    //全局中的中转checkbox 再连接其他组件中的内容
    //这样就可以连接软件中的不同组件
    connect(ui->mottoCheckBox,&QCheckBox::stateChanged,[=](){
        if(ui->mottoCheckBox->isChecked())
            globalMottoCheckBox->setChecked(true);
        else
            globalMottoCheckBox->setChecked(false);
    });

    connect(globalMottoCheckBox,&QCheckBox::stateChanged,[=](){
        if(globalMottoCheckBox->isChecked())
            ui->mottoCheckBox->setChecked(true);
        else
            ui->mottoCheckBox->setChecked(false);
    });

    connect(ui->tryAnotherBtn,&QPushButton::clicked,[=](){
        if (globalMottoChangeCheckBox->isChecked())
            globalMottoChangeCheckBox->setChecked(false);
        else
            globalMottoChangeCheckBox->setChecked(true);
    });



    this->show();
    this->raise();
}





SettingDialog::~SettingDialog()
{
    delete ui;
}
