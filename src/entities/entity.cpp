#include "entities/entity.h"

Entity::Entity(std::string name, sf::Texture& texture, sf::Vector2f startPos, sf::Vector2i spriteSize)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<constructor>") : nullptr;
    
    setName(name);
    setState(NONE);
    setSize(spriteSize);

    initSprite(texture, startPos);
    _animator = new Animator( getSprite() );
}

Entity::~Entity()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<destructor>") : nullptr;
    
    setName("");
    setState(NONE);
    setSize( sf::Vector2i(0,0) );
    delete _animator;
}

void Entity::initSprite(sf::Texture &texture, sf::Vector2f startPos)
{ 
    getSprite().setTexture( texture );
    getSprite().setPosition( startPos );
}

void Entity::addAnimations(std::string name, std::string texture, const sf::Time duration, bool loop, sf::Vector2i startPos, unsigned int frames)                                /* Add Frames */
{
    auto& newAnimation = getAnimator()->createAnimation(name, texture, duration, loop);
    newAnimation.AddFrames(startPos, getSpriteSize(), frames);
}

void Entity::setName(std::string name){ _name = name; }
void Entity::setState(EntityState state){ _state = state; }
void Entity::setSize(sf::Vector2i size){ _spriteSize = size; }
std::string Entity::getName(){ return _name; }
EntityState Entity::getState(){ return _state; }
sf::Vector2i Entity::getSpriteSize(){ return _spriteSize; }

sf::Sprite & Entity::getSprite(){ return _sprite; }
Animator * Entity::getAnimator(){ return _animator; }
std::map<std::string, int>* Entity::getSupportedKeys(){ return _supportedKeys; }