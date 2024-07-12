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

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f};
    std::shared_ptr<VertexBuffer> VBO = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
    BufferLayout layout = {
        {"aPos", ShaderDataType::Float3},
        {"aTexCrood", ShaderDataType::Float2}};
    VBO->SetLayout(layout);
    VAO->AddVertexBuffer(VBO);

    unsigned int indices[] = {0, 1, 2, 1, 2, 3};
    std::shared_ptr<IndexBuffer> EBO = std::make_shared<IndexBuffer>(indices, sizeof(indices) / sizeof(unsigned int));
    VAO->SetIndexBuffer(EBO);

    m_Shader = std::make_shared<Shader>("assets/shaders/Demo1.glsl");
}

void DemoApp::preUpdate()
{
    float r = (float)sin(glfwGetTime()) * 0.5f + 0.5f;
    float g = (float)cos(glfwGetTime()) * 0.5f + 0.5f;
    float b = (r + g) / 2;
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_Shader->Bind();
    m_Shader->SetFloat4("u_Color", {g, b, r, 1.0f});
}

void DemoApp::update()
{
    VAO->Bind();
    glDrawElements(GL_TRIANGLES, VAO->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}
