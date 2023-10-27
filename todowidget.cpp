#include "todowidget.h"
#include "ui_todowidget.h"
#include "taskeditdialog.h"
#include<QMessageBox>
#include<QString>
#include<QFile>
#include<QDataStream>
#include<QList>
#include<string>
#include<fstream>
#include<QTextStream>
#include <QFileDialog>
#include<QListWidgetItem>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QCheckBox>
#include <QSize>
#include <QVector>
#include <QMouseEvent>
#include<QFrame>

using namespace std;

// 重载item的<< 运算符
QDataStream &operator<<(QDataStream &stream, const Task &item)
{
    return stream << item.name << item.flag;
}

// 重载item的>> 运算符
QDataStream &operator>>(QDataStream &stream, Task &item)
{
    return stream >> item.name >> item.flag;
}

// savingdata的函数定义,储存文件的函数
void TodoWidget::savingdata()
{
    //创建一个task.dat来 储存用户的task item
    QFile file("task.dat");

    //判断文件是否正确打开
        if (!file.open(QIODevice::ReadWrite))
        {
            qDebug()<<"Fail to open";
        }

        //建立QStream对象
        QDataStream stream(&file);

        qDebug()<<"Read success";

        //建立一个task类型的数组储存要存的数据
        QVector<Task> items(100);

    //QString 临时名字
    QString name;

    //QString 临时颜色
    QString flag;

    //count表示现在list中有多少item
    int count = ui->listWidget->count();

    //对每一个item进行操作
     for(int i=0;i<count;i++)
     {
         //名字name为item的name
         name = ui->listWidget->item(i)->text();

         //颜色flag为item的flag
         if(ui->listWidget->item(i)->background()==Qt::gray)
         {
             flag="gray";
             items[i].isfinished = false;
         }
         else if(ui->listWidget->item(i)->background()==Qt::blue)
         {
             flag="blue";
             items[i].isfinished = false;
         }
         else if(ui->listWidget->item(i)->background()==Qt::yellow)
         {
             flag="yellow";
             items[i].isfinished = false;
         }
         else if(ui->listWidget->item(i)->background()==Qt::red)
         {
             flag="red";
             items[i].isfinished = false;
         }

         //将相应数据付给items，创造对应item对象
         items[i] = Task(name,flag,items[i].isfinished);
      }

     //将指针放回文件头
        file.seek(0);

        //输出数据到文件
        stream<<items;

        //在Debug中输出对应存储的数据
        for(int i=0;i<count;i++)
        {
            qDebug()<<"Write"<< items[i].name<< items[i].flag;
        }

        //显示关闭文件
        file.close();
}

//readingdata的函数定义,读取文件的函数
void TodoWidget::readingdata()
{
    //创建一个task.dat来 储存用户的task item
    QFile file("task.dat");

        //判断文件是否正确打开
        if (!file.open(QIODevice::ReadWrite))
        {
             QMessageBox::information(this, "Unable to open file", file.errorString());
        }

        //建立QStream对象
        QDataStream stream(&file);

        qDebug()<<"Read success";

        //建立一个task类型的数组储存要存的数据
        QVector<Task> items(100);

        //读取文件
        stream>>items;

        //在Debug中显示读取的数据
        for(int i = 0; i < items.size(); i++)
        {
             qDebug()<<"Read "<< items[i].name+" " << items[i].flag;
        }

        //显示关闭文件
        file.close();

        //对每一个itmes中的对象进行操作
        for(int i = 0; i < items.size(); i++)
        {
            //判断是否创建对应item
            if(items[i].name != "")
            {

                //新建一个checkbox组件
                QCheckBox *checkbox = new QCheckBox;

                //在list中添加同名事件
                ui->listWidget->addItem(items[i].name);

                //复合checkbox
                ui->listWidget->setItemWidget( ui->listWidget->item(i),checkbox);

                if(items[i].flag=="gray")
                {
                    ui->listWidget->item(i)->setBackground(Qt::gray);
                }
                else if(items[i].flag=="blue")
                {
                    ui->listWidget->item(i)->setBackground(Qt::blue);
                }
                else if(items[i].flag=="yellow")
                {
                    ui->listWidget->item(i)->setBackground(Qt::yellow);
                }
                else if(items[i].flag=="red")
                {
                    ui->listWidget->item(i)->setBackground(Qt::red);
                }

                ui->listWidget->item(i)->setSizeHint(QSize(45,55));

                ui->listWidget->item(i)->setTextColor(Qt::white);

            }
        }

        ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

        ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

        ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

}

