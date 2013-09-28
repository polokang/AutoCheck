#-------------------------------------------------
#
# Project created by QtCreator 2013-09-17T09:08:27
#
#-------------------------------------------------

QT       += core gui xml

TARGET = AutoCheck
TEMPLATE = app

CONFIG   += qaxcontainer

SOURCES += main.cpp\
        mainwindow.cpp \
    configdlg.cpp \
    excelengine.cpp \
    importied.cpp \
    impdelegate.cpp \
    impaccpoint.cpp

HEADERS  += mainwindow.h \
    configdlg.h \
    typeDef.h \
    excelengine.h \
    importied.h \
    impdelegate.h \
    impaccpoint.h


unix{
LIBS +=-L/home/lib -lxmlhelplib
}

win32{
LIBS +=-L./lib -lxmlhelplib
}


FORMS    += mainwindow.ui \
    configdlg.ui \
    importied.ui \
    impaccpoint.ui

RESOURCES += \
    image.qrc
