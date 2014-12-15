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