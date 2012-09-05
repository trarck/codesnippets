//
//  MessageHandler.m
//  Message
//
//  Created by trarck trarck on 11-12-27.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#include "CCMessageHandler.h"

NS_CC_BEGIN

CCObject* CCMessageHandler::getTarget()
{
    return m_target;
}

void CCMessageHandler::setTarget(CCObject* target)
{
    CC_SAFE_RETAIN(target);
    CC_SAFE_RELEASE(m_target);
    m_target=target;
}

SEL_MessageHandler CCMessageHandler::getHandle()
{
    return m_handle;
}

void CCMessageHandler::setHandle(SEL_MessageHandler handle)
{
    m_handle=handle;
}

bool CCMessageHandler::initWithTarget(CCObject* target,SEL_MessageHandler handle)
{
    setTarget(target);
    m_handle=handle;
    return true;
}

NS_CC_END