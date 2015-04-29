//
//  GameScene.cpp
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#include "GameScene.h"
#include "GameStateLayer.h"
#include "GameLayer.h"
bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    log("gamescene");
    //加入游戏状态层
   this->addChild(GameStateLayer::create());
    
    //加入游戏层
    this->addChild(GameLayer::create());
    
    return true;
}
Scene* GameScene::createScene()
{
    auto scene=Scene::create();
    auto  layer=GameScene::create();
    scene->addChild(layer);
    return scene;
}

