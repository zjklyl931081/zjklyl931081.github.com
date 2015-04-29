//
//  GameAboutLayer.h
//  protectMonk
//
//  Created by Freedom on 15/4/24.
//
//此类用于负责处理游戏的关于界面，包含一个图片，一个返回到主菜单的按钮菜单
//

#ifndef __protectMonk__GameAboutLayer__
#define __protectMonk__GameAboutLayer__

#include "cocos2d.h"
USING_NS_CC;
class GameAboutLayer:public LayerColor {
    
    
public:
    
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(GameAboutLayer);
    void menuItemCallBack(Ref * pSender);
};

#endif /* defined(__protectMonk__GameAboutLayer__) */
