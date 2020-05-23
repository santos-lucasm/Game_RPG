#include "state/state.h"

State::State(sf::RenderWindow* window): _window(window), _quit(false)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<constructor>") : nullptr;
}

State::~State()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<destructor>") : nullptr;
    /* delete _window; */
}

void State::checkQuit()
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape ) )
    {
        std::cout << "STATE WANTS TO EXIT" << std::endl; /*TODO: This should be a Debug */
        _quit = true;
    }
}

const bool& State::getQuit() const { return _quit; }