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

SOURCES += $$PWD/commandexecutertest.cpp \
           $$PWD/../../Checkers/commandexecuter.cpp \
           $$PWD/../../Checkers/turnanalizer.cpp \
           $$PWD/../../Checkers/command.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
