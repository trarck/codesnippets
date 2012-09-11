#ifndef __CCFSMState_H__
#define __CCFSMState_H__

#include "cocos2d.h"
#include "CCIFSMState.h"

NS_CC_BEGIN

class CCFSMState:public CCIFSMState 
{
public:
	CCFSMState(void);
	~CCFSMState(void);
};

NS_CC_END

#endif //__CCFSMState_H__