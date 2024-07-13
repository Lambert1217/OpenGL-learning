#include "DemoApp.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

#define PI 3.1415926

using namespace GLToolBox;

DemoApp::DemoApp(const char *windowName, unsigned int width, unsigned int height)
    : Application(windowName, width, height)
{
}

void DemoApp::init(int version_major, int version_minor, OpenGLProfile opengl_profile)
{
    Application::init(version_major, version_minor, opengl_profile);

    // 计算焦点坐标
    float c = glm::sqrt(glm::pow(a, 2) - glm::pow(b, 2));
    F1x = -c;
    F2x = c;
    // 每个球初始化位置和速度
    for (int i = 0; i < 360; i++)
    {
        balls[i].x = F1x;
        balls[i].y = F1y;
        balls[i].vx = glm::cos(i * PI / 180);
        balls[i].vy = glm::sin(i * PI / 180);

        balls[i].r = (glm::sin(i * PI / 180) + 1.0f) / 2.0f;
        balls[i].g = (glm::cos(i * PI / 180) + 1.0f) / 2.0f;
        balls[i].b = (glm::sin(i * PI / 180 + PI / 2) + 1.0f) / 2.0f;
    }
}

void DemoApp::preUpdate()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // 深灰色背景
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DemoApp::update()
{
    float time = glfwGetTime();

    // 动态计算椭圆的颜色
    float color_r = (sin(time * 2.0f) + 1.0f) / 2.0f;
    float color_g = (cos(time * 2.0f) + 1.0f) / 2.0f;
    float color_b = (sin(time * 1.5f + PI / 2) + 1.0f) / 2.0f;

    // 绘制椭圆
    glColor3f(color_r, color_g, color_b); // 淡绿色
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (float theta = 0; theta < 2 * PI; theta += 0.01)
    {
        float x = a * glm::cos(theta);
        float y = b * glm::sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    // 焦点
    glColor3f(1.0f, 0.3f, 0.3f); // 红色
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glVertex2f(F1x, F1y);
    glVertex2f(F2x, F2y);
    glEnd();

    // 绘制小球
    // 绘制每个球并更新位置
    for (int i = 0; i < 360; i++)
    {
        // 检测球是否碰撞椭圆壁面
        if (glm::pow(balls[i].x / a, 2) + glm::pow(balls[i].y / b, 2) >= 1)
        {
            // 计算法线方向
            float normalX = balls[i].x / glm::pow(a, 2);
            float normalY = balls[i].y / glm::pow(b, 2);
            float length = glm::sqrt(glm::pow(normalX, 2) + glm::pow(normalY, 2));
            normalX /= length;
            normalY /= length;

            // 计算反射方向
            float dotProduct = balls[i].vx * normalX + balls[i].vy * normalY;
            balls[i].vx -= 2 * dotProduct * normalX;
            balls[i].vy -= 2 * dotProduct * normalY;
        }

        // 绘制球
        glColor3f(balls[i].r, balls[i].g, balls[i].b);
        glPointSize(2.0f);
        glBegin(GL_POINTS);
        glVertex2f(balls[i].x, balls[i].y);
        glEnd();

        // 更新位置
        balls[i].x += balls[i].vx * 0.005f;
        balls[i].y += balls[i].vy * 0.005f;
    }
}
