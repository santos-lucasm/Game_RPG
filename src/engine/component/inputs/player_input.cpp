#include "engine/component/inputs/player_input.h"

PlayerInputComponent::PlayerInputComponent()
{
    db<PlayerInputComponent>(TRC) << "PlayerInputComponent() @ " << this << "\n";
    // initButtons();
}

PlayerInputComponent::~PlayerInputComponent()
{
    db<PlayerInputComponent>(TRC) << "~PlayerInputComponent() @ " << this << "\n";
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
    bool walking = true; /* Handle four directions movement */
    if( EventManager::keyPressed("RIGHT") )
        gameObject.getMachine()->goNext( EventManager::keybind("RIGHT") );
    else if( EventManager::keyPressed("LEFT") )
        gameObject.getMachine()->goNext( EventManager::keybind("LEFT") );
    else if( EventManager::keyPressed("UP") )
        gameObject.getMachine()->goNext( EventManager::keybind("UP") );
    else if( EventManager::keyPressed("DOWN") )
        gameObject.getMachine()->goNext( EventManager::keybind("DOWN") );
    else
        walking = false;
    
    /* Toggle sprinting */
    if( EventManager::keyPressed("LEFT_SHIFT") && walking )
        gameObject.getMachine()->goNext( EventManager::keybind("LEFT_SHIFT") );

    if(!walking)
        gameObject.getMachine()->goNext( 0 );
}