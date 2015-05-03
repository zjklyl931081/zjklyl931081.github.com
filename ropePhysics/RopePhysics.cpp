//
//  RopePhysics.cpp
//  HelloProject
//
//  Created by Freedom on 15/5/3.
//
//

#include "RopePhysics.h"
bool RopePhysics::init()
{
    if(!Layer::init())
    {
        return false;
    }
    log("ropephyscis");
     size=Director::getInstance()->getVisibleSize();
    

  

 
    
    auto lis=EventListenerTouchOneByOne::create();
    lis->onTouchBegan=CC_CALLBACK_2(RopePhysics::onTouchBegan , this);
      lis->onTouchMoved=CC_CALLBACK_2(RopePhysics::onTouchMoved , this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis,this);
    return true;
    
}
void RopePhysics::setPhyWorld(PhysicsWorld* world)
{
    this->m_world=world;
}
Scene * RopePhysics::createScene()
{
    auto scene=Scene::createWithPhysics();
    
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_JOINT);
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer=RopePhysics::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
    
}
void  RopePhysics::onEnter()
{
    Layer::onEnter();
    auto physicsBody=PhysicsBody::createEdgeBox(Size(size.width , size.height ),PHYSICSBODY_MATERIAL_DEFAULT,3);
    auto node=Node::create();
    node->setPosition(Vec2(size.width/2,size.height/2));
    node->setPhysicsBody(physicsBody);
    this->addChild(node);
    
     sprite=Sprite::create();
    sprite->setContentSize(Size(30,30));
    auto staticPhysicsBody =PhysicsBody::createCircle(20);
    staticPhysicsBody->setDynamic(false);
    sprite->setPhysicsBody(staticPhysicsBody);

    sprite->cocos2d::Node::setPosition(Vec2(size.width/2,size.height-10));
    this->addChild(sprite);
   
    Sprite* _sp2=nullptr;
    PhysicsBody* pby2=nullptr;
    for(int i=9;i>0;i--)
    {
         _sp2 = Sprite::create();
         pby2 = PhysicsBody::createCircle(20);
        pby2->setMass(100);
        pby2->setRotationEnable(false);
        _sp2->setPhysicsBody(pby2);
        _sp2->setPosition(Vec2(sprite->getPositionX(),size.height*i*0.1));
        _sp2->setTag(i);
        this->addChild(_sp2);
        auto physicsJoint=PhysicsJointDistance::construct(_sp2->getPhysicsBody(), sprite->getPhysicsBody(), Point::ZERO,Point::ZERO);
        this->m_world->addJoint(physicsJoint);
        
        sprite=_sp2;

    }
    

   

   
}
   bool RopePhysics::onTouchBegan(Touch *touch, Event *unused_event)
{
    log("ontouchmover");
    return true;
}
void RopePhysics::onTouchMoved(Touch *touch, Event *unused_event)
{
    auto sp_1=this->getChildByTag(1);
     auto sp_2=this->getChildByTag(2);
     auto sp_3=this->getChildByTag(3);
    sp_3->getPhysicsBody()->applyImpulse(Vect(200,10));
    sp_2->getPhysicsBody()->applyImpulse(Vect(300,10));
    sp_1->getPhysicsBody()->applyImpulse(Vect(400,10));

}

