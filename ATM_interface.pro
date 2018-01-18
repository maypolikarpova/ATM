#-------------------------------------------------
#
# Project created by QtCreator 2017-11-05T15:16:21
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATM_interface
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    ATM.cpp \
    account.cpp \
    atm_graphics.cpp \
    bd.cpp \
    money_map.cpp

HEADERS += \
    Account.h \
    ATM.h \
    bd.h \
    atm_graphics.h \
    bd.h \
    money_map.h

FORMS += \
    ATM_Graphics.ui
