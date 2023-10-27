#include "memowidget.h"
#include<QString>
#include<QListWidget>
#include<QWidget>
#include<QGridLayout>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QStringList>
#include<QListWidgetItem>
#include<QMessageBox>
#include<QDebug>
#include<QDataStream>
#include<QFile>
#include<QFont>
#include<QFrame>
#include<QLabel>
#include<QIcon>
#include<QPalette>

MemoWidget::MemoWidget(QWidget *parent)
    : QWidget(parent)
   // , ui(new Ui::Memowindow)
{
    //ui->setupUi(this);
    createMemoWidget();
    this->setFixedSize(1300,800);

}

MemoWidget::~MemoWidget()
{
    //delete ui;
}

//[0]创建窗口
void MemoWidget::createMemoWidget()
{
    //创建表格布局
    QGridLayout *layout=new QGridLayout(this);

    QPushButton *confirm=new QPushButton(this);
    QPushButton *del=new QPushButton(this);

    //设置标题编辑框的字体
    QFont *fontOfName=new QFont();
    fontOfName->setBold(true);
    fontOfName->setPointSize(15);

    //设置文本编辑框的字体
    QFont *fontOfContent=new QFont();
    fontOfContent->setPointSize(12);

    //新建QIcon对象
    QIcon myicon;
    QIcon myicon2;
    //让QIcon对象指向想要的图标
    myicon.addFile(tr("://icon/delete2.png"));
    myicon2.addFile(tr("://icon/check.png"));
    list=new QListWidget(this);

    confirm->setText("Confirm");
    del->setText("Delete");

    del->setIcon(myicon);
    del->setIconSize(QSize(30,30));

    //设置delete按钮的视觉效果、鼠标停留和按下按钮时的视觉效果
    del->setStyleSheet("QPushButton{border:none;background-color:lightblue;border-radius:15px;font-family:Arial;}"
                       "QPushButton:hover{background-color:DeepSkyBlue}"
                       "QPushButton:pressed{background:transparent}");

    confirm->setIcon(myicon2);
    confirm->setIconSize(QSize(30,30));

    //设置confirm按钮的视觉效果、鼠标停留和按下按钮时的视觉效果
    confirm->setStyleSheet("QPushButton{border:none;background-color:lightblue;border-radius:15px;font-family:Arial}"
                               "QPushButton:hover{background-color:DeepSkyBlue}"
                               "QPushButton:pressed{background:transparent}");

    //设置风格
    editName=new QLineEdit(this);
    editName->setClearButtonEnabled(true);
    editName->setStyleSheet("");
    editName->setAlignment(Qt::AlignCenter);
    editName->setFont(*fontOfName);
    editContent=new QTextEdit(this);
    editContent->setFont(*fontOfContent);

    //控件布局
    layout->addWidget(list,0,0,5,2);
    layout->addWidget(editName,0,2,1,2);
    layout->addWidget(editContent,1,2,3,2);
    layout->addWidget(confirm,4,3,1,1);
    layout->addWidget(del,4,2,1,1);

    //修改标题编辑框的视觉效果
    editName->setFixedSize(630,100);
    editName->setStyleSheet("QLineEdit{background-color:GoldenRod;border-top-left-radius:15px;border-top-right-radius:15px;"
                                "font-family:微软雅黑;font-weight:bold;font-size:15}");

    //修改文本编辑框的视觉效果
    editContent->setFixedSize(630,590);
    editContent->setStyleSheet("QTextEdit{border:3px solid PeachPuff;font-family:微软雅黑;font-size:12;background-color:LightYellow;"
                                   "border-top-left-radius:8px;border-top-right-radius:8px;border-bottom-left-radius:30px;border-bottom-right-radius:30px;}"
                                   );

    confirm->setFixedSize(310,40);
    del->setFixedSize(310,40);

    //连接相应的函数
    connect(confirm,&QPushButton::clicked,this,&MemoWidget::confirmMemo);
    connect(del,&QPushButton::clicked,this,&MemoWidget::deleteMemo);
    connect(list,&QListWidget::itemDoubleClicked,this,&MemoWidget::editMemo);

    //从文件中读取数据，在程序打开时初始化memolist
    read();
    //展示memolist
    showMemoList();
    //设置list展示框的视觉效果
    setUi();
    list->setStyleSheet("QListWidget{color:black;border:none;border-width:20px;background:transparent}"
                        "QListWidget::item:hover{background-color: lightblue;}");
}
//[0]

