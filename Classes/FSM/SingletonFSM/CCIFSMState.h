//
//  IStateParameter.h
//  GameFsm
//
//  状态对象不能有自己的变更，如果状态需要私有变量，可以放在实体中，实体通过参数传递。
//  状态可以在多个实体之间共用，状态可以使用单例模式。
//  Created by trarck trarck on 11-11-25.
//

#ifndef __CCIFSMState_H__
#define __CCIFSMState_H__

#include "cocos2d.h"
#include "CCMessage.h"
#include "CCIEntity.h"

NS_CC_BEGIN

class CCIFSMState:public CCObject
{
public:
    virtual void enter(CCIEntity* entity);
    virtual void exit(CCIEntity* entity);
    virtual void update(CCIEntity* entity);
    
    virtual void onMessage(CCMessage* message,CCIEntity* entity);
    
};

NS_CC_END

#endif //__CCIFSMState_H__

