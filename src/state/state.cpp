#include "state/state.h"

State::State(sf::RenderWindow* window): _window(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<constructor>") : nullptr;
}

State::~State()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<destructor>") : nullptr;
    /* delete _window; */
}