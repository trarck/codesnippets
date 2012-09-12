#include "Man.h"
#include "CCCompleteMessageManager.h"
#include "Type.h"

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

CCFSMMachine* Man::getFsm()
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
    CCCompleteMessageManager::sharedCompleteMessageManager()->registerReceiver(this, message_selector(Man::handleMessage), MSG_Find_Enimy, NULL);
    CCCompleteMessageManager::sharedCompleteMessageManager()->registerReceiver(this, message_selector(Man::handleMessage), MSG_Approach_Sucess, NULL);
    CCCompleteMessageManager::sharedCompleteMessageManager()->registerReceiver(this, message_selector(Man::handleMessage), MSG_Enimy_Die, NULL);
}

void Man::handleMessage(CCMessage* message)
{
	CCLOG("Man handleMessage");
	fsm_->handleMessage(message);
}