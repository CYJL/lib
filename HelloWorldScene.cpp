#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "EndScene.h"
#include "Vector"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 , origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
#if 0
    auto label = Label::create("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    label->enableShadow();
    label->enableOutline(Color4B::MAGENTA,2);
//    label->enableGlow(Color4B::ORANGE);
    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    auto tintTo = TintTo::create(2, Color3B::RED);
    auto delayTime = DelayTime::create(3);
    auto scaleTo = ScaleTo::create(2, 0.6);
    
    
    auto sequence = Sequence::create(scaleTo,delayTime,tintTo,NULL);
    
    sprite->runAction(sequence);
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
#endif
//    回调创建26个字母
//    int i = random(0, 26);
    
    
//    std::stringstream character;
//    character<<random('a', 'z');
//    auto label = Label::createWithTTF(character.str(), "fonts/Marker Felt.ttf", 40);
//    
//    
//    auto location = Director::getInstance()->convertToGL(Point(label->getContentSize().width + i*20, origin.y - label->getContentSize().height));
//    label->setPosition(location);
//    
//    auto glocation = Director::getInstance()->convertToGL(Point(label->getContentSize().width + i*20, origin.y + visibleSize.height));
//    
//    auto moveTo = MoveTo::create(5, glocation);
//    auto place = Place::create(location);
//    
//    auto sequence = Sequence::create(moveTo,place,NULL);
//    
//    label->runAction(sequence);
//    
//    this->addChild(label, 1,label->getString().c_str()-48);
    
    
    
  
//    auto label = Label::createWithTTF(character.str(), "fonts/Marker Felt.ttf", 24);
//    label->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2 ));
//    this->addChild(label,1,101);
//   添加分数显示
    
    
    showScore = Label::createWithTTF ("0","fonts/Marker Felt.ttf",40);
    showScore->setPosition(Point(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2));
    this->addChild(showScore, 1,101);
    
//    添加26个字母
    for(int i = 0;i<26;i++)
    {
        std::stringstream character;
        
        character<<char('a'+i);
        auto label = Label::createWithTTF(character.str(), "fonts/Marker Felt.ttf", 40);
        
        auto location = Point(label->getContentSize().width + i*16, visibleSize.height+label->getContentSize().height);
        label->setPosition(location);
        
//        auto glocation = Director::getInstance()->convertToGL(Point(label->getContentSize().width + i*14, origin.y + visibleSize.height));
        
//        auto moveTo = MoveTo::create(4, glocation);
//        auto place = Place::create(location);
//        
//        auto sequence = Sequence::create(moveTo,place,NULL);
        
//        label->runAction(sequence);
        label->enableGlow(Color4B::GREEN);
        this->addChild(label, 1,i);
        vec.pushBack(label);
        
    }
    
    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateCharater), 0.5);

    this->scheduleUpdate();
//    事件监听键盘、鼠标、加速度（重力传感器）
    auto child_Low = this->getChildByTag(0);

    
    //    键盘监听按键
