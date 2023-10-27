#ifndef EVENTFULL_H
#define EVENTFULL_H

#include<QDateTime>
#include<QString>
#include<QDate>
#include<QTime>

enum EventType{INTERVAL_EVENT=1,MOMENT_EVENT,DAY_EVENT,COUNTDOWN,BIRTHDAY,ANNIVERSARY};


class EventFull
{

friend QDataStream &operator<<(QDataStream &stream, const EventFull &e);
friend QDataStream &operator>>(QDataStream &stream, EventFull &e);

private:
    QString id;
    QString name;
    QString type;
    QDateTime start_time;
    QDateTime end_time;
    QDateTime reminder;
    QString location;
    QString description;
    QString person;


public:
    EventFull(int id=0, QString name={}, int _type=1,
          QDateTime start_time= QDateTime(QDate::currentDate(),
                        QTime(QTime::currentTime().hour(),
                        QTime::currentTime().minute())),
          QDateTime end_time = QDateTime(QDate::currentDate(),
                        QTime(QTime::currentTime().hour(),
                        QTime::currentTime().minute())).addSecs(3600),
          QDateTime reminder=QDateTime(QDate(0,0,0),QTime(0,15,0)),
          QString location={}, QString description={},
          QString person={});

    EventFull(QString _id, QString _name, QString _type,
                 QDateTime _start_time,
                 QDateTime _end_time,
                 QDateTime _reminder,
                 QString _location,
                 QString _description,
                 QString _person);

    int getId()const;
    QString getIdStr()const;
    QString getName()const;
    int getType()const;
    QDateTime getStart_time()const;
    QDateTime getEnd_time()const;
    QDateTime getReminder()const;
    QString getLocation()const;
    QString getDescription()const;
    QString getPerson()const;
    void setId(int);
    void setName(QString);
    void setType(int);
    void setStart_Time(QDateTime);
    void setEnd_Time(QDateTime);
    void setReminder(QDateTime);
    void setLocation(QString);
    void setDescription(QString);
    void setPerson(QString);

};

#endif // EVENTFULL_H
