#pragma once

#include "GLToolBox.h"

class DemoApp : public GLToolBox::Application
{
public:
    DemoApp(const char *windowName = "DemoApp", unsigned int width = 1600, unsigned int height = 1000);
    virtual void prepareData();
    virtual void preUpdate() override;
    virtual void update() override;

private:
    // 定义椭圆的参数
    float a = 0.9f;
    float b = 0.6f;
    float F1x = 0.0f;
    float F1y = 0.0f;
    float F2x = 0.0f;
    float F2y = 0.0f;

    // 小球
    struct Ball
    {
        float x, y;
        float vx, vy;
        float r, g, b;
    } balls[360];
};
