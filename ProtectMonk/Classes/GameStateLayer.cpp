//
//  GameStateLayer.cpp
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#include "GameStateLayer.h"
#include "GameStartScene.h"
#include "Hammer.h"
bool GameStateLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    log("gamestatelayer");
    auto size=Director::getInstance()->getVisibleSize();

    //做数据初始化
    this->Score=0;
    this->num=4;
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameStateLayer::updateScore), "score", nullptr);
     NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameStateLayer::updateStar), "star", (Ref*)(this->num));
 
    //游戏场景
    auto gameBG=Sprite::createWithSpriteFrameName("sky.png");
    gameBG->setPosition(Vec2::ZERO);
    gameBG->setAnchorPoint(Vec2::ZERO);
    this->addChild(gameBG,-1);

    //墙体
    auto wallBG=Sprite::createWithSpriteFrameName("wall.png");
    wallBG->setPosition(Vec2::ZERO);
    wallBG->setAnchorPoint(Vec2::ZERO);
    this->addChild(wallBG);
    
    //心型
    for(int i=0;i<4;i++)
    {
        auto heartSprite=Sprite::createWithSpriteFrameName("heart.png");
        heartSprite->setPosition(Vec2((i+1)*(size.width*0.1),size.height*0.9));
        heartSprite->setTag(i);//打标签。
        this->addChild(heartSprite);
    }
    
    //击中锤子个数
    auto scoreLabel=Label::createWithSystemFont("分数:", "",30 );
    scoreLabel->setPosition(Vec2(size.width*0.8,size.height*0.9));
    this->addChild(scoreLabel);
    Label* hanmerNumber=Label::createWithTTF("0","fonts/arial.ttf",50);
    hanmerNumber->setPosition(Vec2(size.width*0.9,size.height*0.9));
    hanmerNumber->setTag(5);
    hanmerNumber->enableShadow(Color4B::GREEN, Size(2, 2)); //阴影
//    hanmerNumber->enableOutline(Color4B::RED, 3);             //轮廓
    hanmerNumber->enableGlow(Color4B::GREEN);//发荧光
    this->addChild(hanmerNumber,2);

    return true;
}
//增加分数
void GameStateLayer::updateScore(Ref * pSender)
{
    log("addScore");
    

    auto lb=static_cast<Label*>(this->getChildByTag(5));
    this->Score+=10;
     lb->setString(StringUtils::format("%d",this->Score));
    
     //添加加分图
         auto addScore=Sprite::createWithSpriteFrameName("ten.png");
        addScore->setPosition(Vec2(lb->getPositionX(),lb->getPositionY()-30));
        this->addChild(addScore);
        addScore->runAction(Sequence::create(MoveBy::create(1, Vec2(0,10)),
                                             CallFunc::create([=](){
            addScore->removeFromParent();
        }),nullptr));
    
}
//移除一个星星
  void GameStateLayer::updateStar(Ref* pSender)
{
      this->num--;//此时第一次调用num--为3,标记的最后一个元素也是从3开始

    log("Removeheart");

    if(this->num<0)
    {
        log("gameOver");
       //移除监听
        NotificationCenter::getInstance()->removeAllObservers(this);
        auto size=Director::getInstance()->getVisibleSize();
        this->setOpacity(40);
        auto label=Label::createWithTTF ("Oh!,You are Lose", "fonts/arial.ttf", 40);
          label->enableOutline(Color4B::RED, 3);;             //轮廓
        label->runAction(Sequence::create(FadeOut::create(3),
                                          CallFunc::create([=](){
            label->removeFromParent();
            Director::getInstance()->replaceScene(TransitionFadeBL::create(1, GameStartScene::createScene()));
        }), NULL));
        
    

        label->setPosition(size.width/2,size.height/2);
        this->addChild(label);
        return ;
    }
    auto heart=static_cast<Sprite*>(this->getChildByTag(this->num));
    heart->removeFromParent();
}
