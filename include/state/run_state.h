#ifndef _RUN_STATE_H
#define _RUN_STATE_H

#include "state/settings_menu_state.h"

class RunState: public GameState
{
public:
    RunState(sf::RenderWindow* window);
    ~RunState();

    void update(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);
    void onNotify(Machine& fsm, sf::Event& event);

    template<typename T>
    void createGameObject(std::string textFile, sf::Vector2f startPos, sf::Vector2i size);

private:
    std::list<GameObject*> _entitiesList;
};

#endif