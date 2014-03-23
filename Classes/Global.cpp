
#include "Global.h"

USING_NS_CC;


bool DebugFont::init(void) {
    return true;
}

void DebugFont::term() {
    
}

#define DEBUG_FONT_SCALE (0.5f)
#define DEBUG_FONT_HEIGHT (16*DEBUG_FONT_SCALE)
#define DEBUG_FONT_WIDTH (9*DEBUG_FONT_SCALE)
void DebugFont::put(int x, int y, const char* text) {
    auto visSize = Director::getInstance()->getVisibleSize();
    auto visOrg = Director::getInstance()->getVisibleOrigin();
    
    auto label = CCLabelBMFont::create(text, "font2.fnt");
    label->setAlignment(TextHAlignment::LEFT);
    label->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    float px = DEBUG_FONT_WIDTH * x;
    float py = DEBUG_FONT_HEIGHT * y;
    float topoffset = visSize.height+visOrg.y;
    label->setPosition( Point(px, topoffset-py) );
    label->setScale(DEBUG_FONT_SCALE);
    label->visit();
}

