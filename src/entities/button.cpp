#include "entities/button.h"

Button::Button(GraphicsComponent* g_cmp, InputComponent* i_cmp):
Entity(g_cmp, i_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<constructor>") : nullptr;

    setState( IDLE );

    initColors();
}

Button::~Button()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<destructor>") : nullptr;
}


void Button::initColors()
{
    _idleColor = _graphicsComponent->getSprite().getColor();

    _hoverColor = _graphicsComponent->getSprite().getColor();
    _hoverColor.a = sf::Uint8(100);

    _pressedColor = _graphicsComponent->getSprite().getColor();
    _pressedColor.a = sf::Uint8(200);
}

void Button::update(sf::Time & dt)
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Button<update>") : nullptr;
}

void Button::update(sf::Time & dt, const sf::Vector2f mousePos)
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Button<update>") : nullptr;
    float time = dt.asSeconds();
    updateMouse(mousePos);
    _graphicsComponent->update(*this, time);
}

void Button::updateMouse(const sf::Vector2f mousePos)
{   
    if( sf::Mouse::isButtonPressed(sf::Mouse::Left) && _graphicsComponent->getSprite().getGlobalBounds().contains(mousePos) )
        _graphicsComponent->getSprite().setColor( _pressedColor );
    else if( _graphicsComponent->getSprite().getGlobalBounds().contains(mousePos) )
        _graphicsComponent->getSprite().setColor( _hoverColor );
    else
        _graphicsComponent->getSprite().setColor( _idleColor );
}

void Button::render(sf::RenderTarget* target)
{
    target->draw( _graphicsComponent->getSprite() );
}

void Button::setState(ButtonState state){ _state = state; }
Button::ButtonState Button::getState() { return _state; }