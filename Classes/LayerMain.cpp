
#include "LayerMain.h"

USING_NS_CC;


LayerMain::LayerMain() {
    DPRINT("call LayerMain constructor");
}

LayerMain::~LayerMain() {
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

