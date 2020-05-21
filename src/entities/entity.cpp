#include "entities/entity.h"

Entity::Entity(std::string name, sf::Texture& texture, sf::Vector2f startPos)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<constructor>") : nullptr;

    initSprite(texture, startPos);
    
    setDirection(NONE);
    setName(name);
    _animator = new Animator( getSprite() );
}

Entity::~Entity()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<destructor>") : nullptr;
    
    setDirection(NONE);
    setName("");
    delete _animator;
}

void Entity::initSprite(sf::Texture &texture, sf::Vector2f startPos)
{ 
    getSprite().setTexture( texture );
    getSprite().setPosition( startPos );
}

void Entity::setDirection(Direction dir){ _dir = dir; }
void Entity::setName(std::string name){ _name = name; }
std::string Entity::getName(){ return _name; }
Entity::Direction Entity::getDirection(){ return _dir; }
sf::Sprite & Entity::getSprite(){ return _sprite; }
Animator * Entity::getAnimator(){ return _animator; }