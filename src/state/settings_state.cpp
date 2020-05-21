#include "state/settings_state.h"

SettingsState::SettingsState(sf::RenderWindow* window): State(window)
{
    _font.loadFromFile("resources/fonts/ostrich-regular.ttf");
    _showFPS.setFont( _font );
    _showFPS.setPosition(10, 10);
    _showFPS.setFillColor(sf::Color::Red);
    _showFPS.setCharacterSize(36);
}

SettingsState::~SettingsState(){}

void SettingsState::update(sf::Time& dt)
{
    /* Clear ostringstream */
    _fps.clear();
    _fps.str("");

    /* Calculates FPS */
    _fps << ( 1/dt.asSeconds() );

    /* Passes data to the sf::Text element */
    _showFPS.setString( "FPS: " + _fps.str() );
}

void SettingsState::render(sf::RenderTarget *target)
{    
    if(!target)
        target = _window;
        
    target->draw( _showFPS );
}