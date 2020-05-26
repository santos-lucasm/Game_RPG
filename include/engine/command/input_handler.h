#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H

#include "engine/command/move.h"

class InputHandler
{
public:
    InputHandler();
    ~InputHandler();

    Command* handleInput();
    std::map<std::string, int>& getSupportedKeys();

private:
    void initKeybinds();
    void initButtons();
    std::map<std::string, int> _supportedKeys;

    Command* _buttonRight;
    Command* _buttonLeft;
    Command* _buttonUp;
    Command* _buttonDown;

    static const bool debugged = Traits<InputHandler>::debugged && Tracer::debugActive;
    static const bool traced = Traits<InputHandler>::traced && Tracer::traceActive;
};

#endif