#include "eventeditdialog.h"
#include "eventfull.h"
#include "eventbasewidget.h"
#include "global.h"
#include "ui_eventbasewidget.h"
#include <QPixmap>
#include <QDebug>
#include "mainwidget.h"
#include<QIcon>
#include<QLabel>
#include<QEvent>
#include<QMouseEvent>
#include<QPoint>
#include<QColor>
#include<QPainter>
#include<QStyleOption>
#include<QPaintEvent>
#include<QListWidgetItem>
#include<QFontMetrics>

//这是一个基类，也是一个抽象类，showInfo()是一个纯虚函数
//对于各派生类都共有的特性，我们直接在这个类中写了出来，showInfo在派生的类中单独写
EventBaseWidget::EventBaseWidget(QWidget *parent,
                                 EventFull _e) :
    QWidget(parent),
    e(_e), ui(new Ui::EventBaseWidget)
{
    ui->setupUi(this);
    
    //设置样式表
    this->setStyleSheet(
                "EventBaseWidget{border:1px solid rgb(245,245,245); "
                "background:transparent;}"
                "EventBaseWidget:hover{background:rgba(135,206,250,0.3);}");
    ui->eventNameLabel->move(QPoint(230,23));
    ui->eventLocationLabel->move(QPoint(230,53));
    
    
    
    
    
    
}


void EventBaseWidget::setEventName(const QString &event_name){
    ui->eventNameLabel->setText(event_name);
}

void EventBaseWidget::setEventLocation(const QString &event_location){
    ui->eventLocationLabel->setText(event_location);
}

//如果日程有描述的话，要设置一个小点点（紫色的）
void EventBaseWidget::setDescriptionPoint(){
    if( ! e.getDescription().isEmpty()){
        ui->descriptionPoint->setStyleSheet(
                    "QWidget#descriptionPoint{border-radius:5px;"
                    "background:rgb(160,32,240); border:0px;}");
    }
    
    else if ( e.getDescription().isEmpty()){
        ui->descriptionPoint->setStyleSheet(
                    "QWidget#descriptionPoint{border-radius:10px;"
                    "background:transparent; border:0px;}");
    }
}

//不同的日程类型要展示出不同的ICON
void EventBaseWidget::setEventIcon(unsigned int type){
    switch(type){
    case INTERVAL_EVENT:
    case MOMENT_EVENT:
    case DAY_EVENT:{
        ui->eventIcon->setStyleSheet(
                    "border-image:url(:/icon/event_green.png)");
    }
        break;
    case COUNTDOWN:{
        ui->eventIcon->setStyleSheet(
                    "border-image:url(:/icon/star_green.png)");
    }
        break;
    case BIRTHDAY:{
        ui->eventIcon->setStyleSheet(
                    "border-image:url(:/icon/birthday-cake_green.png)");
    }
        break;
    case ANNIVERSARY:{
        ui->eventIcon->setStyleSheet(
                    "border-image:url(:/icon/badge_green.png)");
    }
        break;
    }
}

//这是一个提供给子类的接口
void EventBaseWidget::moveEventNameLabel(int x,int y){
    ui->eventNameLabel->move(x,y);
}

//鼠标点击这个日程，就让日程编辑的窗口弹出来
void EventBaseWidget::mousePressEvent(QMouseEvent *ev){
    globalEditDlg->setEvent(e);
    globalEditDlg->setTitle("Edit event");
    globalEditDlg->show();
    globalEditDlg->deleteBtn.show();
}

//当鼠标移动到日程上面，如果日程有描述的话，就让描述展示出来（隐藏掉原来的“日程位置”）
void EventBaseWidget::enterEvent(QEvent *ev){
    event_location=ui->eventLocationLabel->text();
    if( ! e.getDescription().isEmpty()){
        ui->eventNameLabel->move(QPoint(230,23));
        ui->eventLocationLabel->setText(e.getDescription());
        
        QString elided_description;
        QFontMetrics metrics(QFont("Adobe Heiti Std R",13));
        if(metrics.horizontalAdvance(e.getDescription()) > 550){
            elided_description=metrics.elidedText(e.getDescription(),
                                                  Qt::ElideRight,550);
            ui->eventLocationLabel->setText(elided_description);
        }
        
        ui->descriptionPoint->hide();
    }
}


//当鼠标离开日程的时候，让日程位置展示出来
void EventBaseWidget::leaveEvent(QEvent *ev){
    ui->eventLocationLabel->setText(event_location);
    ui->descriptionPoint->show();
    switch(e.getType()){
    case INTERVAL_EVENT:
    case MOMENT_EVENT:
    case DAY_EVENT:{
        if(e.getLocation().isEmpty())
            ui->eventNameLabel->move(QPoint(230,38));
        else if ( ! e.getLocation().isEmpty())
            ui->eventNameLabel->move(QPoint(230,23));
    }break;
    case COUNTDOWN:
    case BIRTHDAY:
    case ANNIVERSARY:{
        ui->eventNameLabel->move(QPoint(230,23));
    }break;
    }
}

//由于这是一个继承于QWidget的组件，想要设置它的样式，必须要有这个函数
void EventBaseWidget::paintEvent(QPaintEvent*){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}




EventBaseWidget::~EventBaseWidget()
{
    delete ui;
}


