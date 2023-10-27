#ifndef DETECTAREATO_H
#define DETECTAREATO_H

#include "detectarea.h"
#include <QWidget>
#include<QMouseEvent>
#include<QLabel>

class DetectAreaTo : public DetectArea
{
    Q_OBJECT
public:
    explicit DetectAreaTo(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);


signals:

};

#endif // DETECTAREATO_H
