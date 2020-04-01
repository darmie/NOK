// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#include "mat2x3_module.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKMat2x3Module;

namespace djinni_generated {

class Mat2x3Module
{
public:
    using CppType = std::shared_ptr<::nok::Mat2x3Module>;
    using CppOptType = std::shared_ptr<::nok::Mat2x3Module>;
    using ObjcType = NOKMat2x3Module*;

    using Boxed = Mat2x3Module;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

