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
};

#endif