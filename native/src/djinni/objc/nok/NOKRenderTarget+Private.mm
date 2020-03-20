// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKRenderTarget+Private.h"
#import "NOKRenderTarget.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "NOKRenderTargetFormat+Private.h"
#import "NOKTextureUnit+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NOKRenderTarget ()

- (id)initWithCpp:(const std::shared_ptr<::nok::RenderTarget>&)cppRef;

@end

@implementation NOKRenderTarget {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nok::RenderTarget>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nok::RenderTarget>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable NOKRenderTarget *)create:(int32_t)width
                              height:(int32_t)height
                     depthBufferBits:(int32_t)depthBufferBits
                        antialiasing:(BOOL)antialiasing
                              format:(NOKRenderTargetFormat)format
                   stencilBufferBits:(int32_t)stencilBufferBits
                           contextId:(int32_t)contextId {
    try {
        auto objcpp_result_ = ::nok::RenderTarget::create(::djinni::I32::toCpp(width),
                                                          ::djinni::I32::toCpp(height),
                                                          ::djinni::I32::toCpp(depthBufferBits),
                                                          ::djinni::Bool::toCpp(antialiasing),
                                                          ::djinni::Enum<::nok::RenderTargetFormat, NOKRenderTargetFormat>::toCpp(format),
                                                          ::djinni::I32::toCpp(stencilBufferBits),
                                                          ::djinni::I32::toCpp(contextId));
        return ::djinni_generated::RenderTarget::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable NOKRenderTarget *)createCube:(int32_t)cubeMapSize
                         depthBufferBits:(int32_t)depthBufferBits
                            antialiasing:(BOOL)antialiasing
                                  format:(NOKRenderTargetFormat)format
                       stencilBufferBits:(int32_t)stencilBufferBits
                               contextId:(int32_t)contextId {
    try {
        auto objcpp_result_ = ::nok::RenderTarget::createCube(::djinni::I32::toCpp(cubeMapSize),
                                                              ::djinni::I32::toCpp(depthBufferBits),
                                                              ::djinni::Bool::toCpp(antialiasing),
                                                              ::djinni::Enum<::nok::RenderTargetFormat, NOKRenderTargetFormat>::toCpp(format),
                                                              ::djinni::I32::toCpp(stencilBufferBits),
                                                              ::djinni::I32::toCpp(contextId));
        return ::djinni_generated::RenderTarget::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getWidth {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_width();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getHeight {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_height();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getTexWidth {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_texWidth();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getTexHeight {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_texHeight();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)getContextId {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_contextId();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setWidth:(int32_t)width {
    try {
        _cppRefHandle.get()->set_width(::djinni::I32::toCpp(width));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setHeight:(int32_t)height {
    try {
        _cppRefHandle.get()->set_height(::djinni::I32::toCpp(height));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setTexWidth:(int32_t)width {
    try {
        _cppRefHandle.get()->set_texWidth(::djinni::I32::toCpp(width));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setTexHeight:(int32_t)height {
    try {
        _cppRefHandle.get()->set_texHeight(::djinni::I32::toCpp(height));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setContextId:(int32_t)id {
    try {
        _cppRefHandle.get()->set_contextId(::djinni::I32::toCpp(id));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isCubeMap {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->isCubeMap();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isDepthAttachment {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->isDepthAttachment();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)useColorAsTexture:(nonnull NOKTextureUnit *)unit {
    try {
        _cppRefHandle.get()->useColorAsTexture(::djinni_generated::TextureUnit::toCpp(unit));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)useDepthAsTexture:(nonnull NOKTextureUnit *)unit {
    try {
        _cppRefHandle.get()->useDepthAsTexture(::djinni_generated::TextureUnit::toCpp(unit));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setDepthStencilFrom:(nullable NOKRenderTarget *)source {
    try {
        _cppRefHandle.get()->setDepthStencilFrom(::djinni_generated::RenderTarget::toCpp(source));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)getPixels:(nonnull NSData *)data {
    try {
        _cppRefHandle.get()->getPixels(::djinni::Binary::toCpp(data));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)generateMipmaps:(int32_t)levels {
    try {
        _cppRefHandle.get()->generateMipmaps(::djinni::I32::toCpp(levels));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto RenderTarget::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto RenderTarget::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NOKRenderTarget>(cpp);
}

}  // namespace djinni_generated

@end
