#ifndef DETECTAREAFROM_H
#define DETECTAREAFROM_H

#include "detectarea.h"
#include <QWidget>
#include<QMouseEvent>

class DetectAreaFrom : public DetectArea
{
    Q_OBJECT
public:
    explicit DetectAreaFrom(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);


signals:

};

#endif // DETECTAREAFROM_H
