//
//  IStateParameter.h
//  GameFsm
//
//  状态对象不能有自己的变更，如果状态需要私有变量，可以放在实体中，实体通过参数传递。
//  状态可以在多个实体之间共用，状态可以使用单例模式。
//  Created by trarck trarck on 11-11-25.
//

#ifndef __CCIFSMStateDelegate_H__
#define __CCIFSMStateDelegate_H__

#include "cocos2d.h"
#include "CCIFSMState.h"
#import "CCIEntity.h"

class CCIFSMStateParameter:public CCIFSMState
{

virtual void enter(CCIEntity* entity);
virtual void exit(CCIEntity* entity);
virtual void update(CCIEntity* entity);

};

#endif //__CCIFSMStateDelegate_H__