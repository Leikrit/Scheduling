#include "mainwidget.h"
#include "eventeditdialog.h"
#include "eventbasewidget.h"
#include "dayeventwidget.h"
#include "momenteventwidget.h"
#include "intervaleventwidget.h"
#include "settingdialog.h"
#include "specialdayeventwidget.h"
#include "eventfull.h"
#include "global.h"
#include "ui_mainwidget.h"
#include "eventeditdialog.h"
#include"calendarwidget.h"
#include<iostream>
#include<fstream>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>
#include<QIcon>
#include<QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QDebug>
#include<QString>
#include<QFileDialog>
#include<QFontDialog>
#include<QFont>
#include<QMainWindow>
#include<QMenuBar>
#include<QToolBar>
#include<QPushButton>
#include<QListWidget>
#include<QTreeWidget>
#include<QTreeWidgetItem>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QToolButton>
#include<QFile>
#include<QFileInfo>
#include<QDateTime>
#include<QDate>
#include<QTime>
#include<QButtonGroup>
#include<QFile>
#include<QDataStream>
#include<QVector>
#include"qvector.h"
#include<QObject>
#include<QScrollBar>
#include<QFont>
#include<QFontDatabase>
#include<QCheckBox>


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //去掉最大化按钮
    this->setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    //this->setWindowFlags(Qt::WindowCloseButtonHint);//去掉最大化最小化按钮,只保留关闭按钮
    setFocus(Qt::ActiveWindowFocusReason);

    //嵌入字体
    QFontDatabase::addApplicationFont(":/font/AdobeHeitiStd-Regular.otf");
    QFontDatabase::addApplicationFont(":/font/AdobeSongStd-Light.otf");

    //设置各类组件的样式
    this->setStyleSheet("MainWidget#MainWidget{background:white}"
                        "QWidget{font-family:Adobe Heiti Std R;font:12.5pt;}");

    ui->calendarWidget->setStyleSheet(
                "QWidget#calendarWidget{border:0px;"
                "border-radius:15px;}");

    ui->eventlistWidget->setStyleSheet(
                "QListWidget#eventlistWidget{background:white; border:0px;"
                                "border-radius:3px;}"
                "QListWidget::item{height:100px; border:0px;}");

    ui->addBtn->setStyleSheet(
                "QPushButton#addBtn{border-radius:40px;"
                        "border:3px solid #1296DB; background:white;}"
                "QPushButton#addBtn:hover{background:rgba(135,206,250,0.3);}");

    ui->settingBtn->setStyleSheet(
                "QPushButton#settingBtn{border-radius:0px;"
                        "border:0px; background:transparent;"
                        "border-image:url(://icon/more2.png)}"
                "QPushButton#settingBtn:hover{background:rgba(230,230,230,0.7);}");

    ui->mottoLabel->setStyleSheet(
                "QLabel#mottoLabel{font-family:Adobe Song Std L;"
                        "font:15pt; font-style:italic; border-radius:0px;"
                        "border:30px; background:white;"
                        "border-image:none;}"
                "QLabel#mottoLabel:hover{background:white;}");

    ui->celebrityLabel->setStyleSheet(
                "QLabel#celebrityLabel{font-family:Adobe Song Std L;"
                        "font:15pt;  border-radius:0px;"
                        "border:30px; background:white;"
                        "border-image:none;}"
                "QLabel#celebrityLabel:hover{background:white;}");

    ui->memoPage->setStyleSheet("QWidget#memoPage{border-image:url(://icon/chinese.jpg)}");


    //设置侧边栏
    setSideBar();
    //设置新增日程按钮
    setAddBtn();
    //初始化日程编辑框
    globalEditDlg=new EventEditDialog(this);
    globalEditDlg->hide();
    //初始化日程编辑框中的按钮
    setSaveBtnInEditDialog();
    setDeleteBenInEditDialog();



    //连接日程和日历
    setEventDynamicChangeWithCheckDate();



    freshList();

    //初始化座右铭组件
    initializeMottos();
    setSettingBtn();




}


