
#ifndef __MyGame__TestUnit__
#define __MyGame__TestUnit__

#include "AppStd.h"

class TestUnit : public cocos2d::Node {
public:
    static TestUnit* create(void);
    
    virtual void update(float delta) override;
    virtual void onEnter() override;
    virtual void onExit() override;
protected:
    virtual bool init(void) override;
    void initSprite(void);

    float _moveDirX;
    float _moveDirY;
    float _velocityX;
    float _velocityY;
};

#endif /* defined(__MyGame__TestUnit__) */
