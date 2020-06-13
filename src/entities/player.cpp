#include "entities/player.h"

Player::Player(GraphicsComponent* g_cmp, InputComponent* i_cmp, PhysicsComponent* p_cmp):
GameObject(g_cmp, i_cmp, p_cmp)
{   
    _automata = new Machine( new StandingState( PlayerState::Direction::RIGHT ) );
}

Player::~Player()
{
    delete _automata;
}

void Player::update( sf::Time & dt )
{
    float time = dt.asSeconds();

    _inputComponent->update(*this);
    _physicsComponent->update(*this, time);
    _graphicsComponent->update(*this, time);
}

void Player::render(sf::RenderTarget* target)
{
    target->draw( _graphicsComponent->getSprite() );
}