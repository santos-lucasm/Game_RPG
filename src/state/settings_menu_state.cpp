#include "state/settings_menu_state.h"

SettingsMenuState::SettingsMenuState(sf::RenderWindow* window): State(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsMenuState<constructor>") : nullptr;

    if(!window)
        initWindow();
    initFPS();
}

SettingsMenuState::~SettingsMenuState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsMenuState<destructor>") : nullptr;
}

void SettingsMenuState::initWindow()
{
}

void SettingsMenuState::initFPS()
{
    /* TODO: This should be loaded with an FontManager, that inherits AssetManager */
    _font.loadFromFile(FONTS_PATH(ostrich-regular));
    _showFPS.setFont( _font );
    _showFPS.setPosition(10, 10);
    _showFPS.setFillColor(sf::Color::Red);
    _showFPS.setCharacterSize(36);
}

void SettingsMenuState::update(sf::Time& dt)
{   
    updateMousePositions();
    updateInput();
    updateFPS(dt);
}

void SettingsMenuState::updateInput()
{

}

void SettingsMenuState::updateFPS(sf::Time& dt)
{
    /* Clear ostringstream */
    _fps.clear();
    _fps.str("");

    /* Calculates FPS */
    _fps << ( 1/dt.asSeconds() );

    /* Passes data to the sf::Text element */
    _showFPS.setString( "FPS: " + _fps.str() );
}

void SettingsMenuState::render(sf::RenderTarget* target)
{    
    if(!target)
        target = getWindow();
        
    target->draw( _showFPS );
}