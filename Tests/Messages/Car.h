//
//  Car.h
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#ifndef __Car_H__
#define __Car_H__

#include "cocos2d.h"
#include "CCMessage.h"

USING_NS_CC;

class Car : public CCObject
{
public:
    Car();
    ~Car();
    void stop();
    void onMessage(CCMessage* message);
};

#endif //__Car_H__ 
