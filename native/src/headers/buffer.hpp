#pragma once

#include <cstdint>
#include "nok/usage.hpp"
#include "nok/vertex_structure.hpp"
#include "nok/vertex_buffer.hpp"
#include "nok/vertex_element.hpp"
#include "nok/vertex_data.hpp"
#include "nok/vertex_attribute.hpp"
#include "nok/index_buffer.hpp"
#include "Kore/Graphics4/Graphics.h"

namespace nok
{

class VertexElementImpl : public nok::VertexElement, public Kore::Graphics4::VertexElement
{
public:
    VertexElementImpl() : nok::VertexElement(), Kore::Graphics4::VertexElement(){};
    VertexElementImpl(const std::string & name, VertexData data) : nok::VertexElement(), Kore::Graphics4::VertexElement(name.c_str(), getInternalVertexData(data)){};
    VertexElementImpl(VertexAttribute attribute, VertexData data) : nok::VertexElement(), Kore::Graphics4::VertexElement(getInternalVertexAttribute(attribute), getInternalVertexData(data)){};
    ~VertexElementImpl(){};

    static std::shared_ptr<nok::VertexElement> create() {
        return std::make_shared<VertexElementImpl>();
    }

    static std::shared_ptr<nok::VertexElement> createWithName(const std::string & name, VertexData data){
        return std::make_shared<VertexElementImpl>(name, data);
    }

    static std::shared_ptr<nok::VertexElement> createWithAttribute(VertexAttribute attribute, VertexData data){
        return std::make_shared<VertexElementImpl>(attribute, data);
    }

    std::string get_name();

    void set_name(const std::string & n);

    VertexAttribute get_attribute();

    void set_attribute(VertexAttribute a);

    VertexData get_data();

    void set_data(VertexData d);
};

class VertexStructureImpl : public nok::VertexStructure, public Kore::Graphics4::VertexStructure
{

public:
    VertexStructureImpl() : nok::VertexStructure(), Kore::Graphics4::VertexStructure(){};

    static std::shared_ptr<nok::VertexStructure> create()
    {
        return std::make_shared<VertexStructureImpl>();
    }

    std::vector<std::shared_ptr<VertexElement>> getElements();

    int32_t get_size();

    void set_size(int32_t s);

    bool instanced();

    void add(const std::string &name, VertexData data);

    void addAttribute(VertexAttribute attribute, VertexData data);
};

class VertexBufferImpl : public nok::VertexBuffer, public Kore::Graphics4::VertexBuffer
{
public:
    VertexBufferImpl(int count, const nok::VertexStructureImpl &structure, nok::Usage usage = nok::Usage::STATICUSAGE, int instanceDataStepRate = 0)
        : nok::VertexBuffer(), Kore::Graphics4::VertexBuffer(count, structure, getInternalUsage(usage), instanceDataStepRate){};
    ~VertexBufferImpl(){};

    static std::shared_ptr<nok::VertexBuffer> create(int32_t count, const std::shared_ptr<VertexStructure> &structure, Usage usage, int32_t instanceDataStepRate)
    {
        return std::make_shared<nok::VertexBuffer>(count, structure, usage, instanceDataStepRate);
    };

    std::vector<float> lock();

    void unlock();

    int32_t count();

    int32_t stride();
};

class IndexBufferImpl : public nok::IndexBuffer, public Kore::Graphics4::IndexBuffer
{
public:
    IndexBufferImpl(int count) : nok::IndexBuffer(), Kore::Graphics4::IndexBuffer(count) {}
    ~IndexBufferImpl(){};

    static std::shared_ptr<nok::IndexBuffer> create(int32_t count)
    {
        return std::make_shared<nok::IndexBuffer>(count);
    };

    std::vector<int32_t> lock();

    void unlock();

