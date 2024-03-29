// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "colored_shader_painter.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKColoredShaderPainter;

namespace djinni_generated {

class ColoredShaderPainter
{
public:
    using CppType = std::shared_ptr<::nok::ColoredShaderPainter>;
    using CppOptType = std::shared_ptr<::nok::ColoredShaderPainter>;
    using ObjcType = NOKColoredShaderPainter*;

    using Boxed = ColoredShaderPainter;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

