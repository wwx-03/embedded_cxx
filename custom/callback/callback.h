#pragma once

#include <functional/functional.h>

namespace custom {

template<typename Signature>
struct callback;

template<typename R, typename... Args>
struct callback<R(Args...)>;

template<typename R>
struct callback<R()> {
    function<R()> function;
};

template<typename R, typename Arg1>
struct callback<R(Arg1)> {
    function<R(Arg1)> function;
    Arg1 arg1;
};

template<typename R, typename Arg1, typename Arg2>
struct callback<R(Arg1, Arg2)> {
    function<R(Arg1, Arg2)> function;
    Arg1 arg1;
    Arg2 arg2;
};

template<typename R, typename Arg1, typename Arg2, typename Arg3>
struct callback<R(Arg1, Arg2, Arg3)> {
    function<R(Arg1, Arg2, Arg3)> function;
    Arg1 arg1;
    Arg2 arg2;
    Arg3 arg3;
};

template<typename R, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
struct callback<R(Arg1, Arg2, Arg3, Arg4)> {
    function<R(Arg1, Arg2, Arg3, Arg4)> function;
    Arg1 arg1;
    Arg2 arg2;
    Arg3 arg3;
    Arg4 arg4;
};

template<typename R, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
struct callback<R(Arg1, Arg2, Arg3, Arg4, Arg5)> {
    function<R(Arg1, Arg2, Arg3, Arg4, Arg5)> function;
    Arg1 arg1;
    Arg2 arg2;
    Arg3 arg3;
    Arg4 arg4;
    Arg5 arg5;
};

};
