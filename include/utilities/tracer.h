#ifndef _TRACER_H
#define _TRACER_H

#include <iostream>
#include "utilities/traits.h"

/*! @class
    Tracer is a log class that will be utilized when
Traits<void>::traced is true. When a class that need to be traced
calls one of its methods, it creates a Tracer object passing the
class and method name on a string.
*/
class Tracer
{
public:
    /*! @brief
        If Tracer is enabled, store the passed
    parameter as the private property and prints
    that it entered this section.
        Else, nothing occurs.
    @param  char    message to be printed with IN or OUT at the end.    
    */
    Tracer(const char*);

    /*! @brief
        If Tracer is enabled, destroys the temporary tracer object,
    when it leaves the method context where it was created, printing
    an OUT message with the functionName parameter.
        Else, nothing occurs.
    */
    ~Tracer();

    /*! @property
    Traits flag that allow tracer to be used by other classes. */
    static const bool enable = Traits<void>::traced;
private:
    /*! @property
    Stores the message to be printed on constructor and destructor. */
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