#include "eventfull.h"
#include<QDateTime>
#include<QString>
#include<QDate>
#include<QTime>
#include<QDebug>


//这是存日程信息的类
EventFull::EventFull(int _id, QString _name, int _type,
             QDateTime _start_time,
             QDateTime _end_time,
             QDateTime _reminder,
             QString _location,
             QString _description,
             QString _person)
    :id(QString::number(_id)),name(_name),type(QString::number(_type)),
      start_time(_start_time),end_time(_end_time),reminder(_reminder),
      location(_location),description(_description),
      person(_person)
{



}

EventFull::EventFull(QString _id, QString _name, QString _type,
             QDateTime _start_time,
             QDateTime _end_time,
             QDateTime _reminder,
             QString _location,
             QString _description,
             QString _person)
    :id(_id),name(_name),type(_type),
      start_time(_start_time),end_time(_end_time),reminder(_reminder),
      location(_location),description(_description),
      person(_person){}

//一系列的get 和set 函数
int EventFull::getId()const{
    return id.toInt();
}
QString EventFull::getIdStr()const{
    return id;
}
QString EventFull::getName()const{
    return name;
}
int EventFull::getType()const{
    bool ok;
    return type.toInt(&ok,10);
}
QDateTime EventFull::getStart_time()const{
    return start_time;
}
QDateTime EventFull::getEnd_time()const{
    return end_time;
}
QDateTime EventFull::getReminder()const{
    return reminder;
}
QString EventFull::getLocation()const{
    return location;
}
QString EventFull::getDescription()const{
    return description;
}
QString EventFull::getPerson()const{
    return person;
}
void EventFull::setId(int _id){
    id=QString::number(_id);
}
void EventFull::setName(QString _name){
    name=_name;
}
void EventFull::setType(int _type){
    type=QString::number(_type);
}
void EventFull::setStart_Time(QDateTime _start_time){
    start_time=_start_time;
}
void EventFull::setEnd_Time(QDateTime _end_time){
    end_time=_end_time;
}
void EventFull::setReminder(QDateTime _reminder){
    reminder=_reminder;
}
void EventFull::setLocation(QString _location){
    location=_location;
}
void EventFull::setDescription(QString _description){
    description=_description;
}
void EventFull::setPerson(QString _person){
    person=_person;
}

//重载流提取和插入符以方便文件读写
QDataStream &operator<<(QDataStream &stream, const EventFull &e)
{
    return stream <<e.getIdStr()<<e.getName()<<e.type
                  <<e.getStart_time()<<e.getEnd_time()<<e.getReminder()
                  <<e.getLocation()<<e.getDescription()
                  <<e.getPerson();
}

QDataStream &operator>>(QDataStream &stream, EventFull &e)
{
    return stream >>e.id>>e.name>>e.type>>e.start_time>>e.end_time>>e.reminder
                 >>e.location>>e.description>>e.person;
}

