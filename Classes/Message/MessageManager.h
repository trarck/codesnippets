//
//  MessageManager.h
//  Message
//  对消息优先级的支持
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Message.h"

#ifndef GlobalMessageType
#define GlobalMessageType 0
#endif

@interface MessageManager : NSObject {
	NSMutableDictionary *messages_;
	NSObject *globalObject_;
}
+(id) defaultManager;
/**
 * observer 消息接收者
 * sender   消息发送者
 */
//receiver对sender发来的type消息可以有多个响应方法，实际中情况会很少

-(void) registerReceiver:(id)receiver handle:(SEL)handle type:(MessageType)type sender:(id)sender;
-(void) registerReceiver:(id)receiver handle:(SEL)handle type:(MessageType)type sender:(id)sender handleObject:(id) obj;
-(void) removeReceiver:(id)receiver handle:(SEL)handle type:(MessageType)type sender:(id)sender;
-(void) dispatchMessage:(Message *)message;
-(void) dispatchMessageWithType:(MessageType)type sender:(id)sender receiver:(id)receiver data:(NSDictionary *)data;
-(void) execRegisterReceiverList:(NSArray *)receiverList message:(Message *)message;
-(void) execRegisterWithSenderMap:(NSDictionary *)senderMap message:(Message *)message;
-(void) execAllRegisterWithSenderMap:(NSDictionary *)senderMap message:(Message *)message;

-(void) dispatchMessage:(Message *)message  receiver:(id) receiver;
-(void) execRegisterWithSenderMap:(NSDictionary *)senderMap message:(Message *)message  receiver:(id) receiver;
@end