void MainWidget::setSettingBtn(){

    //这两个global变量是我为了连接日历和日程中变量而设置的
    //日历先发送信号到global变量，global变量在发送信号到日程组件
    globalMottoCheckBox = new QCheckBox;
    globalMottoCheckBox->setTristate(true);
    globalMottoCheckBox->setCheckState(Qt::PartiallyChecked);
    globalMottoChangeCheckBox = new QCheckBox;


    connect(globalMottoCheckBox,&QCheckBox::stateChanged,[=](){
        if(globalMottoCheckBox->isChecked()){
            mottoOff=true;
            ui->mottoLabel->hide();
            ui->celebrityLabel->hide();
        }
        else{
            mottoOff=false;
            ui->mottoLabel->show();
            ui->celebrityLabel->show();
        }

        //把用户对座右铭的设置写进文件里面，包括是否显示和选了那条座右铭
        QFile file("motto.dat");
        if (!file.open(QIODevice::WriteOnly))
            qDebug()<<"Fail to open";
        QDataStream stream(&file);
        stream<<QString::number(mottoOff)<<QString::number(mottoSelection);
        file.close();
    });

    //换一条座右铭，并存进文件里面
    connect(globalMottoChangeCheckBox,&QCheckBox::stateChanged,[=](){
        mottoSelection < 10 ? mottoSelection++ : mottoSelection=0;
        ui->mottoLabel->setText(mottos[mottoSelection]);
        ui->celebrityLabel->setText(celebrities[mottoSelection]);
        QFile file("motto.dat");
        if (!file.open(QIODevice::WriteOnly))
            qDebug()<<"Fail to open";
        QDataStream stream(&file);
        stream<<QString::number(mottoOff)<<QString::number(mottoSelection);
        file.close();
    });

    connect(ui->settingBtn,&QPushButton::clicked,[=](){
        SettingDialog *settingDlg = new SettingDialog(this,mottoOff);
    });
}


//日程新增按钮
void MainWidget::setAddBtn(){
    connect(ui->addBtn,&QPushButton::clicked,[=](){
        QFile file("event.dat");
        if (!file.open(QIODevice::ReadWrite))
            QMessageBox::information(this, "Unable to open file", file.errorString());
        QDataStream stream(&file);

        EventFull e;
        QVector<EventFull> events(1000);
        stream>>events;
        file.close();

        //找到第一个ID为零的项，把它的下标传给他作id
        for(int i=1;i<1000;i++){
            if(events[i].getId()==0){
                e.setId(i);
                break;
            }
        }

        //如果日历那边选择的天不是今天，那传给对话框的应当是他选择的那天
       if(checkDate->date() != QDate::currentDate()){
           e.setStart_Time(QDateTime(checkDate->date(),QTime(8,0)));
           e.setEnd_Time(QDateTime(checkDate->date(),QTime(9,0)));
       }

       //初始对话框的内容
        globalEditDlg->setEvent(e);
        globalEditDlg->setTitle("Add event");
        globalEditDlg->deleteBtn.hide();
        globalEditDlg->saveBtn.setDisabled(true);
        globalEditDlg->show();
        globalEditDlg->activateWindow();
        globalEditDlg->focusEventNameLineEdit();

    });
}

//点击对话框中保存按钮要执行的内容
void MainWidget::setSaveBtnInEditDialog(){
    connect(&globalEditDlg->saveBtn,&QPushButton::clicked,[=](){
        int event_type=globalEditDlg->eventBtnGroup->checkedId();
        globalEditDlg->writeCurrentInfo();
        freshList();
        globalEditDlg->hide();
    });
}

//点击对话框中删除按钮要执行的内容
void MainWidget::setDeleteBenInEditDialog(){
    connect(&globalEditDlg->deleteBtn,&QPushButton::clicked,[=](){
        QFile file("event.dat");
        if (!file.open(QIODevice::ReadWrite))
            QMessageBox::information(this, "Unable to open file", file.errorString());
        QDataStream stream(&file);

        QVector<EventFull> events(1000);
        stream>>events;

        //删除其实就是写一个空日程进去（关键要把他的ID写成零）
        EventFull blankEvent;
//        qDebug()<<globalEditDlg->e.getId()<<globalEditDlg->e.getIdStr()
//                <<globalEditDlg->e.getName();
//        qDebug()<<blankEvent.getId()<<blankEvent.getIdStr()
//                <<blankEvent.getName();
        events[globalEditDlg->e.getId()]=blankEvent;
//        qDebug()<<events[globalEditDlg->e.getId()].getId()
//                <<events[globalEditDlg->e.getId()].getIdStr()
//                <<events[globalEditDlg->e.getId()].getName();
        file.seek(0);
        stream<<events;
        file.close();

        freshList();
        globalEditDlg->hide();
    });
}

