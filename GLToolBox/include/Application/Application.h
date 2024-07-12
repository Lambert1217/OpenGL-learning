/**
 * @file Application.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief 程序
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

class GLFWwindow;

namespace GLToolBox
{
    class Application
    {
    public:
        /**
         * @brief Construct a new Application object
         *
         * @param windowName
         * @param width
         * @param height
         */
        Application(const char *windowName = "GLToolBox-Demo", unsigned int width = 1600, unsigned int height = 1000);

        /**
         * @brief Destroy the Application object
         *
         */
        virtual ~Application();

        /**
         * @brief 用于初始化程序 （创建窗口、初始化glad）
         *
         * @return true
         * @return false
         */
        virtual void init();

        /**
         * @brief 程序循环
         *
         */
        void run();

        /**
         * @brief 用于更新前（例如 glClear）
         *
         */
        virtual void preUpdate();

        /**
         * @brief 更新和渲染主体
         *
         */
        virtual void update();

        /**
         * @brief 用于更新后（例如 glfwSwapBuffers）
         *
         */
        virtual void postUpdate();

    private:
        /**
         * @brief 程序结束时调用
         *
         */
        void shutDown();

    protected:
        GLFWwindow *m_Window;
        unsigned int m_Width, m_Height;
        const char *m_WindowName;
    };
}