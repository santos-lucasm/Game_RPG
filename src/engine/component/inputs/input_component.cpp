#include "engine/component/inputs/input_component.h"

InputComponent::InputComponent()
{
    initKeybinds();
}

InputComponent::~InputComponent() {}

void InputComponent::initKeybinds()
{   
    std::ifstream ifs( CONFIG_PATH(keybinds) );

    if( ifs.is_open() )
    {
        std::string key = "";
        int key_value = 0;

        while(ifs >> key >> key_value)
        {
            _supportedKeys.emplace(key, key_value);
        }
    }
    ifs.close();
}