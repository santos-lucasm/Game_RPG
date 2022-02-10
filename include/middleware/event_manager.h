#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include "middleware/asset_manager.h"

class EventManager
{
public:
    enum
    {
        NONE        = 100,

        RIGHT       = 72,
        LEFT        = 71,
        UP          = 73,
        DOWN        = 74,

        ESC         = 36,
        LEFT_SHIFT  = 38,
        LEFT_CTRL   = 37,
        SPACE       = 57,
        TAB         = 60,

        LEFT_MOUSE  = 0
    
    }typedef Keybinds;

public:
    EventManager();
    ~EventManager();

    static void updateEvents(sf::RenderWindow* wnd);
    static sf::Event* updateSFML(sf::RenderWindow* wnd);
    static void updateMousePositions(sf::RenderWindow* wnd);

    static bool keyPressed( unsigned int cmd );
    static bool keyReleased( unsigned int cmd );
private:
    static sf::Event _sfmlEvent;
    static EventManager* _Instance;

    static sf::Vector2i _mousePosWindow;
    static sf::Vector2i _mousePosScreen;
    static sf::Vector2f _mousePosView;
};

#endif