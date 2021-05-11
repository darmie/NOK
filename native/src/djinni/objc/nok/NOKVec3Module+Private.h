// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#include "vec3_module.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKVec3Module;

namespace djinni_generated {

class Vec3Module
{
public:
    using CppType = std::shared_ptr<::nok::Vec3Module>;
    using CppOptType = std::shared_ptr<::nok::Vec3Module>;
    using ObjcType = NOKVec3Module*;

    using Boxed = Vec3Module;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
