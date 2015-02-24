#-------------------------------------------------
#
# Project created by QtCreator 2011-10-13T22:35:09
#
#-------------------------------------------------

QT       += core gui network

TARGET = Lab2_client
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp \
    testdialog.cpp \
    qcustomplot.cpp

HEADERS  += dialog.h \
    testdialog.h \
    qcustomplot.h

win64:RC_FILE = Lab2_client.rc

FORMS    += dialog.ui \
    testdialog.ui

OTHER_FILES += \
    ClientSettings.ini



