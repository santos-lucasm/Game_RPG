#include "location.h"
#include <iostream>
Location::Location( sf::Vector2f vector, Direction dir )
{
    traced = false;
    if(traced) std::cout << "Location<constructor>: IN" << std::endl;
    setVector2D( vector );
    setDirection( dir );
    if(traced) std::cout << "Location<constructor>: OUT" << std::endl;
}

Location::~Location()
{   
    if(traced) std::cout << "Location<destructor>: IN" << std::endl;
    setVector2D( sf::Vector2f(0, 0) );
    setDirection( Direction::NONE );
    if(traced) std::cout << "Location<destructor>: OUT" << std::endl;
}

sf::Vector2f Location::getVector2D(){ return _vector; }
int Location::getDirection(){ return _direction; }

void Location::setVector2D( sf::Vector2f vector ){ _vector = vector; }
void Location::setDirection( Direction dir ) { _direction = dir; }