#include "entities/button.h"

Button::Button(std::string name, sf::Texture & texture, sf::Vector2f startPos, sf::Vector2i spriteSize):
Entity(name, texture, startPos, spriteSize)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<constructor>") : nullptr;

    setState( IDLE );

    getSprite().setTextureRect( sf::IntRect(0, 0, getSpriteSize().x, getSpriteSize().y) );
    getSprite().setPosition( startPos );

    initAnimations();
    initColors();
}

Button::~Button()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<destructor>") : nullptr;
}

void Button::initAnimations() {}

void Button::initColors()
{
    _idleColor = getSprite().getColor();

    _hoverColor = getSprite().getColor();
    _hoverColor.a = sf::Uint8(100);

    _pressedColor = getSprite().getColor();
    _pressedColor.a = sf::Uint8(200);
}

void Button::update(sf::Time & dt)
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Button<update>") : nullptr;
    getAnimator()->update(dt);
}

void Button::update(sf::Time & dt, const sf::Vector2f mousePos)
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Button<update>") : nullptr;
    updateMouse(mousePos);
    getAnimator()->update(dt);
}

void Button::updateMouse(const sf::Vector2f mousePos)
{   
    if( sf::Mouse::isButtonPressed(sf::Mouse::Left) && getSprite().getGlobalBounds().contains(mousePos) )
        getSprite().setColor( _pressedColor );
    else if( getSprite().getGlobalBounds().contains(mousePos) )
        getSprite().setColor( _hoverColor );
    else
        getSprite().setColor( _idleColor );
}

void Button::render(sf::RenderTarget* target)
{
    target->draw( getSprite() );
}

void Button::setState(ButtonState state){ _state = state; }
Button::ButtonState Button::getState() { return _state; }