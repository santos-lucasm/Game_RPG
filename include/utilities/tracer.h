#ifndef _TRACER_H
#define _TRACER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
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
    Traits flag that allow tracer to print other classes entry points. */
    static const bool traceActive = Traits<Tracer>::tracing_enabled;

    /*! @property
    Traits flag that allow tracer to print other classes returns and parameters. */
    static const bool debugActive = Traits<Tracer>::debug_enabled;

private:
    /*! @property
    Stores the message to be printed on constructor and destructor. */
    std::string * functionName;

    /*! @property
    Number of the current Tracers alive, to do a nested log */
    static int nested_number;
};

#endif