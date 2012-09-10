//
//  Car.m
//  Message
//
//  Created by trarck trarck on 11-12-16.
//  Copyright 2011 yitengku.com. All rights reserved.
//

#include "Car.h"



Car::Car()
{
	CCLOG("Car create");

}

Car::~Car()
{
	CCLOG("Car destroy");
}

void Car::stop()
{
	CCLOG("Car stop");
}

void Car::onMessage(CCMessage *message)
{
    CCLOG("Car onMessage");
}