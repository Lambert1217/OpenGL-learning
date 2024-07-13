#include "GLToolBox.h"
#include "DemoApp.h"

using namespace GLToolBox;
int main()
{
    DemoApp app("Demo1", 1300, 1300);

    app.init(4, 5, Application::OpenGLProfile::COMPAT);
    app.run();

    return 0;
}