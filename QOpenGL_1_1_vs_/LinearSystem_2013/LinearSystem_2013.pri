
INCLUDEPATH += \
    $$PWD/include

#Load OpenMesh4.1 static libraries
win32 {
    contains(QMAKE_HOST.arch, x86_64) {
        CONFIG(debug, debug|release) {
            LIBS += -L$$PWD/lib/x64/debug -lLinearSystemLibD_MD
        } else {
            LIBS += -L$$PWD/lib/x64/release -lLinearSystemLib_MD
        }
    } else {
        CONFIG(debug, debug|release) {
            LIBS += -L$$PWD/lib/Win32/debug -lLinearSystemLibD_MD
        } else {
            LIBS += -L$$PWD/lib/Win32/release -lLinearSystemLib_MD
        }
    }
}
