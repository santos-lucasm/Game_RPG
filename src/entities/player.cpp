#include "entities/player.h"

Player::Player(GraphicsComponent* g_cmp, InputComponent* i_cmp, PhysicsComponent* p_cmp):
GameObject(g_cmp, i_cmp, p_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;
}

Player::~Player()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<destructor>") : nullptr;
}

void Player::update( sf::Time & dt )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;

    float time = dt.asSeconds();

    _inputComponent->update(*this);
    _physicsComponent->update(*this, time);
    _graphicsComponent->update(*this, time);
}

void Player::render(sf::RenderTarget* target)
{
    target->draw( _graphicsComponent->getSprite() );
}