#ifndef _PLAYER_H
#define _PLAYER_H

#include "entities/entity.h"
#include "engine/commands/input_handler.h"

class Player: public Entity
{
public:
    Player(std::string name, sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize, int speed = 40);
    ~Player();

    void update(sf::Time &dt);
    void render(sf::RenderTarget* target);

    void move(float x, float y, EntityState state, std::string animationName);

    void setSpeed(unsigned int speed);
    int getSpeed();

private:
    void initAnimations();

    void updateState(EntityState state, std::string animationName);
    void checkIdleState();

    int _speed;
    InputHandler * _inputHandler;

    static const bool debugged = Traits<Player>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Player>::traced && Tracer::traceActive;
};

#endif