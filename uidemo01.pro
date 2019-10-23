#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T18:38:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = materialManagement
TEMPLATE    = app
#MOC_DIR     = temp/moc
#RCC_DIR     = temp/rcc
#UI_DIR      = temp/ui
#OBJECTS_DIR = temp/obj
#DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp \
    pagewidget.cpp \
    querysetdialog.cpp \
    addmaterial_dialog.cpp \
    inbound_dialog.cpp \
    outbound_dialog.cpp \
    altermaterial_dialog.cpp \
    inboundquery_dialog.cpp \
    outboundquery_dialog.cpp \
    adduser_dialog.cpp \
    alteruser_dialog.cpp \
    frmlogin.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     += uidemo01.cpp

HEADERS     += iconhelper.h \
    pagewidget.h \
    querysetdialog.h \
    addmaterial_dialog.h \
    inbound_dialog.h \
    outbound_dialog.h \
    altermaterial_dialog.h \
    inboundquery_dialog.h \
    outboundquery_dialog.h \
    adduser_dialog.h \
    alteruser_dialog.h \
    frmlogin.h
HEADERS     += appinit.h
HEADERS     += uidemo01.h

FORMS       += uidemo01.ui \
    pagewidget.ui \
    querysetdialog.ui \
    addmaterial_dialog.ui \
    inbound_dialog.ui \
    outbound_dialog.ui \
    altermaterial_dialog.ui \
    inboundquery_dialog.ui \
    outboundquery_dialog.ui \
    adduser_dialog.ui \
    alteruser_dialog.ui \
    frmlogin.ui

RESOURCES   += main.qrc
RESOURCES   += qss.qrc
CONFIG      += qt warn_off
INCLUDEPATH += $$PWD
