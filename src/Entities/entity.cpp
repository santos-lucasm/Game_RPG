#include "Entities/entity.h"
using namespace std;

Entity::Entity( string name, Location * loc, sf::Texture& texture)
{
    setName( name );
    setLocation( loc );
    setSprite( texture );
}

Entity::~Entity()
{
    /* FIXED: nullptr can't be assigned to a std::string */
    getName().clear();
    /* TODO: better destroy this with delete */
    setLocation(nullptr);
}

/*
TODO: Verify if string passed is a nullptr.
    Throw std::logic_error.
    what():  basic_string::_M_construct null not valid
*/
void Entity::setName( string name ){ _name = name; }

/*
TODO: Verify if argument passed is a nullptr.
    Throw an exception.
*/
void Entity::setLocation( Location * loc) { _location = loc; }


void Entity::setSprite( sf::Texture & texture )
{ 
    getSprite()->setTexture( texture );
    getSprite()->setPosition( getLocation()->getVector2D() );
}

string Entity::getName(){ return _name; }
Location * Entity::getLocation() { return _location; }
sf::Sprite * Entity::getSprite(){ return &_sprite; }