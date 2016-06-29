#ifndef __ENDSCENE_H__
#define __ENDSCENE_H__
USING_NS_CC;
#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
//    void update(float dt);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
//    bool onTouchBegan(Touch* t, Event* e);
//   
//    
//    void onTouchMoved(Touch* t, Event* e);
//    
//    void onTouchEnded(Touch* t, Event* e);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif // __HELLOWORLD_SCENE_H__
