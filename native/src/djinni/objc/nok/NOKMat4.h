// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#import <Foundation/Foundation.h>
@class NOKMat4;
@class NOKVec3;

extern float const NOKMat4Width;
extern float const NOKMat4Height;

@interface NOKMat4 : NSObject

- (float)get:(float)row
         col:(float)col;

- (void)set:(float)row
        col:(float)col
          v:(float)v;

+ (nullable NOKMat4 *)orthogonalProjection:(float)left
                                     right:(float)right
                                    bottom:(float)bottom
                                       top:(float)top
                                        zn:(float)zn
                                        zf:(float)zf;

+ (nullable NOKMat4 *)perspective:(float)left
                            right:(float)right
                              top:(float)top
                           bottom:(float)bottom
                             near:(float)near
                              far:(float)far;

+ (nullable NOKMat4 *)perspectiveFOV:(float)fov
                              aspect:(float)aspect
                                near:(float)near
                                 far:(float)far;

+ (nullable NOKMat4 *)lookAt:(nullable NOKVec3 *)eye
                          at:(nullable NOKVec3 *)at
                          up:(nullable NOKVec3 *)up;

+ (nullable NOKMat4 *)lookAlong:(nullable NOKVec3 *)axis
                            eye:(nullable NOKVec3 *)eye
                             up:(nullable NOKVec3 *)up;

+ (nullable NOKMat4 *)translation:(float)x
                                y:(float)y;

+ (nullable NOKMat4 *)movement:(float)x
                             y:(float)y
                             z:(float)z;

+ (nullable NOKMat4 *)identity;

+ (nullable NOKMat4 *)scale:(float)scale;

+ (nullable NOKMat4 *)rotationX:(float)alpha;

+ (nullable NOKMat4 *)rotationY:(float)alpha;

+ (nullable NOKMat4 *)rotationZ:(float)alpha;

+ (nullable NOKMat4 *)rotation:(float)yaw
                         pitch:(float)pitch
                          roll:(float)roll;

+ (nullable NOKMat4 *)create;

+ (nullable NOKMat4 *)from:(nullable NOKMat4 *)mat;

- (nullable NOKMat4 *)add:(nullable NOKMat4 *)mat;

- (nullable NOKMat4 *)sub:(nullable NOKMat4 *)mat;

- (nullable NOKMat4 *)multiply:(float)i;

- (nullable NOKMat4 *)clone;

- (nullable NOKMat4 *)transpose;

- (nullable NOKMat4 *)transpose3x3;

- (float)trace;

- (float)determinant;

+ (nullable NOKMat4 *)linearInterpolate:(nullable NOKMat4 *)a
                                      b:(nullable NOKMat4 *)b
                                   prop:(float)prop;

@end