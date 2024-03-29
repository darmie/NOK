// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#import "RVJavascriptMap.h"
#import "RVJavascriptPromise.h"
#import "RVReactBridge.h"
#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
@class NOKVec3Module;


@interface NOKVec3Module : NSObject<RCTBridgeModule>

+ (nullable NOKVec3Module *)create:(nullable id<RVReactBridge>)bridge;

- (void)getX:(nonnull RCTPromiseResolveBlock)resolver
    rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)getY:(nonnull RCTPromiseResolveBlock)resolver
    rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)getZ:(nonnull RCTPromiseResolveBlock)resolver
    rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)add:(nullable NSDictionary *)v;

- (void)addScaledVector:(nullable NSDictionary *)v;

- (void)sub:(nullable NSDictionary *)v;

- (void)multiply:(double)i;

- (void)divide:(double)i;

- (void)squareLength:(nonnull RCTPromiseResolveBlock)resolver
            rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)getLength:(nonnull RCTPromiseResolveBlock)resolver
         rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)setLength:(double)length;

- (void)normalize:(nonnull RCTPromiseResolveBlock)resolver
         rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)isZero:(nonnull RCTPromiseResolveBlock)resolver
      rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)getXyz:(nonnull RCTPromiseResolveBlock)resolver
      rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)set:(double)x
          y:(double)y
          z:(double)z;

- (void)dot:(nullable NSDictionary *)v
   resolver:(nonnull RCTPromiseResolveBlock)resolver
   rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)cross:(nullable NSDictionary *)v
     resolver:(nonnull RCTPromiseResolveBlock)resolver
     rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)distance:(nullable NSDictionary *)v
        resolver:(nonnull RCTPromiseResolveBlock)resolver
        rejecter:(nonnull RCTPromiseRejectBlock)rejecter;

- (void)invert;

@end
