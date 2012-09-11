#ifndef __MAN_STATE_H__
#define __MAN_STATE_H__

#include "cocos2d.h"
#include "CCFSMState.h"

USING_NS_CC;

class ManStateBase:public CCFSMState
{
public:
	virtual void enter(CCIEntity* entity);
    virtual void exit(CCIEntity* entity);
    virtual void update(CCIEntity* entity);
};

class ManStateIdle:public ManStateBase
{
	virtual void exit(CCIEntity* entity);
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
};

class ManStateApproach:public ManStateBase
{
public:
    virtual void update(CCIEntity* entity);
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
};

class ManStateAttack:public ManStateBase
{
public:
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
};


#endif //__MAN_STATE_H__