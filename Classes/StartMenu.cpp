#include "StdAfx.h" 
#include "StartMenu.h"
#include"HelloWorldScene.h"
#include"AppDelegate.h"
#include"SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;
/*CCScene* StartMenu::scene()
{
CCScene *scene = CCScene::create();

StartMenu *layer = StartMenu::create();
scene->addChild(layer);

return scene;
}*/
Scene* StartMenu::createScene()
{
	return StartMenu::create();
}
bool StartMenu::init()
{
	/*这里if (!CCLayer::init())
	{
	return false;
	}*/

	CCDirector *pDirector = CCDirector::sharedDirector();  //创建一个导演类，用来调用整个场景所需要的变量，比如窗口大小

	CCSize winSize = pDirector->getWinSize();//通过导演类获得窗口的大小

	CCSprite *pLoadingImg = CCSprite::create("loading.png"); //创建一个精灵类，来存放一张背景图片
	pLoadingImg->setPosition(ccp(winSize.width / 2, winSize.height / 2));//图片放在正中央
	this->addChild(pLoadingImg);//场景添加图片

								//创建菜单选项
								//仿照上面的创建一个Logo图，设置图片的锚点，一样放进场景里面
	CCSprite *pLogoImg = CCSprite::create("logo.png");

	pLogoImg->setAnchorPoint(ccp(0.5, 1));

	pLogoImg->setPosition(ccp(winSize.width / 2, winSize.height - 20));
	this->addChild(pLogoImg);

	//添加背景音乐
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menu_music.mp3", true);

	//创建菜单项的方法可能有点复杂，但是思路很清晰
	//1.首先同样用CCSprite创建一个菜单项正常，被点击，不能使用三种状态的图片，后面有个CCRectMake是（0，0）表示从图像的0，0（左上角）
	//点开始，（126，33）表示截取一张完整图像中的宽126，高33的部分图像
	//这么做有个很简单的原因是做美术的时候总是把多张图放在一起整合成一张图，避免太多的图片资源导致混乱。
	//2.接着用CCMenuItemSprite创建一个菜单项，然后把三种不同的状态加进去
	//3.后面有个Menu_selector(StartMenu:menuCallback);用来表示菜单项被点击的时候会响应事件（通常是切换场景）
	//4.最后要给项设置一个节点标志setTag()，用来识别是哪个菜单项被创建
	//这样一个菜单项创建完毕，后面两个菜单项依法炮制创建出来
	CCSprite *pNewNormalItemImg = CCSprite::create("menu.png", CCRectMake(0, 0, 101, 40));
	CCSprite *pNewSelectedItemImg = CCSprite::create("menu.png", CCRectMake(0, 41, 101, 40));
	CCSprite *pNewDisabledItemImg = CCSprite::create("menu.png", CCRectMake(0, 80, 101, 41));
	CCMenuItemSprite *pNewItem = CCMenuItemSprite::create(pNewNormalItemImg, pNewSelectedItemImg, pNewDisabledItemImg, this, menu_selector(StartMenu::menuCallback));
	pNewItem->setTag(1);

	//仿照第一个菜单项创建
	CCSprite *pOptionNormalItemImg = CCSprite::create("menu.png", CCRectMake(100, 0, 99, 40));
	CCSprite *pOptionSelectedItemImg = CCSprite::create("menu.png", CCRectMake(100, 40, 99, 40));
	CCSprite *pOptionDisabledItemImg = CCSprite::create("menu.png", CCRectMake(100, 80, 99, 40));
	CCMenuItemSprite *pOptionItem = CCMenuItemSprite::create(pOptionNormalItemImg, pOptionSelectedItemImg, pOptionDisabledItemImg, this, menu_selector(StartMenu::menuCallback));
	pOptionItem->setTag(2);

	//仿照第一个菜单项创建
	CCSprite *pAboutNormalItemImg = CCSprite::create("menu.png", CCRectMake(198, 0, 99, 40));
	CCSprite *pAboutSelectedItemImg = CCSprite::create("menu.png", CCRectMake(198, 40, 99, 40));
	CCSprite *pAboutDisabledItemImg = CCSprite::create("menu.png", CCRectMake(198, 80, 99, 40));
	CCMenuItemSprite *pAboutItem = CCMenuItemSprite::create(pAboutNormalItemImg, pAboutSelectedItemImg, pAboutDisabledItemImg, this, menu_selector(StartMenu::menuCallback));
	pAboutItem->setTag(3);

	//三个菜单项创建完毕之后，就要把它们合并成一个菜单了
	//用CCMenu 创建一个菜单把三个菜单项包含进去
	//设置每个菜单项之间的距离是30:alignItemsVerticallyWithPadding(20);
	CCMenu *pMenu = CCMenu::create(pNewItem/*, pOptionItem*/, pAboutItem, NULL);
	pMenu->alignItemsVerticallyWithPadding(20);
	pMenu->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 60));
	addChild(pMenu);





	return true;
}

void StartMenu::menuCallback(CCObject* pSender)
{
	int nTag = ((CCNode *)pSender)->getTag();
	switch (nTag)
	{
	case 1:
	{
		CCLOG("New Click");
		//CCScene *GameLayerScene = GameLayer::scene();
		//auto scene = GameLayer::createScene();
		//CCDirector::sharedDirector()->replaceScene(/*GameLayerScene scene);

		//backgram
		/*CCDirector *pDircector = CCDirector::sharedDirector();
		CCSize winSize = pDircector->getWinSize();

		CCSprite *gameLayerBackgroundImg = CCSprite::create("bg1.png");
		gameLayerBackgroundImg->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		this->addChild(gameLayerBackgroundImg);*/

		//auto scene = HelloWorld::createScene();
		//停止菜单音乐
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		//播放游戏音乐
		SimpleAudioEngine::sharedEngine()->playEffect("game_music.mp3", true);

		//开启游戏界面
		CCScene *GameLayerScene = HelloWorld::createScene();
		CCDirector::sharedDirector()->replaceScene(GameLayerScene);


	}
	break;
	/*case 2:
	{
		CCLOG("Option Click");
	}
	break;*/
	case 2:
	{
		CCLOG("About Click");
		Director::getInstance()->end();
	}
	break;
	}
}








//1.菜单是一个场景，场景要有一个导演来调度资源的排布
//2.精灵类在cocos2d中很常见，创建一个图片可以用一个精灵类CCSprite
//3.添加图片经常用this->addChild();