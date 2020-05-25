QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changetagkeyform.cpp \
    changetagvalueform.cpp \
    exifextra.cpp \
    exifkeys.cpp \
    fraction.cpp \
    main.cpp \
    mainwindow.cpp \
    photobase.cpp \
    photomodel.cpp \
    photopresenter.cpp \
    photoview.cpp \
    settingssingleton.cpp \
    tagbase.cpp \
    tagkeyedit.cpp \
    tagkeyeditlist.cpp \
    taglistbase.cpp \
    tagvalueedit.cpp \
    tagvalueeditlist.cpp \
    tagvalueedittable.cpp \
    textbase.cpp

HEADERS += \
    changetagkeyform.h \
    changetagvalueform.h \
    exifextra.h \
    exifkeys.h \
    fraction.h \
    mainwindow.h \
    photobase.h \
    photomodel.h \
    photopresenter.h \
    photosegment.h \
    photoview.h \
    settingssingleton.h \
    tagbase.h \
    tagkeyedit.h \
    tagkeyeditlist.h \
    taglistbase.h \
    tagvalueedit.h \
    tagvalueeditlist.h \
    tagvalueedittable.h \
    textbase.h

FORMS += \
    changetagkeyform.ui \
    changetagvalueform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


LIBS += -lexiv2.dll

RESOURCES += \
    resource.qrc \
    mosaic_icon.ico

RC_ICONS = mosaic_icon.ico
