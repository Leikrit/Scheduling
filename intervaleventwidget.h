#ifndef INTERVALEVENTWIDGET_H
#define INTERVALEVENTWIDGET_H

#include "eventfull.h"
#include "eventbasewidget.h"
#include <QWidget>

namespace Ui {
class IntervalEventWidget;
}

class IntervalEventWidget : public EventBaseWidget
{
    Q_OBJECT

public:
    explicit IntervalEventWidget(QWidget *parent = nullptr,EventFull e=EventFull());
    ~IntervalEventWidget();
    void showInfo(EventFull &);

private:
    Ui::IntervalEventWidget *ui;
};

#endif // INTERVALEVENTWIDGET_H
