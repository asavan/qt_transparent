TEMPLATE = app

QT += qml quick widgets core gui declarative

SOURCES += main.cpp \
    mainwindow.cpp \
    singer.cpp \
    bass.cpp

RESOURCES += qml.qrc


LIBS += -LC:\Develop\qmltest\qmltest -lbass


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    singer.h \
    music.h \
    bass.h
