//
//  NotificationTarget.h
//  主要使用Notification进行消息传递
//
//  Created by trarck trarck on 11-11-18.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSObject(NotificationTarget)

-(void) registerObserver:(NSString *) name selector:(SEL) aSelector  sender:(id) sender;
-(void) registerObserver:(NSString *) name selector:(SEL) aSelector;
-(void) unregisterObserver:(NSString *) name  sender:(id) sender;
-(void) unregisterObserver:(NSString *) name;
-(void) sendMessage:(NSString *) name data:(NSDictionary *) data;
-(void) sendMessage:(NSString *) name;
@end

