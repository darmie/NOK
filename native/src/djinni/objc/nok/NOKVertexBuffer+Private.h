// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "vertex_buffer.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKVertexBuffer;

namespace djinni_generated {

class VertexBuffer
{
public:
    using CppType = std::shared_ptr<::nok::VertexBuffer>;
    using CppOptType = std::shared_ptr<::nok::VertexBuffer>;
    using ObjcType = NOKVertexBuffer*;

    using Boxed = VertexBuffer;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
