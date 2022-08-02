#include    "app.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BasicApp::BasicApp() : OgreBites::ApplicationContext("Hello, Ogre 13!")
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BasicApp::setup()
{
    OgreBites::ApplicationContext::setup();
    addInputListener(this);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool BasicApp::keyPressed(const OgreBites::KeyboardEvent &event)
{
    if (event.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }

    return true;
}
