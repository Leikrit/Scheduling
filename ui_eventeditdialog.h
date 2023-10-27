/********************************************************************************
** Form generated from reading UI file 'eventeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTEDITDIALOG_H
#define UI_EVENTEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <detectareaallday.h>
#include <detectareafrom.h>
#include <detectareato.h>

QT_BEGIN_NAMESPACE

class Ui_EventEditDialog
{
public:
    QLabel *eventNameLabel;
    QLabel *addEventLabel;
    QDateEdit *startDateEdit;
    QTimeEdit *startTimeEdit;
    QDateEdit *endDateEdit;
    QTimeEdit *endTimeEdit;
    QLabel *fromLabel;
    QLabel *toLabel;
    QLineEdit *eventNameLineEdit;
    QLineEdit *locationLineEdit;
    QLabel *locationLabel;
    QLabel *descriptionLabel;
    QPushButton *cancelBtn;
    QPushButton *eventBtn;
    QPushButton *countdownBtn;
    QPushButton *birthdayBtn;
    QPushButton *anniversaryBtn;
    QLabel *allDayLabel;
    QPushButton *fakeButton;
    QWidget *splitLine;
    DetectAreaAllDay *allDayDetectArea;
    QCheckBox *allDayCheckBox;
    QPlainTextEdit *descriptionTextEdit;
    DetectAreaFrom *fromDetectArea;
    DetectAreaTo *toDetectArea;
    QLabel *eventLabel;
    QLabel *countdownLabel;
    QLabel *birthdayLabel;
    QLabel *anniversaryLabel;
    QPushButton *fakeButton2;

    void setupUi(QDialog *EventEditDialog)
    {
        if (EventEditDialog->objectName().isEmpty())
            EventEditDialog->setObjectName(QString::fromUtf8("EventEditDialog"));
        EventEditDialog->resize(500, 800);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(13);
        EventEditDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/white.png"), QSize(), QIcon::Normal, QIcon::Off);
        EventEditDialog->setWindowIcon(icon);
        eventNameLabel = new QLabel(EventEditDialog);
        eventNameLabel->setObjectName(QString::fromUtf8("eventNameLabel"));
        eventNameLabel->setGeometry(QRect(50, 200, 321, 31));
        eventNameLabel->setFont(font);
        eventNameLabel->setCursor(QCursor(Qt::IBeamCursor));
        eventNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        addEventLabel = new QLabel(EventEditDialog);
        addEventLabel->setObjectName(QString::fromUtf8("addEventLabel"));
        addEventLabel->setGeometry(QRect(40, 0, 311, 61));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addEventLabel->sizePolicy().hasHeightForWidth());
        addEventLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(20);
        addEventLabel->setFont(font1);
        addEventLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        startDateEdit = new QDateEdit(EventEditDialog);
        startDateEdit->setObjectName(QString::fromUtf8("startDateEdit"));
        startDateEdit->setGeometry(QRect(205, 325, 160, 40));
        startDateEdit->setFont(font);
        startDateEdit->setDateTime(QDateTime(QDate(2022, 12, 31), QTime(0, 0, 0)));
        startDateEdit->setMaximumDateTime(QDateTime(QDate(2099, 12, 31), QTime(23, 59, 59)));
        startDateEdit->setMinimumDateTime(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)));
        startDateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        startDateEdit->setCalendarPopup(true);
        startTimeEdit = new QTimeEdit(EventEditDialog);
        startTimeEdit->setObjectName(QString::fromUtf8("startTimeEdit"));
        startTimeEdit->setGeometry(QRect(375, 325, 85, 40));
        startTimeEdit->setFont(font);
        startTimeEdit->setFrame(true);
        startTimeEdit->setAlignment(Qt::AlignCenter);
        startTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        startTimeEdit->setCalendarPopup(false);
        endDateEdit = new QDateEdit(EventEditDialog);
        endDateEdit->setObjectName(QString::fromUtf8("endDateEdit"));
        endDateEdit->setGeometry(QRect(205, 385, 160, 40));
        endDateEdit->setFont(font);
        endDateEdit->setDateTime(QDateTime(QDate(2022, 12, 31), QTime(0, 0, 0)));
        endDateEdit->setMaximumDateTime(QDateTime(QDate(2099, 12, 31), QTime(23, 59, 59)));
        endDateEdit->setMinimumDateTime(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)));
        endDateEdit->setCalendarPopup(true);
        endDateEdit->setCurrentSectionIndex(2);
        endTimeEdit = new QTimeEdit(EventEditDialog);
        endTimeEdit->setObjectName(QString::fromUtf8("endTimeEdit"));
        endTimeEdit->setGeometry(QRect(375, 385, 85, 40));
        endTimeEdit->setFont(font);
        endTimeEdit->setFrame(true);
        endTimeEdit->setAlignment(Qt::AlignCenter);
        endTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        endTimeEdit->setCurrentSection(QDateTimeEdit::HourSection);
        endTimeEdit->setCalendarPopup(false);
        fromLabel = new QLabel(EventEditDialog);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));
        fromLabel->setGeometry(QRect(40, 333, 91, 31));
        fromLabel->setFont(font);
        fromLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        toLabel = new QLabel(EventEditDialog);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));
        toLabel->setGeometry(QRect(40, 390, 61, 31));
        toLabel->setFont(font);
        toLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        eventNameLineEdit = new QLineEdit(EventEditDialog);
        eventNameLineEdit->setObjectName(QString::fromUtf8("eventNameLineEdit"));
        eventNameLineEdit->setGeometry(QRect(40, 190, 420, 50));
        eventNameLineEdit->setInputMethodHints(Qt::ImhNone);
        locationLineEdit = new QLineEdit(EventEditDialog);
        locationLineEdit->setObjectName(QString::fromUtf8("locationLineEdit"));
        locationLineEdit->setGeometry(QRect(40, 490, 420, 50));
        locationLabel = new QLabel(EventEditDialog);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(40, 450, 211, 31));
        locationLabel->setFont(font);
        locationLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel = new QLabel(EventEditDialog);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(40, 565, 231, 41));
        descriptionLabel->setFont(font);
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        cancelBtn = new QPushButton(EventEditDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(260, 725, 200, 50));
        cancelBtn->setFocusPolicy(Qt::TabFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/cancel2.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        eventBtn = new QPushButton(EventEditDialog);
        eventBtn->setObjectName(QString::fromUtf8("eventBtn"));
        eventBtn->setGeometry(QRect(40, 65, 75, 75));
        eventBtn->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/event_grey.png"), QSize(), QIcon::Normal, QIcon::Off);
        eventBtn->setIcon(icon2);
        eventBtn->setIconSize(QSize(60, 60));
        eventBtn->setCheckable(true);
        countdownBtn = new QPushButton(EventEditDialog);
        countdownBtn->setObjectName(QString::fromUtf8("countdownBtn"));
        countdownBtn->setGeometry(QRect(155, 65, 75, 75));
        countdownBtn->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/star_grey.png"), QSize(), QIcon::Normal, QIcon::Off);
        countdownBtn->setIcon(icon3);
        countdownBtn->setIconSize(QSize(60, 60));
        countdownBtn->setCheckable(true);
        birthdayBtn = new QPushButton(EventEditDialog);
        birthdayBtn->setObjectName(QString::fromUtf8("birthdayBtn"));
        birthdayBtn->setGeometry(QRect(270, 65, 75, 75));
        birthdayBtn->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/birthday-cake_grey.png"), QSize(), QIcon::Normal, QIcon::Off);
        birthdayBtn->setIcon(icon4);
        birthdayBtn->setIconSize(QSize(60, 60));
        birthdayBtn->setCheckable(true);
        anniversaryBtn = new QPushButton(EventEditDialog);
        anniversaryBtn->setObjectName(QString::fromUtf8("anniversaryBtn"));
        anniversaryBtn->setGeometry(QRect(385, 65, 75, 75));
        anniversaryBtn->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/badge_grey.png"), QSize(), QIcon::Normal, QIcon::Off);
        anniversaryBtn->setIcon(icon5);
        anniversaryBtn->setIconSize(QSize(60, 60));
        anniversaryBtn->setCheckable(true);
        allDayLabel = new QLabel(EventEditDialog);
        allDayLabel->setObjectName(QString::fromUtf8("allDayLabel"));
        allDayLabel->setGeometry(QRect(40, 275, 131, 31));
        allDayLabel->setFont(font);
        allDayLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        fakeButton = new QPushButton(EventEditDialog);
        fakeButton->setObjectName(QString::fromUtf8("fakeButton"));
        fakeButton->setGeometry(QRect(40, 725, 200, 50));
        fakeButton->setFocusPolicy(Qt::TabFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        fakeButton->setIcon(icon6);
        fakeButton->setIconSize(QSize(26, 26));
        splitLine = new QWidget(EventEditDialog);
        splitLine->setObjectName(QString::fromUtf8("splitLine"));
        splitLine->setGeometry(QRect(0, 700, 500, 1));
        allDayDetectArea = new DetectAreaAllDay(EventEditDialog);
        allDayDetectArea->setObjectName(QString::fromUtf8("allDayDetectArea"));
        allDayDetectArea->setGeometry(QRect(0, 265, 500, 45));
        allDayCheckBox = new QCheckBox(allDayDetectArea);
        allDayCheckBox->setObjectName(QString::fromUtf8("allDayCheckBox"));
        allDayCheckBox->setGeometry(QRect(180, 10, 31, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(12);
        allDayCheckBox->setFont(font2);
        allDayCheckBox->setFocusPolicy(Qt::NoFocus);
        allDayCheckBox->setIconSize(QSize(30, 30));
        descriptionTextEdit = new QPlainTextEdit(EventEditDialog);
        descriptionTextEdit->setObjectName(QString::fromUtf8("descriptionTextEdit"));
        descriptionTextEdit->setGeometry(QRect(40, 605, 420, 70));
        descriptionTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fromDetectArea = new DetectAreaFrom(EventEditDialog);
        fromDetectArea->setObjectName(QString::fromUtf8("fromDetectArea"));
        fromDetectArea->setGeometry(QRect(0, 320, 500, 50));
        fromDetectArea->setMouseTracking(false);
        toDetectArea = new DetectAreaTo(EventEditDialog);
        toDetectArea->setObjectName(QString::fromUtf8("toDetectArea"));
        toDetectArea->setGeometry(QRect(0, 380, 500, 50));
        eventLabel = new QLabel(EventEditDialog);
        eventLabel->setObjectName(QString::fromUtf8("eventLabel"));
        eventLabel->setGeometry(QRect(56, 140, 51, 22));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font3.setPointSize(10);
        font3.setBold(false);
        eventLabel->setFont(font3);
        countdownLabel = new QLabel(EventEditDialog);
        countdownLabel->setObjectName(QString::fromUtf8("countdownLabel"));
        countdownLabel->setGeometry(QRect(149, 140, 91, 22));
        countdownLabel->setFont(font3);
        birthdayLabel = new QLabel(EventEditDialog);
        birthdayLabel->setObjectName(QString::fromUtf8("birthdayLabel"));
        birthdayLabel->setGeometry(QRect(275, 140, 71, 22));
        birthdayLabel->setFont(font3);
        anniversaryLabel = new QLabel(EventEditDialog);
        anniversaryLabel->setObjectName(QString::fromUtf8("anniversaryLabel"));
        anniversaryLabel->setGeometry(QRect(378, 140, 91, 22));
        anniversaryLabel->setFont(font3);
        fakeButton2 = new QPushButton(EventEditDialog);
        fakeButton2->setObjectName(QString::fromUtf8("fakeButton2"));
        fakeButton2->setGeometry(QRect(350, 0, 45, 45));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        fakeButton2->setIcon(icon7);
        fakeButton2->setIconSize(QSize(28, 28));
        fromDetectArea->raise();
        toDetectArea->raise();
        allDayDetectArea->raise();
        eventNameLabel->raise();
        addEventLabel->raise();
        startDateEdit->raise();
        startTimeEdit->raise();
        endDateEdit->raise();
        endTimeEdit->raise();
        fromLabel->raise();
        toLabel->raise();
        eventNameLineEdit->raise();
        locationLineEdit->raise();
        locationLabel->raise();
        descriptionLabel->raise();
        cancelBtn->raise();
        eventBtn->raise();
        countdownBtn->raise();
        birthdayBtn->raise();
        anniversaryBtn->raise();
        allDayLabel->raise();
        fakeButton->raise();
        splitLine->raise();
        descriptionTextEdit->raise();
        eventLabel->raise();
        countdownLabel->raise();
        birthdayLabel->raise();
        anniversaryLabel->raise();
        fakeButton2->raise();

        retranslateUi(EventEditDialog);

        QMetaObject::connectSlotsByName(EventEditDialog);
    } // setupUi

    void retranslateUi(QDialog *EventEditDialog)
    {
        EventEditDialog->setWindowTitle(QString());
        eventNameLabel->setText(QCoreApplication::translate("EventEditDialog", "Event name", nullptr));
        addEventLabel->setText(QCoreApplication::translate("EventEditDialog", "Add event", nullptr));
        startTimeEdit->setSpecialValueText(QString());
        startTimeEdit->setDisplayFormat(QCoreApplication::translate("EventEditDialog", "HH:mm", nullptr));
        endTimeEdit->setSpecialValueText(QString());
        endTimeEdit->setDisplayFormat(QCoreApplication::translate("EventEditDialog", "HH:mm", nullptr));
        fromLabel->setText(QCoreApplication::translate("EventEditDialog", "From", nullptr));
        toLabel->setText(QCoreApplication::translate("EventEditDialog", "To", nullptr));
#if QT_CONFIG(tooltip)
        eventNameLineEdit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        eventNameLineEdit->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        eventNameLineEdit->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        eventNameLineEdit->setAccessibleName(QCoreApplication::translate("EventEditDialog", "accessible", nullptr));
#endif // QT_CONFIG(accessibility)
        locationLabel->setText(QCoreApplication::translate("EventEditDialog", "Location", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("EventEditDialog", "Description", nullptr));
        cancelBtn->setText(QCoreApplication::translate("EventEditDialog", "  Cancel", nullptr));
        eventBtn->setText(QString());
        countdownBtn->setText(QString());
        birthdayBtn->setText(QString());
        anniversaryBtn->setText(QString());
        allDayLabel->setText(QCoreApplication::translate("EventEditDialog", "All day", nullptr));
        fakeButton->setText(QCoreApplication::translate("EventEditDialog", "  Save", nullptr));
        allDayCheckBox->setText(QString());
        eventLabel->setText(QCoreApplication::translate("EventEditDialog", "Event", nullptr));
        countdownLabel->setText(QCoreApplication::translate("EventEditDialog", "Countdown", nullptr));
        birthdayLabel->setText(QCoreApplication::translate("EventEditDialog", "Birthday", nullptr));
        anniversaryLabel->setText(QCoreApplication::translate("EventEditDialog", "Anniversary", nullptr));
        fakeButton2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EventEditDialog: public Ui_EventEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTEDITDIALOG_H
