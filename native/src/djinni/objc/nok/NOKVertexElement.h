// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKVertexAttribute.h"
#import "NOKVertexData.h"
#import <Foundation/Foundation.h>
@class NOKVertexElement;


@interface NOKVertexElement : NSObject

- (nonnull NSString *)getName;

- (void)setName:(nonnull NSString *)n;

- (NOKVertexAttribute)getAttribute;

- (void)setAttribute:(NOKVertexAttribute)a;

- (NOKVertexData)getData;

- (void)setData:(NOKVertexData)d;

+ (nullable NOKVertexElement *)create;

+ (nullable NOKVertexElement *)createWithName:(nonnull NSString *)name
                                         data:(NOKVertexData)data;

+ (nullable NOKVertexElement *)createWithAttribute:(NOKVertexAttribute)attribute
                                              data:(NOKVertexData)data;

@end
