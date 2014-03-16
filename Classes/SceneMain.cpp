
#include "LayerMain.h"
#include "SceneMain.h"

SceneMain::SceneMain(void) {
}

cocos2d::Scene* SceneMain::createScene(void)
{
    SceneMain* pScene = NULL;
    do {
        pScene = new SceneMain();
        if (pScene && pScene->init()) {
            pScene->autorelease();
        }
        else {
            DPRINT("SceneMain create failed.");
            CC_SAFE_DELETE(pScene);
            break;
        }
        // 'layer' is an autorelease object
        auto layer = LayerMain::create();
        if(!layer) {
            DPRINT("LayerMain create failed.");
            break;
        }
        
        // add layer as a child to scene
        pScene->addChild(layer);
        
    } while (0);
    
    // return the scene
    return pScene;
}
