#include "calendarwidget.h"
#include"calendarbutton.h"
#include "global.h"
#include "qbuttongroup.h"
#include "qdebug.h"
#include"mainwidget.h"
#include<QGridLayout>
#include<QTextCharFormat>
#include<QDate>
#include<QColor>
#include<QCalendarWidget>
#include<QObject>
#include<QLabel>
#include<QPushButton>
#include<QSpinBox>
#include<QWidget>
#include<QMainWindow>
#include<QSizePolicy>
#include<qpalette.h>
#include<QColor>
#include<QFile>
#include<QMessageBox>
#include<QPoint>

CalendarWidget::CalendarWidget(QWidget *parent)
    : QWidget(parent), leapYear(QDate::isLeapYear(QDate::currentDate().year())),
      daysOfMonth(QDate::currentDate().daysInMonth()),
      year(QDate::currentDate().year()),
      month(QDate::currentDate().month()),
      day(QDate::currentDate().day())
{

    //界面和样式设置
    this->resize(450,800);
    this->setStyleSheet(
                "CalendarWidget{background: rgb(245,245,245);"
                "font-family:Arial}");

    checkDate=new QDateEdit(this);
    checkDate->setDate(QDate::currentDate());
    checkDate->hide();
    afterOrAgoLabel = new QLabel(this);
    afterOrAgoLabel->setGeometry(0,516,355,30);
    afterOrAgoLabel->setStyleSheet(
                "QLabel{border-image:none;"
                "background:transparent; color:rgba(0,0,0,0.6);"
                "border-radius:30px; border:none; "
                "font-family:Adobe Heiti Std R; font: 13pt;}"
                "QLabel:hover{background:transparent;}");
    afterOrAgoLabel->setAlignment(Qt::AlignRight);
    afterOrAgoLabel->hide();
    backToTodayBtn = new QPushButton(this);
    backToTodayBtn->setGeometry(375,500,60,60);
    backToTodayBtn->setStyleSheet(
                "QPushButton{border-image:none;"
                "background:rgba(50,50,250,0.5); color:white;"
                "border-radius:30px; border:none; "
                "font-family:Arial; font: 16pt;}"
                "QPushButton:hover{background:rgba(50,50,250,0.6)}");
    backToTodayBtn->setText(QString::number(QDate::currentDate().day()));
    backToTodayBtn->setCheckable(true);

    //返回今日的按钮设置
    connect(backToTodayBtn,&QPushButton::clicked,[=](){
        yearSpinBox->setValue(QDate::currentDate().year());
        monthSpinBox->setValue(QDate::currentDate().month());
        checkDate->setDate(QDate::currentDate());
        checkToday();
    });

    //checkDate是一个全局变量，它改变的话说明选中的日期不是今天了，那我们显示
    //一个选中日期与今天相差的天数
    connect(checkDate,&QDateEdit::userDateChanged,[=](){
        QString str;
        if(checkDate->date() < QDate::currentDate()){
            int deviation = checkDate->date().daysTo(QDate::currentDate());
            str += QString::number(deviation);
            if(deviation == 1){
                str += " day ago";
            }
            else if(deviation > 1){
                str += " days ago";
            }
        }
        else if (checkDate->date() > QDate::currentDate()){
            int deviation = QDate::currentDate().daysTo(checkDate->date());
            str += "After ";
            str += QString::number(deviation);
            if(deviation == 1){
                str += " day";
            }
            else if(deviation > 1){
                str += " days";
            }
        }
        afterOrAgoLabel->setText(str);
        afterOrAgoLabel->show();
        backToTodayBtn->show();
    });

    MainWidget::readFromFileToGlobalEvents();

    setCalender();
    setDateAndInitialStyle();
    checkToday();

    //年和月的spinBox改变的话，下面的日历也要改变
    connect(yearSpinBox,QOverload<int>::of(&QSpinBox::valueChanged),[=](){
        leapYear = QDate::isLeapYear(yearSpinBox->value());
        year=yearSpinBox->value();
        setDateAndInitialStyle();
    });
    connect(monthSpinBox,QOverload<int>::of(&QSpinBox::valueChanged),[=](){
        setDaysOfMonth();
        month=monthSpinBox->value();
        setDateAndInitialStyle();
    });



}







