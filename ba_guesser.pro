QMAKE_CXXFLAGS_DEBUG += /MDd
QMAKE_CXXFLAGS_RELEASE += /MD
QMAKE_PROJECT_DEPTH = 0

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    randomguess.cpp

HEADERS += \
    mainwindow.h \
    randomguess.h

FORMS += \
    mainwindow.ui

win32 {
    INCLUDEPATH += D:/libraries/opencv/build/include
    INCLUDEPATH += D:/libraries/opencv/build/include/opencv2

    QMAKE_LIBDIR += D:/libraries/opencv/build/x64/vc16/lib

    CONFIG(debug, debug|release) {
        LIBS += -lopencv_world4120d
        DLL_PATH = D:/libraries/opencv/build/x64/vc16/bin/opencv_world4120d.dll
        DLL_DEST = $$OUT_PWD/debug
    } else {
        LIBS += -lopencv_world4120
        DLL_PATH = D:/libraries/opencv/build/x64/vc16/bin/opencv_world4120.dll
        DLL_DEST = $$OUT_PWD/release
    }

    QMAKE_POST_LINK += copy /Y \"$$shell_path($$DLL_PATH)\" \"$$shell_path($$DLL_DEST)\"$$escape_expand(\n\t)
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
