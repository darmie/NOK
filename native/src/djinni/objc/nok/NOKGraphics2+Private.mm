// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKGraphics2+Private.h"
#import "NOKGraphics2.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "NOKImageScaleQuality+Private.h"
#import "NOKKavur+Private.h"
#import "NOKMat3+Private.h"
#import "NOKMat4+Private.h"
#import "NOKPipelineState+Private.h"
#import "NOKRenderTarget+Private.h"
#import "NOKTexture+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NOKGraphics2 ()

- (id)initWithCpp:(const std::shared_ptr<::nok::Graphics2>&)cppRef;

@end

@implementation NOKGraphics2 {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nok::Graphics2>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nok::Graphics2>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable NOKGraphics2 *)create:(int32_t)width
                           height:(int32_t)height
                         rTargets:(BOOL)rTargets {
    try {
        auto objcpp_result_ = ::nok::Graphics2::create(::djinni::I32::toCpp(width),
                                                       ::djinni::I32::toCpp(height),
                                                       ::djinni::Bool::toCpp(rTargets));
        return ::djinni_generated::Graphics2::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)pushRotation:(float)angle
             centerx:(float)centerx
             centery:(float)centery {
    try {
        _cppRefHandle.get()->pushRotation(::djinni::F32::toCpp(angle),
                                          ::djinni::F32::toCpp(centerx),
                                          ::djinni::F32::toCpp(centery));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawImage:(nullable NOKTexture *)img
                x:(float)x
                y:(float)y {
    try {
        _cppRefHandle.get()->drawImage(::djinni_generated::Texture::toCpp(img),
                                       ::djinni::F32::toCpp(x),
                                       ::djinni::F32::toCpp(y));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawScaledSubImage:(nullable NOKTexture *)img
                        sx:(float)sx
                        sy:(float)sy
                        sw:(float)sw
                        sh:(float)sh
                        dx:(float)dx
                        dy:(float)dy
                        dw:(float)dw
                        dh:(float)dh {
    try {
        _cppRefHandle.get()->drawScaledSubImage(::djinni_generated::Texture::toCpp(img),
                                                ::djinni::F32::toCpp(sx),
                                                ::djinni::F32::toCpp(sy),
                                                ::djinni::F32::toCpp(sw),
                                                ::djinni::F32::toCpp(sh),
                                                ::djinni::F32::toCpp(dx),
                                                ::djinni::F32::toCpp(dy),
                                                ::djinni::F32::toCpp(dw),
                                                ::djinni::F32::toCpp(dh));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawImageRenderTarget:(nullable NOKRenderTarget *)img
                            x:(float)x
                            y:(float)y {
    try {
        _cppRefHandle.get()->drawImageRenderTarget(::djinni_generated::RenderTarget::toCpp(img),
                                                   ::djinni::F32::toCpp(x),
                                                   ::djinni::F32::toCpp(y));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawRect:(float)x
               y:(float)y
           width:(float)width
          height:(float)height
        strength:(float)strength {
    try {
        _cppRefHandle.get()->drawRect(::djinni::F32::toCpp(x),
                                      ::djinni::F32::toCpp(y),
                                      ::djinni::F32::toCpp(width),
                                      ::djinni::F32::toCpp(height),
                                      ::djinni::F32::toCpp(strength));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)fillRect:(float)x
               y:(float)y
           width:(float)width
          height:(float)height {
    try {
        _cppRefHandle.get()->fillRect(::djinni::F32::toCpp(x),
                                      ::djinni::F32::toCpp(y),
                                      ::djinni::F32::toCpp(width),
                                      ::djinni::F32::toCpp(height));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawString:(nonnull NSString *)text
                 x:(float)x
                 y:(float)y {
    try {
        _cppRefHandle.get()->drawString(::djinni::String::toCpp(text),
                                        ::djinni::F32::toCpp(x),
                                        ::djinni::F32::toCpp(y));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawLine:(float)x1
              y1:(float)y1
              x2:(float)x2
              y2:(float)y2
        strength:(float)strength {
    try {
        _cppRefHandle.get()->drawLine(::djinni::F32::toCpp(x1),
                                      ::djinni::F32::toCpp(y1),
                                      ::djinni::F32::toCpp(x2),
                                      ::djinni::F32::toCpp(y2),
                                      ::djinni::F32::toCpp(strength));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)fillTriangle:(float)x1
                  y1:(float)y1
                  x2:(float)x2
                  y2:(float)y2
                  x3:(float)x3
                  y3:(float)y3 {
    try {
        _cppRefHandle.get()->fillTriangle(::djinni::F32::toCpp(x1),
                                          ::djinni::F32::toCpp(y1),
                                          ::djinni::F32::toCpp(x2),
                                          ::djinni::F32::toCpp(y2),
                                          ::djinni::F32::toCpp(x3),
                                          ::djinni::F32::toCpp(y3));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setPipeline:(nullable NOKPipelineState *)pip {
    try {
        _cppRefHandle.get()->setPipeline(::djinni_generated::PipelineState::toCpp(pip));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)scissor:(int32_t)x
              y:(int32_t)y
          width:(int32_t)width
         height:(int32_t)height {
    try {
        _cppRefHandle.get()->scissor(::djinni::I32::toCpp(x),
                                     ::djinni::I32::toCpp(y),
                                     ::djinni::I32::toCpp(width),
                                     ::djinni::I32::toCpp(height));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)disableScissor {
    try {
        _cppRefHandle.get()->disableScissor();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable NOKMat3 *)getTransformation {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_transformation();
        return ::djinni_generated::Mat3::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable NOKMat4 *)getProjectionMatrix {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_projectionMatrix();
        return ::djinni_generated::Mat4::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSArray<NSNumber *> *)getFontGlyphs {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_fontGlyphs();
        return ::djinni::List<::djinni::I32>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)begin:(BOOL)renderTargets
        width:(int32_t)width
       height:(int32_t)height
        clear:(BOOL)clear
   clearColor:(int32_t)clearColor {
    try {
        _cppRefHandle.get()->begin(::djinni::Bool::toCpp(renderTargets),
                                   ::djinni::I32::toCpp(width),
                                   ::djinni::I32::toCpp(height),
                                   ::djinni::Bool::toCpp(clear),
                                   ::djinni::I32::toCpp(clearColor));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)clear:(int32_t)color {
    try {
        _cppRefHandle.get()->clear(::djinni::I32::toCpp(color));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)flush {
    try {
        _cppRefHandle.get()->flush();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)end {
    try {
        _cppRefHandle.get()->end();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawVideoInternal:(float)x
                        y:(float)y
                    width:(float)width
                   height:(float)height {
    try {
        _cppRefHandle.get()->drawVideoInternal(::djinni::F32::toCpp(x),
                                               ::djinni::F32::toCpp(y),
                                               ::djinni::F32::toCpp(width),
                                               ::djinni::F32::toCpp(height));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)drawVideo:(float)x
                y:(float)y
            width:(float)width
           height:(float)height {
    try {
        _cppRefHandle.get()->drawVideo(::djinni::F32::toCpp(x),
                                       ::djinni::F32::toCpp(y),
                                       ::djinni::F32::toCpp(width),
                                       ::djinni::F32::toCpp(height));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getColor {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getColor();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setColor:(float)color {
    try {
        _cppRefHandle.get()->setColor(::djinni::F32::toCpp(color));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (float)getOpacity {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getOpacity();
        return ::djinni::F32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setOpacity:(float)opacity {
    try {
        _cppRefHandle.get()->setOpacity(::djinni::F32::toCpp(opacity));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (NOKImageScaleQuality)getImageScaleQuality {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getImageScaleQuality();
        return ::djinni::Enum<::nok::ImageScaleQuality, NOKImageScaleQuality>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setImageScaleQuality:(NOKImageScaleQuality)value {
    try {
        _cppRefHandle.get()->setImageScaleQuality(::djinni::Enum<::nok::ImageScaleQuality, NOKImageScaleQuality>::toCpp(value));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (NOKImageScaleQuality)getMipmapScaleQuality {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getMipmapScaleQuality();
        return ::djinni::Enum<::nok::ImageScaleQuality, NOKImageScaleQuality>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setMipmapScaleQuality:(NOKImageScaleQuality)value {
    try {
        _cppRefHandle.get()->setMipmapScaleQuality(::djinni::Enum<::nok::ImageScaleQuality, NOKImageScaleQuality>::toCpp(value));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable NOKKavur *)getFont {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getFont();
        return ::djinni_generated::Kavur::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getFontSize {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getFontSize();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setFontSize:(int32_t)value {
    try {
        _cppRefHandle.get()->setFontSize(::djinni::I32::toCpp(value));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (double)getFontColor {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getFontColor();
        return ::djinni::F64::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setFontColor:(double)color {
    try {
        _cppRefHandle.get()->setFontColor(::djinni::F64::toCpp(color));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto Graphics2::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Graphics2::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NOKGraphics2>(cpp);
}

}  // namespace djinni_generated

@end