//默认样式
void CalendarWidget::setDateAndInitialStyle()
{
    QDate *date=new QDate();
    date->setDate(year,month,1);
    int x = date->dayOfWeek()-1;
    int count=1;

    for(int i=0;i<6;++i)
    {
        for(int j=0;j<7;++j)
        {
            if(i==0&&j<x){
                days[i][j]->setDisabled(true);
                days[i][j]->setText("");
                days[i][j]->setStyleSheet("background:transparent");
                days[i][j]->setFixedSize(60,60);
            }

            //有效天按钮
            else if(count<=daysOfMonth){

                days[i][j]->setText(QString::number(count));
                days[i][j]->setEnabled(true);
                days[i][j]->setFixedSize(60,60);
                days[i][j]->setFocusPolicy(Qt::NoFocus);

                QDate date=QDate(year,month,count);
                days[i][j]->setDate(date);
                checkEvents(date);
                if( ! events_valid.isEmpty())
                    days[i][j]->hasEvents = true;
                else
                    days[i][j]->hasEvents = false;

                days[i][j]->changeStyle();

//                if(date==QDate::currentDate())
//                    days[i][j]->setChecked(true);

                count++;
            }
            //无效天
            else{
                days[i][j]->setDisabled(true);
                days[i][j]->setText({});
                days[i][j]->setFixedSize(60,60);
                days[i][j]->setStyleSheet("background:transparent");
            }
        }
    }
}

//检查该天是否是今天
void CalendarWidget::checkToday(){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(days[i][j]->date==QDate::currentDate())
                days[i][j]->setChecked(true);
        }
    }
    backToTodayBtn->hide();
}

//初始化日历
void CalendarWidget::setCalender()
{
    QWidget *calendarMainLayoutWidget=new QWidget(this);
    QGridLayout *calendarMainLayout;
    calendarMainLayoutWidget->move(QPoint(0,60));

    QPushButton *d1;
    QPushButton *d2;
    QPushButton *d3;
    QPushButton *d4;
    QPushButton *d5;
    QPushButton *d6;
    QPushButton *d7;
    QLabel *yearLabel;
    QLabel *monthLabel;

    calendarMainLayout=new QGridLayout(calendarMainLayoutWidget);
    calendarMainLayout->setSpacing(0);

    //设置星期
    d1=new QPushButton(tr("Mon"),this);
    d1->setFixedSize(60,60);
    d2=new QPushButton(tr("Tue"),this);
    d2->setFixedSize(60,60);
    d3=new QPushButton(tr("Wed"),this);
    d3->setFixedSize(60,60);
    d4=new QPushButton(tr("Thur"),this);
    d4->setFixedSize(60,60);
    d5=new QPushButton(tr("Fri"),this);
    d5->setFixedSize(60,60);
    d6=new QPushButton(tr("Sat"),this);
    d6->setFixedSize(60,60);
    d7=new QPushButton(tr("Sun"),this);
    d7->setFixedSize(60,60);

    //禁用星期按钮的选中功能
    d1->setDisabled(true);
    d2->setDisabled(true);
    d3->setDisabled(true);
    d4->setDisabled(true);
    d5->setDisabled(true);
    d6->setDisabled(true);
    d7->setDisabled(true);

    //设置星期颜色显示
    d1->setStyleSheet("border:none;color:rgba(0,0,0,0.5);font-family:Arial;");
    d2->setStyleSheet("border:none;color:rgba(0,0,0,0.5);font-family:Arial;");
    d3->setStyleSheet("border:none;color:rgba(0,0,0,0.5);font-family:Arial;");
    d4->setStyleSheet("border:none;color:rgba(0,0,0,0.5);font-family:Arial;");
    d5->setStyleSheet("border:none;color:rgba(0,0,0,0.5);font-family:Arial;");
    d6->setStyleSheet("border:none;color:rgba(255,0,0,0.5);font-family:Arial;");
    d7->setStyleSheet("border:none;color:rgba(255,0,0,0.5);font-family:Arial;");

    //添加到布局中
    calendarMainLayout->addWidget(d1,1,0);
    calendarMainLayout->addWidget(d2,1,1);
    calendarMainLayout->addWidget(d3,1,2);
    calendarMainLayout->addWidget(d4,1,3);
    calendarMainLayout->addWidget(d5,1,4);
    calendarMainLayout->addWidget(d6,1,5);
    calendarMainLayout->addWidget(d7,1,6);

    yearLabel=new QLabel("Year",this);
    monthLabel=new QLabel("Month",this);
    yearLabel->setStyleSheet("font-family:微软雅黑;font:14.5pt;");
    monthLabel->setStyleSheet("font-family:微软雅黑;font:14.5pt;");

    //年、月选择框
    yearSpinBox=new QSpinBox(this);
    monthSpinBox=new QSpinBox(this);
    yearSpinBox->setStyleSheet("font-family:微软雅黑;font:13pt;");
    monthSpinBox->setStyleSheet("font-family:微软雅黑;font:13.5pt;");

    yearSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    monthSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    yearSpinBox->setFocusPolicy(Qt::ClickFocus);
    monthSpinBox->setFocusPolicy(Qt::ClickFocus);

    yearLabel->move(QPoint(55,27));
    yearSpinBox->move(QPoint(126,28));
    monthLabel->move(QPoint(250,27));
    monthSpinBox->move(QPoint(350,26));

    //设置选择上下限
    yearSpinBox->setRange(1970,2099);
    monthSpinBox->setRange(1,12);
    yearSpinBox->setValue(year);
    monthSpinBox->setValue(month);

    //初始化日历按钮
    QButtonGroup *daysBtnGroup = new QButtonGroup(this);
    daysBtnGroup->setExclusive(true);
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<7;++j)
        {
            days[i][j]=new CalendarButton(this);
            days[i][j]->setCheckable(true);
            daysBtnGroup->addButton(days[i][j]);
            days[i][j]->setText(QString::number(j+7*i));
            calendarMainLayout->addWidget(days[i][j],i+2,j);
            connect(days[i][j],&QPushButton::toggled,[=](){
                days[i][j]->changeStyle();
                if(days[i][j]->isChecked())
                    checkDate->setDate(days[i][j]->date);
                if(days[i][j]->date == QDate::currentDate())
                    backToTodayBtn->hide();
            });
        }
    }
}

