#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T20:10:40
#
#-------------------------------------------------

QT       += core #gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Checkers
TEMPLATE = app

debug
{
    PWD = $$PWD/../debug
}
release
{
    PWD = $$PWD/../release
}

SOURCES += main.cpp\
    ./field.cpp \
    ./command.cpp

HEADERS  += field.h \
    ./command.h

OBJECTS_DIR = $$PWD/tmp/obj
UI_DIR = $$PWD/tmp/ui
MOC_DIR = $$PWD/tmp/moc
RCC_DIR = $$PWD/tmp/rcc
DESTDIR = $$PWD/bin

 message(Qt version: $$[QT_VERSION])
 message(Qt is installed in $$[QT_INSTALL_PREFIX])
 message(Qt resources can be found in the following locations:)
 message(Documentation: $$[QT_INSTALL_DOCS])
 message(Header files: $$[QT_INSTALL_HEADERS])
 message(Libraries: $$[QT_INSTALL_LIBS])
 message(Binary files (executables): $$[QT_INSTALL_BINS])
 message(Plugins: $$[QT_INSTALL_PLUGINS])
 message(Data files: $$[QT_INSTALL_DATA])
 message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
 message(Settings: $$[QT_INSTALL_SETTINGS])
 message(Examples: $$[QT_INSTALL_EXAMPLES])
 message(Demonstrations: $$[QT_INSTALL_DEMOS])
 message(The project will be installed in $$DESTDIR)
