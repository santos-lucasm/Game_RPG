#include "engine/component/inputs/player_input.h"

PlayerInputComponent::PlayerInputComponent()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<constructor>") : nullptr;
    initButtons();
}

PlayerInputComponent::~PlayerInputComponent()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<destructor>") : nullptr;

    delete _buttonRight;
    delete _buttonLeft;
    delete _buttonUp;
    delete _buttonDown;
    delete _buttonSprint;
}

void PlayerInputComponent::initButtons()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<initButtons>") : nullptr;

    _buttonRight    = new MoveRightCommand();
    _buttonLeft     = new MoveLeftCommand();
    _buttonUp       = new MoveUpCommand();
    _buttonDown     = new MoveDownCommand();
    _buttonSprint   = new SprintCommand();
}

void PlayerInputComponent::update(GameObject& gameObject)
{
    Command * input = handleInput(gameObject);
    if(input)
        input->execute(gameObject);
    else {
        gameObject.getPhysics()->_velocity = sf::Vector2f(0,0);
    }
}

Command* PlayerInputComponent::handleInput(GameObject& gameObject)
{
    /* Handle running button */
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("LEFT_SHIFT") )) )
        _buttonSprint->execute(gameObject);
    else
        gameObject.getPhysics()->_speed = 40;

    /* Handle four directions */
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("RIGHT") )) )
        return _buttonRight;
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("LEFT") )) )
        return _buttonLeft;
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("UP") )) )
        return _buttonUp;
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("DOWN") )) )
        return _buttonDown;
    else
        return nullptr;
}