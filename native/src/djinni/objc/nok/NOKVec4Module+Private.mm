// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#import "NOKVec4Module+Private.h"
#import "NOKVec4Module.h"
#import "RVReactDjinni.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "RVJavascriptMap+Private.h"
#import "RVJavascriptPromise+Private.h"
#import "RVReactBridge+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NOKVec4Module ()

- (id)initWithCpp:(const std::shared_ptr<::nok::Vec4Module>&)cppRef;

@end

@implementation NOKVec4Module {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nok::Vec4Module>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nok::Vec4Module>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}
+ (NSString *)moduleName
{
    return @"Vec4Module";
}

+ (nullable NOKVec4Module *)create:(nullable id<RVReactBridge>)bridge {
    try {
        auto objcpp_result_ = ::nok::Vec4Module::create(::djinni_generated::ReactBridge::toCpp(bridge));
        return ::djinni_generated::Vec4Module::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(getX, getX:(nonnull RCTPromiseResolveBlock)resolver
                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->get_x(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(getY, getY:(nonnull RCTPromiseResolveBlock)resolver
                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->get_y(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(getZ, getZ:(nonnull RCTPromiseResolveBlock)resolver
                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->get_z(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(getW, getW:(nonnull RCTPromiseResolveBlock)resolver
                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->get_w(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(add:(nullable NSDictionary *)v) {
    try {
        _cppRefHandle.get()->add(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:v]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(addScaledVector:(nullable NSDictionary *)v) {
    try {
        _cppRefHandle.get()->addScaledVector(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:v]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(sub:(nullable NSDictionary *)v) {
    try {
        _cppRefHandle.get()->sub(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:v]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(multiply:(double)i) {
    try {
        _cppRefHandle.get()->multiply(::djinni::F64::toCpp(i));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(divide:(double)i) {
    try {
        _cppRefHandle.get()->divide(::djinni::F64::toCpp(i));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(squareLength, squareLength:(nonnull RCTPromiseResolveBlock)resolver
                                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->squareLength(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(getLength, getLength:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->getLength(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(setLength:(double)length) {
    try {
        _cppRefHandle.get()->setLength(::djinni::F64::toCpp(length));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(normalize, normalize:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->normalize(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(isZero, isZero:(nonnull RCTPromiseResolveBlock)resolver
                       rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->isZero(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(getXyz, getXyz:(nonnull RCTPromiseResolveBlock)resolver
                       rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->get_xyz(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(set:(double)x
                    y:(double)y
                    z:(double)z
                    w:(double)w) {
    try {
        _cppRefHandle.get()->set(::djinni::F64::toCpp(x),
                                 ::djinni::F64::toCpp(y),
                                 ::djinni::F64::toCpp(z),
                                 ::djinni::F64::toCpp(w));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(dot, dot:(nullable NSDictionary *)v
                 resolver:(nonnull RCTPromiseResolveBlock)resolver
                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->dot(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:v]),
                                 ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(cross, cross:(nullable NSDictionary *)v
                     resolver:(nonnull RCTPromiseResolveBlock)resolver
                     rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->cross(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:v]),
                                   ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(distance, distance:(nullable NSDictionary *)v
                           resolver:(nonnull RCTPromiseResolveBlock)resolver
                           rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->distance(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:v]),
                                      ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(invert) {
    try {
        _cppRefHandle.get()->invert();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto Vec4Module::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Vec4Module::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NOKVec4Module>(cpp);
}

}  // namespace djinni_generated

@end
