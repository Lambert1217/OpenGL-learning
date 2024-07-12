/**
 * @file VertexBuffer.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief VertexBuffer
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "BufferLayout.h"

namespace GLToolBox
{
    class VertexBuffer
    {
    public:
        VertexBuffer(float *vertices, unsigned int size);
        virtual ~VertexBuffer();

        virtual void Bind() const;
        virtual void Unbind() const;

        virtual void SetLayout(const BufferLayout &layout) { m_Layout = layout; }
        virtual const BufferLayout &GetLayout() const { return m_Layout; }

    private:
        unsigned int m_RendererID;
        BufferLayout m_Layout;
    };
};