//
//  OSETRewardVideoAd.h
//  YhsADSProject
//
//  Created by 熊俊 on 2020/4/27.
//  Copyright © 2020 熊俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol OSETRewardVideoAdDelegate <NSObject>
@optional

/// 激励视频加载成功
/// @param rewardVideoAd 激励视频实例
/// @param slotId 广告位ID
- (void)rewardVideoDidReceiveSuccess:(id)rewardVideoAd slotId:(NSString *)slotId;

/// 激励视频加载失败
- (void)rewardVideoLoadToFailed:(id)rewardVideoAd error:(NSError *)error;

/// 激励视频点击
- (void)rewardVideoDidClick:(id)rewardVideoAd;

/// 激励视频关闭
- (void)rewardVideoDidClose:(id)rewardVideoAd checkString:(NSString *)checkString;
//激励视频播放出错
- (void)rewardVideoPlayError:(id)rewardVideoAd error:(NSError *)error;
//激励视频播放结束
- (void)rewardVideoPlayEnd:(id)rewardVideoAd  checkString:(NSString *)checkString;
//激励视频开始播放
- (void)rewardVideoPlayStart:(id)rewardVideoAd checkString:(NSString *)checkString;
//激励视频奖励
- (void)rewardVideoOnReward:(id)rewardVideoAd checkString:(NSString *)checkString;

- (void)rewardVideoRequestOnReward:(id)rewardVideoAd checkString:(NSString *)checkString withRequsetData:(NSDictionary *)requsetData;

@end


@interface OSETRewardVideoAd : NSObject
@property (nonatomic,weak) id <OSETRewardVideoAdDelegate> delegate;
@property(nonatomic,readonly,copy)NSString * slotId;
@property(nonatomic,readonly,assign)NSInteger reference;

@property (nonatomic,copy)   NSString *userId;//userId 用户标识符show之前设置有效

/// 激励视频初始化 （默认不验证）
/// @param slotId 广告位ID
- (instancetype)initWithSlotId:(NSString *)slotId;
/// 激励视频初始化 （默认不验证）
/// @param slotId 广告位ID
- (instancetype)initWithSlotId:(NSString *)slotId withUserId:(NSString *)userId;
/// 加载
- (void)loadAdData;
//广告是否有效，以下情况会返回NO，建议在展示广告之前判断
- (BOOL)adIsValid;
/// 显示
/// @param rootViewController 当前控制器
- (void)showFromRootViewController:(UIViewController *)rootViewController;

//checkString 将在OSETRewardVideoAd对象 loadAdData 后失效
- (void)checkRerverWith:(NSString *)checkString success:(void(^)(id responseObject))successful failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
