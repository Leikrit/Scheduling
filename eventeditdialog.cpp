#include "eventeditdialog.h"
#include "ui_eventeditdialog.h"
#include"eventfull.h"
#include"mainwidget.h"
#include"eventbasewidget.h"
#include <QIcon>
#include<QPixmap>
#include<QString>
#include<QDate>
#include<QTime>
#include<QDateTime>
#include<QDebug>
#include<QDataStream>
#include<QCheckBox>
#include<QPoint>
#include<QIcon>
#include"detectarea.h"
#include<QRect>
#include<QPushButton>
#include<QButtonGroup>

EventEditDialog::EventEditDialog(QWidget *parent,EventFull _e) :
    QDialog(parent),
    e(_e),
    ui(new Ui::EventEditDialog)
{
    ui->setupUi(this);

    //设置界面和各类样式表
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    this->setWindowFlag(Qt::WindowCloseButtonHint,false);
    this->setWindowFlag(Qt::FramelessWindowHint,false);
    this->setWindowTitle(" ");
    this->setStyleSheet(
                "EventEditDialog{background:white; border:0px;"
                        "border-radius:0px;}"
                "QLabel#addEventLabel{font-size:20pt;}"
                "QLabel#eventLabel,QLabel#countdownLabel,"
                "QLabel#birthdayLabel,QLabel#anniversaryLabel"
                "{font-family:Adobe Song Std L; font:10pt;}"
                "QLabel#eventNameLabel{color:rgba(0,0,0,0.5);}"
                "QLineEdit{background:transparent;}"
                "QWidget#splitLine{border:1px solid rgb(230,230,230);}"
                "DetectArea:hover{background:rgb(248,248,248);}"
                "QPushButton#eventBtn,QPushButton#countdownBtn,"
                "QPushButton#birthdayBtn,QPushButton#anniversaryBtn"
                "{border:0px; background:transparent;}"
                "QPushButton#eventBtn:hover,QPushButton#countdownBtn:hover,"
                "QPushButton#birthdayBtn:hover,QPushButton#anniversaryBtn:hover"
                "{background:rgba(245,246,246,1);}"
                "QPushButton#deleteBtn{border:0px; background:transparent;}"
                "QPushButton#deleteBtn:hover{background:rgba(243,243,243,1);}");

    this->resize(500,800);
    this->setFocusProxy(ui->eventNameLineEdit);

    saveBtn.setParent(this);
    deleteBtn.setParent(this);

    //设置保存按钮
    saveBtn.setGeometry(40,725,200,50);
    saveBtn.setText("  Save");
    saveBtn.setIcon(QIcon(":/icon/save.png"));
    saveBtn.setIconSize(QSize(26,26));

    //两个假按钮是调试用的
    ui->fakeButton->hide();
    ui->fakeButton2->hide();
    ui->allDayCheckBox->hide();

    //设置删除按钮
    deleteBtn.setGeometry(427,0,45,45);
    deleteBtn.setText({});
    deleteBtn.setIcon(QIcon(":/icon/delete.png"));
    deleteBtn.setIconSize(QSize(28,28));

    //设置"全天事件"的开关
    onOff.setParent(this);
    onOff.setGeometry(390,273,65,30);
    onOff.setStyleSheet("border-image:url(:/icon/off.png)");
    onOff.raise();

    //不同日程类型的按钮组
    eventBtnGroup=new QButtonGroup(this);
    eventBtnGroup->addButton(ui->eventBtn,0);
    eventBtnGroup->addButton(ui->countdownBtn,1);
    eventBtnGroup->addButton(ui->birthdayBtn,2);
    eventBtnGroup->addButton(ui->anniversaryBtn,3);
    eventBtnGroup->setExclusive(true);

    //设置Tab键的跳转先后顺序
    ui->descriptionTextEdit->setTabChangesFocus(true);
    setTabOrder(ui->eventNameLineEdit,ui->startDateEdit);
    ui->startDateEdit->setCurrentSectionIndex(1);
    ui->startDateEdit->sectionAt(2);
    setTabOrder(ui->startDateEdit,ui->startTimeEdit);
    ui->startTimeEdit->setCurrentSectionIndex(0);
    setTabOrder(ui->startTimeEdit,ui->endDateEdit);
    ui->endDateEdit->setCurrentSectionIndex(1);
    setTabOrder(ui->endDateEdit,ui->endTimeEdit);
    ui->endTimeEdit->setCurrentSectionIndex(0);
    setTabOrder(ui->endTimeEdit,ui->locationLineEdit);
    setTabOrder(ui->locationLineEdit,ui->descriptionTextEdit);
    setTabOrder(ui->descriptionTextEdit,&saveBtn);
    setTabOrder(&saveBtn,ui->eventNameLineEdit);
    ui->cancelBtn->setFocusPolicy(Qt::NoFocus);
    deleteBtn.setFocusPolicy(Qt::NoFocus);


    displayEvent();


    //如果用户还没有在日程名称上面输入内容的话，就不能让他按保存按钮
    connect(ui->eventNameLineEdit,&QLineEdit::textChanged,[=](){
        if( ! ui->eventNameLineEdit->text().isEmpty()){
            ui->eventNameLabel->hide();
            saveBtn.setEnabled(true);
        }
        else{
            ui->eventNameLabel->show();
            saveBtn.setDisabled(true);
        }
    });

    //勾选了全天按钮之后，要把时间的编辑框隐藏起来，并移动日期的编辑框位置
    connect(ui->allDayCheckBox,&QCheckBox::stateChanged,[=](){
        if(ui->allDayCheckBox->isChecked()){
            ui->startTimeEdit->hide();
            ui->endTimeEdit->hide();
            ui->startDateEdit->move(QPoint(300,325));
            ui->endDateEdit->move(QPoint(300,385));
        }
        else{
            ui->startTimeEdit->show();
            ui->endTimeEdit->show();
            ui->startDateEdit->move(QPoint(205,325));
            ui->endDateEdit->move(QPoint(205,385));
        }
    });

    //开始 日期 改变了的话，结束 “日期” 也要随之改变
    connect(ui->startDateEdit,&QDateEdit::userDateChanged,[=](){
        if(ui->startDateEdit->date()>ui->endDateEdit->date())
            ui->endDateEdit->setDate(ui->startDateEdit->date());
    });

    //开始 时间 改变了的话，结束 “时间” 也要随时改变
    connect(ui->startTimeEdit,&QTimeEdit::userTimeChanged,[=](){
        if((ui->startDateEdit->date()==ui->endDateEdit->date())&&
            (ui->startTimeEdit->time()>ui->endTimeEdit->time()))
                ui->endTimeEdit->setTime(ui->startTimeEdit->time());
    });

    //同理，对于结束的日期也是这样
    connect(ui->endDateEdit,&QDateEdit::userDateChanged,[=](){
        if(ui->endDateEdit->date()<ui->startDateEdit->date())
            ui->startDateEdit->setDate(ui->endDateEdit->date());
    });

    //结束的时间也是这样
    connect(ui->endTimeEdit,&QTimeEdit::userTimeChanged,[=](){
        if((ui->startDateEdit->date()==ui->endDateEdit->date())&&
            (ui->endTimeEdit->time()<ui->startTimeEdit->time()))
                ui->startTimeEdit->setTime(ui->endTimeEdit->time());
    });

    //点击日程类型，要改界面
    connect(ui->eventBtn,&QPushButton::toggled,[=](){
        if(ui->eventBtn->isChecked()){
            eventUISetting();
            ui->eventNameLabel->setText("Event name");
            ui->eventBtn->setIcon(QIcon(":/icon/event_green.png"));
        }
        else
            ui->eventBtn->setIcon(QIcon(":/icon/event_grey.png"));
    });

    //点击倒数日类型，要改界面
    connect(ui->countdownBtn,&QPushButton::toggled,[=](){
        if(ui->countdownBtn->isChecked()){
            specialDayUISetting();
            ui->addEventLabel->setText("Add countdown");
            ui->eventNameLabel->setText("Name");
            ui->countdownBtn->setIcon(QIcon(":/icon/star_green.png"));
        }
        else
            ui->countdownBtn->setIcon(QIcon(":/icon/star_grey.png"));
    });

    //点击生日类型要改界面
    connect(ui->birthdayBtn,&QPushButton::toggled,[=](){
        if(ui->birthdayBtn->isChecked()){
            specialDayUISetting();
            ui->addEventLabel->setText("Add birthday");
            ui->eventNameLabel->setText("Who");
            ui->birthdayBtn->setIcon(QIcon(":/icon/birthday-cake_green.png"));
        }
        else
            ui->birthdayBtn->setIcon(QIcon(":/icon/birthday-cake_grey.png"));
    });

    //点击纪念日类型要改界面
    connect(ui->anniversaryBtn,&QPushButton::toggled,[=](){
        if(ui->anniversaryBtn->isChecked()){
            specialDayUISetting();
            ui->addEventLabel->setText("Add anniversary");
            ui->eventNameLabel->setText("Name");
            ui->anniversaryBtn->setIcon(QIcon(":/icon/badge_green.png"));
        }
        else
            ui->anniversaryBtn->setIcon(QIcon(":/icon/badge_grey.png"));
    });

    //点了取消就把这个对话框隐藏起来
    connect(ui->cancelBtn,&QPushButton::clicked,[=](){
        this->hide();
    });

    //全天事件的开关按钮设置
    connect(ui->allDayCheckBox,&QCheckBox::toggled,[=](){
        if(ui->allDayCheckBox->isChecked())
            onOff.setStyleSheet("border-image:url(:/icon/on.png)");
        else
            onOff.setStyleSheet("border-image:url(:/icon/off.png)");
    });

}

