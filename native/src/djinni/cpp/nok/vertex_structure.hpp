// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace nok {

class VertexElement;
enum class VertexAttribute;
enum class VertexData;

class VertexStructure {
public:
    virtual ~VertexStructure() {}

    static int32_t const MAXELEMENTSCOUNT;

    virtual std::vector<std::shared_ptr<VertexElement>> getElements() = 0;

    virtual int32_t get_size() = 0;

    virtual void set_size(int32_t s) = 0;

    virtual bool instanced() = 0;

    static std::shared_ptr<VertexStructure> create();

    virtual void add(const std::string & name, VertexData data) = 0;

    virtual void addAttribute(VertexAttribute attribute, VertexData data) = 0;
};

}  // namespace nok
