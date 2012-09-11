//
//  singletonFsm.m
//  GameFsm
//
//  Created by trarck trarck on 11-12-26.
//  Copyright 2011 yitengku.com. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "MessageTarget.h"
#import "IEntity.h"
#import "FSMState.h"
#import "FSMMachine.h"
#import "Config.h"
#import	"CompleteMessageManager.h"
enum  {
	MSG_Find_Enimy=1,
	MSG_Approach_Sucess,
	MSG_Enimy_Die
};

//Man
@interface Man : NSObject<IEntity>
{
	FSMMachine* fsm_;
	NSUInteger distance_;
}

@property(nonatomic,retain) id<IFSMMachine> fsm;
@property(nonatomic,assign) NSUInteger distance;

-(void) update;
-(void) setup;
-(void) handleMessage:(Message *) message;

@end

@implementation Man

@synthesize fsm=fsm_;
@synthesize distance=distance_;

-(void) dealloc
{
	GMS(@"dealloc" );
	self.fsm=nil;
	[super dealloc];
}

-(id) init
{
	if((self=[super init])){
		GMS(@"init");
	}
	return self;
}

-(void) setFsm:(FSMMachine *) fsm
{
	[fsm retain];
	[fsm_ release];
	fsm_=fsm;
	fsm_.owner=self;
}



-(void) update
{
	[fsm_ update];
}

-(void) setup
{
	[self registerMessage:MSG_Find_Enimy handle:@selector(handleMessage:) sender:nil];
	[self registerMessage:MSG_Approach_Sucess handle:@selector(handleMessage:) sender:nil];
	[self registerMessage:MSG_Enimy_Die handle:@selector(handleMessage:) sender:nil];
}

-(void) handleMessage:(Message *)message
{
	[fsm_ HandleMessage:message];
}
@end

//Man state

@interface ManStateBase: FSMState


@end

@interface ManStateIdle : ManStateBase 

@end

@interface ManStateAttack : ManStateBase

@end

@interface ManStateApproach: ManStateBase 

@end

@implementation ManStateBase

-(void) dealloc
{
	GMS(@"dealloc");
	[super dealloc];
}

-(void) enter:(id <IEntity>)entity
{
	GMS(@"enter for %s(0x%2x)",object_getClassName(entity),entity);
}

-(void) exit:(id <IEntity>)entity
{
	GMS(@"exit for %s(0x%2x)",object_getClassName(entity),entity);
}

-(void) update:(id <IEntity>)entity
{
	GMS(@"update for %s(0x%2x)",object_getClassName(entity),entity);
}

@end

@implementation ManStateIdle

//static id instanceIdle_;
//
//+(id) sharedState
//{
//	[super sharedState];
//	if (!instanceIdle_) {
//		instanceIdle_=[[self alloc] init];
//	}
//	return instanceIdle_;
//}

-(void) exit:(id <IEntity>)entity
{
	[super exit:entity];
	Man *man=(Man*)entity;
	man.distance=3;
}

-(void) onMessage:(Message *)message entity:(id<IEntity>) entity
{
	Man *man=(Man*)entity;
	[man.fsm changeState:[ManStateApproach sharedState]];
}

@end

@implementation ManStateApproach
//static id instanceApproach_;
//
//+(id) sharedState
//{
//	if (!instanceApproach_) {
//		instanceApproach_=[[self alloc] init];
//	}
//	return instanceApproach_;
//}

-(void) update:(id <IEntity>)entity
{
	[super update:entity];
	Man *man=(Man*)entity;
	man.distance--;
	GMS(@"distance:%d",man.distance);
	if (man.distance<=0) {
		[self sendMessage:MSG_Approach_Sucess receiver:man data:nil];
	}
}

-(void) onMessage:(Message *)message entity:(id<IEntity>) entity
{
	Man *man=(Man*)entity;
	[man.fsm changeState:[ManStateAttack sharedState]];
}

@end


@implementation ManStateAttack

//static id instanceAttack_;
//
//+(id) sharedState
//{
//	if (!instanceAttack_) {
//		instanceAttack_=[[self alloc] init];
//	}
//	return instanceAttack_;
//}
-(void) onMessage:(Message *)message entity:(id<IEntity>) entity
{
	Man *man=(Man*)entity;
	[man.fsm changeState:[ManStateIdle sharedState]];
}

@end



int main (int argc, const char * argv[]) {
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	
	Man	 *aMan=[[[Man alloc] init] autorelease];
	
	FSMMachine *manFsm=[[[FSMMachine alloc] init] autorelease];
	manFsm.currentState=[ManStateIdle sharedState];
	
	aMan.fsm=manFsm;
	[aMan setup];
	
	[aMan update];
	[aMan update];
	[aMan update];
	[[CompleteMessageManager defaultManager] dispatchMessageWithType:MSG_Find_Enimy 
															  sender:nil 
															receiver:aMan
																data:nil];
	[aMan update];
	[aMan update];
	[aMan update];
	
	[aMan update];
	[aMan update];
	[aMan update];
	[[CompleteMessageManager defaultManager] dispatchMessageWithType:MSG_Enimy_Die 
															  sender:nil 
															receiver:aMan
																data:nil];
	[aMan update];
	[aMan update];
	[aMan update];
	
	NSLog(@"****************autorelease******************");
	[pool drain];
    return 0;
}
