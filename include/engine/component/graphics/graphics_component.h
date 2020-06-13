#ifndef _GRAPHICS_COMPONENT_H
#define _GRAPHICS_COMPONENT_H

#include "middleware/animator.h"

class GraphicsComponent
{
public:
    GraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    virtual ~GraphicsComponent();
    virtual void update(GameObject& GameObject, float& dt) = 0;
    sf::Sprite& getSprite();

protected:
    virtual void initSprite(sf::Texture &texture, sf::Vector2f startPos);
    virtual void initAnimations() = 0;

    void addAnimations(
        std::string name, std::string texture, const sf::Time duration, bool loop,
        sf::Vector2i startPos, unsigned int frames);

protected:
    sf::Sprite _sprite;
    sf::Vector2i _spriteSize;
    Animator * _animator;
};

#endif