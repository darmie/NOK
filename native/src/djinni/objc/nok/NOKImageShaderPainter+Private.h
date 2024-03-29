// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "image_shader_painter.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NOKImageShaderPainter;

namespace djinni_generated {

class ImageShaderPainter
{
public:
    using CppType = std::shared_ptr<::nok::ImageShaderPainter>;
    using CppOptType = std::shared_ptr<::nok::ImageShaderPainter>;
    using ObjcType = NOKImageShaderPainter*;

    using Boxed = ImageShaderPainter;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