//刷新日程的显示列表
void MainWidget::freshList(){

    //保存原来滑动条的位置
    int scrollbar_position=ui->eventlistWidget->verticalScrollBar()->sliderPosition();
    ui->eventlistWidget->clear();

    readFromFileToGlobalEvents();
//    for(auto &e:globalEvents){
//        qDebug()<<e.getId()<<e.getIdStr()<<e.getName()<<e.getType()
//               <<e.getStart_time().toString("yyyy/MM/dd hh:mm:ss")<<
//                  e.getEnd_time().toString("yyyy/MM/dd hh:mm:ss")<<e.getPerson();
//    }

    QDate date=checkDate->date();
    qDebug()<<date<<" date in freshList()";

    //决定当天有哪些日程要显示，因为有倒数日和纪念日的存在，
    //因此，某一天显示的日程并不全是当天的日程，还有其他天的倒数日和纪念日
    QVector<EventFull> events_sorted;
    for(auto &e:globalEvents){
        if(e.getId()!=0){
            switch(e.getType()){
            case INTERVAL_EVENT:{
                if(e.getStart_time().date() <= date &&
                        e.getEnd_time().date() >= date){

                    if(e.getStart_time().date() == e.getEnd_time().date())
                        events_sorted.push_back(e);
                    else if(e.getStart_time().date() == date &&
                            e.getEnd_time().date() > date){
                        e.setEnd_Time(QDateTime(e.getStart_time().date(),
                                                QTime(23,59)));
                        events_sorted.push_back(e);
                    }
                    else if(e.getStart_time().date() < date &&
                            e.getEnd_time().date() == date){
                        e.setStart_Time(QDateTime(e.getEnd_time().date(),
                                                  QTime(0,0)));
                        events_sorted.push_back(e);
                    }
                    else if(e.getStart_time().date() < date &&
                            e.getEnd_time().date() > date){
                        e.setStart_Time(QDateTime(date,
                                                  QTime(0,0)));
                        e.setEnd_Time(QDateTime(date,
                                                QTime(23,59)));
                        events_sorted.push_back(e);
                    }
                }
            }break;
            case MOMENT_EVENT:
            case DAY_EVENT:
            case BIRTHDAY:{
                if(e.getStart_time().date()<=date &&
                        e.getEnd_time().date()>=date){
                    events_sorted.push_back(e);
                }
            }break;
            case COUNTDOWN:{
                if(date<=e.getStart_time().date()){
                    events_sorted.push_back(e);
                }
            }break;
            case ANNIVERSARY:{
                if(date >= e.getStart_time().date()){
                    events_sorted.push_back(e);
                }
            }break;
            }
        }
    }

//    for(auto &e:events_sorted)
//        qDebug()<<e.getId()<<e.getIdStr()<<e.getName();

    //给要显示的日程排序
    QVector<int> rank{0,5,5,4,1,3,2};

    for(int count=0;count<events_sorted.size()-1;count++){
        for(int count2=0;count2<events_sorted.size()-1;count2++){
            for(int i=0;i<events_sorted.size()-1;i++){
                if(rank[events_sorted[i].getType()] >
                        rank[events_sorted[i+1].getType()])
                    events_sorted.swapItemsAt(i,i+1);
                else if (rank[events_sorted[i].getType()] ==
                         rank[events_sorted[i+1].getType()]){
                    if(events_sorted[i].getStart_time() > events_sorted[i+1].getStart_time())
                        events_sorted.swapItemsAt(i,i+1);
                    else if(events_sorted[i].getStart_time() == events_sorted[i+1].getStart_time()){
                        if(events_sorted[i].getEnd_time() > events_sorted[i+1].getEnd_time())
                            events_sorted.swapItemsAt(i,i+1);
                        else if (events_sorted[i].getEnd_time() == events_sorted[i+1].getEnd_time()){
                            if(events_sorted[i].getType() != BIRTHDAY){
                                if(events_sorted[i].getName() >
                                        events_sorted[i+1].getName())
                                    events_sorted.swapItemsAt(i,i+1);
                            }
                            else if (events_sorted[i].getType() == BIRTHDAY){
                                if(events_sorted[i].getPerson() >
                                        events_sorted[i+1].getPerson())
                                    events_sorted.swapItemsAt(i,i+1);
                            }
                        }
                    }
                }
            }
        }
    }

    //把日程显示出来
    for(auto &e:events_sorted)
        setEventItem(e);
    //恢复滑动条的位置
    ui->eventlistWidget->verticalScrollBar()->setSliderPosition(scrollbar_position);

    //同步改变日历组件的显示
    readFromFileToGlobalEvents();
    ui->calendarWidget->setDateAndInitialStyle();
}

