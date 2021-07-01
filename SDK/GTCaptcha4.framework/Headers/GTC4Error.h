//
//  GTC4Error.h
//  GTCaptcha4
//
//  Created by NikoXu on 2020/9/30.
//  Copyright © 2020 geetest. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 不合法的参数。请检查输入的参数。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeInvalidParameter;
/// 操作失败。详细查看描述。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeOperationFail;
/// 资源缺失。请检查 GTCaptcha4.bundle 文件是否完整。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeMissedResource;

/// 用户取消了验证。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeUserDidCancel;

/// 加载文件失败。请检查是否导入了完整的 GTCaptcha4.bundle 文件或者配置的远程静态资源是否可访问。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeLoadFileFailure;
/// 加载超时。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeTimeout;
/// 执行 Javascript 脚本失败。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeEvaluatingJavascriptFail;
/// Javascript 返回错误。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeJavascriptError;
/// WebView 内存警告。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeWebViewMemoryWarning;

/// 未知错误。
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeUnknown;

/// 错误描述对象
@interface GTC4Error : NSObject

/// 错误码
@property (readonly, nonatomic, strong) NSString *code;
/// 错误信息，可用于用户界面展示。
@property (readonly, nonatomic, strong) NSString *msg;
/// 错误详细描述，用于详细排查问题。
@property (readonly, nonatomic, strong) NSDictionary *desc;

@end

NS_ASSUME_NONNULL_END
