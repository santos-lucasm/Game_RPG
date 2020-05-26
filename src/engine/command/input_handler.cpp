#include "engine/command/input_handler.h"

InputHandler::InputHandler()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<constructor>") : nullptr;
    initKeybinds();
    initButtons();
}

InputHandler::~InputHandler()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<destructor>") : nullptr;

    delete _buttonRight;
    delete _buttonLeft;
    delete _buttonUp;
    delete _buttonDown;
}

void InputHandler::initKeybinds()
{   
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<initKeybinds>") : nullptr;
    std::ifstream ifs( CONFIG_PATH(keybinds) );

    if( ifs.is_open() )
    {
        if(debugged) tmp->debug("Successfully opened keybinds.ini file, using last screen settings.");
        std::string key = "";
        int key_value = 0;

        while(ifs >> key >> key_value)
        {
            _supportedKeys.emplace(key, key_value);
        }
    }
    else
    {
        if(debugged) tmp->debug("Couldn't open keybinds.ini file, using standard screen settings.");
    }
    ifs.close();
}

void InputHandler::initButtons()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("InputHandler<initButtons>") : nullptr;

    _buttonRight    = new MoveRightCommand();
    _buttonLeft     = new MoveLeftCommand();
    _buttonUp       = new MoveUpCommand();
    _buttonDown     = new MoveDownCommand();
}

Command* InputHandler::handleInput()
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( getSupportedKeys().at("RIGHT") )) )
        return _buttonRight;
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( getSupportedKeys().at("LEFT") )) )
        return _buttonLeft;
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( getSupportedKeys().at("UP") )) )
        return _buttonUp;
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( getSupportedKeys().at("DOWN") )) )
        return _buttonDown;
    else
        return nullptr;
}

std::map<std::string, int>& InputHandler::getSupportedKeys(){ return _supportedKeys; }