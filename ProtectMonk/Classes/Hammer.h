//
//  Hammer.h
//  protectMonk
//
//  Created by Freedom on 15/4/25.
//
//

#ifndef __protectMonk__Hammer__
#define __protectMonk__Hammer__

#include "cocos2d.h"
USING_NS_CC;
class Hammer:public Sprite {
    
    
public:
    virtual bool init(int type);
    static Hammer* createHammer(int type);
    //锤子飞入到指定位置后产生回调
    void floatHammer(float time,Point endPoint);
     virtual bool onTouchBegan(Touch *touch, Event *unused_event);
private:
    Size size;
    Sprite* hammer;
};

#endif /* defined(__protectMonk__Hammer__) */
