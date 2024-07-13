#pragma once

#include "GLToolBox.h"

class DemoApp : public GLToolBox::Application
{
public:
    DemoApp(const char *windowName = "DemoApp", unsigned int width = 1600, unsigned int height = 1000);
    virtual void init(int version_major = 4, int version_minor = 5,
                      OpenGLProfile opengl_profile = OpenGLProfile::CORE) override;
    virtual void preUpdate() override;
    virtual void update() override;

private:
    std::shared_ptr<GLToolBox::VertexArray> VAO;
    std::shared_ptr<GLToolBox::Shader> m_Shader;
};
