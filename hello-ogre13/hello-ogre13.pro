TEMPLATE = app

DESTDIR = ../../bin

CONFIG += c++11
CONFIG -= qt
CONFIG += console

TARGET = hello-ogre13

win32 {

    INCLUDEPATH += $(OGRE_HOME)/include/OGRE/
    INCLUDEPATH += $(OGRE_HOME)/include/OGRE/Bites/
    INCLUDEPATH += $(OGRE_HOME)/include/OGRE/RTShaderSystem

    CONFIG(debug,debug|release) {

        LIBS += -L$(OGRE_HOME)/lib -lOgreMain_d
        LIBS += -L$(OGRE_HOME)/lib -lOgreBites_d


    } else {

        LIBS += -L$(OGRE_HOME)/lib -lOgreMain
        LIBS += -L$(OGRE_HOME)/lib -lOgreBites

    }
}

INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)
