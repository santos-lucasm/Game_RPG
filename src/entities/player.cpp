#include "entities/player.h"

Player::Player(GraphicsComponent* g_cmp, InputComponent* i_cmp, int speed):
GameObject(g_cmp, i_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;
    _speed = speed;
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
    _graphicsComponent->update(*this, time);

}

void Player::render(sf::RenderTarget* target)
{
    target->draw( _graphicsComponent->getSprite() );
}
