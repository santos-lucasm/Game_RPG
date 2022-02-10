#include "engine/component/physics/physics_component.h"

PhysicsComponent::PhysicsComponent(sf::Vector2f pos, unsigned int speed)
{
    _position = pos;
    _speed = speed;
    _velocity = sf::Vector2f(0,0);
}

PhysicsComponent::~PhysicsComponent()
{
    
}