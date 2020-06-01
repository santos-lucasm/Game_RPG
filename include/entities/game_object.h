#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "engine/component/inputs/input_component.h"

class GameObject
{
public:
    enum MachineState {
        /* ButtonStates */
        IDLE,
        HOVER,
        PRESSED,
        NONE
    };
    MachineState _state;

public:
    GameObject(GraphicsComponent* g_cmp = nullptr, InputComponent* i_cmp = nullptr);
    virtual ~GameObject();

    virtual void update(sf::Time &dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    GraphicsComponent* getGraphics(){ return _graphicsComponent; }
    InputComponent* getInputs(){ return _inputComponent; }

    sf::Vector2f _velocity;
    int _speed;
protected:
    GraphicsComponent* _graphicsComponent;
    InputComponent* _inputComponent;

private:
    static const bool debugged = Traits<GameObject>::debugged && Tracer::debugActive;
    static const bool traced = Traits<GameObject>::traced && Tracer::traceActive;
};

#endif