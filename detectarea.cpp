#include "detectarea.h"
#include "global.h"
#include"eventeditdialog.h"
#include<QMouseEvent>
#include<QPainter>
#include<QStyleOption>

//这是一个检测区域的基类
DetectArea::DetectArea(QWidget *parent)
    : QWidget{parent}
{


}

//使样式表有效
void DetectArea::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}



