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

    // Создаем корневой узел приложения. Через данный класс приложение
    // получает доступ ко всем возможностям движка (системам рендеринга,
    // окнам, конфигурации и прочим доступным в движке классам)
    Ogre::Root *root = OGRE_NEW Ogre::Root(
                cfgDir + "hello.cfg",
                cfgDir + "ogre.cfg",
                logsDir + "hello.log");

    // Вызываем диалоговое окно (по умолчанию, т.к. без параметров)
    // для предварительного выбора системы рендеринга, параметров экрана.
    // Выбранные параметры сохраняются в файл ogre.cfg и будут восстановлены
    // при повторном запуске приложения
    if (!root->showConfigDialog())
        return -1;

    // Инициализация системы рендеринга
    Ogre::Window *window = root->initialise(
                true,                   // Автоматическое создание окна
                "Hello, OGRE Next!");   // Заголовок окна

    const size_t numThreads = 1u;

    // Создаем менеджер сцены. Он организует выборку объектов и рендериг сцены
    Ogre::SceneManager *sceneManager =
            root->createSceneManager(
                Ogre::ST_GENERIC,       // Тип менеджера сцены
                numThreads,             // Число рабочих потоков CPU
                "Hello");               // Необязательный строковый ID

    // Создание камеры (настройка матрицы вида, по сути)
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

    // Создаем обработчик событий окна
    WindowEventListener windowEventListener;
    Ogre::WindowEventUtilities::addWindowEventListener(window, &windowEventListener);

    bool bQuit = false;

    // Цикл обработки событий окна и рендеринга
    while (!bQuit)
    {
        Ogre::WindowEventUtilities::messagePump();
        bQuit |= windowEventListener.getQuit();

        if (!bQuit)
            bQuit |= !root->renderOneFrame();
    }

    // Освобождаем ресурсы
    Ogre::WindowEventUtilities::removeWindowEventListener(
                window,
                &windowEventListener);

    OGRE_DELETE root;
    root = nullptr;

    return 0;
}
