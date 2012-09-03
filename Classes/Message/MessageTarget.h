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
#import "Message.h"

@interface  NSObject(MessageTarget)
-(void) registerMessage:(MessageType) type handle:(SEL) handle sender:(id) sender;
-(void) unregisterMessage:(MessageType) type handle:(SEL) handle sender:(id) sender;
-(void) sendMessage:(MessageType) type receiver:(id) receiver data:(NSDictionary *)data;
@end
