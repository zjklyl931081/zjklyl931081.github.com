//
//  Hammer.cpp
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#include "Hammer.h"
#include "GameStateLayer.h"
#include "GameLayer.h"
Hammer* Hammer::createHammer(int type)
{
    Hammer *pRet = new(std::nothrow) Hammer();
    if (pRet && pRet->init(type))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
bool Hammer::init(int type)
{
    if(!Sprite::init())
    {
        return false;
    }
    log("hammer");
    
    size=Director::getInstance()->getVisibleSize();
    
    switch (type) {
        case 1:
           
        {
             hammer=Sprite::createWithSpriteFrameName("smallhammer.png");
            this->addChild(hammer,1);

        }
        break;
        case 2:
            break;
            
    }
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=CC_CALLBACK_2(Hammer::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,hammer);
      return true;
}
 //锤子飞入到指定位置后产生回调
void Hammer::floatHammer(float time,Point endPoint)
{
 
    
    this->runAction(RepeatForever::create( RotateBy::create(0.1, 90)));
    this->runAction(Sequence::create(MoveTo::create(time, Vec2(endPoint)),
                                     MoveTo::create(3, Vec2(endPoint.x,-(this->getContentSize().height+50))), nullptr));
}
bool Hammer::onTouchBegan(Touch *touch, Event *unused_event)
{
    log("touchbagen");
    
    
    auto target=unused_event->getCurrentTarget();//获取当前事件的接受者
    auto pos=this->convertTouchToNodeSpace(touch);//讲触摸点转换为本地坐标系
    if(target->getBoundingBox().containsPoint(pos))
    {
        
        //加分
        NotificationCenter::getInstance()->postNotification("score",(Ref*)(target));

        
           //点击中移除
        this->removeFromParent();
        
        return true;
    }
    return false;
    
}
 