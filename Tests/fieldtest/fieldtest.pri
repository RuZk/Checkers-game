#-------------------------------------------------
#
# Project created by QtCreator 2015-01-20T14:22:08
#
#-------------------------------------------------

QT       -= gui
QT += core

TARGET = tst_fieldtest
CONFIG   += console
CONFIG   -= app_bundle

 message(testsdir: $$PWD)

SOURCES += $$PWD/tst_fieldtest.cpp \
           $$PWD/../../Checkers/field.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
