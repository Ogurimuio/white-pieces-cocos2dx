#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	/* auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
	"CloseNormal.png",
	"CloseSelected.png",
	CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
	origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
	origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	//sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(sprite, 0);*/

	srand(time(NULL));

	visibleSize = Director::getInstance()->getVisibleSize();
	gameLayer = Node::create();
	addChild(gameLayer);

	timerLabel = Label::create();
	timerLabel->setColor(Color3B::GREEN);
	timerLabel->setSystemFontSize(35);
	timerLabel->setString("CLOCK");
	timerLabel->setPosition(visibleSize.width / 2 -150, visibleSize.height - 40);
	addChild(timerLabel);

	times = Label::create();
	times->setColor(Color3B::GREEN);
	times->setSystemFontSize(35);
	times->setString("TIMES");
	times->setPosition(visibleSize.width / 2 +160, visibleSize.height - 40);
	addChild(times);

	addStartLine();
	startGame();
	//addEndLine();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* t, Event* e)
	{
		log("onTouch");
		auto bs = Block::getBlocks();
		Block *b;

		int ti = 0;
		for (auto it = bs->begin(); it != bs->end(); it++)
		{
			
			b = *it;

			if (b->getLineIndex() == 1 && b->getBoundingBox().containsPoint(t->getLocation()))
			{
				if (b->getColor() == Color3B::BLACK)
				{
					b->setColor(Color3B::GRAY);
					this->moveDown();
					linesCount++;
					this->startTimer();
					//SimpleAudioEngine::sharedEngine()->playEffect("click.mp3", false);
					times->setString(StringUtils::format("%d", ((int)linesCount) / 1));

				}
				else if (b->getColor() == Color3B::GREEN)
				{
					this->moveDown();
					this->stopTimer();
				}
				else
				{
					//MessageBox("GameOver", "失败");
					addEndLine();
					this->stopTimer();
					
					reStart();
				}
				break;
			}
		}

		return false;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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

//添加开始的黄色栏  
void HelloWorld::addStartLine()
{
	//auto b = new Block();  
	//b->createWithArgs(Color3B::YELLOW, Size(visibleSize.width,visibleSize.height/4), "", 10, Color4B::BLACK); 

	auto b = Block::createWithArgs(Color3B::YELLOW, Size(visibleSize.width, visibleSize.height / 4), "Click the black block to START", 25, Color4B::BLACK);
	//addChild(b);
	gameLayer->addChild(b);
	b->setLineIndex(0);
}
//添加结束的黑色栏，占满屏幕  
void HelloWorld::addEndLine()
{
	auto b = Block::createWithArgs(Color3B::BLACK, visibleSize, "Game Over", 30, Color4B::WHITE);
	//addChild(b);
	gameLayer->addChild(b);
	b->setLineIndex(4);

}
//添加普通的黑白块栏  
void HelloWorld::addNormalLine(int lineIndex)
{
	Block *b;
	int blackIndex = rand() % 4;
	for (int i = 0; i<4; i++)
	{
		b = Block::createWithArgs(blackIndex == i ? Color3B::BLACK : Color3B::WHITE, Size(visibleSize.width / 4 - 1, visibleSize.height / 4 - 1), "", 20, Color4B::BLACK);
		b->setPosition(i*visibleSize.width / 4, lineIndex*visibleSize.height / 4);
		b->setLineIndex(lineIndex);
		//addChild(b);
		gameLayer->addChild(b);
	}
}
//开始游戏  
void HelloWorld::startGame()
{
	linesCount = 0;
	showEnd = false;
	timeRunning = false;

	addStartLine();
	addNormalLine(1);
	addNormalLine(2);
	addNormalLine(3);
}
//方块下移  
void HelloWorld::moveDown()
{
	//linesCount = 0;
	if (linesCount>-1)
	{
		addNormalLine(4);

	}
	else if (!showEnd)
	{
		addEndLine();
		showEnd = true;
	}

	auto bs = Block::getBlocks();
	for (auto it = bs->begin(); it != bs->end(); it++)
	{
		(*it)->moveDowm();
	}


}
//每帧都调用
void HelloWorld::update(float dt)
{
	long offset = clock() - startTime;

	timerLabel->setString(StringUtils::format("%g", ((double)offset) / 1000));
}

//开始计时  
void HelloWorld::startTimer()
{
	if (!timeRunning)
	{
		scheduleUpdate();
		startTime = clock();
		timeRunning = true;
	}
}

//结束计时  
void HelloWorld::stopTimer()
{
	if (timeRunning)
	{
		unscheduleUpdate();
		timeRunning = false;
	}
}


bool HelloWorld::reStart()
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	CCSize winSize = pDirector->getWinSize(); //通过导演类获得窗口的大小

	/*CCSprite *pNewNormalItemImg = CCSprite::create("menu.png", CCRectMake(0, 0, 101, 40));
	CCSprite *pNewSelectedItemImg = CCSprite::create("menu.png", CCRectMake(0, 41, 101, 40));
	CCSprite *pNewDisabledItemImg = CCSprite::create("menu.png", CCRectMake(0, 80, 101, 41));
	CCMenuItemSprite *pNewItem = CCMenuItemSprite::create(pNewNormalItemImg, pNewSelectedItemImg, pNewDisabledItemImg, this, menu_selector(HelloWorld::menuCallback));
	pNewItem->setTag(1);

	//仿照第一个菜单项创建
	CCSprite *pOptionNormalItemImg = CCSprite::create("menu.png", CCRectMake(100, 0, 99, 40));
	CCSprite *pOptionSelectedItemImg = CCSprite::create("menu.png", CCRectMake(100, 40, 99, 40));
	CCSprite *pOptionDisabledItemImg = CCSprite::create("menu.png", CCRectMake(100, 80, 99, 40));
	CCMenuItemSprite *pOptionItem = CCMenuItemSprite::create(pOptionNormalItemImg, pOptionSelectedItemImg, pOptionDisabledItemImg, this, menu_selector(HelloWorld::menuCallback));
	pOptionItem->setTag(2);*/

	//仿照第一个菜单项创建
	CCSprite *pAboutNormalItemImg = CCSprite::create("exit1.png", CCRectMake(0, 0, 99, 44));
	CCSprite *pAboutSelectedItemImg = CCSprite::create("exit2.png", CCRectMake(0, 0, 99, 44));
	CCSprite *pAboutDisabledItemImg = CCSprite::create("exit3.png", CCRectMake(0, 0, 99, 44));
	CCMenuItemSprite *pAboutItem = CCMenuItemSprite::create(pAboutNormalItemImg, pAboutSelectedItemImg, pAboutDisabledItemImg, this, menu_selector(HelloWorld::menuCallback));
	pAboutItem->setTag(1);


	CCMenu *pMenu = CCMenu::create(/*pNewItem, pOptionItem */pAboutItem, NULL);
	pMenu->alignItemsVerticallyWithPadding(20);
	pMenu->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 60));
	addChild(pMenu);

	return true;
}
void HelloWorld::menuCallback(CCObject* pSender)
{
	int nTag = ((CCNode *)pSender)->getTag();
	switch (nTag)
	{
	/*case 1:
	{ 
		CCLOG("New Click");
		CCScene *GameLayerScene = HelloWorld::createScene();
		CCDirector::sharedDirector()->replaceScene(GameLayerScene);


	}
	break;*/
	
	case 1:
	{
		CCLOG("About Click");
		Director::getInstance()->end();
	}
	break;
	}
}