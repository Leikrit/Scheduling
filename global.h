#ifndef GLOBAL_H
#define GLOBAL_H

#include "eventfull.h"
#include "qdatetimeedit.h"
#include<QDate>
#include<QVector>
#include<QDateEdit>
#include<QCheckBox>

class EventEditDialog;
class EventFull;

extern EventEditDialog* globalEditDlg;
extern QDateEdit *checkDate;
extern QCheckBox *globalMottoCheckBox;
extern QCheckBox *globalMottoChangeCheckBox;

extern QVector<EventFull> globalEvents;



class global
{
public:
    global();
};

#endif // GLOBAL_H
