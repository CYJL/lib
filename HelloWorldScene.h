#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    int score = 0;
    
    Label* showScore;
    
    
    bool lose = false;
    
    virtual bool init();
    
    Vector<Label*> vec;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void update(float dt);

    void updateCharater(float delta);

    void transition(float dt);

    void updateStatus(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
