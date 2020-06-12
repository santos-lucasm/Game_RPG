#include "engine/component/physics/player_physics.h"

PlayerPhysicsComponent::PlayerPhysicsComponent(sf::Vector2f pos, unsigned int speed):
PhysicsComponent(pos, speed) {}

PlayerPhysicsComponent::~PlayerPhysicsComponent() { }

void PlayerPhysicsComponent::update(GameObject& gameObject, float& dt)
{
    /* Set speed accordingly to player state */
    if( gameObject.getMachine()->getState()->getName() == "SPRINTING" )
        _speed = 80;
    else
        _speed = 40;

    /* Set move aceleration according to player direction */
    if( gameObject.getMachine()->getState()->getName() == "WALKING" || gameObject.getMachine()->getState()->getName() == "SPRINTING" )
    {
        if( gameObject.getMachine()->getState()->getDirection() == PlayerState::RIGHT )
            _velocity = sf::Vector2f(1, 0);
        else if( gameObject.getMachine()->getState()->getDirection() == PlayerState::LEFT )
            _velocity = sf::Vector2f(-1, 0);
        else if( gameObject.getMachine()->getState()->getDirection() == PlayerState::UP )
            _velocity = sf::Vector2f(0, -1);
        else if( gameObject.getMachine()->getState()->getDirection() == PlayerState::DOWN )
            _velocity = sf::Vector2f(0, 1);
    }
    else
        _velocity = sf::Vector2f(0,0);

    /* Set player position */
        sf::Vector2f newPosition = dt * _speed * _velocity;
        /* check world colision using the parameters */
        _position = newPosition;
    
}