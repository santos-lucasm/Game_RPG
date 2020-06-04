#include "engine/component/graphics/player_graphics.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(
    sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize):
    GraphicsComponent(texture, startPos, spriteSize)
{
    _state = PlayerState::RIGHT_IDLE;
    initAnimations();
    initStates();
}

PlayerGraphicsComponent::~PlayerGraphicsComponent() {}

void PlayerGraphicsComponent::initAnimations()
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

void PlayerGraphicsComponent::initStates()
{
    _stateToAnimation.emplace(PlayerState::RIGHT_IDLE,  "idle-right");
    _stateToAnimation.emplace(PlayerState::LEFT_IDLE,   "idle-left");
    _stateToAnimation.emplace(PlayerState::UP_IDLE,     "idle-up");
    _stateToAnimation.emplace(PlayerState::DOWN_IDLE,   "idle-down");

    _stateToAnimation.emplace(PlayerState::RIGHT_MOVE,  "walk-right");
    _stateToAnimation.emplace(PlayerState::LEFT_MOVE,   "walk-left");
    _stateToAnimation.emplace(PlayerState::UP_MOVE,     "walk-up");
    _stateToAnimation.emplace(PlayerState::DOWN_MOVE,   "walk-down");
}

void PlayerGraphicsComponent::update(GameObject& gameObject, float& dt)
{
    sf::Vector2f distance = gameObject.getPhysics()->_position;

    if( distance.x==0 && distance.y==0 )
        updateIdle();
    else
    {
        _sprite.move( distance );
        updateMove( distance );
    }
    _animator->update(dt);
}

void PlayerGraphicsComponent::updateIdle()
{
    switch(_state)
    {
        case RIGHT_MOVE:
            setState(RIGHT_IDLE); break;
        case LEFT_MOVE:
            setState(LEFT_IDLE); break;
        case UP_MOVE:
            setState(UP_IDLE); break;
        case DOWN_MOVE:
            setState(DOWN_IDLE); break;
        default:
            break;
    }
}

void PlayerGraphicsComponent::updateMove(sf::Vector2f& distance)
{
    if(distance.y == 0)
    {
        if(distance.x > 0)
            setState(RIGHT_MOVE);
        else if(distance.x < 0)
            setState(LEFT_MOVE);
    }
    else
    {
        if(distance.y < 0)
            setState(UP_MOVE);
        else if(distance.y > 0)
            setState(DOWN_MOVE);
    }
}

void PlayerGraphicsComponent::setState(PlayerState state)
{
    _state = state;
    /* check if the corresponding animation is already beeing played */
    if( _animator->getCurrentAnimationName() != _stateToAnimation.at(_state) )
        _animator->switchAnimation( _stateToAnimation.at(_state) );
}

