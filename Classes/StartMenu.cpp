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
	/*����if (!CCLayer::init())
	{
	return false;
	}*/

	CCDirector *pDirector = CCDirector::sharedDirector();  //����һ�������࣬��������������������Ҫ�ı��������細�ڴ�С

	CCSize winSize = pDirector->getWinSize();//ͨ���������ô��ڵĴ�С

	CCSprite *pLoadingImg = CCSprite::create("loading.png"); //����һ�������࣬�����һ�ű���ͼƬ
	pLoadingImg->setPosition(ccp(winSize.width / 2, winSize.height / 2));//ͼƬ����������
	this->addChild(pLoadingImg);//�������ͼƬ

								//�����˵�ѡ��
								//��������Ĵ���һ��Logoͼ������ͼƬ��ê�㣬һ���Ž���������
	CCSprite *pLogoImg = CCSprite::create("logo.png");

	pLogoImg->setAnchorPoint(ccp(0.5, 1));

	pLogoImg->setPosition(ccp(winSize.width / 2, winSize.height - 20));
	this->addChild(pLogoImg);

	//��ӱ�������
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menu_music.mp3", true);

	//�����˵���ķ��������е㸴�ӣ�����˼·������
	//1.����ͬ����CCSprite����һ���˵��������������������ʹ������״̬��ͼƬ�������и�CCRectMake�ǣ�0��0����ʾ��ͼ���0��0�����Ͻǣ�
	//�㿪ʼ����126��33����ʾ��ȡһ������ͼ���еĿ�126����33�Ĳ���ͼ��
	//��ô���и��ܼ򵥵�ԭ������������ʱ�����ǰѶ���ͼ����һ�����ϳ�һ��ͼ������̫���ͼƬ��Դ���»��ҡ�
	//2.������CCMenuItemSprite����һ���˵��Ȼ������ֲ�ͬ��״̬�ӽ�ȥ
	//3.�����и�Menu_selector(StartMenu:menuCallback);������ʾ�˵�������ʱ�����Ӧ�¼���ͨ�����л�������
	//4.���Ҫ��������һ���ڵ��־setTag()������ʶ�����ĸ��˵������
	//����һ���˵������ϣ����������˵����������ƴ�������
	CCSprite *pNewNormalItemImg = CCSprite::create("menu.png", CCRectMake(0, 0, 101, 40));
	CCSprite *pNewSelectedItemImg = CCSprite::create("menu.png", CCRectMake(0, 41, 101, 40));
	CCSprite *pNewDisabledItemImg = CCSprite::create("menu.png", CCRectMake(0, 80, 101, 41));
	CCMenuItemSprite *pNewItem = CCMenuItemSprite::create(pNewNormalItemImg, pNewSelectedItemImg, pNewDisabledItemImg, this, menu_selector(StartMenu::menuCallback));
	pNewItem->setTag(1);

	//���յ�һ���˵����
	CCSprite *pOptionNormalItemImg = CCSprite::create("menu.png", CCRectMake(100, 0, 99, 40));
	CCSprite *pOptionSelectedItemImg = CCSprite::create("menu.png", CCRectMake(100, 40, 99, 40));
	CCSprite *pOptionDisabledItemImg = CCSprite::create("menu.png", CCRectMake(100, 80, 99, 40));
	CCMenuItemSprite *pOptionItem = CCMenuItemSprite::create(pOptionNormalItemImg, pOptionSelectedItemImg, pOptionDisabledItemImg, this, menu_selector(StartMenu::menuCallback));
	pOptionItem->setTag(2);

	//���յ�һ���˵����
	CCSprite *pAboutNormalItemImg = CCSprite::create("menu.png", CCRectMake(198, 0, 99, 40));
	CCSprite *pAboutSelectedItemImg = CCSprite::create("menu.png", CCRectMake(198, 40, 99, 40));
	CCSprite *pAboutDisabledItemImg = CCSprite::create("menu.png", CCRectMake(198, 80, 99, 40));
	CCMenuItemSprite *pAboutItem = CCMenuItemSprite::create(pAboutNormalItemImg, pAboutSelectedItemImg, pAboutDisabledItemImg, this, menu_selector(StartMenu::menuCallback));
	pAboutItem->setTag(3);

	//�����˵�������֮�󣬾�Ҫ�����Ǻϲ���һ���˵���
	//��CCMenu ����һ���˵��������˵��������ȥ
	//����ÿ���˵���֮��ľ�����30:alignItemsVerticallyWithPadding(20);
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
		//ֹͣ�˵�����
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		//������Ϸ����
		SimpleAudioEngine::sharedEngine()->playEffect("game_music.mp3", true);

		//������Ϸ����
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








//1.�˵���һ������������Ҫ��һ��������������Դ���Ų�
//2.��������cocos2d�кܳ���������һ��ͼƬ������һ��������CCSprite
//3.���ͼƬ������this->addChild();