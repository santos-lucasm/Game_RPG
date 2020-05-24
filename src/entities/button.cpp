#include "entities/button.h"

Button::Button(std::string name, sf::Texture & texture, sf::Vector2f startPos, sf::Vector2i size):
Entity(name, texture, startPos)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<constructor>") : nullptr;

    setSize(size);
    _color = getSprite().getColor();

    getSprite().setTextureRect( sf::IntRect(0, 0, getSpriteSize().x, getSpriteSize().y) );
    getSprite().setPosition( startPos );

    initAnimations();
}

Button::~Button()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Button<destructor>") : nullptr;
    setSize( sf::Vector2i(0,0) );
}

void Button::initAnimations() {}

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

    if( getSprite().getGlobalBounds().contains( mousePos ) )
        getSprite().setColor( sf::Color(249, 219, 210, 100) );
    else
        getSprite().setColor( _color );
}

void Button::render(sf::RenderTarget* target)
{
    target->draw( getSprite() );
}

void Button::setSize(sf::Vector2i size){ _spriteSize = size; }
sf::Vector2i Button::getSpriteSize(){ return _spriteSize; }