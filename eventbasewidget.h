#ifndef EVENTBASEWIDGET_H
#define EVENTBASEWIDGET_H

#include "eventfull.h"
class EditDialog;
#include <QWidget>
#include <QString>
#include <QObject>
#include <qobject.h>
#include<QEvent>
#include<QMouseEvent>
#include<QLabel>
#include<QPaintEvent>
#include<QListWidgetItem>
#include<QPoint>

namespace Ui {
class EventBaseWidget;
}

class EventBaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventBaseWidget(QWidget *parent = nullptr,
                EventFull e=EventFull());
    ~EventBaseWidget();
    void setEventName(const QString &event_name);
    void setEventLocation(const QString &event_location);
    void setDescriptionPoint();
    void setEventIcon(unsigned int type);
    void moveEventNameLabel(int x,int y);
    //showInfo在这，纯虚函数
    virtual void showInfo(EventFull &)=0;
    virtual void mousePressEvent(QMouseEvent* ev);
    virtual void enterEvent(QEvent *ev);
    virtual void leaveEvent(QEvent *ev);
    void paintEvent(QPaintEvent*);
    QString event_location;
    EventFull e;

private:
    Ui::EventBaseWidget *ui;

};

#endif // EVENTBASEWIDGET_H
