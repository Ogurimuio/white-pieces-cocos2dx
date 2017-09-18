#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


using namespace std;
USING_NS_CC;
class GameOver :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuCloseCallback(Ref* pSender);
	//void addEndLine();
private:
	Size visibleSize;
};
#endif