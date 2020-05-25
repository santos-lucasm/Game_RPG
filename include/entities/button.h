#ifndef _BUTTON_H
#define _BUTTON_H

#include "entities/entity.h"

class Button: public Entity
{
public:
    Button(std::string name, sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    ~Button();

    void update(sf::Time &dt);
    void update(sf::Time & dt, const sf::Vector2f mousePos);
    void updateMouse(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);

private:
    void initAnimations();
    void initColors();

    sf::Color _idleColor;
    sf::Color _hoverColor;
    sf::Color _pressedColor;

    static const bool debugged = Traits<Button>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Button>::traced && Tracer::traceActive;
};

#endif