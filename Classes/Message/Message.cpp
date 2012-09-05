//
//  Message.m
//  Message

//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "Message.h"

using namespace std;

NS_CC_BEGIN

Message::Message(void)
:m_type(0)
,m_sender(NULL)
,m_receiver(NULL)
,m_data(NULL)
,m_timeStamp(0.0f)
{
    
}

Message::~Message(void)
{
    CC_SAFE_RELEASE(m_data);
}

MessageType Message::getType()
{
    return m_type;
}

void Message::setType(MessageType type)
{
    m_type=type;
}

MessageParty Message::getSender()
{
    return m_sender;
}
void Message::setSender(MessageParty sender)
{
    CC_SAFE_RETAIN(sender);
    CC_SAFE_RELEASE(m_sender);
    m_sender=sender;
}

MessageParty Message::getReceiver()
{
    return m_receiver;
}

void Message::setReceiver(MessageParty receiver)
{
    CC_SAFE_RETAIN(receiver);
    CC_SAFE_RELEASE(m_receiver);
    m_receiver=receiver;
}

CCDictionary* Message::getData()
{
    return m_data;
}

void Message::setData(CCDictionary* data)
{
    CC_SAFE_RETAIN(data);
    CC_SAFE_RELEASE(m_data);
    m_data=data;
}


bool Message::initWithType(MessageType type,MessageParty sender ,MessageParty receiver ,CCDictionary *data)
{

    m_type=type;
    setSender(sender);
    setReceiver(receiver);
    setData(data);
    
    return true;
}

bool Message::initWithType(MessageType type,MessageParty sender,CCDictionary *data)
{
    return initWithType(type,sender,NULL,data);
}

NS_CC_END
