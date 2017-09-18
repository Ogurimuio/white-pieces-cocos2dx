#pragma once
#ifndef __Block_H_
#define __Block_H_
#include "cocos2d.h"
USING_NS_CC;

class Block : public Sprite
{
public:
	static Block* createWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);

	//初始化参数：方块颜色、方块大小、字、字体大小、字体颜色  
	virtual bool initWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);
	//用来存放block  
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