//
//  NotificationTarget.m
//
//  Created by trarck trarck on 11-11-18.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import "NotificationTarget.h"


@implementation NSObject(NotificationTarget)

/**
 * 注册接收sender发来的消息
 * sender为空，则接收所有object发来的消息
 */
-(void) registerObserver:(NSString *) name selector:(SEL) aSelector  sender:(id) sender
{
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:aSelector 
												 name:name 
											   object:sender];
}

/**
 * 注册接收收所有object发来的消息
 */
-(void) registerObserver:(NSString *) name selector:(SEL) aSelector
{
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:aSelector 
												 name:name 
											   object:nil];
}

/**
 * 反注册，不再接收sender发来的消息
 * sender为空，则反注册name的所有注册信息
 */
-(void) unregisterObserver:(NSString *) name  sender:(id) sender
{
	[[NSNotificationCenter defaultCenter] removeObserver:self 
													name:name
												  object:sender];
}
/**
 * 反注册，反注册name的所有注册信息
 */
-(void) unregisterObserver:(NSString *) name
{
	[[NSNotificationCenter defaultCenter] removeObserver:self 
													name:name
												  object:nil];
}
/**
 * 发送消息
 * data为消息数据
 */
-(void) sendMessage:(NSString *) name data:(NSDictionary *) data
{
	[[NSNotificationCenter defaultCenter] postNotificationName:name
														object:self
													  userInfo:data];
}
/**
 * 发送无数据消息
 */
-(void) sendMessage:(NSString *) name
{
	[[NSNotificationCenter defaultCenter] postNotificationName:name
														object:self
													  userInfo:nil];
}
@end