//
//  RopePhysics.h
//  HelloProject
//
//  Created by Freedom on 15/5/3.
//
//

#ifndef __HelloProject__RopePhysics__
#define __HelloProject__RopePhysics__

#include "cocos2d.h"
USING_NS_CC;
class RopePhysics :public Layer{
    
    
public:
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(RopePhysics);
    void setPhyWorld(PhysicsWorld* world);
    void  onEnter();
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
private:
    PhysicsWorld* m_world;
    Size size;
    Sprite* sprite;
};

#endif /* defined(__HelloProject__RopePhysics__) */