//对于不同的日常类型,我们要展示不一样的界面
void EventEditDialog::setEvent(EventFull &_e){
    e=_e;
    int type=e.getType();
    switch(type){
    case INTERVAL_EVENT:
    case MOMENT_EVENT:{
        ui->eventBtn->setChecked(true);
        ui->allDayCheckBox->setChecked(false);
    }break;
    case DAY_EVENT:{
        ui->eventBtn->setChecked(true);
        ui->allDayCheckBox->setChecked(true);
    }break;
    case COUNTDOWN:{
        ui->countdownBtn->setChecked(true);
    }break;
    case BIRTHDAY:{
        ui->birthdayBtn->setChecked(true);
    }break;
    case ANNIVERSARY:{
        ui->anniversaryBtn->setChecked(true);
    }break;
    }
    displayEvent();
}

//把日程的内容展示出来
void EventEditDialog::displayEvent(){
    if(e.getType()==BIRTHDAY)
        ui->eventNameLineEdit->setText(e.getPerson());
    else
        ui->eventNameLineEdit->setText(e.getName());
    ui->startDateEdit->setDateTime(e.getStart_time());
    ui->startTimeEdit->setDateTime(e.getStart_time());
    ui->endDateEdit->setDateTime(e.getEnd_time());
    ui->endTimeEdit->setDateTime(e.getEnd_time());
    ui->locationLineEdit->setText(e.getLocation());
    ui->descriptionTextEdit->setPlainText(e.getDescription());
}

