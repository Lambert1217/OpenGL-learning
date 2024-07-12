#include "Render/Buffers/BufferLayout.h"
#include "Debug/Log.h"

namespace GLToolBox
{
    unsigned int ShaderDataTypeSize(ShaderDataType type)
    {
        switch (type)
        {
        case ShaderDataType::Float:
            return 4;
        case ShaderDataType::Float2:
            return 4 * 2;
        case ShaderDataType::Float3:
            return 4 * 3;
        case ShaderDataType::Float4:
            return 4 * 4;
        case ShaderDataType::Mat3:
            return 4 * 3 * 3;
        case ShaderDataType::Mat4:
            return 4 * 4 * 4;
        case ShaderDataType::Int:
            return 4;
        case ShaderDataType::Int2:
            return 4 * 2;
        case ShaderDataType::Int3:
            return 4 * 3;
        case ShaderDataType::Int4:
            return 4 * 4;
        case ShaderDataType::Bool:
            return 1;
        }

        LOG_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    BufferLayout::BufferLayout(const std::initializer_list<BufferElement> &element)
        : m_Elements(element)
    {
        CalculateOffsetAndStride();
    }

    void BufferLayout::CalculateOffsetAndStride()
    {
        unsigned int offset = 0;
        m_Stride = 0;
        for (auto &element : m_Elements)
        {
            element.Offset = offset;
            offset += element.Size;
            m_Stride += element.Size;
        }
    }

    BufferElement::BufferElement(const std::string &name, ShaderDataType type, bool normalized)
        : Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
    {
    }

    unsigned int BufferElement::GetComponentCount() const
    {
        switch (Type)
        {
        case ShaderDataType::Float:
            return 1;
        case ShaderDataType::Float2:
            return 2;
        case ShaderDataType::Float3:
            return 3;
        case ShaderDataType::Float4:
            return 4;
        case ShaderDataType::Mat3:
            return 3 * 3;
        case ShaderDataType::Mat4:
            return 4 * 4;
        case ShaderDataType::Int:
            return 1;
        case ShaderDataType::Int2:
            return 2;
        case ShaderDataType::Int3:
            return 3;
        case ShaderDataType::Int4:
            return 4;
        case ShaderDataType::Bool:
            return 1;
        }

        LOG_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }
}