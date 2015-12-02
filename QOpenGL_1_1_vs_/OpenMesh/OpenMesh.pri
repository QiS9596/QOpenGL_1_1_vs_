
INCLUDEPATH += \
    $$PWD

DEFINES += _USE_MATH_DEFINES

HEADERS += \
    $$PWD/openmeshframework.h

SOURCES += \
    $$PWD/openmeshframework.cpp

#Load OpenMesh4.1 static libraries
win32 {
    contains(QMAKE_HOST.arch, x86_64) {
        CONFIG(debug, debug|release) {
            LIBS += -L$$PWD/lib/x64/debug -lOpenMeshCored_x64 -lOpenMeshToolsd_x64
        } else {
            LIBS += -L$$PWD/lib/x64/release -lOpenMeshCore_x64 -lOpenMeshTools_x64
        }
    } else {
        CONFIG(debug, debug|release) {
            LIBS += -L$$PWD/lib/Win32/debug -lOpenMeshCored_x86 -lOpenMeshToolsd_x86
        } else {
            LIBS += -L$$PWD/lib/Win32/release -lOpenMeshCore_x86 -lOpenMeshTools_x86
        }
    }
}
