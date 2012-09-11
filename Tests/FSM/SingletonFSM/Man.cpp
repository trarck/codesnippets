#include "Man.h"
#include "CompleteMessageManager.h"

Man::Man():fsm_(NULL),distance_(0)
{
	CCLOG("Man create");
}

Man::~Man()
{
	CCLOG("Man destroy");
	CC_SAFE_RELEASE(fsm_);
}

void Man::setFsm(CCFSMMachine* fsm)
{
	CC_SAFE_RETAIN(fsm);
	CC_SAFE_RELEASE(fsm_);
	fsm_=fsm;
	fsm_->setOwner(this);
}

Man::CCFSMMachine* getFsm()
{
	return fsm_;
}

void Man::setDistance(unsigned int distance)
{
	distance_=distance;
}

unsigned int Man::getDistance()
{
	return distance_;
}

void Man::update()
{
	CCLOG("Man update");
	fsm_->update();
}

void Man::setup()
{
	CCLOG("Man update");
	CompleteMessageManager::sharedCompleteMessageManager->registerMessage:MSG_Find_Enimy handle:@selector(handleMessage:) sender:nil];
	[self registerMessage:MSG_Approach_Sucess handle:@selector(handleMessage:) sender:nil];
	[self registerMessage:MSG_Enimy_Die handle:@selector(handleMessage:) sender:nil];
}

void Man::handleMessage(CCMessage* message)
{
	CCLOG("Man handleMessage");
	fsm_->handleMessage(message);
}