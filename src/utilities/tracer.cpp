#include "utilities/tracer.h"

int Tracer::nested_number = 0;

Tracer::Tracer(const char* name): functionName(0)
{
    if(traceActive)
    {
        nested_number++;
        functionName = new std::string(name);

        for(int i=1; i<nested_number; i++)
            std::cout << "\t";
        std::cout << *functionName << ": IN" << std::endl;
    }
}

Tracer::~Tracer()
{
    if(traceActive)
    {   
        for(int i=1; i<nested_number; i++)
            std::cout << "\t";
        std::cout << *functionName << ": OUT" << std::endl;

        delete functionName;
        nested_number--;
    }
}