#ifndef _PLAYER_PHYSICS_H
#define _PLAYER_PHYSICS_H

#include "entities/player.h"

class PlayerPhysicsComponent: public PhysicsComponent
{
public:
    PlayerPhysicsComponent(sf::Vector2f pos, unsigned int speed = 40);
    ~PlayerPhysicsComponent();
    void update(GameObject& gameObject, float& dt);
};

#endif