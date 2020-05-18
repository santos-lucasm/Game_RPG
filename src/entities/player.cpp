#include "entities/player.h"

Player::Player(std::string name, sf::Texture & tex, sf::Vector2f vector, int speed):
Entity(name, tex, vector)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;
    setSpeed( speed );
    initAnimations();
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

void Player::initAnimations()
{
    /* Idle animation in the four directions */
    auto& animationRightIdle = getAnimator()->createAnimation
        ("idle-right", "resources/animations/snorlax.png", sf::seconds(0.5f), false);
    animationRightIdle.AddFrames(sf::Vector2i(32,32), sf::Vector2i(32,32), 1);

    auto& animationLeftIdle = getAnimator()->createAnimation
        ("idle-left", "resources/animations/snorlax.png", sf::seconds(0.5f), false);
    animationLeftIdle.AddFrames(sf::Vector2i(32,96), sf::Vector2i(32,32), 1);

    auto& animationUpIdle = getAnimator()->createAnimation
        ("idle-up", "resources/animations/snorlax.png", sf::seconds(0.5f), false);
    animationUpIdle.AddFrames(sf::Vector2i(32,0), sf::Vector2i(32,32), 1);

    auto& animationDownIdle = getAnimator()->createAnimation
        ("idle-down", "resources/animations/snorlax.png", sf::seconds(0.5f), false);
    animationDownIdle.AddFrames(sf::Vector2i(32,64), sf::Vector2i(32,32), 1);

    /* Walk animations in the four directions */
    auto& animationRight = getAnimator()->createAnimation
        ("walk-right", "resources/animations/snorlax.png", sf::seconds(1), true);
    animationRight.AddFrames(sf::Vector2i(0,32), sf::Vector2i(32,32), 3);

    auto& animationLeft = getAnimator()->createAnimation
        ("walk-left", "resources/animations/snorlax.png", sf::seconds(1), true);
    animationLeft.AddFrames(sf::Vector2i(0,96), sf::Vector2i(32,32), 3);

    auto& animationUp = getAnimator()->createAnimation
        ("walk-up", "resources/animations/snorlax.png", sf::seconds(1), true);
    animationUp.AddFrames(sf::Vector2i(0,0), sf::Vector2i(32,32), 3);

    auto& animationDown = getAnimator()->createAnimation
        ("walk-down", "resources/animations/snorlax.png", sf::seconds(1), true);
    animationDown.AddFrames(sf::Vector2i(0,64), sf::Vector2i(32,32), 3);
}

void Player::update( sf::Time & dt )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;
    
    getAnimator()->update(dt);

    float time = dt.asSeconds();

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
    {
        setDirection( RIGHT_MOVE );
        getSprite()->move( getSpeed() * time, 0 );
        if( getAnimator()->getCurrentAnimationName() != "walk-right" )
            getAnimator()->switchAnimation("walk-right");
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
    {
        setDirection( LEFT_MOVE );
        getSprite()->move( -getSpeed() * time, 0 );
        if( getAnimator()->getCurrentAnimationName() != "walk-left" )
            getAnimator()->switchAnimation("walk-left");
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
    {
        setDirection( UP_MOVE );
        getSprite()->move( 0, -getSpeed()* time );
        if( getAnimator()->getCurrentAnimationName() != "walk-up" )
            getAnimator()->switchAnimation("walk-up");
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
    {
        setDirection( DOWN_MOVE );
        getSprite()->move( 0, getSpeed() * time );
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
    
    setVector2D( getSprite()->getPosition() );
}

sf::Sprite Player::render()
{
    return *getSprite();
}