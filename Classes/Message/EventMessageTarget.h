//
//  MessageTarget.h
//  Message
//  使用事件式消息逻辑上容易绕。特别是系统消息（通常是发送者为空）。
//  事件的监听通常都在别的类的方法中，而消息的监听主要在自己的方法中。
//
//  Created by trarck trarck on 11-11-28.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface  NSObject(EventMessageTarget)
-(void) addListener:(NSString *) name selector:(SEL) aSelector  scope:(id) scope;
-(void) removeListener:(NSString *) name selector:(SEL) aSelector  scope:(id) scope;
-(void) trigger:(NSString *) name data:(NSDictionary *) data;
-(void) trigger:(NSString *) name;

-(void) listenMessage:(NSString *)name selector:(SEL) aSelector sender:(id) sender;

-(void) listenGlobal:(NSString *)name selector:(SEL) aSelector;
-(void) triggerGlobal:(NSString *)name data:(NSDictionary *)data;
-(void) triggerGlobal:(NSString *)name;

@end
