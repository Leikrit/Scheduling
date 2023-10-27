#ifndef EVENTEDITDIALOG_H
#define EVENTEDITDIALOG_H

#include <QDialog>
#include"eventfull.h"
#include "detectareaallday.h"
#include"mainwidget.h"
#include"eventfull.h"
#include"eventbasewidget.h"
#include"ui_mainwidget.h"
#include<QPushButton>
#include<QButtonGroup>

namespace Ui {
class EventEditDialog;
}

class EventEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventEditDialog(QWidget *parent = nullptr,EventFull _e=EventFull());
    ~EventEditDialog();
    void setEvent(EventFull&);
    void displayEvent();
    void writeCurrentInfo();
    void setTitle(QString str);
    void changeAllDayStatus();
    void popupStartDate();
    void popupEndDate();
    void eventUISetting();
    void specialDayUISetting();
    void focusEventNameLineEdit();
    bool getAllDayStatus();
    EventFull e;
    QButtonGroup *eventBtnGroup;
    QPushButton saveBtn;
    QPushButton deleteBtn;
    DetectAreaAllDay onOff;

    Ui::EventEditDialog *ui;

private:

};

#endif // EVENTEDITDIALOG_H
