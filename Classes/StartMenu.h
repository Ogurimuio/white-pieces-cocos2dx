#pragma once
#ifndef __StartMenu_H__
#define __StartMenu_H__

#include "cocos2d.h"


USING_NS_CC;
class StartMenu :/*public cocos2d::CCLayer, */public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	static cocos2d::CCScene *scene();//创建菜单场景
	virtual bool init();//初始化菜单类的成员变量
	void menuCallback(CCObject *pSender);//回调函数，这个在点击菜单项的时候会用到回调机制，调用该函数
	CREATE_FUNC(StartMenu);//自动释放内存的函数

private:

};
#endif // !__StartMenu_H__


//1.#ifndef __StartMenu_H__，#define __StartMenu_H__关于这个作用无非就是防止头文件的重复包含和编译
//2.虚函数机制virtual的作用就是为了声明这个函数是属于派生类的，
//从而对基类的同名函数进行重写，而不是属于基类的，这样基类的指针调用该函数就不会因为同名调用到基类的函数去，
//而是调用派生类的函数
//虚函数的出现是为了体现这样一种C++多态的机制

//友元函数 构造函数 static静态函数 不能用virtual关键字修饰；
//普通成员函数 和析构函数 可以用virtual关键字修饰；