#if 1
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [this,child_Low](EventKeyboard::KeyCode key,Event* e) mutable {
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
            auto tmp_height = 345;
    
            for(int i = 0; i<26; i++)
            {
                auto location_tmp = Point(this->getChildByTag(i)->getPosition());
                
                if(location_tmp.y < tmp_height)
                {
                    child_Low = this->getChildByTag(i);
                    tmp_height = child_Low->getPosition().y;
                }
            }
        
        
            if(child_Low->getTag() == (int)key - 124)
            {
                
                auto location = Point(child_Low->getPosition().x, visibleSize.height + child_Low->getContentSize().height);
                ParticleSystem* system = ParticleExplosion::create();
                system->setPosition(child_Low->getPosition());
                system->setScale(0.2);
                this->addChild(system,2);
                child_Low->setPosition(location);
                child_Low->stopAllActions();
                
                score += 10;
                if (UserDefault::getInstance()->getIntegerForKey("score") < score)
                {
                    UserDefault::getInstance()->setIntegerForKey("score", score);
                }
                
                
                std::stringstream score_tmp;
                score_tmp<<score;
                showScore->setString(score_tmp.str());
                
            }else
            {
                auto transition = TransitionFade::create(1, EndScene::createScene());
                Director::getInstance()->replaceScene(transition);
            }
            
        
//        else
//        {
////            //                    for (std::vector<Label*>::iterator iter = vec.begin(); iter!= vec.end(); iter ++)
////            //                    {
////            //                        (*iter)->stopAllActions();
////            //                    }
////            auto endScene = EndScene::createScene();
////            Director::getInstance()->pushScene(endScene);
//            
//        }
    
    };
    eventListener->onKeyReleased = [](EventKeyboard::KeyCode key,Event* e){
        CCLOG("Key released: %d",key);
        
    };
    
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
#endif
#if 0
    auto mouse = EventListenerMouse::create();
    
    mouse->onMouseUp = [](EventMouse* event)
    {
        CCLOG("onMouseUp");
        if(event->getMouseButton() == MOUSE_BUTTON_LEFT){
            CCLOG("MOUSE_BUTTON_LEFT");
            
        }else if (event->getMouseButton() == MOUSE_BUTTON_RIGHT){
            CCLOG("MOUSE_BUTTON_RIGHT");
            
        }else if (event->getMouseButton() == MOUSE_BUTTON_MIDDLE){
            CCLOG("MOUSE_BUTTON_MIDDLE");
            
        }
        
    };
    
    mouse->onMouseDown = [](EventMouse* event)
    {
        CCLOG("onMouseDown");
    };
    
    mouse->onMouseMove = [](EventMouse* event)
    {
        CCLOG("onMouseMove");
    };
    
    mouse->onMouseScroll = [](EventMouse* event)
    {
        CCLOG("onMouseScroll");
    };
    
    dispatcher->addEventListenerWithSceneGraphPriority(mouse, this);
    
    auto access = EventListenerAcceleration::create([] (Acceleration *, Event *){
        CCLOG("EventListenerAcceleration callback");
    });
    
   
    dispatcher->addEventListenerWithSceneGraphPriority(access, this);
#endif
    
//    自定义事件监听
#if 0
    auto customEventListener = EventListenerCustom::create("custom_event", [](EventCustom* e){
        CCLOG("costomEventListener CallBack!");
    });
    
    dispatcher->addEventListenerWithSceneGraphPriority(customEventListener, this);
    
    this->scheduleOnce([](float dt){
        auto dispatcer = Director::getInstance()->getEventDispatcher();
        
        dispatcer->dispatchCustomEvent("custom_event",NULL);
        
    }, 2.0f, "schedule_once");
#endif
    
    this->scheduleUpdate();
    
    
    
#if 0
//    动画
    Vector<SpriteFrame*> animaFrames;
    animaFrames.reserve(12);
    animaFrames.pushBack(SpriteFrame::create("Blue_Front1.png", Rect(0,0,65,81)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Front2.png", Rect(0,0,65,81)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Front3.png", Rect(0,0,65,81)));
    
    animaFrames.pushBack(SpriteFrame::create("Blue_Left1.png", Rect(0,0,59,81)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Left2.png", Rect(0,0,59,81)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Left3.png", Rect(0,0,59,81)));
    
    animaFrames.pushBack(SpriteFrame::create("Blue_Back1.png", Rect(0,0,65,82)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Back2.png", Rect(0,0,65,82)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Back3.png", Rect(0,0,65,82)));
    
    animaFrames.pushBack(SpriteFrame::create("Blue_Right1.png", Rect(0,0,59,81)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Right2.png", Rect(0,0,59,81)));
    animaFrames.pushBack(SpriteFrame::create("Blue_Right3.png", Rect(0,0,59,81)));
    
    auto sp = Sprite::create("Blue_Front1.png");
    sp->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sp);

//    Animation
    Animation* ani = Animation::createWithSpriteFrames(animaFrames);
    ani->setDelayPerUnit(0.1f);
//    ani->setLoops(unsighed int loops)
    auto animate = Animate::create(ani);
    
    sp->runAction(RepeatForever::create(animate));
#endif
    
//    Action
//    TintTo   设置精灵颜色
//    DelayTime    在动作中停顿
//    ScaleTo   缩放
    
//    Label 3个 enable
    
//    UI  Button
#if 0
    auto btn = cocos2d::ui::Button::create("res/Button_Normal.png","res/Button_Press.png","res/Button_Disable.png");
    btn->setTitleText("button");
    btn->setTitleFontSize(20);
    btn->setTitleColor(Color3B::BLACK);
    btn->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    btn->addClickEventListener([](Ref*){
        CCLOG("Button Clicked");
    });
    this->addChild(btn);
    
//    UI Slider
    auto slider = cocos2d::ui::Slider::create();
    
    slider->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - btn->getContentSize().height));
    slider->loadBarTexture("res/Slider_Back.png");
    slider->loadSlidBallTextureNormal("res/SliderNode_Normal.png");
    slider->loadProgressBarTexture("res/Slider_PressBar.png");
    slider->addEventListener([](Ref* ref, cocos2d::ui::Slider::EventType e){
        CCLOG("Slider Callback  : %d",static_cast<cocos2d::ui::Slider*>(ref)->getPercent());
    });
    this->addChild(slider);
