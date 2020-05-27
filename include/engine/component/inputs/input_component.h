#ifndef _INPUT_COMPONENT_H
#define _INPUT_COMPONENT_H

#include "engine/component/graphics/graphics_component.h"

class InputComponent
{
public:
    InputComponent();
    virtual ~InputComponent();
    virtual void update(GameObject& gameObject) = 0;

protected:
    std::map<std::string, int> _supportedKeys;
    virtual void initButtons() = 0;

private:
    void initKeybinds();
};

#endif