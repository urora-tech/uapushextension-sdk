/*
 * Copyright (c) 2017 Shenzhen MT. All rights reserved.
 */

#import <Foundation/Foundation.h>

#define MTE_EXTENSION_VERSION_NUMBER 15.0.0

@class UNNotificationRequest;

typedef NS_ENUM(NSUInteger, MTExtensionServiceNode) {
  MTExtensionServiceNodeRegionOverseas = 0, // 海外区域
  MTExtensionServiceNodeRegionChina = 1,    // 中国区域
};

@interface MTNotificationExtensionService : NSObject

/*!
 * @abstract 设置数据中心
 *
 * @param siteName 数据中心的名称.
 *
 * @discussion 不设置的话使用默认的数据中心。此接口必须在mtpushSetAppkey:函数之前调用.
 */
+ (void)setSiteName:(NSString *)siteName __attribute__((deprecated("MTPush 4.3.5 版本已过期")));

/**
 设置appkey（需要与main target中的appkey相同）
 */
+ (void)mtpushSetAppkey:(NSString *)appkey;

/*!
 * @abstract 配置服务节点
 * @param serviceNode 服务节点类型,默认为海外区域节点
 * @discussion 此接口必须要在mtpushReceiveNotificationRequest方法调用前进行设置
 */
+ (void)configServiceNode:(MTExtensionServiceNode)serviceNode;


/**
 如有使用语音播报功能，请调用该接口。
 设置appGroupId（需要与主工程中的通过 [MTPUSHService setAppGroupId:] 方法设置的 appGroupId 相同）
 */
+ (void)mtpushSetAppGroupId:(NSString *)appGroupId;

/**
 处理语音通知
 @param request apns请求
 @param completion 回调，soundName为处理成功的语音文件名。请将request.content.sound的值设置为soundName。具体调用示例请查看API文档。
 */
+ (void)handleVoice:(UNNotificationRequest *)request with:(void (^)(NSString *soundName))completion;

/**
 apns送达
 @param request apns请求
 @param completion 回调
 */
+ (void)mtpushReceiveNotificationRequest:(UNNotificationRequest *)request with:(void (^)(void))completion;

/**
 关闭日志
 默认为开启
 建议发布时关闭以减少不必要的IO
 */
+ (void)setLogOff;

/*!
 * @abstract 允许SDK是否使用UDP，默认是允许
 * @param enableUdp 允许使用UDP传YES, 不允许使用UDP传NO
 * @discussion 此接口必须要在 mtpushReceiveNotificationRequest 方法调用前进行设置
 */
+ (void)setEnableUdp:(BOOL)enableUdp;


@end
