#include "engine/component/graphics/graphics_component.h"

GraphicsComponent::GraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize)
{
    _spriteSize = spriteSize;
    initSprite(texture, startPos);
    _animator = new Animator(_sprite);
}

GraphicsComponent::~GraphicsComponent()
{
    delete _animator;
}

void GraphicsComponent::initSprite(sf::Texture &texture, sf::Vector2f startPos)
{
    _sprite.setTexture( texture );
    _sprite.setPosition( startPos );
}

void GraphicsComponent::addAnimations(
    std::string name, std::string texture, const sf::Time duration, bool loop, sf::Vector2i startPos, unsigned int frames)                                /* Add Frames */
{
    auto& newAnimation = _animator->createAnimation(name, texture, duration, loop);
    newAnimation.AddFrames(startPos, _spriteSize, frames);
}

sf::Sprite& GraphicsComponent::getSprite() { return _sprite; }