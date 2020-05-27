#include "engine/component/graphics_component.h"

GraphicsComponent::GraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize)
{
    _spriteSize = spriteSize;
    _state = PlayerState::RIGHT_IDLE;     /* Goes to PlayerGraphicsComponent */

    initSprite(texture, startPos);
    _animator = new Animator(_sprite);
    initAnimations(); /* Different on ButtonGraphicsComponent */
}

GraphicsComponent::~GraphicsComponent()
{
    delete _animator;
}

void GraphicsComponent::initSprite(sf::Texture &texture, sf::Vector2f startPos)
{
    _sprite.setTexture( texture );
    _sprite.setPosition( startPos );
}

void GraphicsComponent::initAnimations()
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

void GraphicsComponent::update(Entity& entity, float& dt)
{
    float move_x = dt * entity._speed * entity._velocity.x;
    float move_y = dt * entity._speed * entity._velocity.y;

    if(move_x==0 && move_y==0)
        checkIdleState();
    else
    {
        _sprite.move(move_x, move_y);
        chooseState(move_x, move_y);
    }
    _animator->update(dt);
}

void GraphicsComponent::chooseState(float& move_x, float& move_y)
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

void GraphicsComponent::chooseAnimation(PlayerState state, std::string animationName)
{
    _state = state;
    if( _animator->getCurrentAnimationName() != animationName)
        _animator->switchAnimation(animationName);
}

void GraphicsComponent::checkIdleState()
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

void GraphicsComponent::addAnimations(
    std::string name, std::string texture, const sf::Time duration, bool loop, sf::Vector2i startPos, unsigned int frames)                                /* Add Frames */
{
    auto& newAnimation = _animator->createAnimation(name, texture, duration, loop);
    newAnimation.AddFrames(startPos, _spriteSize, frames);
}

sf::Sprite& GraphicsComponent::getSprite() { return _sprite; }