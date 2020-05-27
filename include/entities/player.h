#ifndef _PLAYER_H
#define _PLAYER_H

#include "entities/entity.h"

class Player: public Entity
{
public:
    Player(GraphicsComponent* g_cmp, InputComponent* i_cmp, int speed = 40);
    ~Player();

    void update(sf::Time &dt);
    void render(sf::RenderTarget* target);

private:
    static const bool debugged = Traits<Player>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Player>::traced && Tracer::traceActive;
};

#endif