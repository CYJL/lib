#include "EndScene.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
Scene* EndScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EndScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EndScene::init()
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
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(EndScene::menuCloseCallback, this));
//    
//	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    auto label = Label::createWithBMFont("fonts/myfont.fnt", "HelloWorld!");
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//    
//    label->setBMFontSize(42);
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto btn = cocos2d::ui::Button::create("res/Button_Normal.png","res/Button_Press.png","res/Button_Disable.png");
    
    auto score1 = UserDefault::getInstance()->getIntegerForKey("score");
    std::stringstream score_;
    score_<<score1;
    auto label = Label::createWithTTF(score_.str(), "fonts/Marker Felt.ttf",40);
    label->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + btn->getContentSize().height));
    
    this->addChild(label, 2);
    
    auto show = Label::createWithTTF("Your best score is", "fonts/Marker Felt.ttf",40);
    show->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + btn->getContentSize().height*1.5));
    
    this->addChild(show, 2);
    
    
    btn->setTitleText("Start again");
    btn->setTitleFontSize(20);
    btn->setTitleColor(Color3B::BLACK);
    btn->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    btn->addClickEventListener([this](Ref*){
        Director::getInstance()->replaceScene(HelloWorld::createScene());
    });
    this->addChild(btn);
    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
//    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/sprites.plist");
//    auto texture = Director::getInstance()->getTextureCache()->addImage("res/sprites.pvr.ccz");
//    auto batchNode = SpriteBatchNode::createWithTexture(texture);
//    this->addChild(batchNode);
//    
//    auto sprite1 = Sprite::createWithSpriteFrameName("spider-hd.png");
//    sprite1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    this->addChild(sprite1);
    
    
    
//    进度条
#if 0
    auto pt = ProgressTimer::create(sprite);
    pt->setType(ProgressTimer::Type::BAR);
    pt->setPercentage(0);
    pt->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pt,1,101);
    
    this->scheduleUpdate();
       return true;
#endif
////    构造单按键监听类
//    auto listener = EventListenerTouchOneByOne::create();
////    设置按键回调函数
//    listener->onTouchBegan = CC_CALLBACK_2(EndScene::onTouchBegan, this);
//    listener->onTouchMoved = CC_CALLBACK_2(EndScene::onTouchMoved, this);
//    listener->onTouchEnded = CC_CALLBACK_2(EndScene::onTouchEnded, this);
//
////设置按键是否穿透监听
//    listener->setSwallowTouches(true);
//    
//    auto dispatcher = Director::getInstance()->getEventDispatcher();
//    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//    
////    轨迹动画 MotionStreak
//    auto streak = MotionStreak::create(1, 1, 32, Color3B::GREEN, "HelloWorld.png");
//    this->addChild(streak,1,101);
    
//
    
    return true;
}
//
//bool EndScene::onTouchBegan(Touch* t, Event* e)
//{
//    auto location = t->getLocationInView();
//    
//    auto glocation = Director::getInstance()->convertToGL(location);
//    auto streak = this->getChildByTag(101);
//    streak->setPosition(glocation);
//    
//    return true;
//}
//
//void EndScene::onTouchMoved(Touch* t, Event* e)
//{
//    auto location = t->getLocationInView();
//    
//    auto glocation = Director::getInstance()->convertToGL(location);
//    auto streak = this->getChildByTag(101);
//    streak->setPosition(glocation);
//}
//
//void EndScene::onTouchEnded(Touch* t, Event* e)
//{
//    
//}
//
//void EndScene::update(float dt)
//{
//    ProgressTimer* timer = (ProgressTimer*)this->getChildByTag(101);
//    timer->setPercentage(timer->getPercentage() + dt * 10);
//    if (timer->getPercentage() >= 100) {
//        timer->setPercentage(0);
//        
//    }
//}

//void HelloWorld::

void EndScene::menuCloseCallback(Ref* pSender)
{
//    Director::getInstance()->end();
    
    
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
