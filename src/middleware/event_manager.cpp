#include "middleware/event_manager.h"

EventManager* EventManager::_Instance = nullptr;
std::map<std::string, int> EventManager::_supportedKeys;

EventManager::EventManager()
{
    db<EventManager>(TRC) << "EventManager() @ " << this << "\n";

    assert( _Instance == nullptr );
    _Instance = this;

    initKeybinds();
}

EventManager::~EventManager()
{
    db<EventManager>(TRC) << "~EventManager() @ " << this << "\n";

    _Instance = nullptr;
}

void EventManager::initKeybinds()
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

int EventManager::keybind(std::string name)
{
    return _supportedKeys.at( name );
}

bool EventManager::keyPressed(std::string name)
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Key( keybind(name) )) )
        return true;
    else
        return false;
}