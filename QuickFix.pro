QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpanel.cpp \
    main.cpp \
    loginwindow.cpp \
    manageusers.cpp \
    user.cpp \
    userpanel.cpp

HEADERS += \
    adminpanel.h \
    loginwindow.h \
    manageusers.h \
    user.h \
    userpanel.h

FORMS += \
    adminpanel.ui \
    loginwindow.ui \
    userpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
    gdf.scxml

DISTFILES += \
    example.xml \
    issues.xml