//构造器
TodoWidget::TodoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoWidget)
{
    //建立起todolist的ui界面
    ui->setupUi(this);

    //在stackedwidget中设置事件监控
    ui->stackedWidget->installEventFilter(this);//StackWidget

    readingdata();

    ui->stackedWidget->setStyleSheet("QStackedWidget{border-image:url(://icon/chinese.jpg)}");

    //设置stachedwidget的每一页都透明
    ui->page->setAttribute(Qt::WA_TranslucentBackground);

    ui->page_2->setAttribute(Qt::WA_TranslucentBackground);

    ui->label->setStyleSheet("border-image:url(://icon/chinese.jpg)");

    //标记
    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

    //ui设置
    ui->lineEdit->setStyleSheet("border:none");

    ui->textEdit->setStyleSheet("border:none");

    ui->listWidget->setStyleSheet("border:none");

    ui->listWidget_2->setStyleSheet("border:none");

    ui->pushButton->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->pushButton_2->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->pushButton_3->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->pushButton_4->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->pushButton_5->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->pushButton_6->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->GotoUndonepageButton->setText("Undone Page");

    ui->GotoUndonepageButton->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");

    ui->GotoFinishedpageButton->setText("Finished Page");

    ui->GotoFinishedpageButton->setStyleSheet("border:none;background-color:lightblue;border-radius:15px");
}

TodoWidget::~TodoWidget()
{

    //存储文件
    savingdata();

    delete ui;
}


// 这个是添加task的按钮
void TodoWidget::on_pushButton_clicked()
{
    //获取list中的item数
    int count = ui->listWidget->count();
    count++;

    //若输入框为空则显示warningbox
    if(ui->lineEdit->text().isEmpty())
    {

        QMessageBox::warning(this,"Component failed","The task name cannot be empty!");

    }
    else {

        //创建新item
        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget->addItem("    "+ui->lineEdit->text());

        ui->listWidget->setItemWidget( ui->listWidget->item(count-1),checkbox);

        ui->lineEdit->setText("");

        ui->listWidget->item(count-1)->setBackground(Qt::gray);

        ui->listWidget->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget->item(count-1)->setTextColor(Qt::white);

        //标记现在的items数
        ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

        ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

        ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));


    }
}


// 这个是完成task的按钮
void TodoWidget::on_pushButton_2_clicked()
{
    int count = ui->listWidget_2->count();
    count++;

    if(ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        // 将这个赋给list2

        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget_2->addItem(ui->listWidget->currentItem()->text());

        ui->listWidget_2->setItemWidget( ui->listWidget_2->item(count-1),checkbox);

        ui->listWidget_2->item(count-1)->setBackground(Qt::green);

        ui->listWidget_2->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget_2->item(count-1)->setTextColor(Qt::white);

        //删除list的对应item
        delete ui->listWidget->currentItem();
    }

    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

}

// 这个是编辑task的按钮
void TodoWidget::on_pushButton_3_clicked()
{

    if(ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        TaskEditDialog edit_win(this,ui->listWidget->currentItem()->text(),0);
        edit_win.setModal(true);
        edit_win.exec();
    }

}

// 编辑反馈
//在undone界面中编辑
void TodoWidget::rec_edit(QString str,int flag)
{
    int count = ui->listWidget_2->count();
    count++;

    QString new_task;
    if(str==ui->listWidget->currentItem()->text())
    {
        //将task中的名字赋给new_task
        new_task = ui->listWidget->currentItem()->text();
    }
    else
    {
        new_task = str;
    }
    ui->listWidget->currentItem()->setText(new_task);
    if(flag==1)
    {
        // 将这个赋给list2

        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget_2->addItem("    "+ui->listWidget->currentItem()->text());

        ui->listWidget_2->setItemWidget( ui->listWidget_2->item(count-1),checkbox);

        ui->listWidget_2->item(count-1)->setBackground(Qt::green);

        ui->listWidget_2->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget_2->item(count-1)->setTextColor(Qt::white);

        delete ui->listWidget->currentItem();
    }
    else if(flag==2)
    {
        ui->listWidget->currentItem()->setBackground(Qt::blue);
    }
    else if(flag==3)
    {
        ui->listWidget->currentItem()->setBackground(Qt::yellow);
    }
    else if(flag==4)
    {
        ui->listWidget->currentItem()->setBackground(Qt::red);
    }
    else
    {
        ui->listWidget->currentItem()->setBackground(Qt::gray);
    }

    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

}

// 这个是删除task的按钮
void TodoWidget::on_pushButton_4_clicked()
{
    if(ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        delete ui->listWidget->currentItem();
    }

    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));
}

