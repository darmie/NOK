// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKRenderTargetFormat.h"
#import "NOKTextureUnit.h"
#import <Foundation/Foundation.h>
@class NOKRenderTarget;


@interface NOKRenderTarget : NSObject

+ (nullable NOKRenderTarget *)create:(int32_t)width
                              height:(int32_t)height
                     depthBufferBits:(int32_t)depthBufferBits
                        antialiasing:(BOOL)antialiasing
                              format:(NOKRenderTargetFormat)format
                   stencilBufferBits:(int32_t)stencilBufferBits
                           contextId:(int32_t)contextId;

+ (nullable NOKRenderTarget *)createCube:(int32_t)cubeMapSize
                         depthBufferBits:(int32_t)depthBufferBits
                            antialiasing:(BOOL)antialiasing
                                  format:(NOKRenderTargetFormat)format
                       stencilBufferBits:(int32_t)stencilBufferBits
                               contextId:(int32_t)contextId;

- (int32_t)getWidth;

- (int32_t)getHeight;

- (int32_t)getTexWidth;

- (int32_t)getTexHeight;

- (int32_t)getContextId;

- (void)setWidth:(int32_t)width;

- (void)setHeight:(int32_t)height;

- (void)setTexWidth:(int32_t)width;

- (void)setTexHeight:(int32_t)height;

- (void)setContextId:(int32_t)id;

- (BOOL)isCubeMap;

- (BOOL)isDepthAttachment;

- (void)useColorAsTexture:(nonnull NOKTextureUnit *)unit;

- (void)useDepthAsTexture:(nonnull NOKTextureUnit *)unit;

- (void)setDepthStencilFrom:(nullable NOKRenderTarget *)source;

- (void)getPixels:(nonnull NSData *)data;

- (void)generateMipmaps:(int32_t)levels;

@end
