//
//  Npc.m
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import "Man.h"


@implementation Man

-(void) dealloc
{
	NSLog(@"Man dealloc");
	[super dealloc];
}

-(void) wait:(Message *)message
{
	NSLog(@"wait for car stop");
	NSLog(@"%@",message);
}

-(void) waitb:(Message *)message
{
	NSLog(@"waitb for car stop");
	NSLog(@"%@",message);
}

@end
