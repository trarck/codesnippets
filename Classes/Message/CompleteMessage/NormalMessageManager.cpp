//
//  MessageManager.m
//  Message
//
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import "NormalMessageManager.h"
#import <sys/time.h>


@implementation NormalMessageManager

static NormalMessageManager *default_;
+(id) defaultManager
{
	if (!default_) {
		default_=[[NormalMessageManager alloc] init];
	}
	return default_;
}

-(void) dispatchMessage:(Message*) message
{
	//NSAssert(message.type!=0,)
	//message for type
	NSNumber * msgKey=[NSNumber numberWithInt:message.type];
	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
	if (msgMap) {
		//parse for sender
		//如果sender不为空，则不要触发一次全局消息，只触发sender的消息。
		if (message.sender) {
			//执行注册到sender的消息的处理方法
			NSValue *senderKey=[NSValue valueWithNonretainedObject:message.sender];
			NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
			//如果注册则执行
			if (senderMap)  [self execRegisterWithSenderMap:senderMap message:message];
		}else {
			//执行注册到global的消息的处理方法
			NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
			NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
			//如果注册则执行
			if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message];
		}
	}
}
@end
