//
//  MessageManager.m
//  Message
//
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//
#import <sys/time.h>
#import "CompleteMessageManager.h"
#import "MessageHandler.h"


@implementation CompleteMessageManager

- (void)dealloc
{
	[messages_ release];
	[globalObject_ release];
    [super dealloc];
}

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
		messages_=[[NSMutableDictionary alloc] initWithCapacity:10];
		globalObject_=[[NSObject alloc] init];
    }
    
    return self;
}

static CompleteMessageManager *default_;
+(id) defaultManager
{
	if (!default_) {
		default_=[[CompleteMessageManager alloc] init];
	}
	return default_;
}

//使receiver可以接收sender发送过来的叫type的消息，并用handle来处理
//关注的对象是receiver
-(void) registerReceiver:(id) receiver handle:(SEL)handle type:(MessageType) type sender:(id)sender
{
	[self registerReceiver:receiver handle:handle type:type sender:sender handleObject:receiver];
	//NSAssert(receiver!=nil,@"CompleteMessageManage:registerReceiver:receiver can't be null");
//	NSAssert(handle!=nil,@"CompleteMessageManage:registerReceiver:handle");
//	//type等于0，则所有消息都会发送
//	NSNumber * msgKey=[NSNumber numberWithInt:type];
//	//register for type
//	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
//	if (!msgMap) {
//		msgMap=[[NSMutableDictionary alloc] init];
//		[messages_ setObject:msgMap forKey:msgKey];
//		[msgMap release];
//	}
//	//register for sender
//	//sender 为空，则注册到全局对象上
//	sender=sender==nil?globalObject_:sender;
//	NSValue *senderKey=[NSValue valueWithNonretainedObject:sender];
//	NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
//	if (!senderMap) {
//		senderMap=[[NSMutableDictionary alloc] init];
//		[msgMap setObject:senderMap forKey:senderKey];
//		[senderMap release];
//	}
//	//register for receiver
//	NSValue *receiverKey=[NSValue valueWithNonretainedObject:receiver];
//	NSMutableArray *receiverList=[senderMap objectForKey:receiverKey];
//	if (!receiverList) {
//		receiverList=[[NSMutableArray alloc] init];
//		[senderMap setObject:receiverList forKey:receiverKey];
//		[receiverList release];
//	}
//	
//	//检查是否已经注册过
//	for(MessageHandler *handler in receiverList){
//		if (handler.handle==handle) {
//			NSAssert(0,@"Handle has register for %@",receiver);
//		}
//	}
//	//注册时不需要时间
//	//struct timeval now;
////	gettimeofday(&now,NULL);
//	
//	//register for handler
//	MessageHandler *handler=[[MessageHandler alloc] initWithTarget:receiver handle:handle];
//	[receiverList addObject:handler];
//	[handler release];
}

-(void) registerReceiver:(id)receiver handle:(SEL)handle type:(MessageType)type sender:(id)sender handleObject:(id) handleObject
{
	NSAssert(receiver!=nil,@"CompleteMessageManage:registerReceiver:receiver can't be null");
	NSAssert(handle!=nil,@"CompleteMessageManage:registerReceiver:handle");
	NSAssert(handleObject!=nil,@"CompleteMessageManage:registerReceiver:handleObject");
	
	//type等于0，则所有消息都会发送
	NSNumber * msgKey=[NSNumber numberWithInt:type];
	//register for type
	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
	if (!msgMap) {
		msgMap=[[NSMutableDictionary alloc] init];
		[messages_ setObject:msgMap forKey:msgKey];
		[msgMap release];
	}
	//register for sender
	//sender 为空，则注册到全局对象上
	sender=sender==nil?globalObject_:sender;
	NSValue *senderKey=[NSValue valueWithNonretainedObject:sender];
	NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
	if (!senderMap) {
		senderMap=[[NSMutableDictionary alloc] init];
		[msgMap setObject:senderMap forKey:senderKey];
		[senderMap release];
	}
	//register for receiver
	NSValue *receiverKey=[NSValue valueWithNonretainedObject:receiver];
	NSMutableArray *receiverList=[senderMap objectForKey:receiverKey];
	if (!receiverList) {
		receiverList=[[NSMutableArray alloc] init];
		[senderMap setObject:receiverList forKey:receiverKey];
		[receiverList release];
	}
	
	//检查是否已经注册过
	for(MessageHandler *handler in receiverList){
		if (handler.handle==handle) {
			NSAssert(0,@"Handle has register for %@",receiver);
		}
	}
	//注册时不需要时间
	//struct timeval now;
	//	gettimeofday(&now,NULL);
	
	//register for handler
	MessageHandler *handler=[[MessageHandler alloc] initWithTarget:handleObject handle:handle];
	[receiverList addObject:handler];
	[handler release];
}

