#ifndef WIDGET_H
#define WIDGET_H

#include "task.h"
#include <QWidget>
#include <QListWidget>
#include <QSize>
#include <QEvent>
#include<QMessageBox>
#include<QFile>
#include<QDataStream>
#include<QList>
#include<string>
#include<fstream>
#include<QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QCheckBox>
#include <QSize>
#include <QAnimationGroup>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>


QT_BEGIN_NAMESPACE
namespace Ui { class TodoWidget; }
QT_END_NAMESPACE

class TodoWidget : public QWidget
{
    Q_OBJECT

public:

    //构造函数
    TodoWidget(QWidget *parent = nullptr);

    //析构函数
    ~TodoWidget();

private:
    //数据成员ui
    Ui::TodoWidget *ui;

private slots:

    //添加事件按钮
    void on_pushButton_clicked();

    //
    void on_pushButton_2_clicked();

    //
    void on_pushButton_3_clicked();

    //
    void on_pushButton_4_clicked();

    //
    void rec_edit(QString str,int flag);

    //
    void rec_edit2(QString str,int flag);

    //
    void checkboxStateChanged(int);

    //
    bool eventFilter(QObject *watch, QEvent *evn);

    //
    void on_pushButton_5_clicked();

    //
    void on_pushButton_6_clicked();

    //
    void savingdata();

    //
    void readingdata();

    //
    void on_GotoFinishedpageButton_clicked();

    //
    void on_GotoUndonepageButton_clicked();
};
#endif // WIDGET_H
