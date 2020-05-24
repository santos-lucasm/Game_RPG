#include "state/settings_state.h"

SettingsState::SettingsState(sf::RenderWindow* window): State(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsState<constructor>") : nullptr;

    if(!window)
        initWindow();
    initFPS();
}

SettingsState::~SettingsState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsState<destructor>") : nullptr;
}

void SettingsState::initWindow()
{
}

void SettingsState::initFPS()
{
    _font.loadFromFile("resources/fonts/ostrich-regular.ttf");
    _showFPS.setFont( _font );
    _showFPS.setPosition(10, 10);
    _showFPS.setFillColor(sf::Color::Red);
    _showFPS.setCharacterSize(36);
}

void SettingsState::update(sf::Time& dt)
{   
    updateMousePositions();
    updateInput();
    updateFPS(dt);
}

void SettingsState::updateInput()
{

}

void SettingsState::updateFPS(sf::Time& dt)
{
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