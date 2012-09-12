#include "ManState.h"
#include "Man.h"

void ManStateBase::enter(CCIEntity* entity)
{
	CCLOG("enter a man(%d) state",entity->m_uID);
}

void ManStateBase::exit(CCIEntity* entity)
{
	CCLOG("exit a man(%d) state",entity->m_uID);
}

void ManStateBase::update(CCIEntity* entity)
{
	CCLOG("update a man(%d) state",entity->m_uID);
}


ManStateIdle* ManStateIdle::s_idleInstance=NULL;

ManStateIdle*  ManStateIdle::sharedState()
{
	if(!s_idleInstance){
        s_idleInstance=new ManStateIdle();
    }
    return s_idleInstance;
}

void ManStateIdle::exit(CCIEntity* entity)
{
	ManStateBase::exit(entity);
	Man* man=(Man*) entity;
	man->setDistance(3);
}

void ManStateIdle::onMessage(CCMessage* message,CCIEntity* entity)
{

	Man* man=(Man*)entity;
	man->getFsm()->changeState(ManStateApproach::sharedState());

}

ManStateApproach* ManStateApproach::s_approachInstance=NULL;

ManStateApproach*  ManStateApproach::sharedState()
{
	if(!s_approachInstance){
        s_approachInstance=new ManStateApproach();
    }
    return s_approachInstance;
}

void ManStateApproach::update(CCIEntity* entity)
{

}

void ManStateApproach::onMessage(CCMessage* message,CCIEntity* entity)
{

}

ManStateAttack* ManStateAttack::s_attackInstance=NULL;

ManStateAttack*  ManStateAttack::sharedState()
{
	if(!s_attackInstance){
        s_attackInstance=new ManStateAttack();
    }
    return s_attackInstance;
}

void ManStateAttack::onMessage(CCMessage* message,CCIEntity* entity)
{

}