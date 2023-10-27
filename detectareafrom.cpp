#include "detectareafrom.h"
#include "global.h"
#include"eventeditdialog.h"
#include<QMouseEvent>
#include<QDebug>

DetectAreaFrom::DetectAreaFrom(QWidget *parent)
    : DetectArea{parent}
{


}

//点击这个检测区域就让相应的组件弹出来
void DetectAreaFrom::mousePressEvent(QMouseEvent *ev){
    globalEditDlg->popupStartDate();
}






