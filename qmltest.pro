TEMPLATE = app

QT = declarative

SOURCES += main.cpp \
    mainwindow.cpp \
    singer.cpp \
    bass.cpp

RESOURCES += qml.qrc


LIBS += -LC:\Develop\qmltest\qmltest -lbass


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

HEADERS += \
    mainwindow.h \
    singer.h \
    music.h \
    bass.h
