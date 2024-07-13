#include "DemoApp.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <math.h>

using namespace GLToolBox;

DemoApp::DemoApp(const char *windowName, unsigned int width, unsigned int height)
    : Application(windowName, width, height), VAO(nullptr), m_Shader(nullptr)
{
}

void DemoApp::init()
{
    Application::init();

    VAO = std::make_shared<VertexArray>();
    m_Shader = std::make_shared<Shader>("assets/shaders/shader1.glsl");

    unsigned int indices[] = {0, 1, 2};
    std::shared_ptr<IndexBuffer> EBO = std::make_shared<IndexBuffer>(indices, sizeof(indices) / sizeof(unsigned int));
    VAO->SetIndexBuffer(EBO);
}

void DemoApp::preUpdate()
{
    float r = (float)sin(glfwGetTime()) * 0.5f + 0.5f;
    float g = (float)cos(glfwGetTime()) * 0.5f + 0.5f;
    float b = (r + g) / 2;
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float offset[] = {
        r - 0.5f, g - 0.5f, 0.0f, 0.0f, r, g, b, 1.0f,
        r - 0.5f, g - 0.5f, 0.0f, 0.0f, g, b, r, 1.0f,
        r - 0.5f, g - 0.5f, 0.0f, 0.0f, b, r, g, 1.0f};
    std::shared_ptr<VertexBuffer> VBO = std::make_shared<VertexBuffer>(offset, sizeof(offset));
    BufferLayout layout = {
        {"offset", ShaderDataType::Float4},
        {"color", ShaderDataType::Float4}};
    VBO->SetLayout(layout);
    VAO->AddVertexBuffer(VBO);
}

void DemoApp::update()
{
    m_Shader->Bind();
    VAO->Bind();
    glDrawElements(GL_TRIANGLES, VAO->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}
