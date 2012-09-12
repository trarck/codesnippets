//
//  IFSMachine.h
//  GameFsm
//
//

#ifndef __CCIFSMMachine_H__
#define __CCIFSMMachine_H__

#include "CCIFSMState.h"
#include "CCIEntity.h"

NS_CC_BEGIN


class CCIFSMMachine:public CCObject
{
public:    
    virtual void setOwner(CCIEntity* owner);
    virtual CCIEntity* getOwner();
    virtual CCIFSMState* getCurrentState();
    virtual void setCurrentState(CCIFSMState* state);
    
    virtual void addState(CCIFSMState* state ,CCObject* key);
    virtual void addState(CCIFSMState* state ,CCString* name);
    virtual void addState(CCIFSMState* state ,unsigned int guid);
    
    virtual void removeStateWithKey(CCObject* key);
    virtual void removeStateWithName(CCString* name);
    virtual void removeStateWithGuid(unsigned int guid);
    
    virtual CCIFSMState* stateForKey(CCObject* key);
    virtual CCIFSMState* stateForName(CCString* name);
    virtual CCIFSMState* stateForGuid(unsigned int guid);
    
    virtual void update();
    
    virtual void handleMessage(CCMessage* message);
    
    virtual void changeState(CCIFSMState* state);//可有可无
    
};

NS_CC_END

#endif //__CCIFSMMachine_H__
