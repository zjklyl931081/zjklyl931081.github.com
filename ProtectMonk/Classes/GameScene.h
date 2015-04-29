//
//  GameScene.h
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//      游戏主场景，负责游戏逻辑的判断，显示玩家人物
//

#ifndef __protectMonk__GameScene__
#define __protectMonk__GameScene__

#include "cocos2d.h"
USING_NS_CC;
class GameScene :public Scene{
    
    
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(GameScene);
    
    
};

#endif /* defined(__protectMonk__GameScene__) */
