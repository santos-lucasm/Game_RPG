#ifndef _PLAYER_GRAPHICS_H
#define _PLAYER_GRAPHICS_H

#include "entities/player.h"

class PlayerGraphicsComponent: public GraphicsComponent
{
public:

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
    PlayerGraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    ~PlayerGraphicsComponent();

    void update(GameObject& GameObject, float& dt);

private:
    void initAnimations();
    void initStates();

    void updateIdle();
    void updateMove(sf::Vector2f& distance);
    void setState(PlayerState state);

    PlayerState _state;
    std::map<PlayerState, std::string> _stateToAnimation;
};

#endif