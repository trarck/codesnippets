//
//  Message.m
//  Message
//
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import "Message.h"


@implementation Message

@synthesize type,timeStamp;
@synthesize sender,receiver,data;

-(id)initWithType:(int) type_ sender:(id) sender_ receiver:(id) receiver_ data:(NSDictionary *) data_ 
{
	self = [super init];
    if (self) {
        type=type_;
		sender=sender_;
		receiver=receiver_;
		data=data_;
		timeStamp=0;
    }
    
    return self;
}

- (id)initWithType:(int) type_ sender:(id) sender_ data:(NSDictionary *) data_
{
    return [self initWithType:type_ sender:sender_ receiver:nil data:data_];
}

- (void)dealloc
{
    [super dealloc];
}

-(NSString *) description
{
	return [NSString stringWithFormat:@"type:%d,sender:%@,receiver:%@,data:%@",type,sender,receiver,data];
}

@end
