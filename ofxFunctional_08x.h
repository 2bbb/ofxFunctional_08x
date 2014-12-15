//
//  ofxFunctional_08x.h
//
//  Created by ISHII 2bit on 2014/12/15.
//
//

#pragma once

#if __cplusplus < 201103L

#include <tr1/functional>
#include <tr1/tuple>

    namespace std {
        using tr1::function;
        using tr1::bind;
        
        using tr1::placeholders::_1;
        using tr1::placeholders::_2;
        using tr1::placeholders::_3;
        using tr1::placeholders::_4;
        using tr1::placeholders::_5;
        using tr1::placeholders::_6;
        using tr1::placeholders::_7;
        using tr1::placeholders::_8;
        using tr1::placeholders::_9;
        using tr1::placeholders::_10;
        
        using tr1::tuple;
    };

#endif

#define ofxFunctionalReference(type, name) __block type name

#include <Block.h>

template <typename Res, typename ... Args>
class ofxFunction {};

template <typename Res, typename ... Args>
class ofxFunction<Res(Args ...)> : public function<Res(Args ...)> {
    typedef Res(^BlockType)(Args ...);
public:
    ofxFunction()
    : function<Res(Args ...)>()
    , f(NULL) {};
    
    ofxFunction(const function<Res(Args ...)> &f)
    : function<Res(Args ...)>(f)
    , f(NULL) {};
    
    ofxFunction(const BlockType &f)
    : function<Res(Args ...)>(f)
    , f(Block_copy(f)) {};
    
    ofxFunction &operator=(const function<Res(Args ...)> &f) {
        blockRelease();
        function<Res(Args ...)> F(f);
        this->swap(F);
    }
    
    ofxFunction &operator=(const BlockType &f) {
        blockRelease();
        this->f = Block_copy(f);
        function<Res(Args ...)> F(this->f);
        this->swap(F);
    }
    
    virtual ~ofxFunction() {
        blockRelease();
    }
    
    inline void blockRelease() {
        if(f) { Block_release(f); }
    }
private:
    BlockType f;
};