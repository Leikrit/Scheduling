#include "detectareato.h"
#include "global.h"
#include"eventeditdialog.h"
#include<QMouseEvent>

DetectAreaTo::DetectAreaTo(QWidget *parent)
    : DetectArea{parent}
{

}

//点击这个检测区域就让相应的组件弹出来
void DetectAreaTo::mousePressEvent(QMouseEvent *ev){
    globalEditDlg->popupEndDate();
}
