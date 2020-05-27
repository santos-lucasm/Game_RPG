#include "engine/component/inputs/button_input.h"

ButtonInputComponent::ButtonInputComponent(sf::RenderWindow* window):
_window(window)
{
    _window = window;
    initButtons();
}

ButtonInputComponent::~ButtonInputComponent()
{
    delete _mouseLeftButton;
}

void ButtonInputComponent::initButtons()
{
    _mouseLeftButton= new ClickCommand();
}

void ButtonInputComponent::update(GameObject& gameObject)
{
    updateMousePositions();
    Command * input = handleInput(gameObject);
    
    if(input && gameObject.getGraphics()->getSprite().getGlobalBounds().contains(_mousePosView) )
        input->execute(gameObject);
    else if ( gameObject.getGraphics()->getSprite().getGlobalBounds().contains(_mousePosView) )
        gameObject._hover = true;
    else
    {
        gameObject._pressed = false;
        gameObject._hover = false;
    }
}

void ButtonInputComponent::updateMousePositions() 
{
    _mousePosScreen = sf::Mouse::getPosition();
    _mousePosWindow = sf::Mouse::getPosition(*_window);
    _mousePosView = _window->mapPixelToCoords( sf::Mouse::getPosition() );
}

Command* ButtonInputComponent::handleInput(GameObject& gameObject)
{
    if( sf::Mouse::isButtonPressed( sf::Mouse::Button( _supportedKeys.at("MOUSE_LEFT") )) )
        return _mouseLeftButton;
    else
        return nullptr;
}