//把文件中的内容写到全局日程变量中
void MainWidget::readFromFileToGlobalEvents(){
    QFile file("event.dat");
    if (!file.open(QIODevice::ReadWrite))
        qDebug()<<"Fail to open";
    QDataStream stream(&file);
    stream>>globalEvents;
    qDebug()<<"Read from file to global events: "<<globalEvents.size();
    if(globalEvents.size()==0){
        globalEvents.fill(EventFull(),1000);
        stream.resetStatus();
        file.seek(0);
        stream<<globalEvents;
        file.seek(0);
        stream>>globalEvents;
    }
    file.close();
}

//把日程编辑框中的内容写进文件里
void MainWidget::write(EventFull &e){
    QFile file("event.dat");
    if (!file.open(QIODevice::ReadWrite))
        qDebug()<<"Fail to open";
    QDataStream stream(&file);

    qDebug()<<"Read success";

    stream>>globalEvents;
    globalEvents[e.getId()]=e;
    file.seek(0);
    stream<<globalEvents;
    qDebug()<<"Write"<<e.getId()<<e.getName()<<e.getStart_time();
    file.close();
}

//设置日程列表中的各项
void MainWidget::setEventItem(EventFull &e){
    int type=e.getType();
    QListWidgetItem *item=new QListWidgetItem(ui->eventlistWidget);
    EventBaseWidget *event_brief = nullptr;

    switch (type){
    case INTERVAL_EVENT:{
        event_brief=new IntervalEventWidget(this,e);
        }break;

    case MOMENT_EVENT:{
        event_brief=new MomentEventWidget(this,e);
        }break;

    case DAY_EVENT:{
        event_brief=new DayEventWidget(this,e);
        }break;

    case COUNTDOWN:
    case BIRTHDAY:
    case ANNIVERSARY:{
        event_brief=new SpecialDayEventWidget(this,e);
        }break;
    }

    ui->eventlistWidget->setItemWidget(item,event_brief);
    //这一步是多态,event_brief是基类指针，showInfo()是virtual函数
    event_brief->showInfo(e);
    event_brief->setDescriptionPoint();
}

//全局变量发生改变，就要刷新列表
void MainWidget::setEventDynamicChangeWithCheckDate(){
    connect(checkDate,&QDateEdit::userDateChanged,[=](){
        freshList();
    });
}

//初始化座右铭
void MainWidget::initializeMottos(){
    mottos+={"Your time is limited, so \n"
            "  don't waste it living \n"
            "  someone else's life.",
            "A man who dares to waste \n"
            "  one hour of time has not \n"
            "  discovered the value of life.",
            "Years fly by, but the heart \n"
            "  stays in the same place.",
            "I believe every human has a finite \n"
            "  number of heartbeats. I don't \n"
            "  intend to waste any of mine.",
            "Every moment is a\n"
            "  fresh beginning.",
            "The people who are crazy enough \n"
            "  to think they can change the \n"
            "  world, are the ones that do.",
            "When you cease to dream, \n"
            "  you cease to live.",
            "The best way to predict your \n"
            "  future is to create it.",
            "Make each day your masterpiece.",
            "You can't put a limit on \n"
            "  anything. The more you \n"
            "  dream, the farther you get.",
            "Sometimes it's the very people who \n"
            "  no one imagines anything of who \n"
            "  do the things no one can imagine."};

    celebrities+={"- Steve Jobs",
                 "- Charles Darwin",
                 "- Harlan Coben",
                 "- Neil Armstrong",
                 "- T.S. Eliot",
                 "- Steve Jobs",
                 "- Malcolm Forbes",
                 "- Abraham Lincoln",
                 "- John Wooden",
                 "- Michael Phelps",
                 "- Alan Turing"};

    //把用户之前的设置读进来
    QFile file("motto.dat");
    if (!file.open(QIODevice::ReadOnly))
        qDebug()<<"Fail to open";
    QDataStream stream(&file);
    QString mottoOffStr, mottoSelectionStr;
    stream>>mottoOffStr>>mottoSelectionStr;
    file.close();

    mottoOff = mottoOffStr.toInt();
    qDebug()<<mottoOffStr<<" "<<mottoOffStr.toInt();
    mottoSelection = mottoSelectionStr.toInt();
    qDebug()<<mottoSelection<<" "<<mottoSelectionStr.toInt();

    ui->mottoLabel->setText(mottos[mottoSelection]);
    ui->celebrityLabel->setText(celebrities[mottoSelection]);

    if(mottoOff){
        ui->mottoLabel->hide();
        ui->celebrityLabel->hide();
    }
}


