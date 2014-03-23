#ifndef MyGame_LayerDebug_h
#define MyGame_LayerDebug_h

#include "AppStd.h"

class LayerDebug : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(LayerDebug);
    
public:
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

protected:
    LayerDebug();
    virtual ~LayerDebug() override;
    virtual bool init() override;
};


#endif
