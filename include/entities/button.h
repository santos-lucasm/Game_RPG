#ifndef _BUTTON_H
#define _BUTTON_H

#include "entities/game_object.h"

class Button: public GameObject
{
public:
    Button(GraphicsComponent* g_cmp = nullptr, InputComponent* i_cmp = nullptr);
    ~Button();

    void update(sf::Time &dt);
    void render(sf::RenderTarget* target);

    bool isPressed();
private:

    static const bool debugged = Traits<Button>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Button>::traced && Tracer::traceActive;
};

#endif