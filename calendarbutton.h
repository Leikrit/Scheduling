#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include<QPushButton>
#include<QDate>

class CalendarButton : public QPushButton
{
    Q_OBJECT
public:
    CalendarButton(const QIcon &icon,const QString &text,QWidget*parent=nullptr);
    CalendarButton(const QString &text,QWidget*parent=nullptr);
    CalendarButton(QWidget*parent=nullptr);
    void setDate(QDate &);
    void setCheckTodayColorToDarkBlue();
    void changeStyle();
    QDate getDate();
    QDate date = QDate(1969,0,0);
    bool hasEvents=false;
};

#endif // BUTTON_H
