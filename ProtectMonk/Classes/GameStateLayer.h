//
//  GameStateLayer.h
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#ifndef __protectMonk__GameStateLayer__
#define __protectMonk__GameStateLayer__

#include "cocos2d.h"
USING_NS_CC;
class GameStateLayer :public Layer{
    
    
public:
    
    virtual bool init();
    CREATE_FUNC(GameStateLayer);
private:
   void updateScore(Ref * pSender);
    void updateStar(Ref* pSender);
    int Score;
    int num;//用来记录星星的移除
};

#endif /* defined(__protectMonk__GameStateLayer__) */
