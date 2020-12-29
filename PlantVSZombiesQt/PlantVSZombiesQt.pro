QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += multimedia
SOURCES += \
    BucketHeadZombie.cpp \
    Bullet.cpp \
    Cards.cpp \
    CherryBomb.cpp \
    Common.cpp \
    ConeHeadZombie.cpp \
    EndSign.cpp \
    FlagZombie.cpp \
    Garlic.cpp \
    Grassland.cpp \
    NormalZombie.cpp \
    PauseButton.cpp \
    PeaBullet.cpp \
    PeaShooter.cpp \
    Plants.cpp \
    PoleVaultingZombie.cpp \
    PumpkinHead.cpp \
    Repeater.cpp \
    Shovel.cpp \
    SnowPea.cpp \
    SnowPeaBullet.cpp \
    Squash.cpp \
    Sun.cpp \
    SunFlower.cpp \
    SunPanel.cpp \
    TallNut.cpp \
    WallNut.cpp \
    Zombies.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BucketHeadZombie.h \
    Bullet.h \
    Cards.h \
    CherryBomb.h \
    Common.h \
    ConeHeadZombie.h \
    EndSign.h \
    FlagZombie.h \
    Garlic.h \
    Grassland.h \
    NormalZombie.h \
    PauseButton.h \
    PeaBullet.h \
    PeaShooter.h \
    Plants.h \
    PoleVaultingZombie.h \
    PumpkinHead.h \
    Repeater.h \
    Shovel.h \
    SnowPea.h \
    SnowPeaBullet.h \
    Squash.h \
    Sun.h \
    SunFLower.h \
    SunPanel.h \
    TallNut.h \
    WallNut.h \
    Zombies.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    PlantVSZombiesQt_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
