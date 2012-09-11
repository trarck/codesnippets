/*
 *  Datas.h
 *  Message
 *
 *  Created by trarck trarck on 11-12-16.
 *  Copyright 2011 yitengku.com. All rights reserved.
 *
 */
#include "cocos2d.h"

using namespace cocos2d;

typedef struct Register_Data{
	MessageType type;
	CCObject* sender;
	CCObject* receiver;
	SEL_MessageHandler handle;
	
} RegisterData;

typedef struct Dispatch_Data{
	MessageType type;
	CCObject* sender;
	CCObject* receiver;
	CCDictionary* data;
} DispatchData;

typedef struct DataItem{
	RegisterData regiester;
	DispatchData dispatch;
    int result;
} DataItem;

enum  {
	MsgAll=0,
	CarStop,
	CarMove,
	DirverCar
};