QT       += testlib
TARGET = Tests
CONFIG   += console
TEMPLATE = app
SOURCES += main.cpp

include(./fieldtest/fieldtest.pri)
include(./commandexecutertest/commandexecutertest.pri)
