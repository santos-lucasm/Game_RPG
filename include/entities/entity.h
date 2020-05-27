#ifndef _ENTITY_H
#define _ENTITY_H

#include "manager/animator.h"
#include "engine/component/input_component.h"
#include "engine/component/graphics_component.h"

class Entity
{
public:
    Entity(GraphicsComponent* g_cmp = nullptr, InputComponent* i_cmp = nullptr);
    virtual ~Entity();

    virtual void update(sf::Time &dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    GraphicsComponent* getGraphics(){ return _graphicsComponent; }

    sf::Vector2f _velocity;
    int _speed;
protected:
    GraphicsComponent* _graphicsComponent;
    InputComponent* _inputComponent;

private:
    static const bool debugged = Traits<Entity>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Entity>::traced && Tracer::traceActive;
};

#endif