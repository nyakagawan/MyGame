
#include "LayerMain.h"

USING_NS_CC;


LayerMain::LayerMain() {
    DPRINT("call LayerMain constructor");
}

LayerMain::~LayerMain() {
    //sampleではonExitでやってたけど。
    auto cache = SpriteFrameCache::getInstance();
    cache->removeSpriteFramesFromFile("majo.plist");
}

bool LayerMain::init() {
    DPRINT("call LayerMain::init");
    if(! Layer::init()) {
        DPRINT("failed Layer::init");
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    auto item1 = MenuItemLabel::create(label,
                                        [](Object *obj) {
                                            DPRINT("item1 touched");
                                        });
	item1->setPosition(Point(origin.x + visibleSize.width - item1->getContentSize().width/2 ,
                                 origin.y + item1->getContentSize().height/2));
    auto menu = Menu::create(item1, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
//    auto filePath = FileUtils::getInstance()->fullPathForFilename("images/chara/majo.png");
//    auto pSprite = Sprite::create(filePath);
//    auto pSprite = Sprite::create("effect/balloon.png");
    auto pSprite = Sprite::create("majo.png");
    pSprite->setPosition(Point(100,100));
    this->addChild(pSprite);

    
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("majo.plist", "majo.png");
    
    auto s = Director::getInstance()->getWinSize();
    auto _sprite1 = Sprite::createWithSpriteFrameName("majo_01.png");
    _sprite1->setPosition( Point( s.width/2-16, s.height/2) );
    
    auto spritebatch = SpriteBatchNode::create("majo.png");
    spritebatch->addChild(_sprite1);
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
    _sprite1->runAction( RepeatForever::create( Animate::create(animation) ) );
    
    // create move actions
    {
        auto seqActs = Vector<FiniteTimeAction*>();
        {
            auto spawnActs = Vector<FiniteTimeAction*>();
            
            auto mv = MoveBy::create(2, Point(0, -50));
            auto es = EaseInOut::create(mv, 10);
            spawnActs.pushBack( es );
            
            mv = MoveBy::create(2, Point(50, 0));
            es = EaseInOut::create(mv, 10);
            spawnActs.pushBack( es );
            
            auto actSpawn = Spawn::create( spawnActs );
            seqActs.pushBack(actSpawn);
        }
        {
            auto spawnActs = Vector<FiniteTimeAction*>();
            spawnActs.pushBack( MoveBy::create(2, Point(0, 50)) );
            spawnActs.pushBack( MoveBy::create(2, Point(-50, 0)) );
            auto actSpawn = Spawn::create( spawnActs );
            seqActs.pushBack(actSpawn);
        }
        
        auto actSeq = Sequence::create(seqActs);
        
        _sprite1->runAction(RepeatForever::create(actSeq));
    }
    
    return true;
}

/**
 *  <#Description#>
 *
 *  @param keyCode <#keyCode description#>
 *  @param event   <#event description#>
 */
void LayerMain::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    DPRINT("call onKeyPressed");
}

/**
 *  <#Description#>
 *
 *  @param keyCode <#keyCode description#>
 *  @param event   <#event description#>
 */
void LayerMain::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    DPRINT("call onKeyPressed");
}

