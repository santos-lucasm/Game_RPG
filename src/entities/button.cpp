#include "entities/button.h"

Button::Button(GraphicsComponent* g_cmp, InputComponent* i_cmp):
GameObject(g_cmp, i_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<constructor>") : nullptr;
}

Button::~Button()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<destructor>") : nullptr;
}

void Button::update(sf::Time & dt)
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Button<update>") : nullptr;
    float time = dt.asSeconds();

    _inputComponent->update(*this);
    _graphicsComponent->update(*this, time);
}

void Button::render(sf::RenderTarget* target)
{
    target->draw( _graphicsComponent->getSprite() );
}