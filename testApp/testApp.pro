#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T18:29:28
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++11

TEMPLATE = app

android {
    INCLUDEPATH += "/home/polibr/home/joselito.nogueira/dev/git/qt-third-party/github.com/openssl/include"
    LIBS += -L"/home/polibr/home/joselito.nogueira/dev/git/fastseller/libs/qt53/armeabi-v7a"

    ANDROID_EXTRA_LIBS += "/home/polibr/home/joselito.nogueira/dev/git/fastseller/libs/qt53/armeabi-v7a/libssl.so"
    ANDROID_EXTRA_LIBS += "/home/polibr/home/joselito.nogueira/dev/git/fastseller/libs/qt53/armeabi-v7a/libcrypto.so"

#    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/testApp/android
}

INCLUDEPATH += $$PWD/../telegram-qt

LIBS += \
    -lssl \
    -lcrypto
LIBS += -lz
LIBS += -lTelegramQt
LIBS += -L$$OUT_PWD/../telegram-qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testApp
TEMPLATE = app

SOURCES += main.cpp\
    MainWindow.cpp \
    CContactModel.cpp \
    CMessagingModel.cpp \
    CChatInfoModel.cpp

HEADERS  += MainWindow.hpp \
    CContactModel.hpp \
    CMessagingModel.hpp \
    CChatInfoModel.hpp

FORMS    += MainWindow.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += CMakeLists.txt