//检查这个月中的每一天是否有事件，有的有就传一个bool值给对应的按钮
//之后按钮根据这个bool值改变自己显示出来的样式
void CalendarWidget::checkEvents(QDate &date){
    events_valid.clear();

    for(auto &e:globalEvents){
        if(e.getId()!=0){
            switch(e.getType()){
            case INTERVAL_EVENT:{
                if(e.getStart_time().date() <= date &&
                        e.getEnd_time().date() >= date){

                    if(e.getStart_time().date() == e.getEnd_time().date())
                        events_valid.push_back(e);
                    else if(e.getStart_time().date() == date &&
                            e.getEnd_time().date() > date){
                        events_valid.push_back(e);
                    }
                    else if(e.getStart_time().date() < date &&
                            e.getEnd_time().date() == date){
                        events_valid.push_back(e);
                    }
                    else if(e.getStart_time().date() < date &&
                            e.getEnd_time().date() > date){
                        events_valid.push_back(e);
                    }
                }
            }break;
            case MOMENT_EVENT:
            case DAY_EVENT:
            case BIRTHDAY:{
                if(e.getStart_time().date()<=date &&
                        e.getEnd_time().date()>=date){
                    events_valid.push_back(e);
                }
            }break;
            case COUNTDOWN:{
                if(date==e.getStart_time().date()){
                    events_valid.push_back(e);
                }
            }break;
            case ANNIVERSARY:{
                if(date == e.getStart_time().date()){
                    events_valid.push_back(e);
                }
            }break;
            }
        }
    }
}

//判断月份有多少天
void CalendarWidget::setDaysOfMonth()
{
    int m=monthSpinBox->value();
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        daysOfMonth=31;
    }
    else if(m==2){
        if(leapYear)
            daysOfMonth=29;
        else
            daysOfMonth=28;
    }
    else
        daysOfMonth=30;
}

CalendarWidget::~CalendarWidget()
{
}
