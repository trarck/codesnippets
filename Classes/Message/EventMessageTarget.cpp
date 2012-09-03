//
//  MessageTarget.m
//  Message
//
//  Created by trarck trarck on 11-11-28.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import "EventMessageTarget.h"


@implementation NSObject(EventMessageTarget)

-(void) addListener:(NSString *) name selector:(SEL) aSelector  scope:(id) scope
{
	[[NSNotificationCenter defaultCenter] addObserver:scope 
											 selector:aSelector 
												 name:name 
											   object:self];
}

-(void) removeListener:(NSString *) name selector:(SEL) aSelector  scope:(id) scope
{
	[[NSNotificationCenter defaultCenter] removeObserver:scope 
													name:name
												  object:self];
}

-(void) trigger:(NSString *) name data:(NSDictionary *) data
{
	[[NSNotificationCenter defaultCenter] postNotificationName:name
														object:self
													  userInfo:data];
}

-(void) trigger:(NSString *) name
{
	[[NSNotificationCenter defaultCenter] postNotificationName:name
														object:self
													  userInfo:nil];
}

-(void) listenMessage:(NSString *)name selector:(SEL) aSelector sender:(id) sender
{
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:aSelector 
												 name:name 
											   object:sender];
}

-(void) listenGlobal:(NSString *)name selector:(SEL) aSelector
{
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:aSelector 
												 name:name 
											   object:nil];
}

-(void) triggerGlobal:(NSString *) name data:(NSDictionary *) data
{
	[[NSNotificationCenter defaultCenter] postNotificationName:name
														object:nil
													  userInfo:data];
}

-(void) triggerGlobal:(NSString *) name
{
	[[NSNotificationCenter defaultCenter] postNotificationName:name
														object:nil
													  userInfo:nil];
}

@end
