// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import <Foundation/Foundation.h>
@class NOKColor;

extern double const NOKColorBlack;
extern float const NOKColorWhite;
extern float const NOKColorRed;
extern float const NOKColorBlue;
extern float const NOKColorGreen;
extern float const NOKColorMagenta;
extern float const NOKColorYellow;
extern float const NOKColorCyan;
extern float const NOKColorPurple;
extern float const NOKColorPink;
extern float const NOKColorOrange;

@interface NOKColor : NSObject

- (float)getR;

- (float)getG;

- (float)getB;

- (float)getA;

- (void)setR:(float)r;

- (void)setG:(float)g;

- (void)setB:(float)b;

- (void)setA:(float)a;

+ (nullable NOKColor *)create:(double)color;

@end
