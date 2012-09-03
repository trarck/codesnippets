/*
 *  Datas.h
 *  Message
 *
 *  Created by trarck trarck on 11-12-16.
 *  Copyright 2011 yitengku.com. All rights reserved.
 *
 */
typedef struct Register_Data{
	MessageType type;
	id sender;
	id receiver;
	SEL handle;
	
} RegisterData;

typedef struct Dispatch_Data{
	MessageType type;
	id sender;
	id receiver;
	id data;
} DispatchData;

typedef struct DataItem{
	RegisterData regiester;
	DispatchData dispatch;
} DataItem;

enum  {
	MsgAll=0,
	CarStop,
	CarMove,
	DirverCar
};

//Man *aMan=[[Man alloc] init];
//Car *aCar=[[Car alloc] init];
//
//DataItem datas[]={
//	{CarStop,aMan,aCar,@selector(wait:)}
//};