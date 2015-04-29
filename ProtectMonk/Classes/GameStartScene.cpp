//
//  GameStartScene.cpp
//  protectMonk
//
//  Created by Freedom on 15/4/24.
//
//

#include "GameStartScene.h"
#include "GameAboutLayer.h"
#include "GameScene.h"

 bool GameStartScene::init()
{
    if(!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
  

    log("GameStartScene");
    
    auto size=Director::getInstance()->getVisibleSize();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameResouce.plist");
    
    this->initUI(size);

    return true;
}
Scene * GameStartScene::createScene()
{
    auto scene=Scene::create();
     auto  layer=GameStartScene::create();
    scene->addChild(layer);
    return scene;
}
void GameStartScene::initUI(Size size)
{
    
    //显示游戏小人物
    auto gameSmallPlayer=Sprite::createWithSpriteFrameName("StartBG.png");
    gameSmallPlayer->setPosition(Vec2::ZERO);
    gameSmallPlayer->setAnchorPoint(Vec2::ZERO);
   this->addChild(gameSmallPlayer);
    
    //显示游戏菜单
    auto action1=ScaleBy::create(1, 1.1);
    auto action2=action1->clone()->reverse();
    auto startSprite=Sprite::createWithSpriteFrameName("startGameMenu.png");
    startSprite->runAction(RepeatForever::create(Sequence::create(action1,
                                                                 action2,
                                                                  nullptr)));
   
    auto action_1=ScaleBy::create(1, 1.1);
    auto action_2=action_1->reverse();
    auto aboutSprite=Sprite::createWithSpriteFrameName("aboutMenu.png");
    aboutSprite->runAction(RepeatForever::create(Sequence::create(action_1,
                                                                  action_2,
                                                                  nullptr)));

   
    auto startMenuItem=MenuItemSprite::create(startSprite, startSprite,CC_CALLBACK_1(GameStartScene::menuCallBack,this));
    startMenuItem->setTag(1);
     startMenuItem->setPosition(Vec2(size.width*0.7,size.height*0.8));
     auto aboutMenuItem=MenuItemSprite::create(aboutSprite, aboutSprite,CC_CALLBACK_1(GameStartScene::menuCallBack,this));
     aboutMenuItem->setTag(2);
        aboutMenuItem->setPosition(Vec2(size.width*0.7,size.height*0.7));
    auto menu=Menu::create(startMenuItem,aboutMenuItem,nullptr);
    menu->setPosition(Vec2::ZERO);
    menu->setAnchorPoint(Vec2::ZERO);
    this->addChild(menu);

}
//菜单切换
void GameStartScene::menuCallBack(Ref* pSender)
{
    log("menuCallBack");
    MenuItem * menuItem=static_cast<MenuItem*>(pSender);
    switch (menuItem->getTag()) {
        case 1:
            //跳转到游戏界面
            Director::getInstance()->replaceScene(TransitionFadeBL::create(1, GameScene::create()));
            break;
            
        case 2:
            //跳转到关于界面
            Director::getInstance()->replaceScene(TransitionFadeBL::create(1, GameAboutLayer::createScene()));
            break;
        default:break;
    }
}