#endif
//    LoadingBar
#if 0
    auto loadingBar = cocos2d::ui::LoadingBar::create("res/LoadingBarFile.png");
    loadingBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
    loadingBar->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->schedule([loadingBar,this](float){
        static int second = 0;
       
        loadingBar->setPercent(second);
         second += 5;
        
        if (second == 100) {
            this->unschedule("schedule1");
        }
    }, 0.5,"schedule1");
    
    this->addChild(loadingBar,0);
#endif

//    CheckBox
 #if 0
//    auto checkBox = cocos2d::ui::CheckBox::create("res/CheckBox_Normal.png","CheckBoxNode_Normal.png");
    auto checkBox = cocos2d::ui::CheckBox::create("res/CheckBox_Normal.png","res/CheckBox_Press.png","res/CheckBoxNode_Normal.png","res/CheckBox_Disable.png","res/CheckBoxNode_Disable.png");
    checkBox->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
//    checkBox->setEnabled(false);
    
    this->addChild(checkBox);
    checkBox->addEventListener([](Ref*, cocos2d::ui::CheckBox::EventType type){
        if (type == cocos2d::ui::CheckBox::EventType::SELECTED) {
            CCLOG("Check Box is selected");
        }
        else{
            CCLOG("Check Box is Unselected");
        }
    });
    
 
    
#endif
    
    //    TextField
    
#if 1
    auto tf = cocos2d::ui::TextField::create("Please input your email", "fonts/arial.ttf", 18);
    tf->setPosition(Point(visibleSize.width/2,visibleSize.height/2-tf->getContentSize().height));
    tf->setMaxLengthEnabled(true);
    tf->setMaxLength(5);
    this->addChild(tf,2);
#endif
    
    return true;
    
}

void HelloWorld::updateStatus(float dt)
{
//    this->getChildByTag(dt);
    
}

void HelloWorld::update(float dt)
{
//    auto showScore = this->getChildByTag(101);
//    showScore->setString();
}

void HelloWorld::updateCharater(float delta)
{
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//    auto random = this->getChildByTag(2);
    auto random = this->getChildren().getRandomObject();
    auto location_tmp = Point(random->getPosition());
//    int i = random(0, 26);
//    std::stringstream character;
//    character<<random('a', 'z');
//    auto label = Label::createWithTTF(character.str(), "fonts/Marker Felt.ttf", 40);
     if(location_tmp.y ==  visibleSize.height + random->getContentSize().height){
//         random->setColor(Color3B::WHITE);
         auto location = Point(location_tmp.x, visibleSize.height + random->getContentSize().height);
    
         auto glocation = Point(location_tmp.x, -random->getContentSize().height);
    
         auto moveTo = MoveTo::create(3, glocation);
         auto place = Place::create(location);
    
         auto sequence = Sequence::create(moveTo,place,NULL);
         
         random->runAction(sequence);
     }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
