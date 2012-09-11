#ifndef __Man_H__
#define __Man_H__

#include "cocos2d.h"
#include "CCFSMMachine.h"

USING_NS_CC;

class Man:public CCObject
{
public:
	
	Man();
	~Man();

	void setFsm(CCFSMMachine* fsm);
	CCFSMMachine* getFsm();
	void setDistance(unsigned int distance);
	unsigned int getDistance();

	void update();
	void setup();
	void handleMessage:(CCMessage* message);

private:
	CCFSMMachine* fsm_;
	unsigned int distance_;
};

#endif //__Man_H__