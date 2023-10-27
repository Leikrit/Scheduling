#ifndef MOMENTEVENTWIDGET_H
#define MOMENTEVENTWIDGET_H

#include <QWidget>
#include "eventfull.h"
#include "eventbasewidget.h"

namespace Ui {
class MomentEventWidget;
}

class MomentEventWidget : public EventBaseWidget
{
    Q_OBJECT

public:
    explicit MomentEventWidget(QWidget *parent = nullptr,EventFull e=EventFull());
    ~MomentEventWidget();
    void showInfo(EventFull &e);


private:
    Ui::MomentEventWidget *ui;
};

#endif // MOMENTEVENTWIDGET_H
