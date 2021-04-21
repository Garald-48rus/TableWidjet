QT       += core gui
QT += multimedia
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apple.cpp \
    db.cpp \
    fieldobject.cpp \
    gamefield.cpp \
    inventory.cpp \
    main.cpp \
    menu.cpp \
    sound.cpp

HEADERS += \
    apple.h \
    db.h \
    fieldobject.h \
    gamefield.h \
    inventory.h \
    menu.h \
    sound.h

FORMS += \
    gamefield.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
