//
//  FSMachine.h
//  GameFsm
//
//  Created by trarck trarck on 11-11-24.
//

#import "IFSMState.h"
#import "IFSMMachine.h"
#import "IEntity.h"

@interface FSMMachine : NSObject<IFSMMachine> {
	id<IFSMState> currentState_;
	id<IEntity> owner_;
}

-(id) initWithOwner:(id <IEntity>)owner;

@end
