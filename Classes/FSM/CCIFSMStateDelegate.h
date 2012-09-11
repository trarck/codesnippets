//
//  IStateDelegate.h
//  GameFsm
//
//  状态使用代理模式。状态可以保存自己的变量，每个实体都有一个状态对象。
//  Created by trarck trarck on 11-11-25.
//

#ifndef __CCIFSMStateDelegate_H__
#define __CCIFSMStateDelegate_H__

#include "cocos2d.h"
#include "CCIFSMState.h"




class CCIFSMStateDelegate:public CCIFSMState
{

    //状态的拥有者，状态机或实体对象
    virtual void setOwner(CCObject* owner);
    virtual CCObject* getOwner();

}

#endif //__CCIFSMStateDelegate_H__
