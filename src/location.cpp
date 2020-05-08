#include "location.h"

Location::Location( sf::Vector2f vector, Direction dir )
{
    setVector2D( vector );
    setDirection( dir );
}

Location::~Location()
{
    setVector2D( sf::Vector2f(0, 0) );
    setDirection( Direction::NONE );
}

sf::Vector2f Location::getVector2D(){ return _vector; }
int Location::getDirection(){ return _direction; }

void Location::setVector2D( sf::Vector2f vector ){ _vector = vector; }
void Location::setDirection( Direction dir ) { _direction = dir; }