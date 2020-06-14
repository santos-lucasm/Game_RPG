#include "middleware/event_manager.h"

EventManager* EventManager::_Instance = nullptr;
sf::Event EventManager::_sfmlEvent;
sf::Vector2i EventManager::_mousePosWindow;
sf::Vector2i EventManager::_mousePosScreen;
sf::Vector2f EventManager::_mousePosView;

EventManager::EventManager()
{
    db<EventManager>(TRC) << "EventManager() @ " << this << "\n";

    assert( _Instance == nullptr );
    _Instance = this;
}

EventManager::~EventManager()
{
    db<EventManager>(TRC) << "~EventManager() @ " << this << "\n";

    _Instance = nullptr;
}

void EventManager::updateEvents(sf::RenderWindow* wnd)
{
    updateSFML(wnd);
    updateMousePositions(wnd);
}

sf::Event* EventManager::updateSFML(sf::RenderWindow* wnd)
{
    while( wnd->pollEvent( _sfmlEvent ) )
    {
        switch( _sfmlEvent.type )
        {
            case sf::Event::EventType::Closed :
                // wnd->close(); break;
            case sf::Event::EventType::KeyReleased:
                return &_sfmlEvent; break;
            case sf::Event::EventType::MouseButtonPressed:
                return &_sfmlEvent; break;
            default:
                break;
        }   
    }
    return nullptr;
}

void EventManager::updateMousePositions(sf::RenderWindow* wnd)
{
    _mousePosScreen = sf::Mouse::getPosition();
    _mousePosWindow = sf::Mouse::getPosition(*wnd);
    _mousePosView = wnd->mapPixelToCoords( sf::Mouse::getPosition() );
}

bool EventManager::keyReleased(unsigned int cmd)
{
    if( _sfmlEvent.type == sf::Event::KeyReleased && _sfmlEvent.key.code == (int)cmd )
        return true;
    else
        return false;
}

bool EventManager::keyPressed(unsigned int cmd)
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Key( cmd )) )
        return true;
    else
        return false;
}