#include "position.h"

Position::Position( sf::Vector2i vector, Direction dir )
{
    setPosition( vector );
    setDirection( dir );
}

Position::~Position()
{
    setPosition( sf::Vector2i(0, 0) );
    setDirection( Direction::NONE );
}

sf::Vector2i getPosition(){ return _vector; }
int Position::getDirection() { return _direction; }

void Position::setPosition( sf::Vector2i vector ){ _vector = vector; }
void Position::setDirection( Direction dir ) { _direction = dir; }