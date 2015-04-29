//
//  GameAboutLayer.cpp
//  protectMonk
//
//  Created by Freedom on 15/4/24.
//
//

#include "GameAboutLayer.h"
#include "GameStartScene.h"

 bool GameAboutLayer::init()
{
    if(!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }


    log("gameAboutLayer");
    //显示关于游戏帮助界面
    auto size=Director::getInstance()->getVisibleSize();
    auto aboutBG=Sprite::create("helpBG.png");
    aboutBG->setPosition(Vec2(size.width/2,size.height/2));
    this->addChild(aboutBG);
    
    auto normalSprite=Sprite::createWithSpriteFrameName("gameBack.png");
     normalSprite->setScale(0.3);
    auto selectSprite=Sprite::createWithSpriteFrameName("gameBack.png");
    selectSprite->setScale(0.4);
   
    //返回菜单
    auto backMenuItem=MenuItemSprite::create(
                                             normalSprite,selectSprite,
                                             CC_CALLBACK_1(GameAboutLayer::menuItemCallBack, this));
    backMenuItem->setPosition(Vec2(size.width*0.9,size.height*0.2));
    auto menu=Menu::create(backMenuItem,nullptr);
    menu->setPosition(Vec2::ZERO);
    menu->setAnchorPoint(Vec2::ZERO);
    this->addChild(menu);
    
    return true;
}
  Scene * GameAboutLayer::createScene()
{
    auto scene=Scene::create();
    auto  layer=GameAboutLayer::create();
    scene->addChild(layer);
    return scene;
}
 void GameAboutLayer::menuItemCallBack(Ref * pSender)
{
    //返回主界面
      Director::getInstance()->replaceScene(TransitionFadeBL::create(1, GameStartScene::createScene()));
}