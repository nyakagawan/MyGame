
#include "TestUnit.h"

USING_NS_CC;

TestUnit* TestUnit::create(void) {
    TestUnit* pUnit = new TestUnit();
    pUnit->init();
    return pUnit;
}

bool TestUnit::init(void) {
    if(!Node::init()) {
        return false;
    }
    initSprite();
    scheduleUpdate();
    
    _moveDirX = 1.f;
    _moveDirY = -1.f;
    
    auto s = Director::getInstance()->getWinSize();
//    setPosition( Point( s.width/2-16, s.height/2) );
    setPosition( Point( 0, s.height ) );
    return true;
}

void TestUnit::initSprite(void) {
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("majo.plist", "majo.png");
    
    auto s = Director::getInstance()->getWinSize();
    auto sprite = Sprite::createWithSpriteFrameName("majo_01.png");
    auto sprSize = sprite->getContentSize();
    sprite->setPosition( Point( -(sprSize.width/2), -(sprSize.height/2) ) );
    
    auto spritebatch = SpriteBatchNode::create("majo.png");
    spritebatch->addChild(sprite);
    addChild(spritebatch);
    
    Vector<SpriteFrame*> animFrames(3);
    
    char str[100] = {0};
    for(int i = 1; i < 3; i++)
    {
        sprintf(str, "majo_%02d.png", i);
        auto frame = cache->getSpriteFrameByName( str );
        animFrames.pushBack(frame);
    }
    
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
    sprite->runAction( RepeatForever::create( Animate::create(animation) ) );
}


void TestUnit::update(float delta) {
    Node::update(delta);

    auto visSize = Director::getInstance()->getVisibleSize();
    auto visOrg = Director::getInstance()->getVisibleOrigin();
    auto visibleRect = Rect(visOrg.x,
                            visOrg.y,
                            visOrg.x + visSize.width,
                            visOrg.y + visSize.height
                            );
    
    auto pos = getPosition();
    
    const float kAccelerationX = 50.f;
    const float kAccelerationY = 50.f;
    const float kVelocityLimitX = 150.f;
    const float kVelocityLimitY = 150.f;
    const float kGravity = -10.f;
    
    _velocityX += (kAccelerationX*delta) * _moveDirX;
    _velocityY += (kAccelerationY*delta) * _moveDirY + (kGravity*delta);

    if( abs(_velocityX)>kVelocityLimitX ) {
        _velocityX = kVelocityLimitX * (_velocityX/abs(_velocityX));
    }
    if( abs(_velocityY)>kVelocityLimitY ) {
        _velocityY = kVelocityLimitY * (_velocityY/abs(_velocityY));
    }
    
    pos.x += _velocityX*delta;
    pos.y += _velocityY*delta;
    
    if( pos.x>visibleRect.getMaxX()) {
        DPRINT("overthrough max x");
        pos.x = visibleRect.getMaxX();
        _moveDirX = -_moveDirX;
        _velocityX = -_velocityX;
    }
    if( pos.x<visibleRect.getMinX()) {
        DPRINT("overthrough min x");
        pos.x = visibleRect.getMinX();
        _moveDirX = -_moveDirX;
        _velocityX = -_velocityX;
    }
    if( pos.y>visibleRect.getMaxY()) {
        DPRINT("overthrough man y");
        pos.y = visibleRect.getMaxY();
        _moveDirY = -_moveDirY;
        _velocityY = -_velocityY;
    }
    if( pos.y<visibleRect.getMinY()) {
        DPRINT("overthrough min y");
        pos.y = visibleRect.getMinY();
//        _moveDirY = -_moveDirY;
        _velocityY = -_velocityY;
    }
    
    setPosition(pos);

    //Debug Display
    {
        char msg[256] = {0};
        sprintf(msg, "mvdirX:%f, mvdirY:%f, velX:%f, velY:%f", _moveDirX, _moveDirY, _velocityX, _velocityY);
        DebugFont::getInstance()->put(0,0, msg);
        sprintf(msg, "posX:%f, posY:%f", pos.x, pos.y);
        DebugFont::getInstance()->put(0,1, msg);
    }
}

void TestUnit::onEnter(void) {
    Node::onEnter();
    DPRINT("--- TestUnit::onEnter");
    auto visSize = Director::getInstance()->getVisibleSize();
    auto visOrg = Director::getInstance()->getVisibleOrigin();
    auto visibleRect = Rect(visOrg.x,
                            visOrg.y,
                            visOrg.x + visSize.width,
                            visOrg.y + visSize.height
                            );
    DPRINT("%f, %f", visSize.width, visSize.height);
    DPRINT("%f, %f", visOrg.x, visOrg.y);
    DPRINT("%f, %f, %f, %f", visibleRect.getMinX(), visibleRect.getMinY(), visibleRect.getMaxX(), visibleRect.getMaxY());
}

void TestUnit::onExit(void) {
    Node::onExit();
    DPRINT("--- TestUnit::onExit");
}




