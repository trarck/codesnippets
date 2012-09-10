//
//  TestMessage.cpp
//  codecodesnippets
//
//  Created by duanhouhai on 12-9-10.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "TestMessage.h"
#include "Car.h"
#include "Man.h"

void TestMessage::testCreateMessage()
{
    Car* car=new Car();
    CCMessage* pMsg=new CCMessage();
    pMsg->initWithType(1, car, car, NULL);
    
    CCLOG("car retainCount=%d",car->retainCount());
    CCLOG("pMsg retainCount=%d",pMsg->retainCount());

    
    CCLOG("do car release");
    car->release();
    
    
    CCLOG("do pMsg release");
    pMsg->release();
    
 
    
    CCLOG("car retainCount=%d",car->retainCount());
    CCLOG("pMsg retainCount=%d",pMsg->retainCount());
}

void TestMessage::testMessageHandle()
{
    
}

void TestMessage::testComplexMessageManager()
{
    
}

void TestMessage::testSimpleMessageManager()
{
    
}
