#ifndef _DEBUG_H
#define _DEBUG_H

#include "utils/traits.h"

/* Overloads <<, to flush a message into cout */
class Debug
{
public:
    template<typename T>
    Debug & operator<<(T p) { std::cout << p; return *this; }
};

/* Overloads <<, but just returns to the previous context */
class NullDebug
{
public:
    template<typename T>
    NullDebug & operator<<(const T & o) { return *this; }
};

/*
    Middleware class that will choose to use << overload
from Debug or NullDebug, according to template debug and
tracing flags defined on traits.h
*/
template<bool debugged>
class SelectDebug: public Debug {};
template<>
class SelectDebug<false>: public NullDebug {};

enum DebugInfo{ INF = 1 };

template<typename T>
inline SelectDebug< (Traits<T>::debugged && Traits<Debug>::info) >
db(DebugInfo l)
{
    return SelectDebug< (Traits<T>::debugged && Traits<Debug>::info) >();
}

enum DebugTrace{ TRC = 2 };

template<typename T>
inline SelectDebug< (Traits<T>::debugged && Traits<Debug>::trace) >
db(DebugTrace l)
{
    return SelectDebug< (Traits<T>::debugged && Traits<Debug>::trace) >();
}

#endif