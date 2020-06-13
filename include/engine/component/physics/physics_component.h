#ifndef _PHYSICS_COMPONENT_H
#define _PHYSICS_COMPONENT_H

#include "middleware/animator.h"

class PhysicsComponent
{
public:
    PhysicsComponent(sf::Vector2f pos, unsigned int speed);
    virtual ~PhysicsComponent();
    virtual void update(GameObject& gameObject, float& dt) = 0;

    sf::Vector2f _position;
    sf::Vector2f _velocity;
    unsigned int _speed;
};

#endif