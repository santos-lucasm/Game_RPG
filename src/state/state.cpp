#include "state/state.h"

State::State(sf::RenderWindow* window): _window(window), _quit(false) {}

State::~State(){ /* delete _window; */ }

void State::checkQuit()
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape ) )
        _quit = true;
}

const bool& State::getQuit() const { return _quit; }