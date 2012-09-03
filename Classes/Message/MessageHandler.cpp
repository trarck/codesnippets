//
//  MessageHandler.m
//  Message
//
//  Created by trarck trarck on 11-12-27.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import "MessageHandler.h"


@implementation MessageHandler

@synthesize target=target_;
@synthesize handle=handle_;

-(id) initWithTarget:(id) target handle:(SEL) handle
{
	if ((self=[super init])) {
		target_=target;
		handle_=handle;
	}
	return self;
}
@end
