#include "entities/player.h"

Player::Player(std::string name, sf::Texture & texture, sf::Vector2f vector, sf::Vector2i spriteSize, int speed):
Entity(name, texture, vector, spriteSize)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;

    setSpeed( speed );
    setState( RIGHT_IDLE );

    // getSprite().setTextureRect( sf::IntRect(0, 0, getSpriteSize().x, getSpriteSize().y) );
    // getSprite().setScale(2, 2);

    initAnimations();
    _inputHandler = new InputHandler();
}

Player::~Player()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<destructor>") : nullptr;
    setSpeed(0);
    delete _inputHandler;
}

void Player::initAnimations()
{
    /* Idle animation in the four directions */
    addAnimations("idle-right", ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32,32), 1);
    addAnimations("idle-left",  ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32,96), 1);
    addAnimations("idle-up",    ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32, 0), 1);
    addAnimations("idle-down",  ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32,64), 1);

    /* Walk animations in the four directions */
    addAnimations("walk-right", ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0,32), 3);
    addAnimations("walk-left",  ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0,96), 3);
    addAnimations("walk-up",    ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0, 0), 3);
    addAnimations("walk-down",  ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0,64), 3);
}

void Player::update( sf::Time & dt )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;

    float time = dt.asSeconds();

    Command * input = _inputHandler->handleInput();
    if(input)
        input->execute(*this, time);
    else
        checkIdleState();

    getAnimator()->update(dt);
}

void Player::move(float x, float y, PlayerState state, std::string animationName)
{
    getSprite().move(x, y);
    updateState(state, animationName);
}

void Player::updateState(PlayerState state, std::string animationName)
{
    setState(state);
    if( getAnimator()->getCurrentAnimationName() != animationName )
        getAnimator()->switchAnimation(animationName);
}

void Player::checkIdleState()
{
    /* If the player was moving in a X direction and the X direction button
    is not beeing pressed anymore, sets Entity direction to the X_IDLE. */
    switch( getState() )
    {
        case RIGHT_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
                updateState(RIGHT_IDLE, "idle-right");
            break;

        case LEFT_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
                updateState(LEFT_IDLE, "idle-left");
            break;

        case UP_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
                updateState(UP_IDLE, "idle-up");
            break;

        case DOWN_MOVE:
            if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
                updateState(DOWN_IDLE, "idle-down");
            break;

        default:
            break;
    }
}

void Player::render(sf::RenderTarget* target)
{
    target->draw( getSprite() );
}

void Player::setSpeed(unsigned int speed ) { _speed = speed; }
void Player::setState(PlayerState state){ _state = state; }
int Player::getSpeed(){ return _speed; }
Player::PlayerState Player::getState() { return _state; }