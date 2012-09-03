//
//  MessageTarget.m
//  Message
//
//  Created by trarck trarck on 11-11-28.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import "MessageTarget.h"
#import "CompleteMessageManager.h"

@implementation NSObject(MessageTarget)

-(void) registerMessage:(MessageType) type handle:(SEL) handle sender:(id) sender
{
	[[CompleteMessageManager defaultManager] registerReceiver:self handle:handle type:type sender:sender];
}

-(void) unregisterMessage:(MessageType) type handle:(SEL) handle sender:(id) sender
{
	[[CompleteMessageManager defaultManager] removeReceiver:self handle:handle type:type sender:sender];
}
-(void) sendMessage:(MessageType) type receiver:(id) receiver data:(NSDictionary *)data
{
	[[CompleteMessageManager defaultManager] dispatchMessageWithType:type sender:self receiver:receiver data:data];
}

@end
