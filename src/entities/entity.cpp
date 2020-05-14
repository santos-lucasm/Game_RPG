#include "entities/entity.h"

Entity::Entity( std::string name, sf::Texture& texture, sf::Vector2f vector )
{
    if(traced) Tracer("Entity<constructor>");

    setName( name );
    setVector2D( vector );
    setSprite( texture );
}

Entity::~Entity()
{
    if(traced) Tracer("Entity<destructor>");
    getName().clear();
    setVector2D( sf::Vector2f(0,0) );
}

void Entity::setName( std::string name )
{
    if( name.empty() )
        return; /* TODO: Throw invalid argument exception */
    _name = name;
}

void Entity::setVector2D( sf::Vector2f vector ) { _vector2D = vector; }


void Entity::setSprite( sf::Texture & texture )
{ 
    getSprite()->setTexture( texture );
    getSprite()->setPosition( getVector2D() );
}

std::string Entity::getName(){ return _name; }
sf::Vector2f Entity::getVector2D() { return _vector2D; }
sf::Sprite * Entity::getSprite(){ return &_sprite; }