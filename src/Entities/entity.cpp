#include "Entities/entity.h"
using namespace std;

Entity::Entity( string name, sf::Texture& texture, sf::Vector2f startPos, Location::Direction dir)
{
    if(traced) Tracer("Entity<constructor>");

    setName( name );
    Location * loc = new Location(startPos, dir);
    setLocation(loc);
    setSprite( texture );
}

Entity::~Entity()
{
    if(traced) Tracer("Entity<destructor>");
    getName().clear();
    delete _location;
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