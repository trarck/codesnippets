//
//  MessageHandler.h
//  Message
//
//  Created by trarck trarck on 11-12-27.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MessageHandler : NSObject {
	id target_;
	SEL handle_;
}
@property(nonatomic,retain) id target;
@property(nonatomic,assign) SEL handle;

-(id) initWithTarget:(id) target handle:(SEL) handle;

@end
