#include "state/game_state.h"

GameState::GameState(sf::RenderWindow* window): State()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<constructor>") : nullptr;
    _window = window;
}

GameState::~GameState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<destructor>") : nullptr;
}

void GameState::updateMousePositions() 
{
    _mousePosScreen = sf::Mouse::getPosition();
    _mousePosWindow = sf::Mouse::getPosition(*_window);
    _mousePosView = _window->mapPixelToCoords( sf::Mouse::getPosition() );
}

sf::RenderWindow* GameState::getWindow() { return _window; }