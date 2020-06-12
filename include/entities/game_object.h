#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "engine/component/inputs/input_component.h"
#include "engine/component/physics/physics_component.h"
#include "engine/component/graphics/graphics_component.h"

#include "engine/machine_state.h"

class GameObject
{
public:
    GameObject(GraphicsComponent* g_cmp = nullptr, InputComponent* i_cmp = nullptr, PhysicsComponent* p_cmp = nullptr);
    virtual ~GameObject();

    virtual void update(sf::Time &dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    GraphicsComponent* getGraphics();
    InputComponent* getInputs();
    PhysicsComponent* getPhysics();
    Machine* getMachine();
    State* currentState();
    
protected:
    GraphicsComponent* _graphicsComponent;
    InputComponent* _inputComponent;
    PhysicsComponent* _physicsComponent;
    Machine* _automata;

private:
    static const bool debugged = Traits<GameObject>::debugged && Tracer::debugActive;
    static const bool traced = Traits<GameObject>::traced && Tracer::traceActive;
};

#endif