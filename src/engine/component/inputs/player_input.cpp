#include "engine/component/inputs/player_input.h"

PlayerInputComponent::PlayerInputComponent()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<constructor>") : nullptr;
    // initButtons();
}

PlayerInputComponent::~PlayerInputComponent()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<destructor>") : nullptr;
    /*
    delete _buttonRight;
    delete _buttonLeft;
    delete _buttonUp;
    delete _buttonDown;
    delete _buttonSprint;
    */
}

void PlayerInputComponent::initButtons()
{
    /*
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<initButtons>") : nullptr;

    _buttonRight    = new MoveRightCommand( 1 );
    _buttonLeft     = new MoveLeftCommand( 2 );
    _buttonUp       = new MoveUpCommand( 3 );
    _buttonDown     = new MoveDownCommand( 4 );

    _buttonSprint   = new SprintCommand( 10 );
    */
}

void PlayerInputComponent::update(GameObject& gameObject)
{
    handleInput(gameObject);
}

void PlayerInputComponent::handleInput(GameObject& gameObject)
{
    /*
    Handle running button.
    TODO: Supress SprintingState, here just set speed. (There is no difference from Walking and State)
    */
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("LEFT_SHIFT") )) )
        gameObject.getMachine()->goNext( 10 );

    /* Handle four directions */
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("RIGHT") )) )
        gameObject.getMachine()->goNext( 1 );
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("LEFT") )) )
        gameObject.getMachine()->goNext( 2 );
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("UP") )) )
        gameObject.getMachine()->goNext( 3 );
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( _supportedKeys.at("DOWN") )) )
        gameObject.getMachine()->goNext( 4 );
    else
        gameObject.getMachine()->goNext( 0 );
}