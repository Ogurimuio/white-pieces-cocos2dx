#include "StdAfx.h" 
#include"GameOver.h"
#include "SimpleAudioEngine.h"
#include "Block.h" 

USING_NS_CC;


Scene* GameOver::createScene()
{
	return GameOver::create();
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto b = Block::createWithArgs(Color3B::BLACK, visibleSize, "Game Over", 30, Color4B::WHITE);
	addChild(b);

	//添加退出按钮
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(Director::getInstance()->end();));
	pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
}

void GameOver::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

/*void GameOver::addEndLine()
{
	auto b = Block::createWithArgs(Color3B::BLACK, visibleSize, "Game Over", 30, Color4B::WHITE);
	addChild(b);

	//添加退出按钮
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));
	pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
}*/