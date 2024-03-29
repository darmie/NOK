// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "constant_location.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKConstantLocation;

namespace djinni_generated {

class ConstantLocation
{
public:
    using CppType = std::shared_ptr<::nok::ConstantLocation>;
    using CppOptType = std::shared_ptr<::nok::ConstantLocation>;
    using ObjcType = NOKConstantLocation*;

    using Boxed = ConstantLocation;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

