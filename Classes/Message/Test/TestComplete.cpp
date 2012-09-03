//
//  main.m
//  Message
//
//  Created by trarck on 11-11-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sys/time.h>

#import "CompleteMessageManager.h"
#import "Car.h"
#import "Man.h"
#import "Datas.h"

int main (int argc, const char * argv[])
{
	
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	
	// insert code here...
	NSMutableDictionary *md=[[NSMutableDictionary alloc] init];
	[md setObject:@"1" forKey:@"ee"];
	NSLog(@"%d",[[md objectForKey:@"ee"] intValue]);
	
	Man *aMan=[[[Man alloc] init] autorelease];
	Car *aCar=[[[Car alloc] init] autorelease];
	
	NSLog(@"********message***************");
	//NSMutableDictionary *md=[[NSMutableDictionary alloc] init];
//	NSValue *aKey=[NSValue valueWithPointer:aCar];
//	[md setObject:aMan forKey:aKey];
//	NSLog(@"%@",md);
//	NSValue *bKey=[NSValue valueWithNonretainedObject:aCar];
//	NSLog(@"%@",[md objectForKey:bKey]);
	DataItem datas[]={
		{CarStop,aCar,aMan,@selector(wait:),CarStop,aCar,aMan,nil},
		{CarStop,aCar,aMan,@selector(wait:),CarStop,aCar,nil,nil},
		{CarStop,aCar,aMan,@selector(wait:),CarStop,nil,aMan,nil},//no
		{CarStop,aCar,aMan,@selector(wait:),CarStop,nil,nil,nil},//no
		{CarStop,nil,aMan,@selector(wait:),CarStop,aCar,aMan,nil},
		{CarStop,nil,aMan,@selector(wait:),CarStop,nil,aMan,nil},
		{CarStop,nil,aMan,@selector(wait:),CarStop,nil,nil,nil},
		{MsgAll,aCar,aMan,@selector(wait:),CarStop,aCar,aMan,nil}
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
		CompleteMessageManager * mm=[[CompleteMessageManager alloc] init];
		[mm registerReceiver:rd.receiver handle:rd.handle type:rd.type sender:rd.sender];
		//dispatch
		Message *message=[[Message alloc] initWithType:dd.type sender:dd.sender receiver:dd.receiver data:dd.data];
		[mm dispatchMessage:message];
	}
	NSLog(@"do test special message");
	//regiester aMan的CarStop消息，使用aCar的stop函数来处理
	CompleteMessageManager * mm=[[CompleteMessageManager alloc] init];
	[mm registerReceiver:aMan handle:@selector(stop) type:CarStop sender:nil handleObject:aCar];
	//dispatch
	Message *message=[[Message alloc] initWithType:CarStop sender:aCar receiver:aMan data:nil];
	[mm dispatchMessage:message];
	
	gettimeofday(&end,NULL);
	NSLog(@"%ld,%d",end.tv_sec-start.tv_sec,end.tv_usec-start.tv_usec);
	
	NSLog(@"********auto release***************");
    [pool drain];
    return 0;
}

