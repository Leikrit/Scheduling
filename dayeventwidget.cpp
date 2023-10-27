#include "dayeventwidget.h"
#include"eventfull.h"
#include "ui_dayeventwidget.h"
#include <QLabel>
#include<QDebug>


//这是继承于EventBaseWidget的派生类
DayEventWidget::DayEventWidget(QWidget *parent, EventFull _e) :
    EventBaseWidget(parent),
    ui(new Ui::DayEventWidget)
{
    ui->setupUi(this);
    e=_e;

}

//全天事件有自己的showInfo，这是一个override函数，也是实现多态的一步
void DayEventWidget::showInfo(EventFull &e){

    ui->alldayLabel->setText("All day");
    setEventIcon(e.getType());

    if(e.getLocation().isEmpty()){
        setEventName(e.getName());
        moveEventNameLabel(230,38);
        setEventLocation({});
    }
    else {
        setEventName(e.getName());
        setEventLocation(e.getLocation());

    }

    QString elided_name,elided_location;
    QFontMetrics metrics(QFont("Adobe Heiti Std R",13));
    if(metrics.horizontalAdvance(e.getName()) > 450){
        elided_name=metrics.elidedText(e.getName(),
                                       Qt::ElideRight,450);
        setEventName(elided_name);
    }
    if(metrics.horizontalAdvance(e.getLocation()) > 550){
        elided_location=metrics.elidedText(e.getLocation(),
                                           Qt::ElideRight,550);
        setEventLocation(elided_location);
    }

}


DayEventWidget::~DayEventWidget()
{
    delete ui;
}
