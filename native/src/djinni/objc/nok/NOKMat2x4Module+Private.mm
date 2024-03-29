// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#import "NOKMat2x4Module+Private.h"
#import "NOKMat2x4Module.h"
#import "RVReactDjinni.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "RVJavascriptArray+Private.h"
#import "RVJavascriptMap+Private.h"
#import "RVJavascriptPromise+Private.h"
#import "RVReactBridge+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NOKMat2x4Module ()

- (id)initWithCpp:(const std::shared_ptr<::nok::Mat2x4Module>&)cppRef;

@end

@implementation NOKMat2x4Module {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nok::Mat2x4Module>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nok::Mat2x4Module>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}
+ (NSString *)moduleName
{
    return @"Mat2x4Module";
}

+ (nullable NOKMat2x4Module *)create:(nullable id<RVReactBridge>)bridge {
    try {
        auto objcpp_result_ = ::nok::Mat2x4Module::create(::djinni_generated::ReactBridge::toCpp(bridge));
        return ::djinni_generated::Mat2x4Module::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(get, get:(double)row
                      col:(double)col
                 resolver:(nonnull RCTPromiseResolveBlock)resolver
                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->get(::djinni::F64::toCpp(row),
                                 ::djinni::F64::toCpp(col),
                                 ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(set:(double)row
                  col:(double)col
                    v:(double)v) {
    try {
        _cppRefHandle.get()->set(::djinni::F64::toCpp(row),
                                 ::djinni::F64::toCpp(col),
                                 ::djinni::F64::toCpp(v));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(orthogonalProjection, orthogonalProjection:(double)left
                                                      right:(double)right
                                                     bottom:(double)bottom
                                                        top:(double)top
                                                         zn:(double)zn
                                                         zf:(double)zf
                                                   resolver:(nonnull RCTPromiseResolveBlock)resolver
                                                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->orthogonalProjection(::djinni::F64::toCpp(left),
                                                  ::djinni::F64::toCpp(right),
                                                  ::djinni::F64::toCpp(bottom),
                                                  ::djinni::F64::toCpp(top),
                                                  ::djinni::F64::toCpp(zn),
                                                  ::djinni::F64::toCpp(zf),
                                                  ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(perspective, perspective:(double)left
                                    right:(double)right
                                      top:(double)top
                                   bottom:(double)bottom
                                     near:(double)near
                                      far:(double)far
                                 resolver:(nonnull RCTPromiseResolveBlock)resolver
                                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->perspective(::djinni::F64::toCpp(left),
                                         ::djinni::F64::toCpp(right),
                                         ::djinni::F64::toCpp(top),
                                         ::djinni::F64::toCpp(bottom),
                                         ::djinni::F64::toCpp(near),
                                         ::djinni::F64::toCpp(far),
                                         ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(perspectiveFOV, perspectiveFOV:(double)fov
                                         aspect:(double)aspect
                                           near:(double)near
                                            far:(double)far
                                       resolver:(nonnull RCTPromiseResolveBlock)resolver
                                       rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->perspectiveFOV(::djinni::F64::toCpp(fov),
                                            ::djinni::F64::toCpp(aspect),
                                            ::djinni::F64::toCpp(near),
                                            ::djinni::F64::toCpp(far),
                                            ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(lookAt, lookAt:(nullable NSDictionary *)eye
                             at:(nullable NSDictionary *)at
                             up:(nullable NSDictionary *)up
                       resolver:(nonnull RCTPromiseResolveBlock)resolver
                       rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->lookAt(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:eye]),
                                    ::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:at]),
                                    ::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:up]),
                                    ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(lookAlong, lookAlong:(nullable NSDictionary *)axis
                                  eye:(nullable NSDictionary *)eye
                                   up:(nullable NSDictionary *)up
                             resolver:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->lookAlong(::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:axis]),
                                       ::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:eye]),
                                       ::djinni_generated::JavascriptMap::toCpp([RVReactDjinni wrapMap:up]),
                                       ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(translation, translation:(double)x
                                        y:(double)y
                                 resolver:(nonnull RCTPromiseResolveBlock)resolver
                                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->translation(::djinni::F64::toCpp(x),
                                         ::djinni::F64::toCpp(y),
                                         ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(movement, movement:(double)x
                                  y:(double)y
                                  z:(double)z
                           resolver:(nonnull RCTPromiseResolveBlock)resolver
                           rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->movement(::djinni::F64::toCpp(x),
                                      ::djinni::F64::toCpp(y),
                                      ::djinni::F64::toCpp(z),
                                      ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(identity, identity:(nonnull RCTPromiseResolveBlock)resolver
                           rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->identity(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(scale, scale:(double)scale
                     resolver:(nonnull RCTPromiseResolveBlock)resolver
                     rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->scale(::djinni::F64::toCpp(scale),
                                   ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(rotationX, rotationX:(double)alpha
                             resolver:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->rotationX(::djinni::F64::toCpp(alpha),
                                       ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(rotationY, rotationY:(double)alpha
                             resolver:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->rotationY(::djinni::F64::toCpp(alpha),
                                       ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(rotationZ, rotationZ:(double)alpha
                             resolver:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->rotationZ(::djinni::F64::toCpp(alpha),
                                       ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(rotation, rotation:(double)yaw
                              pitch:(double)pitch
                               roll:(double)roll
                           resolver:(nonnull RCTPromiseResolveBlock)resolver
                           rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->rotation(::djinni::F64::toCpp(yaw),
                                      ::djinni::F64::toCpp(pitch),
                                      ::djinni::F64::toCpp(roll),
                                      ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(from, from:(nullable NSArray *)mat
                   resolver:(nonnull RCTPromiseResolveBlock)resolver
                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->from(::djinni_generated::JavascriptArray::toCpp([RVReactDjinni wrapArray:mat]),
                                  ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(add, add:(nullable NSArray *)mat
                 resolver:(nonnull RCTPromiseResolveBlock)resolver
                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->add(::djinni_generated::JavascriptArray::toCpp([RVReactDjinni wrapArray:mat]),
                                 ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(sub, sub:(nullable NSArray *)mat
                 resolver:(nonnull RCTPromiseResolveBlock)resolver
                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->sub(::djinni_generated::JavascriptArray::toCpp([RVReactDjinni wrapArray:mat]),
                                 ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(multiply, multiply:(double)i
                           resolver:(nonnull RCTPromiseResolveBlock)resolver
                           rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->multiply(::djinni::F64::toCpp(i),
                                      ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(clone, clone:(nonnull RCTPromiseResolveBlock)resolver
                     rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->clone(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(transpose, transpose:(nonnull RCTPromiseResolveBlock)resolver
                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->transpose(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(transpose3x3, transpose3x3:(nonnull RCTPromiseResolveBlock)resolver
                                   rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->transpose3x3(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(trace, trace:(nonnull RCTPromiseResolveBlock)resolver
                     rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->trace(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(determinant, determinant:(nonnull RCTPromiseResolveBlock)resolver
                                 rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->determinant(::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_REMAP_METHOD(linearInterpolate, linearInterpolate:(nullable NSArray *)a
                                                    b:(nullable NSArray *)b
                                                 prop:(double)prop
                                             resolver:(nonnull RCTPromiseResolveBlock)resolver
                                             rejecter:(nonnull RCTPromiseRejectBlock)rejecter) {
    try {
        _cppRefHandle.get()->linearInterpolate(::djinni_generated::JavascriptArray::toCpp([RVReactDjinni wrapArray:a]),
                                               ::djinni_generated::JavascriptArray::toCpp([RVReactDjinni wrapArray:b]),
                                               ::djinni::F64::toCpp(prop),
                                               ::djinni_generated::JavascriptPromise::toCpp([RVReactDjinni wrapPromiseWithResolver:resolver rejecter:rejecter]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (NSDictionary *)constantsToExport
{
    return @{
        @"width": @(NOKMat2x4ModuleWidth),
        @"height": @(NOKMat2x4ModuleHeight),
    };
}

namespace djinni_generated {

auto Mat2x4Module::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Mat2x4Module::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NOKMat2x4Module>(cpp);
}

}  // namespace djinni_generated

@end
