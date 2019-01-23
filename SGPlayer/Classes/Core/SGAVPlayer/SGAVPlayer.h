//
//  SGAVPlayer.h
//  SGPlayer
//
//  Created by Single on 16/6/28.
//  Copyright © 2016年 single. All rights reserved.
//

#import "SGPlayerImp.h"
#import <AVFoundation/AVFoundation.h>

@protocol SGAVPlayerOutput <NSObject>

- (AVPlayer *)playerOutputGetAVPlayer;
- (CVPixelBufferRef)playerOutputGetPixelBufferAtCurrentTime;
- (SGPLFImage *)playerOutputGetSnapshotAtCurrentTime;

@end

@interface SGAVPlayer : NSObject <SGAVPlayerOutput>

+ (instancetype)new NS_UNAVAILABLE;
+ (instancetype)init NS_UNAVAILABLE;

+ (instancetype)playerWithAbstractPlayer:(SGPlayer *)abstractPlayer;

@property (nonatomic, weak, readonly) SGPlayer * abstractPlayer;
@property (nonatomic, strong, readonly) AVPlayer * avPlayer;

@property (nonatomic, assign, readonly) SGPlayerState state;
@property (nonatomic, assign, readonly) CGSize presentationSize;
@property (nonatomic, assign, readonly) NSTimeInterval bitrate;
@property (nonatomic, assign, readonly) NSTimeInterval progress;
@property (nonatomic, assign, readonly) NSTimeInterval duration;
@property (nonatomic, assign, readonly) NSTimeInterval playableTime;
@property (nonatomic, assign, readonly) BOOL seeking;
@property (nonatomic, assign) float rate;

- (void)replaceVideo;
- (void)reloadVolume;

- (void)play;
- (void)pause;
- (void)stop;

@property (nonatomic, assign, readonly) BOOL seekEnable;
- (void)seekToTime:(NSTimeInterval)time;
- (void)seekToTime:(NSTimeInterval)time completeHandler:(void(^)(BOOL finished))completeHandler;
- (void)seekToTime:(NSTimeInterval)time toleranceBefore:(NSTimeInterval)toleranceBefore toleranceAfter:(NSTimeInterval)toleranceAfter;
- (void)seekToTime:(NSTimeInterval)time toleranceBefore:(NSTimeInterval)toleranceBefore toleranceAfter:(NSTimeInterval)toleranceAfter completeHandler:(void(^)(BOOL finished))completeHandler;


#pragma mark - track info

@property (nonatomic, assign, readonly) BOOL videoEnable;
@property (nonatomic, assign, readonly) BOOL audioEnable;

@property (nonatomic, strong, readonly) SGPlayerTrack * videoTrack;
@property (nonatomic, strong, readonly) SGPlayerTrack * audioTrack;

@property (nonatomic, strong, readonly) NSArray <SGPlayerTrack *> * videoTracks;
@property (nonatomic, strong, readonly) NSArray <SGPlayerTrack *> * audioTracks;

- (void)selectAudioTrackIndex:(int)audioTrackIndex;

@end
