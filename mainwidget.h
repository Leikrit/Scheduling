#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "eventbasewidget.h"
#include "eventfull.h"
#include <QWidget>
#include <QFile>
#include<QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    Ui::MainWidget *ui;

    void setSideBar();
    void setEventItem(EventFull &);
    static void initialize();
    static void readFromFileToGlobalEvents();
    static void write(EventFull &);
    void freshList();
    void setAddBtn();
    void setSaveBtnInEditDialog();
    void setDeleteBenInEditDialog();
    void setEventDynamicChangeWithCheckDate();
    void setSettingBtn();
    void initializeMottos();
    QStringList mottos;
    QStringList celebrities;

private:
    bool mottoOff=false;
    int mottoSelection=0;
};
#endif // MAINWIDGET_H
