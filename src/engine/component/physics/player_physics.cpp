#include "engine/component/physics/player_physics.h"

PlayerPhysicsComponent::PlayerPhysicsComponent(sf::Vector2f pos, unsigned int speed):
PhysicsComponent(pos, speed) {}

PlayerPhysicsComponent::~PlayerPhysicsComponent() { }

void PlayerPhysicsComponent::update(GameObject& gameObject, float& dt)
{
    /* Set speed accordingly to player state */
    if( gameObject.currentState()->getName() == "SPRINTING" )
        _speed = 80;
    else
        _speed = 40;

    /* Set move aceleration according to player direction */
    if( gameObject.currentState()->getName() == "WALKING" || gameObject.currentState()->getName() == "SPRINTING" )
    {
        if( gameObject.currentState()->getDirection() == PlayerState::RIGHT )
            _velocity = sf::Vector2f(1, 0);
        else if( gameObject.currentState()->getDirection() == PlayerState::LEFT )
            _velocity = sf::Vector2f(-1, 0);
        else if( gameObject.currentState()->getDirection() == PlayerState::UP )
            _velocity = sf::Vector2f(0, -1);
        else if( gameObject.currentState()->getDirection() == PlayerState::DOWN )
            _velocity = sf::Vector2f(0, 1);
    }
    else
        _velocity = sf::Vector2f(0,0);

    /* Set player position */
        sf::Vector2f newPosition = dt * _speed * _velocity;
        /* check world colision using the parameters */
        _position = newPosition;
    
}