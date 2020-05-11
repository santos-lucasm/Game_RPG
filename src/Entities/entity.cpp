#include "Entities/entity.h"
#include <iostream>
using namespace std;

Entity::Entity( string name, sf::Texture& texture, sf::Vector2f startPos, Location::Direction dir)
{
    traced = false;
    if(traced) std::cout << "Entity<constructor>: IN" << std::endl;

    setName( name );
    Location * loc = new Location(startPos, dir);
    setLocation(loc);
    setSprite( texture );

    if(traced) std::cout << "Entity<constructor>: IN" << std::endl;
}

Entity::~Entity()
{
    if(traced) std::cout << "Entity<destructor>: IN" << std::endl;
    getName().clear();
    delete _location;
    if(traced) std::cout << "Entity<destructor>: OUT" << std::endl;
}

void Entity::setName( string name )
{
    if( name.empty() )
        return; /* TODO: Throw invalid argument exception */
    _name = name;
}

void Entity::setLocation( Location * loc) {
    if( !loc )
        return; /* TODO: Throw invalid argument exception */
    _location = loc;
}


void Entity::setSprite( sf::Texture & texture )
{ 
    getSprite()->setTexture( texture );
    getSprite()->setPosition( getLocation()->getVector2D() );
}

string Entity::getName(){ return _name; }
Location * Entity::getLocation() { return _location; }
sf::Sprite * Entity::getSprite(){ return &_sprite; }