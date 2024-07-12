/**
 * @file Shader.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief Shader
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <string>
#include <unordered_map>
#include "glm/glm.hpp"

// TODO: 删除
typedef unsigned int GLenum;

namespace GLToolBox
{
    class Shader
    {
    public:
        Shader(const std::string &filepath);
        Shader(const std::string &name, const std::string &vertexSource, const std::string &fragmentSource);
        virtual ~Shader();

        virtual const std::string &GetName() const { return m_Name; }

        void SetInt(const std::string &name, const int value);
        void SetFloat(const std::string &name, const float value);
        void SetFloat3(const std::string &name, const glm::vec3 &value);
        void SetFloat4(const std::string &name, const glm::vec4 &value);
        void SetMat4(const std::string &name, const glm::mat4 &matrix);

        void Bind() const;
        void Unbind() const;

        void UploadUniformInt(const std::string &name, const int value);

        void UploadUniformFloat(const std::string &name, const float value);
        void UploadUniformFloat2(const std::string &name, const glm::vec2 &value);
        void UploadUniformFloat3(const std::string &name, const glm::vec3 &value);
        void UploadUniformFloat4(const std::string &name, const glm::vec4 &value);

        void UploadUniformMat3(const std::string &name, const glm::mat3 &matrix);
        void UploadUniformMat4(const std::string &name, const glm::mat4 &matrix);

    private:
        void Compile(std::unordered_map<GLenum, std::string> shaderSource);
        std::string ReadFile(const std::string &filepath);
        std::unordered_map<GLenum, std::string> PreProcess(const std::string &SourceCode);

    private:
        uint32_t m_RendererID;
        std::string m_Name;
    };
}