// 编辑反馈2
// 在finished界面编辑
void TodoWidget::rec_edit2(QString str,int flag)
{
    int count = ui->listWidget->count();
    count++;

    QString new_task;

    if(str==ui->listWidget_2->currentItem()->text())
    {
        new_task = ui->listWidget_2->currentItem()->text();
    }
    else
    {
        new_task = str;
    }
    ui->listWidget_2->currentItem()->setText(new_task);
    if(flag==1)
    {
        ui->listWidget_2->currentItem()->setBackground(Qt::green);
    }
    else if(flag==2)
    {

        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget->addItem("    "+ui->listWidget_2->currentItem()->text());

        ui->listWidget->setItemWidget( ui->listWidget->item(count-1),checkbox);

        ui->lineEdit->setText("");

        ui->listWidget->item(count-1)->setBackground(Qt::blue);

        ui->listWidget->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget->item(count-1)->setTextColor(Qt::white);

        ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

        ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

        delete ui->listWidget_2->currentItem();
    }
    else if(flag==3)
    {


        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget->addItem("    "+ui->listWidget_2->currentItem()->text());

        ui->listWidget->setItemWidget( ui->listWidget->item(count-1),checkbox);

        ui->lineEdit->setText("");

        ui->listWidget->item(count-1)->setBackground(Qt::yellow);

        ui->listWidget->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget->item(count-1)->setTextColor(Qt::white);

        ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

        ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

        delete ui->listWidget_2->currentItem();
    }
    else if(flag==4)
    {

        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget->addItem("    "+ui->listWidget_2->currentItem()->text());

        ui->listWidget->setItemWidget( ui->listWidget->item(count-1),checkbox);

        ui->lineEdit->setText("");

        ui->listWidget->item(count-1)->setBackground(Qt::red);

        ui->listWidget->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget->item(count-1)->setTextColor(Qt::white);

        ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

        ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

        delete ui->listWidget_2->currentItem();
    }
    else
    {

        QCheckBox *checkbox = new QCheckBox;

        ui->listWidget->addItem("    "+ui->listWidget_2->currentItem()->text());

        ui->listWidget->setItemWidget( ui->listWidget->item(count-1),checkbox);

        ui->lineEdit->setText("");

        ui->listWidget->item(count-1)->setBackground(Qt::gray);

        ui->listWidget->item(count-1)->setSizeHint(QSize(45,55));

        ui->listWidget->item(count-1)->setTextColor(Qt::white);

        ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

        ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));

        delete ui->listWidget_2->currentItem();
    }

    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));
}

//检查checkbox是否被改变
void TodoWidget::checkboxStateChanged(int)
{
    //StackWidget是需要监控的控件
    ui->stackedWidget->installEventFilter(this);

    QStringList itemList;
    //遍历当前的listwidget
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件

        QCheckBox *checkbox = static_cast<QCheckBox *>(ui->listWidget->itemWidget(item));

        if(checkbox->isChecked())
        {
            ui->listWidget->item(i)->setBackground(Qt::green);
        }
    }

    qDebug()<<itemList;
}

