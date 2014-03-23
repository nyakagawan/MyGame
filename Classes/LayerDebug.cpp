
#include "LayerDebug.h"

USING_NS_CC;


LayerDebug::LayerDebug() {
}

LayerDebug::~LayerDebug() {
}

bool LayerDebug::init() {
    if(! Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
//    _FPSLabel = LabelAtlas::create();
//    _FPSLabel->retain();
//    _FPSLabel->setIgnoreContentScaleFactor(true);
//    _FPSLabel->initWithString("00.0", texture, 12, 32 , '.');
//    _FPSLabel->setScale(factor);
    
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
    
    
//    auto pTestUnit = TestUnit::create();
//    addChild(pTestUnit);
    
    return true;
}

/**
 *  <#Description#>
 *
 *  @param keyCode <#keyCode description#>
 *  @param event   <#event description#>
 */
void LayerDebug::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    DPRINT("call onKeyPressed");
}

/**
 *  <#Description#>
 *
 *  @param keyCode <#keyCode description#>
 *  @param event   <#event description#>
 */
void LayerDebug::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    DPRINT("call onKeyPressed");
}

