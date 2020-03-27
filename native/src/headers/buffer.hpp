#pragma once

#include <cstdint>
#include "nok/usage.hpp"
#include "nok/vertex_structure.hpp"
#include "nok/vertex_buffer.hpp"
#include "nok/index_buffer.hpp"
#include "Kore/Graphics4/Graphics.h"


namespace nok
{
    class VertexStructureImpl : public nok::VertexStructure, public Kore::Graphics4::VertexStructure {};
    class VertexBufferImpl : public nok::VertexBuffer , public Kore::Graphics4::VertexBuffer {
        public:
            VertexBufferImpl(int count, const nok::VertexStructureImpl &structure, nok::Usage usage = nok::Usage::STATICUSAGE, int instanceDataStepRate = 0)
            : nok::VertexBuffer(), Kore::Graphics4::VertexBuffer(count, structure, getInternalUsage(usage), instanceDataStepRate){};
            ~VertexBufferImpl(){};


            static std::shared_ptr<nok::VertexBuffer> create(int32_t count, const std::shared_ptr<VertexStructure> & structure, Usage usage, int32_t instanceDataStepRate) {
                return std::make_shared<nok::VertexBuffer>(count, structure, usage, instanceDataStepRate);
            };
    };

    class IndexBufferImpl : public nok::IndexBuffer , public Kore::Graphics4::IndexBuffer {
        public:
            IndexBufferImpl(int count) : nok::IndexBuffer(), Kore::Graphics4::IndexBuffer(count) {}
            ~IndexBufferImpl(){};

            static std::shared_ptr<nok::IndexBuffer> create(int32_t count) {
                return std::make_shared<nok::IndexBuffer>(count);
            };
    };

    static Kore::Graphics4::Usage getInternalUsage(nok::Usage usage){
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
} // namespace nok
