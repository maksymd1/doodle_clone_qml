TEMPLATE = app

QT += core gui qml quick

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += qml \
               data

SOURCES += \
        main.cpp \
    doodleobject.cpp \
    doodleunit.cpp \
    doodleplatform.cpp \
    doodleengine.cpp \
    highscores.cpp

HEADERS += \
    doodleobject.h \
    doodleunit.h \
    doodleplatform.h \
    doodleengine.h \
    highscores.h

RESOURCES += \
    res.qrc


# if you are using Shadow build, you need to get the output folder
CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug

# if you are using normal build (non-shadow) that would have worked as well.
CONFIG(release, debug|release): DESTDIR = release
CONFIG(debug, debug|release): DESTDIR = debug

datafiles.commands = $(COPY_DIR) $$shell_path($$PWD/data/scores.ini) $$shell_path($$DESTDIR)
first.depends = $(first) datafiles
export(first.depends)
export(datafiles.commands)
QMAKE_EXTRA_TARGETS += first datafiles


#install_scores.path   = $$DESTDIR
#install_scores.files += $$files(data/*.ini)
##%{sourceDir}\data\scores.ini

#INSTALLS += install_scores

