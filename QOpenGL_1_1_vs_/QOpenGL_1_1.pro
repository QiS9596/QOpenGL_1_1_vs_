#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T14:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QOpenGL_1_1
TEMPLATE = app

#Executable directory
win32 {
    contains(QMAKE_HOST.arch, x86_64) {
        CONFIG(debug, debug|release) {
            #x64 - debug
            DESTDIR = $$PWD/bin/x64/debug
        } else {
            #x64 - release
            DESTDIR = $$PWD/bin/x64/release
        }
    } else {
        CONFIG(debug, debug|release) {
            #x86 - debug
            DESTDIR = $$PWD/bin/Win32/debug
        } else {
            #x86 - release
            DESTDIR = $$PWD/bin/Win32/release
        }
    }
}

include ($$PWD/OpenMesh/OpenMesh.pri)
include ($$PWD/LinearSystem_2013/LinearSystem_2013.pri)

LIBS += glu32.lib

INCLUDEPATH += OpenGLTemplate

SOURCES += main.cpp\
        mainwindow.cpp \
    OpenGLTemplate/glframework.cpp \
    OpenGLTemplate/transform.cpp \
    OpenGLTemplate/camera.cpp \
    OpenGLTemplate/trackballcamera.cpp \
    Utilities/righclickmenu.cpp \
    OpenGLTemplate/subwidget.cpp

HEADERS  += mainwindow.h \
    OpenGLTemplate/glstdafx.h \
    OpenGLTemplate/transform.h \
    OpenGLTemplate/camera.h \
    OpenGLTemplate/trackballcamera.h \
    OpenGLTemplate/glframework.h \
    Utilities/rightclickmenu.h \
    OpenGLTemplate/subwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    OpenGLTemplate/resources/textures.qrc
