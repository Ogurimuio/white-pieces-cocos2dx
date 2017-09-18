#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Block.h" 

class HelloWorld : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);


	//添加开始的黄色栏  
	void addStartLine();
	//添加结束的黑色栏，占满屏幕  
	void addEndLine();
	//添加普通的黑白块栏  
	void addNormalLine(int lineIndex);
	void startGame();
	void moveDown();
	//开始计时  
	void startTimer();

	//结束计时  
	void stopTimer();

	virtual void update(float dt);

	//重新开始
	bool reStart();
	void menuCallback(CCObject* pSender);

private:
	Size visibleSize;
	int linesCount;
	bool showEnd;
	Label *timerLabel;
	Node *gameLayer;
	long startTime;
	bool timeRunning;
	Label *times;
};

#endif // __HELLOWORLD_SCENE_H__