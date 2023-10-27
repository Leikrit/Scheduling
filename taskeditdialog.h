#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include <QSize>
#include "todowidget.h"
#include "ui_taskeditdialog.h"

//包括UI
namespace Ui {
class TaskEditDialog;
}

//编辑task的类
class TaskEditDialog : public QDialog
{
    Q_OBJECT

public:

    //构造器
    explicit TaskEditDialog(QWidget *parent = nullptr,QString cur="Current", int type = 0);
    ~TaskEditDialog();

private slots:
    //按钮的槽函数
    void on_pushButton_clicked();

signals:
    //信号函数，与相应函数连接起来
    void send_edit(QString str,int flag);

private:
    //数据成员包括ui
    Ui::TaskEditDialog *ui;
};

#endif // EDIT_H
