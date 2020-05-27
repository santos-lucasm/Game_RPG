#ifndef _BUTTON_H
#define _BUTTON_H

#include "entities/player.h"

class Button: public Entity
{
public:
    enum {
        IDLE,
        HOVER,
        PRESSED
    }typedef ButtonState;

public:
    Button(GraphicsComponent* g_cmp = nullptr, InputComponent* i_cmp = nullptr);
    ~Button();

    void update(sf::Time &dt);
    void update(sf::Time & dt, const sf::Vector2f mousePos);
    void updateMouse(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);

    void setState(ButtonState state);
    Button::ButtonState getState();

private:
    void initAnimations();
    void initColors();

    sf::Color _idleColor;
    sf::Color _hoverColor;
    sf::Color _pressedColor;
    ButtonState _state;

    static const bool debugged = Traits<Button>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Button>::traced && Tracer::traceActive;
};

#endif