#ifndef _PLAYER_H
#define _PLAYER_H

#include "entities/entity.h"
#include "engine/command/input_handler.h"

class Player: public Entity
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
    Player(std::string name, sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize, int speed = 40);
    ~Player();

    void update(sf::Time &dt);
    void render(sf::RenderTarget* target);

    void move(float x, float y, PlayerState state, std::string animationName);

    void setSpeed(unsigned int speed);
    void setState(PlayerState dir);
    int getSpeed();
    PlayerState getState();

private:
    void initAnimations();

    void updateState(PlayerState state, std::string animationName);
    void checkIdleState();

    int _speed;
    PlayerState _state;
    InputHandler * _inputHandler;

    static const bool debugged = Traits<Player>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Player>::traced && Tracer::traceActive;
};

#endif