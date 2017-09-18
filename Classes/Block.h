#pragma once
#ifndef __Block_H_
#define __Block_H_
#include "cocos2d.h"
USING_NS_CC;

class Block : public Sprite
{
public:
	static Block* createWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);

	//��ʼ��������������ɫ�������С���֡������С��������ɫ  
	virtual bool initWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);
	//�������block  
	static Vector<Block*> * blocks;
	void removeBlock();
	void setLineIndex(int index);
	int getLineIndex();
	static Vector<Block*> * getBlocks();
	void moveDowm();
private:
	int lineIndex;
};

#endif