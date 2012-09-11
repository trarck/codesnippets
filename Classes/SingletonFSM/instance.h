/*
 *  instance.h
 *  GameFsm
 *
 *  Created by trarck trarck on 11-12-26.
 *  Copyright 2011 yitengku.com. All rights reserved.
 *
 */
static id instance_;

static id classInstance(Class cls){
	if (!instance_) {
		instance_=[[cls alloc] init];
	}
	return instance_;
}
