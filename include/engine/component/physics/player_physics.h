#ifndef _PLAYER_PHYSICS_H
#define _PLAYER_PHYSICS_H

#include "entities/player.h"

class PlayerPhysicsComponent: public PhysicsComponent
{
public:
    PlayerPhysicsComponent(sf::Vector2f pos, unsigned int speed = 40);
    ~PlayerPhysicsComponent();
    void update(GameObject& gameObject, float& dt);

private:
    static const bool debugged = Traits<PlayerInputComponent>::debugged && Tracer::debugActive;
    static const bool traced = Traits<PlayerInputComponent>::traced && Tracer::traceActive;
};

#endif