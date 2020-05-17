#include <memory.h>
#include "entities/entity.h"

Entity::Entity( std::string name, sf::Texture& texture, sf::Vector2f vector )
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<constructor>") : nullptr;

    setName( name );
    setVector2D( vector );
    setSprite( texture );
}

Entity::~Entity()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<destructor>") : nullptr;
    
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
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<setSprite>") : nullptr;

    getSprite()->setTexture( texture );
    getSprite()->setPosition( getVector2D() );
    getSprite()->setTextureRect( sf::IntRect(0, 0, 32, 32) );
    getSprite()->setScale(2, 2);
}

std::string Entity::getName(){ return _name; }
sf::Vector2f Entity::getVector2D() { return _vector2D; }
sf::Sprite * Entity::getSprite(){ return &_sprite; }