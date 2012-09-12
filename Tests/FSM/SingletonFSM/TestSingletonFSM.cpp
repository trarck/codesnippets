//
//  singletonFsm.m
//  GameFsm
//
//  Created by trarck trarck on 11-12-26.
//

#include "cocos2d.h"
#include "CCCompleteMessageManager.h"
#include "Man.h"
#include "ManState.h"
#include "CCFSMMachine.h"
#include "TestSingletonFSM.h"
#include "Type.h"


USING_NS_CC;



void TestSingletonFSM::test () 
{
	
	Man* aMan=new Man();
	
	CCFSMMachine* manFsm=new CCFSMMachine();
    
	manFsm->setCurrentState(ManStateIdle::sharedState());
	
	aMan->setFsm(manFsm);
	aMan->setup();
	
	aMan->update();
	aMan->update();
	aMan->update();
    CCCompleteMessageManager::sharedCompleteMessageManager()->dispatchMessageWithType(MSG_Find_Enimy, 
															  NULL,
															  aMan,
                                                            NULL);
	aMan->update();
	aMan->update();
	aMan->update();
	
	aMan->update();
	aMan->update();
	aMan->update();
	CCCompleteMessageManager::sharedCompleteMessageManager()->dispatchMessageWithType(MSG_Enimy_Die, 
                                                                                      NULL,
                                                                                      aMan,
                                                                                      NULL);
	aMan->update();
	aMan->update();
	aMan->update();
	
    manFsm->release();
	aMan->release();
}
