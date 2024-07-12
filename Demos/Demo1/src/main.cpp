#include "GLToolBox.h"
#include "DemoApp.h"

using namespace GLToolBox;
int main()
{
    DemoApp app("Demo1");

    app.init();
    app.run();

    return 0;
}