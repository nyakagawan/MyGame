/**
 *  コード全体でincludeするヘッダ
 */
#ifndef MyGame_AppStd_h
#define MyGame_AppStd_h

// 標準ライブラリ
#include <stdio.h>
#include <vector>
#include <iostream>

// cocos2dx 系
#include "cocos2d.h"

#include "Define.h"

#define DPRINT(fmt,...) cocos2d::log("[%s:%d] " fmt, __FUNCTION__, __LINE__, ## __VA_ARGS__)

#include "Global.h"

#endif
