//
//  IFSMachine.h
//  GameFsm
//
//  状态机不能使用单例模式，每个对象的当前状态不一样，而状态机则保存有当前状态对象。
//  游戏实体可以做为状态机。
//  Created by trarck trarck on 11-11-24.
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

    //由于State是单例，可以直接取得，无须另外保存

    void update();
    void handleMessage(CCMessage* message);

    void changeState(CCIFSMState* state);//可有可无

};

NS_CC_END

#endif //__CCIFSMMachine_H__
