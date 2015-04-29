//
//  GameLayer.cpp
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#include "GameLayer.h"
#include <random>
std::uniform_int_distribution<int>u(1,3);
std::default_random_engine e;

bool GameLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    log("gamelayer");
    size=Director::getInstance()->getVisibleSize();
    this->isClick=false;
    //显示小和尚
    this->createSmallMonk();
    
    //加入锤子
    this->schedule(schedule_selector(GameLayer::createHammer), 1.2);

    //计划任务做检测处理
    this->scheduleUpdate();

    return true;
}

void GameLayer::createSmallMonk()//添加小和尚
{
    for (int i=1; i<4; i++)
    {
        auto monkSprite=Sprite::createWithSpriteFrameName(StringUtils::format("monk_0%d.png",i));
        monkSprite->setPosition(Vec2(size.width*(2*i+i)*0.1-monkSprite->getContentSize().width,monkSprite->getContentSize().height));
        this->addChild(monkSprite,1);
        hammerPoint[i-1]=Point(size.width*(2*i+i)*0.1-monkSprite->getContentSize().width,size.height*0.8);
        monkVector.pushBack(monkSprite);
    }
}
void GameLayer::createHammer(float t)//添加锤子
{
    this->num=u(e);
    Hammer * hammer=Hammer::createHammer(1);
    //锤子的位置分为左中右三个位置
    switch (this->num) {
        case 1:
        {
          
            hammer->setPosition(Vec2(size.width+hammer->getContentSize().width,size.height/2));
        
            hammer->floatHammer(0.5,  hammerPoint[0]);
        }
            break;
            
        case 2:
            
        {
            hammer->setPosition(Vec2(-hammer->getContentSize().width,size.height/2));
            hammer->floatHammer(0.5,  hammerPoint[2]);
        }
            break;
        case 3:
        {
            hammer->setPosition(Vec2(size.width/2,size.height+hammer->getContentSize().height));
            hammer->floatHammer(0.5,  hammerPoint[1]);
        }
            break;
    }
   
    this->addChild(hammer);
    hammerVector.pushBack(hammer);
    this->isClick=true;
}

void GameLayer::update(float t)
{
    
    for (int i=0;i<this->hammerVector.size();i++ )
    {
      auto hammer=dynamic_cast<Hammer*>(this->hammerVector.at(i));
      if(hammer!=nullptr)
      {
          for (auto &monk:this->monkVector) {
              if(monk->getBoundingBox().intersectsRect(hammer->getBoundingBox()))
              {
                  hammer->removeFromParent();
                  this->hammerVector.eraseObject(hammer);
                  NotificationCenter::getInstance()->postNotification("star",nullptr);
                  return;
              }
              
          }

          //对超出屏幕的锤子进行移除
          if(hammer->getPositionY()<-(hammer->getContentSize().height)||hammer->getPositionX()<0||hammer->getPositionX()>size.width)
          {
              //移除
              hammer->removeFromParent();
              this->hammerVector.eraseObject(hammer);
          }
      }

    }
}

