#include "entities/player.h"

Player::Player(std::string name, sf::Texture & tex, sf::Vector2f vector, int speed):
Entity(name, tex, vector)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;
    setSpeed( speed );
}

Player::~Player()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<destructor>") : nullptr;
    setSpeed(0);
}

void Player::setSpeed( int speed )
{
    if(speed < 0)
        return; /* TODO: Throw invalid argument exception */
    _speed = speed;
}

int Player::getSpeed(){ return _speed; }

void Player::update( sf::Time & dt )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;
    float time = dt.asSeconds();

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
    {
        getSprite()->move( getSpeed() * time, 0 );
        getSprite()->setTextureRect( sf::IntRect(0, 32, 32, 32) );
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
    {
        getSprite()->move( -getSpeed() * time, 0 );
        getSprite()->setTextureRect( sf::IntRect(0, 96, 32, 32) );
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
    {
        getSprite()->move( 0, -getSpeed()* time );
        getSprite()->setTextureRect( sf::IntRect(0, 0, 32, 32) );
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
    {
        getSprite()->move( 0, getSpeed() * time );
        getSprite()->setTextureRect( sf::IntRect(0, 64, 32, 32) );
    }

    setVector2D( getSprite()->getPosition() );
}

sf::Sprite Player::render()
{
    return *getSprite();
}