#-------------------------------------------------
#
# Project created by QtCreator 2011-07-10T22:52:26
#
#-------------------------------------------------

QT       += core gui opengl xml

TARGET = fotoproj
TEMPLATE = app

LIBS += -lGLU

SOURCES += main.cpp\
    window.cpp \
    map.cpp \
    new_dlg.cpp \
    projecthandle.cpp \
    glwidget.cpp \
    graph_widget.cpp \
    func.cpp \
    lib_dialog.cpp

HEADERS  += \
    window.h \
    glwidget.h \
    map.h \
    new_dlg.h \
    projecthandle.h \
    type_and_const.h \
    graph_widget.h \
    func.h \
    lib_dialog.h

FORMS += \
    window.ui \
    newp_dlg.ui \
    lib_dialog.ui

RESOURCES += \
    resources.qrc
