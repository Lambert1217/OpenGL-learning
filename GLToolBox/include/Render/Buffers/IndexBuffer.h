/**
 * @file IndexBuffer.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief IndexBuffer
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "BufferLayout.h"

namespace GLToolBox
{
    class IndexBuffer
    {
    public:
        IndexBuffer(unsigned int *indices, unsigned int count);
        virtual ~IndexBuffer();

        virtual unsigned int GetCount() const { return m_Count; }

        virtual void Bind() const;
        virtual void Unbind() const;

    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
    };
};