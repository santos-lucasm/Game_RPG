#ifndef _TRACER_H
#define _TRACER_H

#include "Utilities/traits.h"
#include <iostream>

class Tracer
{
public:
    Tracer(const char* name);
    ~Tracer();
    // void debug (const std::string &msg);

    static const bool enable = Traits<void>::traced;
private:
    std::string * functionName;
};

inline
Tracer::Tracer(const char* name): functionName(0)
{
    if(enable)
    {
        functionName = new std::string(name);
        std::cout << *functionName << "\t: IN" << std::endl;
    }
}

inline
Tracer::~Tracer()
{
    if(enable)
    {
        std::cout << *functionName << "\t: OUT" << std::endl;
        delete functionName;
    }
}

#endif