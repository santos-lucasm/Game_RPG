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
    /* TODO: Define a speed for each entity, to use here at move method
        speed attribute: to be multiplied by delta time and get distance
    */
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;
    float time = dt.asSeconds();

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        getSprite()->move( getSpeed() * time, 0 );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        getSprite()->move( getSpeed() * -1 * time, 0 );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        getSprite()->move( 0, getSpeed() * -1 * time );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        getSprite()->move( 0, getSpeed() * time );
}

sf::Sprite Player::render()
{
    return *getSprite();
}