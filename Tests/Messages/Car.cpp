//
//  Car.m
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#include "Car.h"

Car::Car()
{
	CCLOG("Car create");

}

Car::~Car()
{
	CCLOG("Car destroy");
}

void Car::stop()
{
	CCLOG("Car stop");
    m_messageResult=1; 
}

void Car::onMessage(CCMessage *message)
{
    CCLOG("Car onMessage");
    
//    CCLOG("receive message with type=%d,senderId=%d,receiverId=%d",message->getType(),message->getSender()->m_uID,message->getReceiver()->m_uID);
    
    m_messageResult=1;    
}

void Car::resetMessageResult()
{
    m_messageResult=0;
}

int Car::getMessageResult()
{
    return m_messageResult;
}