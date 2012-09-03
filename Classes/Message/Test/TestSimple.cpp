//
//  main.m
//  Message
//
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SimpleMessageManager.h"
#import "Car.h"
#import "Man.h"
#import "Datas.h"

int main (int argc, const char * argv[])
{
	
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	
	// insert code here...
	
	Man *aMan=[[[Man alloc] init] autorelease];
	Car *aCar=[[[Car alloc] init] autorelease];
	
	NSLog(@"********message***************");
	
	DataItem datas[]={
		{CarStop,aCar,aMan,@selector(wait:),CarStop,aCar,aMan,nil},
		{CarStop,aCar,aMan,@selector(wait:),CarStop,aCar,nil,nil},
		{CarStop,aCar,aMan,@selector(wait:),CarStop,nil,aMan,nil},//no
		{CarStop,aCar,aMan,@selector(wait:),CarStop,nil,nil,nil},//no
		{CarStop,nil,aMan,@selector(wait:),CarStop,aCar,aMan,nil},
		{CarStop,nil,aMan,@selector(wait:),CarStop,nil,aMan,nil},
		{CarStop,nil,aMan,@selector(wait:),CarStop,nil,nil,nil}
	};
	
	int dataLength=sizeof(datas)/sizeof(DataItem);
	DataItem it;
	
	struct timeval start,end;
	gettimeofday(&start,NULL);
	
	for(int i=0;i<dataLength;i++){
		NSLog(@"do test %d",i);
		it=datas[i];
		RegisterData rd=it.regiester;
		DispatchData dd=it.dispatch;
		//regiester
		SimpleMessageManager * mm=[[SimpleMessageManager alloc] init];
		[mm registerReceiver:rd.receiver  type:rd.type sender:rd.sender handle:rd.handle];
		//dispatch
		Message *message=[[Message alloc] initWithType:dd.type sender:dd.sender receiver:dd.receiver data:dd.data];
		[mm dispatchMessage:message];
	}
	
	//regiester aMan的CarStop消息，使用aCar的stop函数来处理
	SimpleMessageManager * mm=[[SimpleMessageManager alloc] init];
	[mm registerReceiver:aMan type:CarStop sender:nil handle:@selector(stop) handleObject:aCar];
	//dispatch
	Message *message=[[Message alloc] initWithType:CarStop sender:aCar receiver:aMan data:nil];
	[mm dispatchMessage:message];
	
	gettimeofday(&end,NULL);
	NSLog(@"used time:%ld,%d",end.tv_sec-start.tv_sec,end.tv_usec-start.tv_usec);
	
	NSLog(@"********auto release***************");
    [pool drain];
    return 0;
}

