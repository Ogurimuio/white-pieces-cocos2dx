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


	//��ӿ�ʼ�Ļ�ɫ��  
	void addStartLine();
	//��ӽ����ĺ�ɫ����ռ����Ļ  
	void addEndLine();
	//�����ͨ�ĺڰ׿���  
	void addNormalLine(int lineIndex);
	void startGame();
	void moveDown();
	//��ʼ��ʱ  
	void startTimer();

	//������ʱ  
	void stopTimer();

	virtual void update(float dt);

	//���¿�ʼ
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