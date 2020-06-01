#include "engine/component/inputs/button_input.h"

ButtonInputComponent::ButtonInputComponent(sf::RenderWindow* window):
_window(window)
{
    _window = window;
    initButtons();
}

ButtonInputComponent::~ButtonInputComponent()
{
    // delete _mouseLeftButton;
}

void ButtonInputComponent::initButtons()
{
    // _mouseLeftButton= new ClickCommand();
}

void ButtonInputComponent::update(GameObject& gameObject)
{
    updateMousePositions();
    
    if( sf::Mouse::isButtonPressed( sf::Mouse::Button( _supportedKeys.at("MOUSE_LEFT"))) 
        && gameObject.getGraphics()->getSprite().getGlobalBounds().contains(_mousePosView) )
        gameObject._state = GameObject::PRESSED;
    else if ( gameObject.getGraphics()->getSprite().getGlobalBounds().contains(_mousePosView) )
        gameObject._state = GameObject::HOVER;
    else
        gameObject._state = GameObject::IDLE;
}

void ButtonInputComponent::updateMousePositions() 
{
    _mousePosScreen = sf::Mouse::getPosition();
    _mousePosWindow = sf::Mouse::getPosition(*_window);
    _mousePosView = _window->mapPixelToCoords( sf::Mouse::getPosition() );
}