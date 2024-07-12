/**
 * @file BufferLayout.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief 缓冲区布局
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <string>
#include <vector>

namespace GLToolBox
{
    /**
     * @brief 枚举着色器数据类型
     *
     */
    enum class ShaderDataType
    {
        None = 0,
        Float,
        Float2,
        Float3,
        Float4,
        Mat3,
        Mat4,
        Int,
        Int2,
        Int3,
        Int4,
        Bool
    };

    /**
     * @brief 计算着色器数据类型的大小
     *
     * @param type
     * @return unsigned int
     */
    static unsigned int ShaderDataTypeSize(ShaderDataType type);

    struct BufferElement
    {
        std::string Name;
        ShaderDataType Type;
        unsigned int Size;
        unsigned int Offset;
        bool Normalized;

        BufferElement() = default;

        BufferElement(const std::string &name, ShaderDataType type, bool normalized = false);

        unsigned int GetComponentCount() const;
    };

    /**
     * @brief 缓冲区布局
     *
     */
    class BufferLayout
    {
    public:
        BufferLayout() = default;
        BufferLayout(const std::initializer_list<BufferElement> &element);

        inline unsigned int GetStride() const { return m_Stride; }
        inline const std::vector<BufferElement> &GetElements() const { return m_Elements; }

        // 方便外部遍历使用
        std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
        std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

    private:
        std::vector<BufferElement> m_Elements;
        unsigned int m_Stride = 0;

        void CalculateOffsetAndStride();
    };
}