//[1]
void MemoWidget::setUi()
{
    for(int i=0;i<memolist.size();++i)
    {
        //设置前景色
        list->item(i)->setForeground(QBrush(QColor(Qt::black)));
        //设置背景色70,153,181
        list->item(i)->setBackground(QBrush(QColor(Qt::white)));
        //设置字体
        list->item(i)->setFont(QFont("Arial",12,QFont::Bold));
        //设置大小
        list->item(i)->setSizeHint(QSize(20,50));
        //设置对齐方式（居中）
        list->item(i)->setTextAlignment(Qt::AlignCenter);
    }
}
//[1]

//[2]
void MemoWidget::confirmMemo()
{
    QString n=editName->text();
    //判断不为空标题
    if(n!="")
    {
        QString s1;
        bool existence=false;
        memo m;
        m.name=editName->text();
        m.content=editContent->toPlainText();
        if(!editState)
        {
            if(memolist.size()>0)
            {
                //判断标题没有重复
                for(int i=0;i<memolist.size();++i)
                {
                    if(m.name==memolist[i].name)
                    {
                        existence=true;
                    }
                }
            }
            if(existence)
            {
                QMessageBox::warning(this,"warning","The title has existed.");
            }
            else
            {
                //添加新的笔记
                memolist.push_back(m);
                list->addItem(m.name);
                editName->setText("");
                editContent->setText("");
                editState=false;
                write();
            }
        }
        else
        {
            if(memolist.size()>0)
            {
                for(int i=0;i<memolist.size();++i)
                {
                    if(m.name==memolist[i].name&&i!=currentItemIndex)
                    {
                        existence=true;
                    }
                }
            }
            if(existence)
            {
                QMessageBox::warning(this,"Warning","The title has existed.");
            }
            else
            {
                //编辑原有的笔记
                memolist[currentItemIndex].name=m.name;
                memolist[currentItemIndex].content=m.content;
                list->insertItem(currentItemIndex,m.name);
                list->takeItem(currentItemIndex+1);
                editName->setText("");
                editContent->setText("");
                editState=false;
                currentItemIndex=-1;
                write();
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"Warning","The title should not be empty");
    }
    setUi();
}
//[2]

//[3]
void MemoWidget::editMemo()
{
    setUi();
    editName->setText(list->currentItem()->text());
    QString name=editName->text();
    for(int i=0;i<memolist.size();++i)
    {
        //找到被选中的笔记
        if(name==memolist[i].name)
        {
            editContent->setText(memolist[i].content);
            editState=true;
            currentItemIndex=i;
            list->item(i)->setBackground(QColor(55,135,160));//55,135,160
            break;
        }
    }
}
//[3]

//[4]
void MemoWidget::deleteMemo()
{
    //判断是否选中了某条笔记
    if(currentItemIndex>=0)
    {
        list->takeItem(currentItemIndex);

        //防止无笔记时重复删除某一项而导致向量下标越界
        if(memolist.size()>0)
        {
            memolist.remove(currentItemIndex);
        }
        editName->setText("");
        editContent->setText("");

        //退出编辑状态
        currentItemIndex=-1;
        editState=false;
        write();
    }
    else
    {
        QMessageBox::warning(this,"Warning","No selected memo");
    }
}
//[4]

//[5]将备忘录数据保存到文件中
void MemoWidget::write()
{
    QFile file("memo.dat");
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug()<<"Fail to open";
    }
    QDataStream stream(&file);
    qDebug()<<"Open success";

    stream<<memolist;
    file.close();
}
//[5]

//[6]从文件读取数据
void MemoWidget::read()
{
    QFile file("memo.dat");
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug()<<"Fail to open";
    }
    QDataStream stream(&file);
    qDebug()<<"Open success";
    stream>>memolist;
    file.close();
}
//[6]

//[7]展示备忘录
void MemoWidget::showMemoList()
{
    for(int i=0;i<memolist.size();++i)
    {
        list->addItem(memolist[i].name);
    }
}
//[7]

//[8]友元函数，重载运算符
QDataStream& operator<<(QDataStream& output,const memo& m)
{
    output<<m.name<<m.content;
    return output;
}
//[8]

//[9]友元函数，重载运算符
QDataStream& operator>>(QDataStream& input,memo& m)
{
    input>>m.name>>m.content;
    return input;
}
//[9]
