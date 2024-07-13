#include "Application/Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Debug/Log.h"

namespace GLToolBox
{
    Application::Application(const char *windowName, unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height), m_WindowName(windowName), m_Window(nullptr)
    {
    }

    Application::~Application()
    {
        shutDown();
    }

    void Application::init(int version_major, int version_minor, OpenGLProfile opengl_profile)
    {
        Log::init();

        if (!glfwInit())
        {
            LOG_ERROR("glfw 初始化失败");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version_major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version_minor);
        switch (opengl_profile)
        {
        case OpenGLProfile::CORE:
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            break;
        case OpenGLProfile::COMPAT:
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
            break;
        default:
            LOG_ERROR("未知 OpenGLProfile");
        }

        m_Window = glfwCreateWindow(m_Width, m_Height, m_WindowName, nullptr, nullptr);
        if (m_Window == nullptr)
        {
            LOG_ERROR("创建窗口失败");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);

        // 初始化GLAD来获取OpenGL函数指针
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_ERROR("glad 初始化失败");
            glfwTerminate();
            return;
        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_DEPTH_TEST);

        prepareData();
        LOG_INFO("程序初始化成功");
    }

    void Application::prepareData()
    {
    }

    void Application::run()
    {
        while (!glfwWindowShouldClose(m_Window))
        {
            preUpdate();
            update();
            postUpdate();
        }
    }

    void Application::preUpdate()
    {
        glClearColor(1.0f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Application::update()
    {
    }

    void Application::postUpdate()
    {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }

    void Application::shutDown()
    {
        glfwTerminate();
    }
}
