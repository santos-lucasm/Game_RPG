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
    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;

    void updateMousePositions();
    void mouseVisible(bool v);

    void initCamera();
    void resetCamera();
    void lockCamera(GameObject* obj);
protected:
    /* TODO: Goes to EventManager */
    sf::RenderWindow* _window;
    sf::View _camera;

    sf::Vector2i _mousePosWindow;
    sf::Vector2i _mousePosScreen;
    sf::Vector2f _mousePosView;
};

#endif