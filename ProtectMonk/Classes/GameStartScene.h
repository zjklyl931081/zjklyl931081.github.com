//
//  GameStartScene.h
//  protectMonk
//
//  Created by Freedom on 15/4/24.
//          APP进如到这个场景，主要负责现实游戏菜单，游戏背景，各个菜单选项的切换
//

#ifndef __protectMonk__GameStartScene__
#define __protectMonk__GameStartScene__

#include "cocos2d.h"
USING_NS_CC;
class GameStartScene:public LayerColor {
    
    
public:
    
    virtual bool init();
    static Scene * createScene();
    void initUI(Size size);//初始化UI
    void menuCallBack(Ref* pSender);//菜单切换
    CREATE_FUNC(GameStartScene);

};

#endif /* defined(__protectMonk__GameStartScene__) */