//把现在对话框里的内容写进文件里面
void EventEditDialog::writeCurrentInfo(){
    QString name,location,description;
    QDate start_date,end_date;
    QTime start_time,end_time;
    int type;

    int event_type=eventBtnGroup->checkedId();
    bool isallday=ui->allDayCheckBox->isChecked();
    switch(event_type){

    //这个case 0是日程
    case 0:{
        if( ! isallday){
            name=ui->eventNameLineEdit->text();
            start_date=ui->startDateEdit->date();
            start_time=ui->startTimeEdit->time();
            end_date=ui->endDateEdit->date();
            end_time=ui->endTimeEdit->time();
            location=ui->locationLineEdit->text();
            description=ui->descriptionTextEdit->toPlainText();
            if(QDateTime(start_date,start_time)==QDateTime(end_date,end_time))
                type=MOMENT_EVENT;
            else
                type=INTERVAL_EVENT;

            e.setName(name);
            e.setType(type);
            e.setStart_Time(QDateTime(start_date,start_time));
            e.setEnd_Time(QDateTime(end_date,end_time));
            e.setLocation(location);
            e.setDescription(description);
            e.setPerson({});
        }
        else{
            name=ui->eventNameLineEdit->text();
            start_date=ui->startDateEdit->date();
            end_date=ui->endDateEdit->date();
            location=ui->locationLineEdit->text();
            description=ui->descriptionTextEdit->toPlainText();
            type=DAY_EVENT;

            e.setName(name);
            e.setType(type);
            e.setStart_Time(QDateTime(start_date,QTime(0,0,0)));
            e.setEnd_Time(QDateTime(end_date,QTime(0,0,0)));
            e.setLocation(location);
            e.setDescription(description);
            e.setPerson({});
        }
    }break;

    //case 1 是倒数日
    case 1:{
        name=ui->eventNameLineEdit->text();
        start_date=ui->startDateEdit->date();
        description=ui->descriptionTextEdit->toPlainText();
        type=COUNTDOWN;

        e.setName(name);
        e.setType(type);
        e.setStart_Time(QDateTime(start_date,QTime(0,0,0)));
        e.setEnd_Time(QDateTime(start_date,QTime(0,0,0)));
        e.setDescription(description);
        e.setPerson({});
    }break;

        //case2是生日
    case 2:{
        name=ui->eventNameLineEdit->text();
        start_date=ui->startDateEdit->date();
        description=ui->descriptionTextEdit->toPlainText();
        type=BIRTHDAY;

        e.setPerson(name);
        e.setType(type);
        e.setStart_Time(QDateTime(start_date,QTime(0,0,0)));
        e.setEnd_Time(QDateTime(start_date,QTime(0,0,0)));
        e.setDescription(description);
        e.setName({});
    }break;

        //case 3 是纪念日
    case 3:{
        name=ui->eventNameLineEdit->text();
        start_date=ui->startDateEdit->date();
        description=ui->descriptionTextEdit->toPlainText();
        type=ANNIVERSARY;

        e.setName(name);
        e.setType(type);
        e.setStart_Time(QDateTime(start_date,QTime(0,0,0)));
        e.setEnd_Time(QDateTime(start_date,QTime(0,0,0)));
        e.setDescription(description);
        e.setPerson({});
    }break;

    default:
        qDebug()<<"None selected";
    }

    MainWidget::write(e);
}

