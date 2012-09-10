//
//  Npc.m
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#include "Man.h"

Man::Man()
{
	CCLOG("Man create");
}


Man::~Man()
{
	CCLOG("Man destroy");
}

void Man::wait(CCMessage *message)
{
    CCLOG("Man wait");
}
