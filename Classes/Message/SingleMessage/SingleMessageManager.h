//
//  MessageManager.h
//
//	注册时，一个接收者的同一个消息只有一个处理函数
//
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Message.h"

@interface SingleMessageManager : NSObject {
    NSMutableDictionary *messages_;
	NSObject *globalObject_;
}

+(id) defaultManager;
/**
 * observer 消息接收者
 * sender   消息发送者
 */
//receiver对sender发来的type消息可以有多个响应方法，实际中情况会很少

-(void) registerReceiver:(id)receiver type:(MessageType)type sender:(id)sender handle:(SEL)handle;
-(void) registerReceiver:(id)receiver type:(MessageType)type sender:(id)sender handle:(SEL)handle handleObject:(id) handleObject;
-(void) removeReceiver:(id)receiver type:(MessageType)type sender:(id)sender handle:(SEL)handle;
-(void) dispatchMessage:(Message *)message;
-(void) dispatchMessageWithType:(MessageType)type sender:(id)sender receiver:(id)receiver data:(NSMutableDictionary *)data;
-(void) execRegisterWithSenderMap:(NSDictionary *)senderMap message:(Message *)message;
-(void) execAllRegisterWithSenderMap:(NSDictionary *)senderMap message:(Message *)message;

-(void) dispatchMessage:(Message *)message  receiver:(id) receiver;
-(void) execRegisterWithSenderMap:(NSDictionary *)senderMap message:(Message *)message  receiver:(id) receiver;

@end
