#include "utils/tracer.h"

int Tracer::_nestedNumber = 0;

Tracer::Tracer(const std::string msg): _entryName(msg)
{
    _nestedNumber++;

    for(int i=1; i<_nestedNumber; i++)
        std::cout << "\t";
    std::cout << _entryName << ": IN" << std::endl;
}

Tracer::~Tracer()
{   
    for(int i=1; i<_nestedNumber; i++)
        std::cout << "\t";
    std::cout << _entryName << ": OUT" << std::endl;

    _entryName.erase();
    _nestedNumber--;
}

void Tracer::debug(std::string msg)
{
    _nestedNumber++;
    for(int i=1; i<_nestedNumber; i++)
        std::cout << "\t";
        
    std::cout << "DEBUG: " << msg << std::endl;
    _nestedNumber--;
}