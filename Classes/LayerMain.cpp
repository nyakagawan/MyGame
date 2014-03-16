
#include "LayerMain.h"


LayerMain::LayerMain() {
    DPRINT("call LayerMain constructor");
}

LayerMain::~LayerMain() {
}

bool LayerMain::init() {
    cocos2d::log("log tet#########");
    DPRINT("call LayerMain::init");
    if(! Layer::init()) {
        DPRINT("failed Layer::init");
        return false;
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

