#include "state/settings_state.h"

SettingsState::SettingsState(sf::RenderWindow* window): State(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsState<constructor>") : nullptr;

    _font.loadFromFile("resources/fonts/ostrich-regular.ttf");
    _showFPS.setFont( _font );
    _showFPS.setPosition(10, 10);
    _showFPS.setFillColor(sf::Color::Red);
    _showFPS.setCharacterSize(36);
}

SettingsState::~SettingsState(){ std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsState<destructor>") : nullptr; }

void SettingsState::update(sf::Time& dt)
{   
    checkQuit();

    /* Clear ostringstream */
    _fps.clear();
    _fps.str("");

    /* Calculates FPS */
    _fps << ( 1/dt.asSeconds() );

    /* Passes data to the sf::Text element */
    _showFPS.setString( "FPS: " + _fps.str() );
}

void SettingsState::render(sf::RenderTarget* target)
{    
    if(!target)
        target = getWindow();
        
    target->draw( _showFPS );
}