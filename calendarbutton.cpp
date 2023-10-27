#include "calendarbutton.h"
#include"global.h"
#include<QDebug>
#include<QDate>

CalendarButton::CalendarButton(const QIcon &icon,const QString &text,QWidget*parent)
    :QPushButton(icon,text,parent)
{

}
CalendarButton::CalendarButton(const QString &text,QWidget*parent)
    :QPushButton(text,parent)
{

}
CalendarButton::CalendarButton(QWidget* parent)
    :QPushButton(parent)
{

}

void CalendarButton::changeStyle(){

    //选中今天的样式
    if(this->isChecked()){
        if(date == QDate::currentDate()){
            this->setStyleSheet(
                        "QPushButton{border-image:none;"
                        "background:rgba(50,50,250,0.6); color:white;"
                        "border-radius:30px; border:none; "
                        "font-family:Arial; font: 16pt;}"
                        "QPushButton:hover{}");
        }

        else if(date != QDate::currentDate()){
            //选中的不是今天但当天有事件的样式
            if(hasEvents){
                this->setStyleSheet(
                            "QPushButton{border-image:url(://icon/redpoint3.png);"
                            "background:rgb(200,200,200); color:black;"
                            "border-radius:30px; border:none; "
                            "font-family:Arial; font: 16pt;}"
                            "QPushButton:hover{}");
            }

            //选中的不是今天，当天也没有事件的样式
            else if( ! hasEvents){
                this->setStyleSheet(
                            "QPushButton{border-image:none;"
                            "background:rgb(200,200,200); color:black;"
                            "border-radius:30px; border:none; "
                            "font-family:Arial; font: 16pt;}"
                            "QPushButton:hover{}");
            }
        }
    }

    else if( ! this->isChecked()){
        if( date == QDate::currentDate()){
            //未选中、是今天、有事件的样式
            if(hasEvents){
                this->setStyleSheet(
                            "QPushButton{border-image:url(://icon/redpoint3.png);"
                            "background:lightblue; color:blue;"
                            "border-radius:30px; border:none; "
                            "font-family:Arial; font: 16pt;}"
                            "QPushButton:hover{background:rgba(50,50,250,0.3);}");
            }

            //未选中、是今天、无事件的样式
            else if( ! hasEvents){
                this->setStyleSheet(
                            "QPushButton{border-image:none;"
                            "background:lightblue; color:blue;"
                            "border-radius:30px; border:none; "
                            "font-family:Arial; font: 16pt;}"
                            "QPushButton:hover{background:rgba(50,50,250,0.3);}");
            }
        }
        else if( date != QDate::currentDate()){
            if(hasEvents){
                //未选中、非今天、有事件的样式
                this->setStyleSheet(
                            "QPushButton{border-image:url(://icon/redpoint3.png);"
                            "background:rgb(245,245,245); color:black;"
                            "border-radius:30px; border:none; "
                            "font-family:Arial; font: 16pt;}"
                            "QPushButton:hover{background:rgb(230,230,230);}");
            }

            //未选中、非今天、无事件的样式
            else if( ! hasEvents){
                this->setStyleSheet(
                            "QPushButton{border-image:none;"
                            "background:rgb(245,245,245); color:black;"
                            "border-radius:30px; border:none; "
                            "font-family:Arial; font: 16pt;}"
                            "QPushButton:hover{background:rgb(230,230,230);}");
            }
        }
    }
}

void CalendarButton::setDate(QDate& _date){
    date=_date;
}


QDate CalendarButton::getDate()
{
    return date;
}
