#include "entities/player.h"

Player::Player(std::string name, sf::Texture & texture, sf::Vector2f vector, sf::Vector2i size, int speed):
Entity(name, texture, vector)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;

    setSize(size);
    setSpeed( speed );

    getSprite().setTextureRect( sf::IntRect(0, 0, getSpriteSize().x, getSpriteSize().y) );
    getSprite().setScale(2, 2);

    initAnimations();
}

Player::~Player()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<destructor>") : nullptr;
    setSize( sf::Vector2i(0,0) ); 
    setSpeed(0);
}

void Player::initAnimations()
{
    /* Idle animation in the four directions */
    auto& animationRightIdle = getAnimator()->createAnimation("idle-right", ANIMATION_PATH(snorlax), sf::seconds(0.5f), false);
    animationRightIdle.AddFrames(sf::Vector2i(32,32), getSpriteSize(), 1);

    auto& animationLeftIdle = getAnimator()->createAnimation("idle-left", ANIMATION_PATH(snorlax), sf::seconds(0.5f), false);
    animationLeftIdle.AddFrames(sf::Vector2i(32,96), getSpriteSize(), 1);

    auto& animationUpIdle = getAnimator()->createAnimation("idle-up", ANIMATION_PATH(snorlax), sf::seconds(0.5f), false);
    animationUpIdle.AddFrames(sf::Vector2i(32,0), getSpriteSize(), 1);

    auto& animationDownIdle = getAnimator()->createAnimation("idle-down", ANIMATION_PATH(snorlax), sf::seconds(0.5f), false);
    animationDownIdle.AddFrames(sf::Vector2i(32,64), getSpriteSize(), 1);

    /* Walk animations in the four directions */
    auto& animationRight = getAnimator()->createAnimation("walk-right", ANIMATION_PATH(snorlax), sf::seconds(1), true);
    animationRight.AddFrames(sf::Vector2i(0,32), getSpriteSize(), 3);

    auto& animationLeft = getAnimator()->createAnimation("walk-left", ANIMATION_PATH(snorlax), sf::seconds(1), true);
    animationLeft.AddFrames(sf::Vector2i(0,96), getSpriteSize(), 3);

    auto& animationUp = getAnimator()->createAnimation("walk-up", ANIMATION_PATH(snorlax), sf::seconds(1), true);
    animationUp.AddFrames(sf::Vector2i(0,0), getSpriteSize(), 3);

    auto& animationDown = getAnimator()->createAnimation("walk-down", ANIMATION_PATH(snorlax), sf::seconds(1), true);
    animationDown.AddFrames(sf::Vector2i(0,64), getSpriteSize(), 3);
}

void Player::update( sf::Time & dt )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;

    float time = dt.asSeconds();

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
    {
        setDirection( RIGHT_MOVE );
        getSprite().move( getSpeed() * time, 0 );
        if( getAnimator()->getCurrentAnimationName() != "walk-right" )
            getAnimator()->switchAnimation("walk-right");
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
    {
        setDirection( LEFT_MOVE );
        getSprite().move( -getSpeed() * time, 0 );
        if( getAnimator()->getCurrentAnimationName() != "walk-left" )
            getAnimator()->switchAnimation("walk-left");
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
    {
        setDirection( UP_MOVE );
        getSprite().move( 0, -getSpeed()* time );
        if( getAnimator()->getCurrentAnimationName() != "walk-up" )
            getAnimator()->switchAnimation("walk-up");
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
    {
        setDirection( DOWN_MOVE );
        getSprite().move( 0, getSpeed() * time );
        if( getAnimator()->getCurrentAnimationName() != "walk-down" )
            getAnimator()->switchAnimation("walk-down");
    }

    /* If the player was moving in a X direction and the X direction button
    is not beeing pressed anymore, sets Entity direction to the X_IDLE. */
    switch( getDirection() )
    {
        case RIGHT_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
            {
                setDirection( RIGHT_IDLE );
                getAnimator()->switchAnimation("idle-right");
            }
            break;

        case LEFT_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
            {
                setDirection( LEFT_IDLE );
                getAnimator()->switchAnimation("idle-left");
            }
            break;

        case UP_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
            {
                setDirection( UP_IDLE );
                getAnimator()->switchAnimation("idle-up");
            }
            break;

        case DOWN_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
            {
                setDirection( DOWN_IDLE );
                getAnimator()->switchAnimation("idle-down");
            }
            break;

        default:
            break;
    }

    getAnimator()->update(dt);
}

void Player::render(sf::RenderTarget* target)
{
    target->draw( getSprite() );
}

void Player::setSpeed( int speed )
{
    if(speed < 0)
        return; /* TODO: Throw invalid argument exception */
    _speed = speed;
}
void Player::setSize(sf::Vector2i size){ _spriteSize = size; }
int Player::getSpeed(){ return _speed; }
sf::Vector2i Player::getSpriteSize(){ return _spriteSize; }