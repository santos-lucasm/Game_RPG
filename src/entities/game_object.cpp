#include "entities/game_object.h"

GameObject::GameObject(GraphicsComponent* g_cmp, InputComponent* i_cmp, PhysicsComponent* p_cmp)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameObject<constructor>") : nullptr;
    _graphicsComponent = g_cmp;
    _inputComponent = i_cmp;
    _physicsComponent = p_cmp;
}

GameObject::~GameObject()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameObject<destructor>") : nullptr;
    delete _graphicsComponent;
    delete _inputComponent;
    delete _physicsComponent;
}

GraphicsComponent*  GameObject::getGraphics(){ return _graphicsComponent; }
InputComponent*     GameObject::getInputs()  { return _inputComponent; }
PhysicsComponent*   GameObject::getPhysics() { return _physicsComponent; }
Machine*            GameObject::getMachine() { return _automata; }
State*              GameObject::currentState(){ return getMachine()->getState(); }