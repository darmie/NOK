// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKConstantLocation+Private.h"
#import "NOKConstantLocation.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NOKConstantLocation ()

- (id)initWithCpp:(const std::shared_ptr<::nok::ConstantLocation>&)cppRef;

@end

@implementation NOKConstantLocation {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nok::ConstantLocation>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nok::ConstantLocation>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

namespace djinni_generated {

auto ConstantLocation::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto ConstantLocation::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NOKConstantLocation>(cpp);
}

}  // namespace djinni_generated

@end
