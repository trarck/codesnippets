#include "ManState.h"
#include "Man.h"

void ManState::enter(CCIEntity* entity)
{
	CCLOG("enter a man(%d) state",entity->m_uID);
}

void ManState::exit(CCIEntity* entity)
{
	CCLOG("exit a man(%d) state",entity->m_uID);
}

void ManState::update(CCIEntity* entity)
{
	CCLOG("update a man(%d) state",entity->m_uID);
}

void ManStateIdle::exit(CCIEntity* entity)
{
	ManState::exit();
	Man* man=(Man*) entity;
	man->setDistance(3);
}

void ManStateIdle::onMessage(CCMessage* message,CCIEntity* entity)
{

	Man* man=(Man*)entity;
	man->getFsm()->changeState(ManStateApproach::sharedState);

}

void ManStateApproach::update(CCIEntity* entity)
{

}

void ManStateApproach::onMessage(CCMessage* message,CCIEntity* entity)
{

}

void ManStateAttack::onMessage(CCMessage* message,CCIEntity* entity)
{

}