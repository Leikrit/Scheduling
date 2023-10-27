#include "detectareaallday.h"
#include "global.h"
#include"eventeditdialog.h"
#include "qdebug.h"
#include<QMouseEvent>

DetectAreaAllDay::DetectAreaAllDay(QWidget *parent)
    : DetectArea{parent}
{

}

//这个是继承于DetectArea 的类，鼠标点击detectAreaAllDay的区域,就改变其状态
void DetectAreaAllDay::mousePressEvent(QMouseEvent *ev){
    globalEditDlg->changeAllDayStatus();
}
