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

void PlayerInputComponent::update(GameObject& obj)
{
    handleInput(obj);
}

void PlayerInputComponent::handleInput(GameObject& obj)
{
    bool walking = true; /* Handle four directions movement */
    if( EventManager::keyPressed( EventManager::Keybinds::RIGHT ) )
        obj.getMachine()->goNext( EventManager::Keybinds::RIGHT );
    else if( EventManager::keyPressed( EventManager::Keybinds::LEFT ) )
        obj.getMachine()->goNext( EventManager::Keybinds::LEFT );
    else if( EventManager::keyPressed( EventManager::Keybinds::UP ) )
        obj.getMachine()->goNext( EventManager::Keybinds::UP );
    else if( EventManager::keyPressed( EventManager::Keybinds::DOWN ) )
        obj.getMachine()->goNext( EventManager::Keybinds::DOWN );
    else
        walking = false;
    
    /* Toggle sprinting */
    if( EventManager::keyPressed( EventManager::Keybinds::LEFT_SHIFT ) && walking )
        obj.getMachine()->goNext( EventManager::Keybinds::LEFT_SHIFT );

    if(!walking)
        obj.getMachine()->goNext( EventManager::Keybinds::NONE );
}