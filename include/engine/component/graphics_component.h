#ifndef _GRAPHICS_COMPONENT_H
#define _GRAPHICS_COMPONENT_H

#include "engine/component/input_component.h"

class GraphicsComponent
{
public:
    /* Goes to PlayerGraphicsComponent */
    enum {
        RIGHT_MOVE,
        RIGHT_IDLE,

        LEFT_MOVE,
        LEFT_IDLE,

        UP_MOVE,
        UP_IDLE,

        DOWN_MOVE,
        DOWN_IDLE
    }typedef PlayerState;

public:
    GraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    ~GraphicsComponent();

    void update(Entity& entity, float& dt); /* Virtual on GraphicsComponent */

    void addAnimations( /* Stay on GraphicsComponent */
        std::string name, std::string texture, const sf::Time duration, bool loop,
        sf::Vector2i startPos, unsigned int frames);
    
    /* Goes to PlayerGraphicsComponent */
    void chooseState(float& x, float& y);
    void chooseAnimation(PlayerState state, std::string animationName);
    void checkIdleState();

    void initSprite(sf::Texture &texture, sf::Vector2f startPos); /* Stay on GraphicsComponent */
    void initAnimations(); /* Changes for every GraphicsComponent */

    sf::Sprite& getSprite(); /* Stay on GraphicsComponent */

private:
    /* Goes to PlayerGraphicsComponent */
    PlayerState _state;
    /* Stay on GraphicsComponent */
    sf::Sprite _sprite;
    sf::Vector2i _spriteSize;
    Animator * _animator;
};

#endif