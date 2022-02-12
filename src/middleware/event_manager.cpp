#include "middleware/event_manager.h"

EventManager* EventManager::_m_Instance = nullptr;
sf::Event EventManager::_sfmlEvent;
sf::Vector2i EventManager::_mousePosWindow;
sf::Vector2i EventManager::_mousePosScreen;
sf::Vector2f EventManager::_mousePosView;

EventManager::EventManager()
{
    db<EventManager>(TRC) << "EventManager() @ " << this << "\n";

    assert( _m_Instance == nullptr );
    _m_Instance = this;
}

EventManager::~EventManager()
{
    db<EventManager>(TRC) << "~EventManager() @ " << this << "\n";

    _m_Instance = nullptr;
}

sf::Event* EventManager::updateEvents(sf::RenderWindow* wnd)
{
    updateMousePositions(wnd);
    return updateSFML(wnd);
}

bool EventManager::keyPressed(unsigned int cmd)
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Key( cmd )) )
        return true;
    else
        return false;
}

bool EventManager::keyReleased(unsigned int cmd)
{
    if( _sfmlEvent.type == sf::Event::KeyReleased && _sfmlEvent.key.code == (int)cmd )
        return true;
    else
        return false;
}

sf::Event* EventManager::updateSFML(sf::RenderWindow* wnd)
{
    while( wnd->pollEvent( _sfmlEvent ) )
    {
        switch( _sfmlEvent.type )
        {
            /* TODO: Implement this here, maybe add an "memory deallocator"
            to be able to handle this event out of main.
            
            case sf::Event::EventType::Closed :
                wnd->close(); break;
            */
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