//鼠标拖动动画
//设置eventFilter监控鼠标动作
//根据鼠标点击及松开距离判断是否进行动画
bool TodoWidget::eventFilter(QObject *watch, QEvent *evn)
{

    //鼠标按下时的位置
    static int press_x;
    static int press_y;

    //鼠标释放时的位置
    static int relea_x;
    static int relea_y;

    //将之转换为鼠标事件
    QMouseEvent *event = static_cast<QMouseEvent *>(evn);

    //如果鼠标按下
    if(event->type()==QEvent::MouseButtonPress)
    {
        press_x = event->globalX();
        press_y = event->globalY();
    }

    //如果鼠标释放
    if(event->type()==QEvent::MouseButtonRelease)
    {
         relea_x = event->globalX();
         relea_y = event->globalY();
    }

    //判断滑动方向（右滑）
    if((relea_x - press_x)>12 && event->type()==QEvent::MouseButtonRelease && qAbs(relea_y-press_y)<50)
    {
        int current_page = ui->stackedWidget->currentIndex();

        if(current_page<=2)
        {
            //捕获当前界面并绘制到label上
            ui->label->setPixmap(ui->stackedWidget->currentWidget()->grab());

            //将label设置到前面
            ui->label->raise();

            //新建动画
            QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label,"geometry");

            //设置动画时间为0.6秒
            animation1->setDuration(600);

            animation1->setStartValue(QRect(0,0,this->width(),this->height()));

            animation1->setEndValue(QRect(this->width()*2,0,this->width(),this->height()));

            //切换界面
            ui->stackedWidget->setCurrentIndex(current_page-1);

            ui->stackedWidget->setStyleSheet("QStackedWidget{border-image:url(://icon/chinese.jpg)}");

            QPropertyAnimation *animation2 = new QPropertyAnimation(ui->stackedWidget->currentWidget(),"geometry");

            animation2->setDuration(600);

            animation2->setStartValue(QRect(-this->width()*2,0,this->width(),this->height()));

            animation2->setEndValue(QRect(0,0,this->width(),this->height()));

            QParallelAnimationGroup *group = new QParallelAnimationGroup;  //动画容器

            group->addAnimation(animation1);

            group->addAnimation(animation2);

            group->start();

            ui->label->stackUnder(ui->page_2);
        }
    }

    //判断滑动方向（左滑）
    if((press_x - relea_x)>12 && event->type()==QEvent::MouseButtonRelease && qAbs(relea_y-press_y)<50)
    {
        int current_page = ui->stackedWidget->currentIndex();
        if(current_page>=0)
        {
            ui->label->setPixmap(ui->stackedWidget->currentWidget()->grab());

            ui->label->raise();

            QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label,"geometry");

            animation1->setDuration(600);

            animation1->setStartValue(QRect(0,0,this->width(),this->height()));

            animation1->setEndValue(QRect(-this->width(),0,this->width(),this->height()));

            ui->stackedWidget->setCurrentIndex(current_page+1);

            ui->stackedWidget->setStyleSheet("QStackedWidget{border-image:url(://icon/chinese.jpg)}");

            QPropertyAnimation *animation2 = new QPropertyAnimation(ui->stackedWidget->currentWidget(),"geometry");

            animation2->setDuration(600);

            animation2->setStartValue(QRect(this->width()*2,0,this->width(),this->height()));

            animation2->setEndValue(QRect(0,0,this->width(),this->height()));

            QParallelAnimationGroup *group = new QParallelAnimationGroup;

            group->addAnimation(animation1);

            group->addAnimation(animation2);

            group->start();

            ui->label->stackUnder(ui->page);
        }
    }

    return QWidget::eventFilter(watch,evn);
}

// finish list
// 中的编辑按钮
void TodoWidget::on_pushButton_5_clicked()
{
    if(ui->listWidget_2->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        TaskEditDialog edit_win(this,ui->listWidget_2->currentItem()->text(),1);

        edit_win.setModal(true);

        edit_win.exec();
    }

    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));
}

//finished界面中的删除按钮
void TodoWidget::on_pushButton_6_clicked()
{
    if(ui->listWidget_2->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        delete ui->listWidget_2->currentItem();
    }

    ui->label_6->setText("All Tasks:    "+QString::number(ui->listWidget->count()+ui->listWidget_2->count()));

    ui->label_2->setText("Unfinished Tasks:    "+QString::number(ui->listWidget->count()));

    ui->label_3->setText("Finished Tasks:      "+QString::number(ui->listWidget_2->count()));
}

//翻页按钮2
void TodoWidget::on_GotoFinishedpageButton_clicked()
{
    int current_page = ui->stackedWidget->currentIndex();

    ui->label->setPixmap(ui->stackedWidget->currentWidget()->grab());

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label,"geometry");

    animation1->setDuration(600);

    animation1->setStartValue(QRect(0,0,this->width(),this->height()));

    animation1->setEndValue(QRect(-this->width(),0,this->width(),this->height()));

    ui->stackedWidget->setCurrentIndex(current_page+1);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->stackedWidget->currentWidget(),"geometry");

    animation2->setDuration(580);

    animation2->setStartValue(QRect(this->width()*2,0,this->width(),this->height()));

    animation2->setEndValue(QRect(0,0,this->width(),this->height()));

    QParallelAnimationGroup *group = new QParallelAnimationGroup;

    group->addAnimation(animation1);

    group->addAnimation(animation2);

    group->start();
}

//翻页按钮1
void TodoWidget::on_GotoUndonepageButton_clicked()
{
    int current_page = ui->stackedWidget->currentIndex();

    ui->label->setPixmap(ui->stackedWidget->currentWidget()->grab());  //捕获当前界面并绘制到label上

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label,"geometry");

    //设置动画时间为0.6秒
    animation1->setDuration(600);

    animation1->setStartValue(QRect(0,0,this->width(),this->height()));

    animation1->setEndValue(QRect(this->width()*2,0,this->width(),this->height()));

    //切换界面
    ui->stackedWidget->setCurrentIndex(current_page-1);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->stackedWidget->currentWidget(),"geometry");

    animation2->setDuration(600);

    animation2->setStartValue(QRect(-this->width()*2,0,this->width(),this->height()));

    animation2->setEndValue(QRect(0,0,this->width(),this->height()));

    QParallelAnimationGroup *group = new QParallelAnimationGroup;  //动画容器

    group->addAnimation(animation1);

    group->addAnimation(animation2);

    group->start();
}

