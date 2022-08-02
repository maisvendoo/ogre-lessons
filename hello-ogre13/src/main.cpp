#include    "app.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    try
    {
        BasicApp app;
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();


    }  catch (const std::exception &e)
    {
        std::cerr << "Error occured during execution" << e.what() << std::endl;
        return 1;
    }

    return 0;
}
