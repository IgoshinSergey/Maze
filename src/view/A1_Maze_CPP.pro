QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mazewidget.cpp \
    ../maze/maze.cpp \
    ../eller/eller_algorithm.cpp \
    ../file_handling/export_file.cpp \
    ../file_handling/import_file.cpp \
    ../waveAlgorithm/waveAlgorythm.cpp

HEADERS += \
    mainwindow.h \
    mazewidget.h \
    ../maze/maze.hpp \
    ../eller/eller_algorithm.hpp \
    ../file_handling/file_handling.hpp \
    ../waveAlgorithm/waveAlgorythm.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
