#include "entities/entity.h"

Entity::Entity(GraphicsComponent* g_cmp, InputComponent* i_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<constructor>") : nullptr;
    _graphicsComponent = g_cmp;
    _inputComponent = i_cmp;
    _velocity = sf::Vector2f(0,0);
}

Entity::~Entity()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Entity<destructor>") : nullptr;
    delete _graphicsComponent;
    delete _inputComponent;
}