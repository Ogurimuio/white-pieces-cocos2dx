#pragma once
#ifndef __StartMenu_H__
#define __StartMenu_H__

#include "cocos2d.h"


USING_NS_CC;
class StartMenu :/*public cocos2d::CCLayer, */public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	static cocos2d::CCScene *scene();//�����˵�����
	virtual bool init();//��ʼ���˵���ĳ�Ա����
	void menuCallback(CCObject *pSender);//�ص�����������ڵ���˵����ʱ����õ��ص����ƣ����øú���
	CREATE_FUNC(StartMenu);//�Զ��ͷ��ڴ�ĺ���

private:

};
#endif // !__StartMenu_H__


//1.#ifndef __StartMenu_H__��#define __StartMenu_H__������������޷Ǿ��Ƿ�ֹͷ�ļ����ظ������ͱ���
//2.�麯������virtual�����þ���Ϊ�������������������������ģ�
//�Ӷ��Ի����ͬ������������д�����������ڻ���ģ����������ָ����øú����Ͳ�����Ϊͬ�����õ�����ĺ���ȥ��
//���ǵ���������ĺ���
//�麯���ĳ�����Ϊ����������һ��C++��̬�Ļ���

//��Ԫ���� ���캯�� static��̬���� ������virtual�ؼ������Σ�
//��ͨ��Ա���� ���������� ������virtual�ؼ������Σ