#ifndef __MAN_STATE_H__
#define __MAN_STATE_H__

#include "cocos2d.h"
#include "CCFSMState.h"
#include "CCIEntity.h"

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
public:
    static ManStateIdle* sharedState();
	virtual void exit(CCIEntity* entity);
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
private:
    static ManStateIdle* s_idleInstance;
};

class ManStateApproach:public ManStateBase
{
public:
    static ManStateApproach* sharedState();
    virtual void update(CCIEntity* entity);
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
private:
    static ManStateApproach* s_approachInstance;
};

class ManStateAttack:public ManStateBase
{
public:
    static ManStateAttack* sharedState();
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
private:
    static ManStateAttack* s_attackInstance;
};


#endif //__MAN_STATE_H__