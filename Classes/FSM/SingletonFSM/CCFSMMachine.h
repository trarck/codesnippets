//
//  FSMachine.h
//  GameFsm
//
//  Created by trarck trarck on 11-11-24.
//

#ifndef __CCFSMMachine_H__
#define __CCFSMMachine_H__

#include "CCIFSMMachine.h"
#include "CCIFSMState.h"
#include "CCIEntity.h"

NS_CC_BEGIN

class CCFSMMachine:public CCIFSMMachine
{
public:
	CCFSMMachine(void);
	~CCFSMMachine(void);
	void initWithOwner(CCIEntity* owner);

	//ovveride
	virtual void setOwner(CCIEntity* owner);
    virtual CCIEntity* getOwner();
    virtual CCIFSMState* getCurrentState();
    virtual void setCurrentState(CCIFSMState* state);

    //由于State是单例，可以直接取得，无须另外保存

    virtual void update();
    virtual void handleMessage(CCMessage* message);

    virtual void changeState(CCIFSMState* state);//可有可无
private:
	CCIFSMState* m_currentState;
	CCIEntity* m_owner;
	
};

NS_CC_END

#endif //__CCFSMMachine_H__
