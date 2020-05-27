#include "engine/component/graphics/player_graphics.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(
    sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize):
    GraphicsComponent(texture, startPos, spriteSize)
{
    _state = PlayerState::RIGHT_IDLE;
    initAnimations();
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

void PlayerGraphicsComponent::update(GameObject& gameObject, float& dt)
{
    float move_x = dt * gameObject._speed * gameObject._velocity.x;
    float move_y = dt * gameObject._speed * gameObject._velocity.y;

    if(move_x==0 && move_y==0)
        checkIdleState();
    else
    {
        _sprite.move(move_x, move_y);
        chooseState(move_x, move_y);
    }
    _animator->update(dt);
}

void PlayerGraphicsComponent::chooseState(float& move_x, float& move_y)
{
    if(move_y == 0)
    {
        if(move_x > 0)
            chooseAnimation(RIGHT_MOVE, "walk-right");
        else if(move_x < 0)
            chooseAnimation(LEFT_MOVE, "walk-left");
    }
    else
    {
        if(move_y < 0)
            chooseAnimation(UP_MOVE, "walk-up");
        else if(move_y > 0)
            chooseAnimation(DOWN_MOVE, "walk-down");
    }
}

void PlayerGraphicsComponent::chooseAnimation(PlayerState state, std::string animationName)
{
    _state = state;
    if( _animator->getCurrentAnimationName() != animationName)
        _animator->switchAnimation(animationName);
}

void PlayerGraphicsComponent::checkIdleState()
{
    switch(_state)
    {
        case RIGHT_MOVE:
            chooseAnimation(RIGHT_IDLE, "idle-right"); break;
        case LEFT_MOVE:
            chooseAnimation(LEFT_IDLE, "idle-left"); break;
        case UP_MOVE:
            chooseAnimation(UP_IDLE, "idle-up"); break;
        case DOWN_MOVE:
            chooseAnimation(DOWN_IDLE, "idle-down"); break;
        default:
            break;
    }
}

