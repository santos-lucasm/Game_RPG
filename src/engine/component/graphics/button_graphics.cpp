#include "engine/component/graphics/button_graphics.h"

ButtonGraphicsComponent::ButtonGraphicsComponent(
    sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize):
    GraphicsComponent(texture, startPos, spriteSize)
{
    initColors();
    initAnimations();
}

ButtonGraphicsComponent::~ButtonGraphicsComponent() {}

void ButtonGraphicsComponent::initColors()
{
    _idleColor = _sprite.getColor();

    _hoverColor = _sprite.getColor();
    _hoverColor.a = sf::Uint8(100);

    _pressedColor = _sprite.getColor();
    _pressedColor.a = sf::Uint8(200);
}

void ButtonGraphicsComponent::initAnimations() {}

void ButtonGraphicsComponent::update(GameObject& gameObject, float& dt)
{
    if( gameObject._pressed )
        _sprite.setColor( _pressedColor );
    else if( gameObject._hover )
        _sprite.setColor( _hoverColor );
    else
        _sprite.setColor( _idleColor );
}