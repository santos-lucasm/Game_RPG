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
}

void PlayerInputComponent::initButtons()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<initButtons>") : nullptr;

    _buttonRight    = new MoveRightCommand();
    _buttonLeft     = new MoveLeftCommand();
    _buttonUp       = new MoveUpCommand();
    _buttonDown     = new MoveDownCommand();
}

void PlayerInputComponent::update(GameObject& gameObject)
{
    Command * input = handleInput(gameObject);
    if(input)
        input->execute(gameObject);
    else
        gameObject._velocity = sf::Vector2f(0,0);
}

Command* PlayerInputComponent::handleInput(GameObject& gameObject)
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("RIGHT") )) )
        return _buttonRight;
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("LEFT") )) )
        return _buttonLeft;
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("UP") )) )
        return _buttonUp;
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("DOWN") )) )
        return _buttonDown;
    else
        return nullptr;
}