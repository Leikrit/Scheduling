#include "specialdayeventwidget.h"
#include <QLabel>
#include "global.h"
#include "ui_specialdayeventwidget.h"
#include<QEvent>
#include<QDebug>
#include<QMouseEvent>

//继承于DayEventWidget，而DayEventWidget又继承于EventBaseWidget，二级继承
SpecialDayEventWidget::SpecialDayEventWidget(QWidget *parent, EventFull _e) :
    DayEventWidget(parent),
    ui(new Ui::SpecialDayEventWidget)
{
    ui->setupUi(this);
    e=_e;


}

//有自己的showInfo,多态
void SpecialDayEventWidget::showInfo(EventFull &e){

    setEventIcon(e.getType());
    QString str1,str2;
    QString elided_name,elided_person;
    QFontMetrics metrics(QFont("Adobe Heiti Std R",13));

    //由于我们已经写了足够的继承结构和多态，不想再为了多态而多态（这不仅没有提高编程效率，
    //反而增加低效的工作量），因此下面直接switch解决
    switch(e.getType()){
    case COUNTDOWN:{

        str1=e.getName();

        if(metrics.horizontalAdvance(e.getName()) > 400)
            str1 = metrics.elidedText(e.getName(), Qt::ElideRight,400);

        str1+=" - ";
        QDateTime startDay(checkDate->date(),QTime());
        int daysto=startDay.daysTo(e.getStart_time());

        if(daysto==0){
            str1+="Today";
        }
        else if(daysto==1){
            str1+=QString::number(daysto);
            str1+=" day left";
        }
        else{
            str1+=QString::number(daysto);
            str1+=" days left";
        }
        setEventName(str1);

        str2="Countdown | ";
        str2+=e.getStart_time().toString("MMMM dd, yyyy");
        setEventLocation(str2);
    }
        break;

    case BIRTHDAY:{

        str1=e.getPerson();

        if(metrics.horizontalAdvance(e.getPerson()) > 400)
            str1 = metrics.elidedText(e.getPerson(), Qt::ElideRight,400);

        str1+="'s birthday";
        setEventName(str1);

        str2+=e.getStart_time().toString("MMMM dd, yyyy");
        setEventLocation(str2);
    }
        break;

    case ANNIVERSARY:{

        str1=e.getName();

        if(metrics.horizontalAdvance(e.getName()) > 400)
            str1 = metrics.elidedText(e.getName(), Qt::ElideRight,400);

        QDateTime today(checkDate->date(),QTime());
        int daysto=e.getStart_time().daysTo(today);

        if(daysto==0){
            str1+=" - Since today";
        }
        else if(daysto==1){
            str1+=" - ";
            str1+=QString::number(daysto);
            str1+=" day";
        }
        else{
            str1+=" - ";
            str1+=QString::number(daysto);
            str1+=" days";
        }
        setEventName(str1);

        str2="Anniversary | ";
        str2+=e.getStart_time().toString("MMMM dd, yyyy");
        setEventLocation(str2);

    }
        break;
    }

}




SpecialDayEventWidget::~SpecialDayEventWidget()
{
    delete ui;
}