void MainWidget::setSideBar(){

    //设置侧边栏的背景颜色
    ui->sideBar->setStyleSheet(
                "QWidget#sideBar{background:white}");

    //设置侧边栏与stackedWidget的分割线
    ui->splitLine->setStyleSheet(
                "QWidget#splitLine{border:1px solid rgb(225,225,225);}");

    //设置侧边栏三个按钮的样式
    ui->calendarBtn->setStyleSheet("QToolButton{border:0px;"
                                        "border-radius:32px;}"
                                   "QToolButton:hover{border:0px;"
                                        "border-radius:32px;"
                                        "background:rgb(244,244,244);}"
                                   "QToolButton:checked{border:0px;"
                                        "border-radius:32px;"
                                        "background:rgb(240,240,240);}");

    ui->todoBtn->setStyleSheet("QToolButton{border:0px;"
                                        "border-radius:32px;}"
                                   "QToolButton:hover{border:0px;"
                                        "border-radius:32px;"
                                        "background:rgb(244,244,244);}"
                                   "QToolButton:checked{border:0px;"
                                        "border-radius:32px;"
                                        "background:rgb(240,240,240);}");

    ui->memoBtn->setStyleSheet("QToolButton{border:0px;"
                                        "border-radius:32px;}"
                                   "QToolButton:hover{border:0px;"
                                        "border-radius:32px;"
                                        "background:rgb(244,244,244);}"
                                   "QToolButton:checked{border:0px;"
                                        "border-radius:32px;"
                                        "background:rgb(240,240,240);}");

    //设置侧边栏三个按钮可被选中
    ui->calendarBtn->setCheckable(true);
    ui->todoBtn->setCheckable(true);
    ui->memoBtn->setCheckable(true);

    //给侧边栏的三个按钮，建立一个按钮组并设置不可多选
    QButtonGroup *sideBarBtnGroup=new QButtonGroup(this);
    sideBarBtnGroup->addButton(ui->calendarBtn,0);
    sideBarBtnGroup->addButton(ui->todoBtn,1);
    sideBarBtnGroup->addButton(ui->memoBtn,2);
    sideBarBtnGroup->setExclusive(true);
    ui->calendarBtn->setChecked(true);

    //按一下按钮改变组件
    connect(ui->calendarBtn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->calendarPage);
    });

    connect(ui->todoBtn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->todoPage);
    });

    connect(ui->memoBtn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->memoPage);
    });
}










void MainWidget::initialize(){

        QFile file("event.dat");
        if (!file.open(QIODevice::ReadWrite))
            qDebug()<<"Fail to open";
        QDataStream stream(&file);
        file.seek(0);

        QVector<EventFull> events(1000);
        stream<<events;
        file.close();
        qDebug()<<"Blank complete";

//        for(auto &e:events){
//            qDebug()<<e.getId()<<e.getIdStr()<<e.getName()<<e.getType()
//                   <<e.getStart_time().toString("yyyy/MM/dd hh:mm:ss")<<
//                      e.getEnd_time().toString("yyyy/MM/dd hh:mm:ss")<<e.getPerson();
//        }
}

MainWidget::~MainWidget()
{
    delete ui;
}

