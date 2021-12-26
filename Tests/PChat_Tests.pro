include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
    tst_CheckerTests.h

SOURCES += \
        main.cpp

