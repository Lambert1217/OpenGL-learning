/**
 * @file VertexArray.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief VertexArray
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <memory>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace GLToolBox
{
    class VertexArray
    {
    public:
        VertexArray();
        virtual ~VertexArray();

        virtual void Bind() const;
        virtual void Unbind() const;

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>);
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>);

        virtual const std::vector<std::shared_ptr<VertexBuffer>> &GetVertexBuffers() const { return m_VertexBuffers; }
        virtual const std::shared_ptr<IndexBuffer> &GetIndexBuffer() const { return m_IndexBuffer; }

    private:
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
        unsigned int m_RendererID;
    };
}