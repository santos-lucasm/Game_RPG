#ifndef _GAME_STATE_H
#define _GAME_STATE_H

#include "engine/component/inputs/player_input.h"
#include "engine/component/graphics/player_graphics.h"
#include "engine/component/physics/player_physics.h"

#include "state/state.h"

class GameState: public State
{
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    virtual void update(sf::Time& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void goNext(Machine& fsm) {}

    void mouseVisible(bool v);

    void initCamera();
    void resetCamera();
    void lockCamera(GameObject* obj);
protected:
    sf::RenderWindow* _window;
    sf::View _camera;
};

#endif