//给外界提供接口，改变对话框的标题
void EventEditDialog::setTitle(QString str){
    ui->addEventLabel->setText(str);
}

//日程界面的UI设置
void EventEditDialog::eventUISetting(){

    ui->addEventLabel->setText("Add event");
    ui->fromLabel->setText("From");

    ui->allDayLabel->show();
    onOff.show();
    ui->allDayDetectArea->show();
    ui->fromLabel->move(QPoint(40,333));
    ui->startDateEdit->move(QPoint(205,325));
    ui->startTimeEdit->move(QPoint(375,325));
    ui->startTimeEdit->show();
    ui->endDateEdit->move(QPoint(205,385));
    ui->fromDetectArea->move(QPoint(0,320));
    ui->toLabel->show();
    ui->endDateEdit->show();
    ui->endTimeEdit->show();
    ui->toDetectArea->show();

    if(ui->allDayCheckBox->isChecked()){
        ui->startDateEdit->move(QPoint(300,325));
        ui->startTimeEdit->hide();
        ui->endDateEdit->move(QPoint(300,385));
        ui->endTimeEdit->hide();
    }

    ui->locationLabel->show();
    ui->locationLineEdit->show();
    ui->descriptionLabel->move(QPoint(40,565));
    ui->descriptionTextEdit->move(QPoint(40,605));
}

//特殊日的ui设置
void EventEditDialog::specialDayUISetting(){

    ui->fromLabel->setText("When");

    ui->allDayLabel->hide();
    onOff.hide();
    ui->allDayDetectArea->hide();
    ui->fromLabel->move(QPoint(40,278));
    ui->startDateEdit->move(QPoint(300,270));
    ui->startTimeEdit->hide();
    ui->fromDetectArea->move(QPoint(0,265));
    ui->toLabel->hide();
    ui->endDateEdit->hide();
    ui->endTimeEdit->hide();
    ui->toDetectArea->hide();
    ui->locationLabel->hide();
    ui->locationLineEdit->hide();
    ui->descriptionLabel->move(QPoint(40,345));
    ui->descriptionTextEdit->move(QPoint(40,385));
}

//全天的复选框和它实际展示出来的组件不是同一个
//(因为我想让展示出来的组件更加好看，它不能是复选框框那种的样子)
//这两个函数是中转用的
void EventEditDialog::changeAllDayStatus(){
    if(ui->allDayCheckBox->isChecked())
        ui->allDayCheckBox->setChecked(false);
    else
        ui->allDayCheckBox->setChecked(true);
}


bool EventEditDialog::getAllDayStatus(){
    return ui->allDayCheckBox->isChecked();
}

//这个是模拟鼠标点击,我设置了一个检测区域,点击那个检测区域会让日期的设置组件popup出来
void EventEditDialog::popupStartDate(){
    QMouseEvent clickPopup(QEvent::MouseButtonPress, QPoint(140,20),
                           Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent(ui->startDateEdit, &clickPopup);
}

//同样这个也是模拟鼠标点击
void EventEditDialog::popupEndDate(){
    QMouseEvent clickPopup(QEvent::MouseButtonPress, QPoint(140,20),
                           Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent(ui->endDateEdit, &clickPopup);
}

//设置键盘输入聚焦
void EventEditDialog::focusEventNameLineEdit(){
    ui->eventNameLineEdit->setFocus();
}



EventEditDialog::~EventEditDialog()
{
    delete ui;
}
