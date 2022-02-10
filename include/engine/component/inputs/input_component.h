#ifndef _INPUT_COMPONENT_H
#define _INPUT_COMPONENT_H

#include "middleware/animator.h"

class InputComponent
{
public:
    InputComponent();
    virtual ~InputComponent();
    virtual void update(GameObject& gameObject) = 0;
};

#endif