TEMPLATE = app

QT += qml quick
QT += widgets

SOURCES += main.cpp \
    singer.cpp \
    bass.cpp

RESOURCES += qml.qrc


LIBS += -LC:\Develop\qt_transparent\dependencies -lbass


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

HEADERS += \
    singer.h \
    music.h \
    dependencies/bass.h
