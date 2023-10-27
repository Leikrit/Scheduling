#ifndef DETECTAREAALLDAY_H
#define DETECTAREAALLDAY_H

#include <QWidget>
#include"detectarea.h"
#include<QMouseEvent>

class DetectAreaAllDay : public DetectArea
{
    Q_OBJECT
public:
    explicit DetectAreaAllDay(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);
    void setOnOffStyle();

signals:

};

#endif // DETECTAREAALLDAY_H
