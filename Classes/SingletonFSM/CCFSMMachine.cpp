//
//  FSMachine.m
//  GameFsm
//
//  Created by trarck trarck on 11-11-24.
//

#import "FSMMachine.h"

@implementation FSMMachine

@synthesize owner=owner_;
@synthesize currentState=currentState_;

-(void) dealloc
{
	NSLog(@"FSMMachine dealloc");

	[super dealloc];
}

-(id) init
{
	if((self=[super init])){
		NSLog(@"FSMMachine init");
	}
	return self;
}


-(id) initWithOwner:(id<IEntity>) owner
{
	if((self=[self init])){
		owner_=owner;
	}
	return self;
}
	


-(void) changeState:(id <IFSMState>)state
{
	[currentState_ exit:owner_];
	currentState_=state;
	[currentState_ enter:owner_];
}

-(void) update
{
	[currentState_ update:owner_];
}

-(void) HandleMessage:(Message *) message
{
	[currentState_ onMessage:message entity:owner_];
}
@end
