//
//  TestMessage.cpp
//  codecodesnippets
//
//  Created by duanhouhai on 12-9-10.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
#include "CCMessageHandler.h"
#include "CCMessage.h"
#include "Car.h"
#include "Man.h"
#include "CCCompleteMessageManager.h"
#include "CCSimpleMessageManager.h"
#include "TestMessage.h"
#include "Datas.h"

USING_NS_CC;

void TestMessage::testCreateMessage()
{
    CCLOG("*****************testCreateMessage*****************");
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
    CCLOG("*****************testMessageHandle*****************");
    
	Car* car=new Car();
    Man* man=new Man();
	
	CCMessageHandler* pMsgHandler=new CCMessageHandler();
	pMsgHandler->initWithTarget(car, message_selector(Car::onMessage));
	
    CCMessage* pMsg=new CCMessage();
    pMsg->initWithType(1, car, man, NULL);

	pMsgHandler->execute(pMsg);
	
	CCLOG("do pMsg release");
    pMsg->release();

	CCLOG("do pMsgHandler release");
	pMsgHandler->release();
	
    man->release();
	car->release();
}

void TestMessage::testComplexMessageManager()
{
   CCLOG("*****************testComplexMessageManager*****************");
    
    Car* aCar=new Car();
    Man* aMan=new Man();
    
    DataItem datas[]={
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,aCar,aMan,NULL ,1},
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,aCar,NULL,NULL ,1},
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,NULL,aMan,NULL ,0},//no
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,NULL,NULL,NULL ,0},//no
		{CarStop,NULL,aMan,message_selector(Man::wait)  ,CarStop,aCar,aMan,NULL ,1},
		{CarStop,NULL,aMan,message_selector(Man::wait)  ,CarStop,NULL,aMan,NULL ,1},
		{CarStop,NULL,aMan,message_selector(Man::wait)  ,CarStop,NULL,NULL,NULL ,1},
		{MsgAll,aCar,aMan,message_selector(Man::wait)   ,CarStop,aCar,aMan,NULL ,1}
	};
    
    int dataLength=sizeof(datas)/sizeof(DataItem);
    CCLOG("dataLength=%d",dataLength);
    DataItem it;
    for(int i=0;i<dataLength;i++){
        CCLOG("do test %d",i);
        it=datas[i];
        RegisterData rd=it.regiester;
        DispatchData dd=it.dispatch;
        CCCompleteMessageManager* cmm=new CCCompleteMessageManager();
        cmm->init();
        cmm->registerReceiver(rd.receiver, rd.handle, rd.type, rd.sender);
        
        CCMessage* message=new CCMessage();
        message->initWithType(dd.type, dd.sender, dd.receiver, dd.data);
        
        cmm->dispatchMessage(message);
        
        CCAssert(aMan->getMessageResult()==it.result, "test testComplexMessageManager fail");
        aMan->resetMessageResult();
        
        message->release();
        cmm->release();
        
    }
    CCLOG("do test special message");
	//regiester aMan的CarStop消息，使用aCar的stop函数来处理
    CCCompleteMessageManager* messageManager=CCCompleteMessageManager::sharedCompleteMessageManager();
    messageManager->registerReceiver(aMan, message_selector(Car::stop), CarStop, NULL,aCar);
    
    CCMessage* message=new CCMessage();
    message->initWithType(CarStop, aCar, aMan, NULL);
    
    messageManager->dispatchMessage(message);
    
    CCAssert(aCar->getMessageResult()==1, "test testComplexMessageManager fail");
    aCar->resetMessageResult();
    
    message->release();   
    messageManager->release();
    
    aCar->release();
    aMan->release();
    
}

void TestMessage::testSimpleMessageManager()
{
    
    CCLOG("*****************testComplexMessageManager*****************");
    
    
    Car* aCar=new Car();
    Man* aMan=new Man();
    
    DataItem datas[]={
        {CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,aCar,aMan,NULL ,1},
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,aCar,NULL,NULL ,1},
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,NULL,aMan,NULL ,0},//no
		{CarStop,aCar,aMan,message_selector(Man::wait)  ,CarStop,NULL,NULL,NULL ,0},//no
		{CarStop,NULL,aMan,message_selector(Man::wait)  ,CarStop,aCar,aMan,NULL ,1},
		{CarStop,NULL,aMan,message_selector(Man::wait)  ,CarStop,NULL,aMan,NULL ,1},
		{CarStop,NULL,aMan,message_selector(Man::wait)  ,CarStop,NULL,NULL,NULL ,1},
		{MsgAll,aCar,aMan,message_selector(Man::wait)   ,CarStop,aCar,aMan,NULL ,1}	
    };
    
    int dataLength=sizeof(datas)/sizeof(DataItem);
    DataItem it;
    
    for(int i=0;i<dataLength;i++){
        CCLOG("do test %d",i);
        it=datas[i];
        RegisterData rd=it.regiester;
        DispatchData dd=it.dispatch;
        CCSimpleMessageManager* smm=new CCSimpleMessageManager();
        smm->init();
        smm->registerReceiver(rd.receiver, rd.handle,rd.type, rd.sender);
        
        CCMessage* message=new CCMessage();
        message->initWithType(dd.type, dd.sender, dd.receiver, dd.data);
        
        smm->dispatchMessage(message);
        
        CCAssert(aMan->getMessageResult()==it.result, "test testComplexMessageManager fail");
        aMan->resetMessageResult();
        
        message->release();
        smm->release();
    }
    
    CCSimpleMessageManager* cmm=new CCSimpleMessageManager();
    cmm->init();
    cmm->registerReceiver(aMan, message_selector(Car::stop), CarStop, NULL,aCar);
    
    CCMessage* message=new CCMessage();
    message->initWithType(CarStop, aCar, aMan, NULL);
    cmm->dispatchMessage(message);
    
    CCAssert(aCar->getMessageResult()==1, "test testComplexMessageManager fail");
    aCar->resetMessageResult();
    
    
    message->release();
    cmm->release();
    
    aMan->release();
    aCar->release();
    
}
