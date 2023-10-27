#ifndef DAYEVENTWIDGET_H
#define DAYEVENTWIDGET_H

#include <QWidget>
#include "eventfull.h"
#include "eventbasewidget.h"

namespace Ui {
class DayEventWidget;
}

class DayEventWidget : public EventBaseWidget
{
    Q_OBJECT

public:
    explicit DayEventWidget(QWidget *parent = nullptr,EventFull e=EventFull());
    ~DayEventWidget();
    void showInfo(EventFull &e) override;

private:
    Ui::DayEventWidget *ui;
};

#endif // DAYEVENTWIDGET_H