-(void) removeReceiver:(id)receiver handle:(SEL)handle type:(MessageType)type sender:(id)sender
{
	NSAssert(receiver!=nil,@"CompleteMessageManage:removeReceiver:receiver can't be null!");
	NSAssert(handle!=nil,@"CompleteMessageManage:registerReceiver:handle");
	
	//message for type
	NSNumber * msgKey=[NSNumber numberWithInt:type];
	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
	if (msgMap) {
		//message for sender
		sender=sender==nil?globalObject_:sender;
		NSValue *senderKey=[NSValue valueWithNonretainedObject:sender];
		NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
		if (senderMap) {
			//message for receiver
			NSValue *receiverKey=[NSValue valueWithNonretainedObject:receiver];
			NSMutableArray *receiverList=[senderMap objectForKey:receiverKey];
			if (receiverList) {
				for(MessageHandler *handler in receiverList){
					if (handler.handle==handle) {
						[receiverList removeObject:handler];
					}
				}
			}
		}
	}
}

//
-(void) dispatchMessage:(Message*) message
{
	//NSAssert(message.type!=0,)
	//如果message的type不为0，则需要执行一个type为global的所有消息
	if (message.type!=GlobalMessageType) {
		//message for global
		NSNumber * msgKey=[NSNumber numberWithInt:GlobalMessageType];
		NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
		if (msgMap) {
			//parse for sender
			//如果sender不为空，则还要触发一次全局消息。
			if (message.sender) {
				//执行注册到sender的消息的处理方法
				NSValue *senderKey=[NSValue valueWithNonretainedObject:message.sender];
				NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
				//如果注册则执行
				if (senderMap)  [self execRegisterWithSenderMap:senderMap message:message];
				//执行注册到global的消息的处理方法
				NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
				NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
				//如果注册则执行
				if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message];
			}else {
				//执行注册到global的消息的处理方法
				NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
				NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
				//如果注册则执行
				if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message];
			}
		}
	}

	//message for type
	NSNumber * msgKey=[NSNumber numberWithInt:message.type];
	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
	if (msgMap) {
		//parse for sender
		//如果sender不为空，则还要触发一次全局消息。
		if (message.sender) {
			//执行注册到sender的消息的处理方法
			NSValue *senderKey=[NSValue valueWithNonretainedObject:message.sender];
			NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
			//如果注册则执行
			if (senderMap)  [self execRegisterWithSenderMap:senderMap message:message];
			//执行注册到global的消息的处理方法
			NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
			NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
			//如果注册则执行
			if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message];
		}else {
			//执行注册到global的消息的处理方法
			NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
			NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
			//如果注册则执行
			if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message];
		}
	}
}

-(void) dispatchMessageWithType:(MessageType) type sender:(id)sender receiver:(id)receiver data:(NSDictionary*) data
{
	Message *message=[[Message alloc] initWithType:type sender:sender receiver:receiver data:data];
	[self dispatchMessage:message];
	[message release];
}

-(void) execRegisterWithSenderMap:(NSDictionary *) senderMap message:(Message *)message
{
	NSAssert(senderMap!=nil,@"CompleteMessageManage:execRegisterWithSenderMap:senderMap can't be null!");
	if (message.receiver) {
		//message for receiver
		NSValue *receiverKey=[NSValue valueWithNonretainedObject:message.receiver];
		NSMutableArray *receiverList=[senderMap objectForKey:receiverKey];
		if(receiverList) [self execRegisterReceiverList:receiverList message:message];
	}else {
		//send to all receiver
		[self execAllRegisterWithSenderMap:senderMap message:message];
	}
}

-(void) execAllRegisterWithSenderMap:(NSDictionary *) senderMap message:(Message *)message 
{
	NSAssert(senderMap!=nil,@"CompleteMessageManage:execAllRegisterWithSenderMap:senderMap can't be null!");
	//send to all
	NSEnumerator *it=[senderMap objectEnumerator];
	NSArray *receiverList;
	while ((receiverList=[it nextObject])){
		[self execRegisterReceiverList:receiverList message:message];
	}
}

-(void) execRegisterReceiverList:(NSArray *) receiverList message:(Message *) message
{

	NSAssert(receiverList!=nil,@"CompleteMessageManage:execRegisterReceiverList:receiverList can't be null!");
	for(MessageHandler *handler in receiverList){
		//if (message.receiver==nil||handler.target==message.receiver) {
			[handler.target performSelector:handler.handle withObject:message];
		//}
	}
}

