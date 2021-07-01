//
//  GTCaptcha4Session.h
//  GTCaptcha4.h
//
//  Created by NikoXu on 2020/9/29.
//  Copyright © 2020 geetest. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class GTCaptcha4SessionConfiguration, GTC4Error;

@protocol GTCaptcha4SessionTaskDelegate;

/// 验证会话
@interface GTCaptcha4Session : NSObject

/// 验证会话任务的代理
@property (nullable, nonatomic, weak) id<GTCaptcha4SessionTaskDelegate> delegate;

/// 当前验证会话的验证ID
@property (nonnull, readonly, nonatomic, strong) NSString *captchaID;
/// 当前验证会话的流水号
@property (nullable, readonly, nonatomic, strong) NSString *challenge;
/// 当前验证会话的配置
@property (nonnull, readonly, nonatomic, strong) GTCaptcha4SessionConfiguration *configuration;

/// 创建一个新的验证会话实例
/// @param captchaID 验证ID
+ (instancetype)sessionWithCaptchaID:(NSString *)captchaID;

/// 创建一个新的验证会话实例
/// @param captchaID 验证ID
/// @param configuration 会话配置
+ (instancetype)sessionWithCaptchaID:(NSString *)captchaID
                       configuration:(nullable GTCaptcha4SessionConfiguration *)configuration;

/// 初始化一个新的验证会话实例
/// @param captchaID 验证ID
- (instancetype)initWithCaptchaID:(NSString *)captchaID;

/// 初始化一个新的验证会话实例
/// @param captchaID 验证ID
/// @param configuration 会话配置
- (instancetype)initWithCaptchaID:(NSString *)captchaID
                    configuration:(nullable GTCaptcha4SessionConfiguration *)configuration;

/// 开始验证
- (void)verify;

/// 取消验证
- (void)cancel;

/// SDK 版本号
+ (NSString *)sdkVersion;

@end

/// 验证会话任务代理协议
@protocol GTCaptcha4SessionTaskDelegate <NSObject>

@required

/// 回调验证会话的结果参数
/// @discussion 拿到验证结果的参数后，需要提交到业务服务端，
///             完成参数的校验
/// @param captchaSession 验证会话
/// @param status 状态码。@"0"/@"1": 未完成/完成。当 status 为 @"1"
///                     时，则为成功，需要对结果进行二次校验。
/// @param result 结果校验参数。示例如:
///               ```
///               {
///                 challenge = "19080ae5-fe79-4431-9c78-4ee8e0dec798";
///                 captcha_id = "c62d0f270240799b3113b0a5787ead55";
///               }
///               ```
- (void)gtCaptchaSession:(GTCaptcha4Session *)captchaSession
              didReceive:(NSString *)status
                  result:(nullable NSDictionary *)result;

/// 回调验证会话中发生的错误
/// @param captchaSession 验证会话
/// @param error 错误描述对象
- (void)gtCaptchaSession:(GTCaptcha4Session *)captchaSession
         didReceiveError:(GTC4Error *)error;

@optional

/// 通知验证界面将要展现
/// @param captchaSession 验证会话
- (void)gtCaptchaSessionWillShow:(GTCaptcha4Session *)captchaSession;

@end

NS_ASSUME_NONNULL_END
