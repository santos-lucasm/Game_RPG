#ifndef _PLAYER_H
#define _PLAYER_H

#include "entities/game_object.h"
#include "state/player_state.h"

class Player: public GameObject
{
public:
    Player(GraphicsComponent* g_cmp, InputComponent* i_cmp, PhysicsComponent* p_cmp = nullptr);
    ~Player();

    void update(sf::Time &dt);
    void render(sf::RenderTarget* target);

};

#endif