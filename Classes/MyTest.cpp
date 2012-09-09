//
//  MyTest.cpp
//  codecodesnippets
//
//  Created by duanhouhai on 12-9-6.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "CCMessageHandler.h"
#include "CCMessage.h"

using namespace cocos2d;


class MyHandler:public CCObject
{
public:

    void onMessage(CCMessage* msg);
};

void MyHandler::onMessage(CCMessage *msg)
{
    CCLog("####doMessage");
}


void TestMain()
{
    CCLog("TestMain");
    CCObject* o1= new CCObject();
    
    CCMessage* pMsg=new CCMessage();
    pMsg->initWithType(1, o1, o1, NULL);
    
    CCLOG("o1 retainCount=%d",o1->retainCount());
    CCLOG("pMsg retainCount=%d",pMsg->retainCount());
    
    MyHandler* myHandler=new MyHandler();
    
    CCMessageHandler *pMsgHandler= new CCMessageHandler();
    pMsgHandler->initWithTarget(myHandler, message_selector(MyHandler::onMessage));
    
    pMsgHandler->execute(pMsg);
    
    pMsg->release();
    
    CCLOG("myHandler retainCount=%d",myHandler->retainCount());
    myHandler->release();
    CCLOG("myHandler retainCount=%d",myHandler->retainCount());
    pMsgHandler->release();
    CCLOG("myHandler retainCount=%d",myHandler->retainCount());
    
    CCLOG("pMsgHandler retainCount=%d",pMsgHandler->retainCount());
    
    CCLOG("o1 retainCount=%d",o1->retainCount());
    CCLOG("pMsg retainCount=%d",pMsg->retainCount());    
    
    o1->release();
}


