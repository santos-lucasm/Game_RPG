#ifndef _GAME_STATE_H
#define _GAME_STATE_H

#include "state/settings_menu_state.h"

class GameState: public State
{
public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    ~GameState();

    void update(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);
    void onNotify(sf::Event& event);

    template<typename T>
    void createGameObject(std::string textFile, sf::Vector2f startPos, sf::Vector2i size);

private:
    std::list<GameObject*> _entitiesList;
    sf::View _camera;

    static const bool debugged = Traits<GameState>::debugged && Tracer::debugActive;
    static const bool traced = Traits<GameState>::traced && Tracer::traceActive;
};

#endif