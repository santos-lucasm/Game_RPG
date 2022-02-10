#include "engine/component/graphics/player_graphics.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(
    sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize):
    GraphicsComponent(texture, startPos, spriteSize)
{
    initAnimations();
}

PlayerGraphicsComponent::~PlayerGraphicsComponent() {}

void PlayerGraphicsComponent::initAnimations()
{
    /* TODO: USE CONSTRUCTOR PARAMETERS TO BUILD ANIMATIONS */

    /* Idle animation in the four directions */
    addAnimations("stand-right", ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32,32), 1);
    addAnimations("stand-left",  ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32,96), 1);
    addAnimations("stand-up",    ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32, 0), 1);
    addAnimations("stand-down",  ANIMATION_PATH(snorlax), sf::seconds(0.5f), false, sf::Vector2i(32,64), 1);

    /* Walk animations in the four directions */
    addAnimations("walk-right", ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0,32), 3);
    addAnimations("walk-left",  ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0,96), 3);
    addAnimations("walk-up",    ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0, 0), 3);
    addAnimations("walk-down",  ANIMATION_PATH(snorlax), sf::seconds(1),    true,  sf::Vector2i( 0,64), 3);

    /* Walk animations in the four directions */
    addAnimations("sprint-right", ANIMATION_PATH(snorlax), sf::seconds(0.2f),    true,  sf::Vector2i( 0,32), 3);
    addAnimations("sprint-left",  ANIMATION_PATH(snorlax), sf::seconds(0.2f),    true,  sf::Vector2i( 0,96), 3);
    addAnimations("sprint-up",    ANIMATION_PATH(snorlax), sf::seconds(0.2f),    true,  sf::Vector2i( 0, 0), 3);
    addAnimations("sprint-down",  ANIMATION_PATH(snorlax), sf::seconds(0.2f),    true,  sf::Vector2i( 0,64), 3);
}

void PlayerGraphicsComponent::update(GameObject& gameObject, float& dt)
{
    sf::Vector2f distance = gameObject.getPhysics()->_position;

    /* set current standing animation */
    if( gameObject.currentState()->getName() == "STANDING" )
        setStandingAnimation( gameObject.currentState()->getDirection() );
        
    /* set current walking animation */
    else if( gameObject.currentState()->getName() == "WALKING" )
    {
        _sprite.move( distance );
        setWalkingAnimation( gameObject.currentState()->getDirection() );
    }

    /* set current sprinting animation */
    else if( gameObject.currentState()->getName() == "SPRINTING" )
    {
        _sprite.move( distance );
        setSprintingAnimation( gameObject.currentState()->getDirection() );
    }

    /* Update Animator */
    _animator->update(dt);
}

void PlayerGraphicsComponent::setStandingAnimation(unsigned int dir)
{
    switch(dir)
    {
        case PlayerState::RIGHT:
            chooseAnimation("stand-right"); break;
        case PlayerState::LEFT:
            chooseAnimation("stand-left"); break;
        case PlayerState::UP:
            chooseAnimation("stand-up"); break;
        case PlayerState::DOWN:
            chooseAnimation("stand-down"); break;
        default:
            break;
    }
}

void PlayerGraphicsComponent::setWalkingAnimation(unsigned int dir)
{
    switch(dir)
    {
        case PlayerState::RIGHT:
            chooseAnimation("walk-right"); break;
        case PlayerState::LEFT:
            chooseAnimation("walk-left"); break;
        case PlayerState::UP:
            chooseAnimation("walk-up"); break;
        case PlayerState::DOWN:
            chooseAnimation("walk-down"); break;
        default:
            break;
    }
}

void PlayerGraphicsComponent::setSprintingAnimation(unsigned int dir)
{
    switch(dir)
    {
        case PlayerState::RIGHT:
            chooseAnimation("sprint-right"); break;
        case PlayerState::LEFT:
            chooseAnimation("sprint-left"); break;
        case PlayerState::UP:
            chooseAnimation("sprint-up"); break;
        case PlayerState::DOWN:
            chooseAnimation("sprint-down"); break;
        default:
            break;
    }
}

void PlayerGraphicsComponent::chooseAnimation(std::string name)
{
    /* check if the corresponding animation is already beeing played */
    if( _animator->getCurrentAnimationName() != name )
        _animator->switchAnimation( name );
}