    int32_t count();
};

static Kore::Graphics4::Usage getInternalUsage(nok::Usage usage)
{
    switch (usage)
    {
    case nok::Usage::STATICUSAGE:
        return Kore::Graphics4::Usage::StaticUsage;
    case nok::Usage::DYNAMICUSAGE:
        return Kore::Graphics4::Usage::DynamicUsage;
    case nok::Usage::READABLEUSAGE:
        return Kore::Graphics4::Usage::ReadableUsage;
    }
}

static Kore::Graphics4::VertexData getInternalVertexData(nok::VertexData data)
{
    switch (data)
    {
    case nok::VertexData::SHORT2NORMVERTEXDATA:
        return Kore::Graphics4::VertexData::Short2NormVertexData;
    case nok::VertexData::SHORT4NORMVERTEXDATA:
        return Kore::Graphics4::VertexData::Short4NormVertexData;
    case nok::VertexData::COLORVERTEXDATA:
        return Kore::Graphics4::VertexData::ColorVertexData;
    case nok::VertexData::FLOAT1VERTEXDATA:
        return Kore::Graphics4::VertexData::Float1VertexData;
    case nok::VertexData::FLOAT2VERTEXDATA:
        return Kore::Graphics4::VertexData::Float2VertexData;
    case nok::VertexData::FLOAT3VERTEXDATA:
        return Kore::Graphics4::VertexData::Float3VertexData;
    case nok::VertexData::FLOAT4VERTEXDATA:
        return Kore::Graphics4::VertexData::Float4VertexData;
    case nok::VertexData::FLOAT4X4VERTEXDATA:
        return Kore::Graphics4::VertexData::Float4x4VertexData;
    case nok::VertexData::NOVERTEXDATA:
        return Kore::Graphics4::VertexData::NoVertexData;
    }
}

static nok::VertexData getVertexData(Kore::Graphics4::VertexData data){
    switch (data)
    {
    case Kore::Graphics4::VertexData::ColorVertexData: return nok::VertexData::COLORVERTEXDATA;
    case Kore::Graphics4::VertexData::Float1VertexData: return nok::VertexData::FLOAT1VERTEXDATA;
    case Kore::Graphics4::VertexData::Float2VertexData: return nok::VertexData::FLOAT2VERTEXDATA;
    case Kore::Graphics4::VertexData::Float3VertexData: return nok::VertexData::FLOAT3VERTEXDATA;
    case Kore::Graphics4::VertexData::Float4VertexData: return nok::VertexData::FLOAT4VERTEXDATA;
    case Kore::Graphics4::VertexData::Float4x4VertexData: return nok::VertexData::FLOAT4X4VERTEXDATA;
    case Kore::Graphics4::VertexData::NoVertexData: return nok::VertexData::NOVERTEXDATA;
    case Kore::Graphics4::VertexData::Short2NormVertexData: return nok::VertexData::SHORT2NORMVERTEXDATA;
    case Kore::Graphics4::VertexData::Short4NormVertexData: return nok::VertexData::SHORT4NORMVERTEXDATA;
    }
}

static Kore::Graphics4::VertexAttribute getInternalVertexAttribute(nok::VertexAttribute attr){
    switch (attr)
    {
    case nok::VertexAttribute::NOVERTEXATTRIBUTE: return Kore::Graphics4::VertexAttribute::NoVertexAttribute;
    case nok::VertexAttribute::VERTEXCOLOR0: return Kore::Graphics4::VertexAttribute::VertexColor0;
    case nok::VertexAttribute::VERTEXCOLOR1: return Kore::Graphics4::VertexAttribute::VertexColor1;
    case nok::VertexAttribute::VERTEXCOORD: return Kore::Graphics4::VertexAttribute::VertexCoord;
    case nok::VertexAttribute::VERTEXNORMAL: return Kore::Graphics4::VertexAttribute::VertexNormal;
    case nok::VertexAttribute::VERTEXTEXCOORD0: return Kore::Graphics4::VertexAttribute::VertexTexCoord0;
    case nok::VertexAttribute::VERTEXTEXCOORD1: return Kore::Graphics4::VertexAttribute::VertexTexCoord1;
    case nok::VertexAttribute::VERTEXTEXCOORD2: return Kore::Graphics4::VertexAttribute::VertexTexCoord2;
    case nok::VertexAttribute::VERTEXTEXCOORD3: return Kore::Graphics4::VertexAttribute::VertexTexCoord3;
    case nok::VertexAttribute::VERTEXTEXCOORD4: return Kore::Graphics4::VertexAttribute::VertexTexCoord4;
    case nok::VertexAttribute::VERTEXTEXCOORD5: return Kore::Graphics4::VertexAttribute::VertexTexCoord5;
    case nok::VertexAttribute::VERTEXTEXCOORD6: return Kore::Graphics4::VertexAttribute::VertexTexCoord6;
    case nok::VertexAttribute::VERTEXTEXCOORD7: return Kore::Graphics4::VertexAttribute::VertexTexCoord7;
    }
}

static nok::VertexAttribute getVertexAttribute(Kore::Graphics4::VertexAttribute attr){
    switch (attr)
    {
    case Kore::Graphics4::VertexAttribute::NoVertexAttribute: return nok::VertexAttribute::NOVERTEXATTRIBUTE;
    case Kore::Graphics4::VertexAttribute::VertexColor0: return nok::VertexAttribute::VERTEXCOLOR0;
    case Kore::Graphics4::VertexAttribute::VertexColor1: return nok::VertexAttribute::VERTEXCOLOR1;
    case Kore::Graphics4::VertexAttribute::VertexCoord: return nok::VertexAttribute::VERTEXCOORD;
    case Kore::Graphics4::VertexAttribute::VertexNormal: return nok::VertexAttribute::VERTEXNORMAL;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord0: return nok::VertexAttribute::VERTEXTEXCOORD0;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord1: return nok::VertexAttribute::VERTEXTEXCOORD1;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord2: return nok::VertexAttribute::VERTEXTEXCOORD2;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord3: return nok::VertexAttribute::VERTEXTEXCOORD3;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord4: return nok::VertexAttribute::VERTEXTEXCOORD4;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord5: return nok::VertexAttribute::VERTEXTEXCOORD5;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord6: return nok::VertexAttribute::VERTEXTEXCOORD6;
    case Kore::Graphics4::VertexAttribute::VertexTexCoord7: return nok::VertexAttribute::VERTEXTEXCOORD7;
    }
}


} // namespace nok
