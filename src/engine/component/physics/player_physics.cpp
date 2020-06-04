#include "engine/component/physics/player_physics.h"

PlayerPhysicsComponent::PlayerPhysicsComponent(sf::Vector2f pos, unsigned int speed):
PhysicsComponent(pos, speed) {}

PlayerPhysicsComponent::~PlayerPhysicsComponent() { }

void PlayerPhysicsComponent::update(GameObject& gameObject, float& dt)
{
    sf::Vector2f newPosition = dt * _speed * _velocity;

    /* check world colision using the parameters */

    _position = newPosition;
    
    /* set state */
}