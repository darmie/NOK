// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "vertex_structure.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKVertexStructure;

namespace djinni_generated {

class VertexStructure
{
public:
    using CppType = std::shared_ptr<::nok::VertexStructure>;
    using CppOptType = std::shared_ptr<::nok::VertexStructure>;
    using ObjcType = NOKVertexStructure*;

    using Boxed = VertexStructure;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

