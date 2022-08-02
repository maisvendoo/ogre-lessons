TEMPLATE = app

DESTDIR = ../../bin

CONFIG += c++17
CONFIG -= qt
CONFIG += console

TARGET = hello

win32 {

    INCLUDEPATH += $(OGRE_NEXT_HOME)/include/OGRE

    CONFIG(debug,debug|release) {

        LIBS += -L$(OGRE_NEXT_HOME)/lib/Debug -lOgreMain_d
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Debug -lOgreHlmsPbs_d
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Debug -lOgreHlmsUnlit_d
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Debug -lOgreMeshLodGenerator_d
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Debug -lOgreOverlay_d
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Debug -lOgreSceneFormat_d

    } else {

        LIBS += -L$(OGRE_NEXT_HOME)/lib/Release -lOgreMain
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Release -lOgreHlmsPbs
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Release -lOgreHlmsUnlit
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Release -lOgreMeshLodGenerator
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Release -lOgreOverlay
        LIBS += -L$(OGRE_NEXT_HOME)/lib/Release -lOgreSceneFormat

    }
}

INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)
