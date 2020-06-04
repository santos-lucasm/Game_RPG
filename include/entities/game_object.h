#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "engine/component/physics/physics_component.h"

class GameObject
{
public:
    GameObject(GraphicsComponent* g_cmp = nullptr, InputComponent* i_cmp = nullptr, PhysicsComponent* p_cmp = nullptr);
    virtual ~GameObject();

    virtual void update(sf::Time &dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    GraphicsComponent* getGraphics(){ return _graphicsComponent; }
    InputComponent* getInputs(){ return _inputComponent; }
    PhysicsComponent* getPhysics(){ return _physicsComponent; }
    
protected:
    GraphicsComponent* _graphicsComponent;
    InputComponent* _inputComponent;
    PhysicsComponent* _physicsComponent;

private:
    static const bool debugged = Traits<GameObject>::debugged && Tracer::debugActive;
    static const bool traced = Traits<GameObject>::traced && Tracer::traceActive;
};

#endif