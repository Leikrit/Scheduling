QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendarbutton.cpp \
    calendarwidget.cpp \
    dayeventwidget.cpp \
    detectarea.cpp \
    detectareaallday.cpp \
    detectareafrom.cpp \
    detectareato.cpp \
    eventbasewidget.cpp \
    eventeditdialog.cpp \
    eventfull.cpp \
    global.cpp \
    intervaleventwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    memowidget.cpp \
    momenteventwidget.cpp \
    settingdialog.cpp \
    specialdayeventwidget.cpp \
    taskeditdialog.cpp \
    todowidget.cpp

HEADERS += \
    calendarbutton.h \
    calendarwidget.h \
    dayeventwidget.h \
    detectarea.h \
    detectareaallday.h \
    detectareafrom.h \
    detectareato.h \
    eventbasewidget.h \
    eventeditdialog.h \
    eventfull.h \
    global.h \
    intervaleventwidget.h \
    mainwidget.h \
    memowidget.h \
    momenteventwidget.h \
    settingdialog.h \
    specialdayeventwidget.h \
    task.h \
    taskeditdialog.h \
    todowidget.h

FORMS += \
    dayeventwidget.ui \
    eventbasewidget.ui \
    eventeditdialog.ui \
    intervaleventwidget.ui \
    mainwidget.ui \
    momenteventwidget.ui \
    settingdialog.ui \
    specialdayeventwidget.ui \
    taskeditdialog.ui \
    todowidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
