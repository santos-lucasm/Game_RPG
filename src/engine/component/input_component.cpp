#include "engine/component/input_component.h"

InputComponent::InputComponent()
{
    _inputHandler = new InputHandler();
}

InputComponent::~InputComponent() {}

void InputComponent::update(Entity& entity)
{
    Command * input = _inputHandler->handleInput();
    if(input)
        input->execute(entity);
    else
        entity._velocity = sf::Vector2f(0,0);
}