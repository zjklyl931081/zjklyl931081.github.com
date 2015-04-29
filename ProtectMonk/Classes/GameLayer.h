//
//  GameLayer.h
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#ifndef __protectMonk__GameLayer__
#define __protectMonk__GameLayer__

#include "cocos2d.h"
#include "Hammer.h"
USING_NS_CC;
class GameLayer:public Layer {
    
    
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);
    void createSmallMonk();//添加小和尚
    void createHammer(float t);//添加锤子
    void update(float t);

private:
    Size size;
    Vector<Hammer*>hammerVector;
    Vector<Sprite*>monkVector;
    //锤子可下落的三个点
    Point hammerPoint[3];
    int num;//接受随机数
    bool isClick;//
};

#endif /* defined(__protectMonk__GameLayer__) */
