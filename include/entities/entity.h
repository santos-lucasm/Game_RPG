#ifndef _ENTITY_H
#define _ENTITY_H

#include "manager/animator.h"

class Entity
{
public:
    Entity(std::string name, sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    virtual ~Entity();

    virtual void update(sf::Time &dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;
    sf::Sprite & getSprite();

protected:
    void addAnimations(
        std::string name, std::string texture, const sf::Time duration, bool loop,  /* Create Animations */
        sf::Vector2i startPos, unsigned int frames);                                /* Add Frames */

    void setName(std::string name);
    void setSize(sf::Vector2i size);
    std::string getName();
    sf::Vector2i getSpriteSize();

    Animator * getAnimator();
private:
    void initSprite(sf::Texture &texture, sf::Vector2f startPos);

    std::string _name;
    sf::Sprite _sprite;
    sf::Vector2i _spriteSize;

    Animator * _animator;

    static const bool debugged = Traits<Entity>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Entity>::traced && Tracer::traceActive;
};

#endif