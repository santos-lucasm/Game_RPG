#include "state/state.h"

State::State(sf::RenderWindow* window): _window(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<constructor>") : nullptr;
}

State::~State()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<destructor>") : nullptr;
}

void State::updateMousePositions() 
{
    _mousePosScreen = sf::Mouse::getPosition();
    _mousePosWindow = sf::Mouse::getPosition(*_window);
    _mousePosView = getWindow()->mapPixelToCoords( sf::Mouse::getPosition() );
}