#-------------------------------------------------
#
# Project created by QtCreator 2014-11-09T22:23:11
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = QtTetris
TEMPLATE = app

SOURCES += main.cpp\
    qttetris.cpp \
    tetrisgroup.cc \
    square.cc \
    dot.cc \
    box.cc \
    four.cc \
    seven.cc \
    randbox.cc \
    sevenreverse.cc \
    z.cc \
    zreverse.cc \
    convex.cc \
    one.cc \
    transcolor.cpp \
    five.cc \
    three.cc \
    cross.cc \
    qttetrisgroupwidget.cpp \
    qtnextboxwidget.cpp

HEADERS  += qttetris.h \
    tetrisgroup.h \
    square.h \
    dot.h \
    define.h \
    box.h \
    four.h \
    seven.h \
    sevenreverse.h \
    z.h \
    zreverse.h \
    convex.h \
    one.h \
    five.h \
    three.h \
    cross.h \
    qttetrisgroupwidget.h \
    qtnextboxwidget.h

OTHER_FILES += \
    app_icon.rc

RESOURCES += \
    icon.qrc

RC_FILE = app_icon.rc
