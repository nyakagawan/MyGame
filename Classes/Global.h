#ifndef MyGame_Global_h
#define MyGame_Global_h

#include "AppStd.h"

/**
 *  Singleton base class
 */
template<typename T>
class SingletonBase {
public:
    /**
     *  Create intance
     *
     *  @return instance
     */
    static T* getInstance(void) {
        if(_pInstance==NULL) {
            _pInstance = new T();
            _pInstance->init();
        }
        return _pInstance;
    }
    
    /**
     *  initialize function
     *
     *  @return true/successed false/failed
     */
    virtual bool init(void) = 0;
    /**
     *  terminate function
     */
    virtual void term(void) = 0;
protected:
    static T* _pInstance;
};
template<typename T> T* SingletonBase<T>::_pInstance = NULL;

/**
 *  デバッグ用フォント描画
 */
class DebugFont : public SingletonBase<DebugFont> {
public:
    bool init(void) override;
    void term(void) override;
    
    /**
     *  デバッグ用フォント描画
     *
     *  @param x    描画座標X
     *  @param y    描画座標Y
     *  @param text 描画文字列
     */
    void put(int x, int y, const char* text);
};

#endif
