#include "state/settings_menu_state.h"

SettingsMenuState::SettingsMenuState(sf::RenderWindow* window, std::stack<State*>* states): State(window, states)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsMenuState<constructor>") : nullptr;
    _window->setMouseCursorVisible(true);
    initFPS();
}

SettingsMenuState::~SettingsMenuState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("SettingsMenuState<destructor>") : nullptr;
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
    updateFPS(dt);
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

void SettingsMenuState::onNotify(sf::Event& event)
{
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        delete _states->top();
        _states->pop();
    }
}