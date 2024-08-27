//
//  OSETInterstitialLandscapeAd.h
//  YhsADSProject
//
//  Created by Shens on 1/8/2023.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OSETInterstitialLandscapeAdDelegate <NSObject>
@optional

/// 插屏加载成功
/// @param interstitialLandscapeAd 插屏实例
/// @param slotId 广告位ID
- (void)interstitialLandscapeDidReceiveSuccess:(id)interstitialLandscapeAd slotId:(NSString *)slotId;

/// 插屏加载失败
- (void)interstitialLandscapeLoadToFailed:(id)interstitialLandscapeAd error:(NSError *)error;

/// 插屏点击
- (void)interstitialLandscapeDidClick:(id)interstitialLandscapeAd;

/// 插屏关闭
- (void)interstitialLandscapeDidClose:(id)interstitialLandscapeAd;

@end

@interface OSETInterstitialLandscapeAd : NSObject

@property (nonatomic,weak) id <OSETInterstitialLandscapeAdDelegate> delegate;

/// 插屏初始化
/// @param slotId 广告位ID
- (instancetype)initWithSlotId:(NSString *)slotId;

/// 加载
- (void)loadAdData;

/// 显示
/// @param rootViewController 当前控制器
- (void)showFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
