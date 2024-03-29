// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

#import <Foundation/Foundation.h>
@class NOKAudioChannel;


@interface NOKAudioChannel : NSObject

- (nonnull NSArray<NSNumber *> *)getData;

- (void)setData:(nonnull NSArray<NSNumber *> *)d;

+ (nullable NOKAudioChannel *)create:(BOOL)looping;

- (void)nextSamples:(nonnull NSArray<NSNumber *> *)requestedSamples
    requestedLength:(int32_t)requestedLength
         sampleRate:(int32_t)sampleRate;

- (void)play;

- (void)pause;

- (void)stop;

- (float)getLength;

- (float)getPosition;

- (void)setPosition:(float)pos;

- (float)getVolume;

- (void)setVolume:(float)vol;

- (BOOL)getFinished;

- (void)max:(int32_t)a
          b:(int32_t)b;

- (void)min:(int32_t)a
          b:(int32_t)b;

@end
