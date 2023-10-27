#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"calendarbutton.h"
#include "eventfull.h"
#include<QWidget>
#include<QDateTime>
#include <QMainWindow>
#include<QPushButton>
#include<QVector>
#include<QLabel>
QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QCheckBox;
class QComboBox;
class QDate;
class QDateEdit;
class QGridLayout;
class QGroupBox;
class QPushButton;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();
    friend CalendarButton;
    void setDateAndInitialStyle();
    void checkEvents(QDate &date);
    void checkToday();
    QLabel *afterOrAgoLabel;
    QPushButton *backToTodayBtn;

public slots:
    void setDaysOfMonth();
    void setCalender();

private:

    CalendarButton* days[6][7];
    QSpinBox *yearSpinBox;
    QSpinBox *monthSpinBox;
    bool leapYear;
    int daysOfMonth;
    int year;
    int month;
    int day;
    QVector<EventFull> events_valid;
};
#endif // MAINWINDOW_H

