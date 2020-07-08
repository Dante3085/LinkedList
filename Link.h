
#pragma once

#include <utility>
#include "Util.h"

template <typename T>
struct Link
{
    T data;
    Link<T> *next;
    Link<T> *prev;

    template <typename... Args>
    Link(Link<T> *next, Link<T> *prev, Args &&... args)
        : next{next},
          prev{prev},
          data{std::forward<Args>(args)...}
    {
        // LOG("Perfect forwarding.");
    }
};