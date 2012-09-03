//
//  Message.h
//  Message
//  
//  消息是基于投递的，不存在父子关系。一个消息对应消息的处理函数（一个或多个），不存捕捉和冒泡。可以延迟发关。可以设置优先级。
//  注意和事件的区别，事件要复杂些。消息通常和简单发送执行，所以性能要高一些。
//  当然事件可以定义的很简单或遵循一定模式(dom事件模型)。
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//
#ifndef __Message_H__
#define __Message_H__
#include "cocos2d.h"

typedef unsigned int MessageType;
typedef CCObject *MessageObject;
//typedef NSString *MessageType
//typedef id MessageSender;
//typedef int MessageSender;

class Message : public CCObject {
public:
	MessageType getType();
	void setType(MessageType type);
	MessageObject getSender();
	void setSender(MessageObject sender);
	MessageObject getReceiver();
	void setReceiver(MessageObject receiver);
	CCDictionary* getData();
	void setData(CCDictionary* data);
private:
    MessageType type;//消息的类型或ID。
    MessageObject sender;//消息的发送者
	MessageObject receiver;//消息的接收者
    float timeStamp;//发送时间
	CCDictionary *data;
}

-(id)initWithType:(MessageType type,MessageObject sender ,MessageObject receiver ,CCDictionary *data;
-(id)initWithType:(MessageType type,MessageObject sender,CCDictionary *data);



#endif  // __Message_H__
