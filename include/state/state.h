#ifndef _STATE_H
#define _STATE_H

#include "entities/player.h"

class State
{
public:
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void update(sf::Time& dt) = 0;
    virtual void updateMousePositions();
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
    sf::RenderWindow* getWindow();

    sf::RenderWindow* _window;
    sf::Vector2i _mousePosWindow;
    sf::Vector2i _mousePosScreen;
    sf::Vector2f _mousePosView;

private:
    static const bool debugged = Traits<State>::debugged && Tracer::debugActive;
    static const bool traced = Traits<State>::traced && Tracer::traceActive;
};

#endif