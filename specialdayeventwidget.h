#ifndef SPECIALDAYEVENTWIDGET_H
#define SPECIALDAYEVENTWIDGET_H

#include <QWidget>
#include "dayeventwidget.h"

namespace Ui {
class SpecialDayEventWidget;
}

class SpecialDayEventWidget : public DayEventWidget
{
    Q_OBJECT

public:
    explicit SpecialDayEventWidget(QWidget *parent = nullptr,EventFull e=EventFull());
    ~SpecialDayEventWidget();
    void showInfo(EventFull &e);


private:
    Ui::SpecialDayEventWidget *ui;
};

#endif // SPECIALDAYEVENTWIDGET_H
