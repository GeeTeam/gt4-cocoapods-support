//
//  GTCaptcha4SessionConfiguration.h
//  GTCaptcha4
//
//  Created by NikoXu on 2020/9/30.
//  Copyright © 2020 geetest. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 验证界面样式
typedef NS_ENUM(NSInteger, GTC4UserInterfaceStyle) {
    /** 系统样式 */
    GTC4UserInterfaceStyleSystem = 0,
    /** 普通样式 */
    GTC4UserInterfaceStyleLight,
    /** 暗黑样式 */
    GTC4UserInterfaceStyleDark,
    /** 默认样式 */
    GTC4UserInterfaceStyleDefault = GTC4UserInterfaceStyleLight
};

/// 验证展示样式
typedef NS_ENUM(NSInteger, GTC4DisplayStyle) {
    /** 居中展示 */
    GTC4DisplayStyleCenter = 0,
    /** 底部展示 */
    GTC4DisplayStyleBottom,
    /** 默认展示 */
    GTC4DisplayStyleDefault = GTC4DisplayStyleBottom,
};

/// 验证会话配置
@interface GTCaptcha4SessionConfiguration : NSObject <NSCoding>

/// 远程访问静态资源的完整路径, 默认为空。
@property (nullable, nonatomic, strong) NSString *resourcePath;
/// 远程访问静态资源时的协议，默认 @“https”。
@property (nullable, nonatomic, strong) NSString *protocol;
/// 静态服务地址，默认为空。
@property (nullable, nonatomic, strong) NSArray<NSString *> *staticServers;
/// 接口服务地址，默认为空。
@property (nullable, nonatomic, strong) NSArray<NSString *> *apiServers;

/// 界面的交互样式，默认普通。
@property (nonatomic, assign) GTC4UserInterfaceStyle userInterfaceStyle;
/// 界面的展示样式，默认居中
@property (nonatomic, assign) GTC4DisplayStyle displayStyle;
/// 背景颜色，默认透明
@property (nonatomic, strong) UIColor *backgroundColor;

/// 调试模式开关，默认关闭。
@property (nonatomic, assign) BOOL debugEnable;
/// 点击背景的交互，默认开启。
@property (nonatomic, assign) BOOL backgroundUserInteractionEnable;
/// 请求超时时长，默认 5 秒。
@property (nonatomic, assign) NSTimeInterval timeout;
/// 语言，默认跟随系统。指定语言请参考语言短码。
@property (nonatomic, strong) NSString *language;
/// 额外的参数, 默认为空。参数将被组装后提交到极验。
@property (nullable, nonatomic, strong) NSMutableDictionary *additionalParameter;

/// 获得一个默认配置
+ (GTCaptcha4SessionConfiguration *)defaultConfiguration;

@end

NS_ASSUME_NONNULL_END
