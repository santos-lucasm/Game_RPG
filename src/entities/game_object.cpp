#include "entities/game_object.h"

GameObject::GameObject(GraphicsComponent* g_cmp, InputComponent* i_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameObject<constructor>") : nullptr;
    _graphicsComponent = g_cmp;
    _inputComponent = i_cmp;
    _velocity = sf::Vector2f(0,0);
}

GameObject::~GameObject()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameObject<destructor>") : nullptr;
    delete _graphicsComponent;
    delete _inputComponent;
}