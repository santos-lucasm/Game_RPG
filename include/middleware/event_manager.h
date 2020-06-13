#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include "middleware/asset_manager.h"

class EventManager
{
public:
    EventManager();
    ~EventManager();

    // updateSFML( sf::RenderWindow& )
    // updateMousePositions
    static int keybind(std::string name);
    static bool keyPressed( std::string name );
    // keyReleased()
private:
    void initKeybinds();
    static std::map<std::string, int> _supportedKeys;
    // sf::Event _event
    static EventManager* _Instance;
};

#endif