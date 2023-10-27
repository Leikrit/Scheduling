#include "momenteventwidget.h"
#include "ui_momenteventwidget.h"

//继承于EventBaseWidget的派生类
MomentEventWidget::MomentEventWidget(QWidget *parent, EventFull _e) :
    EventBaseWidget(parent),
    ui(new Ui::MomentEventWidget)
{
    ui->setupUi(this);
    e=_e;
}

//有自己的showInfo()，实现多态
void MomentEventWidget::showInfo(EventFull &e){

    QString start_time_str=e.getStart_time().toString("hh:mm");
    ui->startTimeLabel->setText(start_time_str);
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

MomentEventWidget::~MomentEventWidget()
{
    delete ui;
}
