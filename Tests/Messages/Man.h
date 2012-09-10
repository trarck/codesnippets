//
//  Npc.h
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#ifndef __Man_H__
#define __Man_H__

#include "cocos2d.h"
#include "CCMessage.h"

USING_NS_CC;

class Man : public CCObject
{
public:
    Man();
    ~Man();
    void wait(CCMessage* message);
};

#endif //__Man_H__

