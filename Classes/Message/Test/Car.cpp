//
//  Car.m
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import "Car.h"


@implementation Car

-(void) dealloc
{
	NSLog(@"Car dealloc");
	[super dealloc];
}

-(void) stop
{
	NSLog(@"Car stop");
}

-(id)copyWithZone:(NSZone *)zone
{
	//Car *copy=[[[self class] allocWithZone:zone] init];
	return [self retain];
}

@end
