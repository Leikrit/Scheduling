#include "taskeditdialog.h"
#include "ui_taskeditdialog.h"
#include "todowidget.h"

QString curr;

TaskEditDialog::TaskEditDialog(QWidget *parent,QString cur,int type) :
    QDialog(parent),
    ui(new Ui::TaskEditDialog)
{
    ui->setupUi(this);
    ui->label_2->setText("Current : "+cur);

    this->setStyleSheet(
                "QCheckBox{font-family:Adobe Heiti Std R;font:10.5pt;}"
                "QCheckBox#checkBox{color:grey;}"
                "QCheckBox#checkBox_2{color:black;}"
                "QCheckBox#checkBox_3{color:rgba(255,0,0,0.75);}"
                "QCheckBox#checkBox_4{color:rgba(255,0,0,1); font:bold;}");

    if(type==0)
    {
        connect(this,SIGNAL(send_edit(QString,int)),parent,SLOT(rec_edit(QString,int)));
    }
    else if(type==1)
    {
        connect(this,SIGNAL(send_edit(QString,int)),parent,SLOT(rec_edit2(QString,int)));
    }

    curr = cur;

    ui->pushButton->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");
}

TaskEditDialog::~TaskEditDialog()
{
    delete ui;
}

void TaskEditDialog::on_pushButton_clicked()
{
    int x=0;
    if(ui->checkBox->isChecked())
    {
        x=1;
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->checkBox_3->setCheckState(Qt::Unchecked);
        ui->checkBox_4->setCheckState(Qt::Unchecked);
    }
    else if(ui->checkBox_2->isChecked())
    {
        x=2;
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox_3->setCheckState(Qt::Unchecked);
        ui->checkBox_4->setCheckState(Qt::Unchecked);
    }
    else if(ui->checkBox_3->isChecked())
    {
        x=3;
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->checkBox_4->setCheckState(Qt::Unchecked);
    }
    else if(ui->checkBox_4->isChecked())
    {
        x=4;
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->checkBox_3->setCheckState(Qt::Unchecked);
    }
    QString s;
    if(ui->lineEdit->text()=="")
    {
        s = curr;
    }
    else
    {
        s = "    "+ui->lineEdit->text();
    }
    emit send_edit(s,x);
    close();
}
