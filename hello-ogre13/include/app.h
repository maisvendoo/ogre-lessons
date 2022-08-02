#ifndef     APP_H
#define     APP_H

#include    <Ogre.h>
#include    <OgreApplicationContext.h>
#include    <OgreInput.h>
#include    <OgreRTShaderSystem.h>

#include    <iostream>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class BasicApp
        : public OgreBites::ApplicationContext
        , public OgreBites::InputListener
{
public:

    BasicApp();

    virtual ~BasicApp() {}

    void setup();

    bool keyPressed(const OgreBites::KeyboardEvent &event);
};

#endif // APP_H