//适应message中没有receiver的情况
-(void) dispatchMessage:(Message*) message receiver:(id) receiver
{
	//NSAssert(message.type!=0,)
	if (message.type!=GlobalMessageType) {
		//message for global
		NSNumber * msgKey=[NSNumber numberWithInt:GlobalMessageType];
		NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
		if (msgMap) {
			//parse for sender
			//如果sender不为空，则还要触发一次全局消息。
			if (message.sender) {
				//执行注册到sender的消息的处理方法
				NSValue *senderKey=[NSValue valueWithNonretainedObject:message.sender];
				NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
				//如果注册则执行
				if (senderMap)  [self execRegisterWithSenderMap:senderMap message:message receiver:receiver];
				//执行注册到global的消息的处理方法
				NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
				NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
				//如果注册则执行
				if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message receiver:receiver];
			}else {
				//执行注册到global的消息的处理方法
				NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
				NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
				//如果注册则执行
				if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message receiver:receiver];
			}
		}
	}
	//message for type
	NSNumber * msgKey=[NSNumber numberWithInt:message.type];
	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
	if (msgMap) {
		//parse for sender
		//如果sender不为空，则还要触发一次全局消息。
		if (message.sender) {
			//执行注册到sender的消息的处理方法
			NSValue *senderKey=[NSValue valueWithNonretainedObject:message.sender];
			NSMutableDictionary *senderMap=[msgMap objectForKey:senderKey];
			//如果注册则执行
			if (senderMap)  [self execRegisterWithSenderMap:senderMap message:message receiver:receiver];
			//执行注册到global的消息的处理方法
			NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
			NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
			//如果注册则执行
			if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message receiver:receiver];
		}else {
			//执行注册到global的消息的处理方法
			NSValue *globalKey=[NSValue valueWithNonretainedObject:globalObject_];
			NSMutableDictionary *globalMap=[msgMap objectForKey:globalKey];
			//如果注册则执行
			if (globalMap)  [self execRegisterWithSenderMap:globalMap message:message receiver:receiver];
		}
	}
	
}

-(void) execRegisterWithSenderMap:(NSDictionary *) senderMap message:(Message *)message receiver:(id)receiver
{
	NSAssert(senderMap!=nil,@"CompleteMessageManage:execRegisterWithSenderMap:senderMap can't be null!");
	if (receiver) {
		//message for receiver
		NSValue *receiverKey=[NSValue valueWithNonretainedObject:receiver];
		NSMutableArray *receiverList=[senderMap objectForKey:receiverKey];
		if(receiverList) [self execRegisterReceiverList:receiverList message:message];
	}else {
		//send to all receiver
		[self execAllRegisterWithSenderMap:senderMap message:message];
	}
}

//-(void) execAllRegisterWithSenderMap:(NSDictionary *) senderMap message:(Message *)message receiver:(id)receiver
//{
//	NSAssert(senderMap!=nil,@"CompleteMessageManage:execAllRegisterWithSenderMap:senderMap can't be null!");
//	//send to all
//	NSEnumerator *it=[senderMap objectEnumerator];
//	NSArray *receiverList;
//	while ((receiverList=[it nextObject])){
//		[self execRegisterReceiverList:receiverList message:message];
//	}
//}

//-(void) execRegisterReceiverList:(NSArray *) receiverList message:(Message *) message receiver:(id)receiver
//{
//	
//	NSAssert(receiverList!=nil,@"CompleteMessageManage:execRegisterReceiverList:receiverList can't be null!");
//	for(MessageHandler *handler in receiverList){
//		if (receiver==nil||handler.target==receiver) {
//			[handler.target performSelector:handler.handle withObject:message];
//		}
//	}
//}

////type,sender,receiver,handle唯一
//-(void) registerReceiver2:(id) receiver handle:(SEL)handle type:(MessageType) type sender:(id)sender
//{
//	NSAssert(receiver!=nil,@"CompleteMessageManage:registerReceiver:receiver can't be null");
//	NSAssert(handle!=nil,@"CompleteMessageManage:registerReceiver:handle");
//	//type等于0，则所有消息都会发送
//	NSNumber * msgKey=[NSNumber numberWithInt:type];
//	//register for type
//	NSMutableDictionary *msgMap=[messages_ objectForKey:msgKey];
//	if (!msgMap) {
//		msgMap=[[NSMutableDictionary alloc] init];
//		[messages_ setObject:msgMap forKey:msgKey];
//		[msgMap release];
//	}
//	//register for sender
//	//sender 为空，则注册到全局对象上
//	sender=sender==nil?globalObject_:sender;
//	NSMutableDictionary *senderMap=[msgMap objectForKey:sender];
//	if (!senderMap) {
//		senderMap=[[NSMutableDictionary alloc] init];
//		[msgMap setObject:senderMap forKey:sender];
//		[senderMap release];
//	}
//	//handler for receiver
//	MessageHandler *handler=[senderMap objectForKey:receiver];
//	NSAssert(!handler,"CompleteMessageManage:registerReceiver:Handle has register for %@",receiver);
//	
//	//	//检查是否已经注册过
//	//	for(MessageHandler *handler in receiverList){
//	//		if (handler.handle==handle) {
//	//			NSAssert(0,"Handle has register for %@",receiver);
//	//		}
//	//	}
//	//注册时不需要时间
//	//struct timeval now;
//	//	gettimeofday(&now,NULL);
//	
//	//register for handler
//	MessageHandler *handler=[[MessageHandler alloc] initWithTarget:receiver handle:handle];
//	[receiverList addObject:handler];
//	[handler release];
//}
//-(void) execRegisterReceiverHandle:(id) receiver
//{
//	
//}
@end
