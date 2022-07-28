#include    "main.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class WindowEventListener : public Ogre::WindowEventListener
{
public:

    WindowEventListener()
        : mQuit(false)
    {

    }

    virtual void windowClosed(Ogre::Window *rw)
    {
        (void) rw;

        mQuit = true;
    }

    bool getQuit() const { return mQuit; }

private:

    bool mQuit;
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    const Ogre::String logsDir("..\\logs\\");
    const Ogre::String cfgDir("..\\cfg\\");

    Ogre::Root *root = OGRE_NEW Ogre::Root(
                cfgDir + "hello.cfg",
                cfgDir + "ogre.cfg",
                logsDir + "hello.log");

    if (!root->showConfigDialog())
        return -1;

    Ogre::Window *window = root->initialise(true, "Hello, OGRE Next!");

    const size_t numThreads = 1u;

    Ogre::SceneManager *sceneManager =
            root->createSceneManager(Ogre::ST_GENERIC,
                                     numThreads,
                                     "Hello");

    Ogre::Camera *camera = sceneManager->createCamera("Main Camera");
    camera->setPosition(Ogre::Vector3(0.0, 5.0, 15.0));
    camera->lookAt(Ogre::Vector3(0.0, 0.0, 0.0));
    camera->setNearClipDistance(0.1f);
    camera->setFarClipDistance(1000.0f);
    camera->setAutoAspectRatio(true);

    Ogre::CompositorManager2 *compositorManager = root->getCompositorManager2();
    const Ogre::String workspaceName("Demo Workspace");
    const Ogre::ColourValue backgroundColor(0.2f, 0.4f, 0.6f);
    compositorManager->createBasicWorkspaceDef(
                workspaceName,
                backgroundColor,
                Ogre::IdString());
    compositorManager->addWorkspace(
                sceneManager,
                window->getTexture(),
                camera,
                workspaceName,
                true);

    WindowEventListener windowEventListener;
    Ogre::WindowEventUtilities::addWindowEventListener(window, &windowEventListener);

    bool bQuit = false;

    while (!bQuit)
    {
        Ogre::WindowEventUtilities::messagePump();
        bQuit |= windowEventListener.getQuit();

        if (!bQuit)
            bQuit |= !root->renderOneFrame();
    }

    Ogre::WindowEventUtilities::removeWindowEventListener(
                window,
                &windowEventListener);

    OGRE_DELETE root;
    root = nullptr;

    return 0;
}
