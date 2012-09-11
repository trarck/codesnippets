//
//  State.h
//  GameFsm
//
//  Created by trarck trarck on 11-11-24.
//

#ifndef __CCFSMState_H__
#define __CCFSMState_H__

#include "cocos2d.h"
#include "CCIFSMState.h"

NS_CC_BEGIN

class CCFSMState : public CCIFSMState
{
public:
    CCFSMState();
    ~CCFSMState();
    static CCFSMState* create();
    
    virtual void enter(CCIEntity* entity);
    virtual void exit(CCIEntity* entity);
    virtual void update(CCIEntity* entity);
    
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
};

NS_CC_END

#endif //__CCFSMState_H__
