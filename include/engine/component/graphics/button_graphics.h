#ifndef _BUTTON_GRAPHICS_H
#define _BUTTON_GRAPHICS_H

#include "engine/component/graphics/player_graphics.h"
#include "entities/button.h"

class ButtonGraphicsComponent: public GraphicsComponent, public Button
{
public:
    ButtonGraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    ~ButtonGraphicsComponent();

    void update(GameObject& gameObject, float& dt);

private:
    void initAnimations();
    void initColors();

    sf::Color _idleColor;
    sf::Color _hoverColor;
    sf::Color _pressedColor;
};

#endif