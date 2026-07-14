QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classes_auxiliares.cpp \
    dialogfundos.cpp \
    dialogobjetivo.cpp \
    dialogtransacao.cpp \
    fundos.cpp \
    main.cpp \
    mainwindow.cpp \
    objetivo.cpp \
    pessoa.cpp \
    transacao.cpp

HEADERS += \
    classes_auxiliares.h \
    dialogfundos.h \
    dialogobjetivo.h \
    dialogtransacao.h \
    fundos.h \
    mainwindow.h \
    objetivo.h \
    pessoa.h \
    transacao.h

FORMS += \
    dialogfundos.ui \
    dialogobjetivo.ui \
    dialogtransacao.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
