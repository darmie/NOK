// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKTextureUnit+Private.h"
#import "NOKTextureUnit.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NOKTextureUnit ()

- (id)initWithCpp:(const std::shared_ptr<::nok::TextureUnit>&)cppRef;

@end

@implementation NOKTextureUnit {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nok::TextureUnit>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nok::TextureUnit>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

namespace djinni_generated {

auto TextureUnit::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto TextureUnit::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NOKTextureUnit>(cpp);
}

}  // namespace djinni_generated

@end