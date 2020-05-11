#include "game.h"
#include <iostream>

Game::Game(std::string title)
{   
    traced = false;
    if(traced) std::cout << "Game<constructor>: IN" << std::endl;

    if( title.empty() )
        return; /* TODO: Throw invalid argument exception */

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _manager = new AssetManager();

    if(traced) std::cout << "Game<constructor>: OUT" << std::endl;
}

Game::~Game()
{
    if(traced) std::cout << "Game<destructor: IN" << std::endl;

    // _entities_queue.erase( _entities_queue.begin(), _entities_queue.end() );
    for (std::list<Entity*>::iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        delete (*it);
    
    delete _manager;

    if(traced) std::cout << "Game<destructor>: OUT" << std::endl;
}

void Game::windowConfig()
{
    if(traced) std::cout << "Game<windowConfig>: IN" << std::endl;

    _window->setFramerateLimit(60);
    _window->setMouseCursorVisible( false );

    if(traced) std::cout << "Game<windowConfig>: OUT" << std::endl;
}

void Game::createEntity()
{
    if(traced) std::cout << "Game<createEntity>: IN" << std::endl;

    Entity* tmp_entity  = new Player("Sevothart", AssetManager::getTexture("resources/sensei.png"),
    sf::Vector2f(0, 0), Location::Direction::DOWN);

    _entities_queue.push_back(tmp_entity);

    if(traced) std::cout << "Game<createEntity>: OUT" << std::endl;
}

void Game::eventHandler( sf::Event& event )
{
    if(traced) std::cout << "Game<eventHandler>: IN" << std::endl;

    while( _window->pollEvent(event) )
    {
        if( event.type == sf::Event::EventType::Closed )
            _window->close();
    }

    if(traced) std::cout << "Game<eventHandler>: OUT" << std::endl;
}

void Game::updateEntities( sf::Time& dt )
{
    if(traced) std::cout << "Game<updateEntities>: IN" << std::endl;

    for (std::list<Entity*>::iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        (*it)->update(dt);

    if(traced) std::cout << "Game<updateEntities>: OUT" << std::endl;
}

void Game::renderEntities()
{
    if(traced) std::cout << "Game<renderEntities>: IN" << std::endl;

    for (std::list<Entity*>::iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        _window->draw( (*it)->render() );

    if(traced) std::cout << "Game<renderEntities>: OUT" << std::endl;
}

void Game::gameLoop()
{
    if(traced) std::cout << "Game<gameLoop>: IN" << std::endl;

    while( _window->isOpen() )
    {   
        sf::Time dt = _clock.restart();

        sf::Event event;
        eventHandler( event );
        
        _elapsedTime += dt;
        updateEntities(dt);

        _window->clear( sf::Color::Black );
        renderEntities();
        _window->display();
    }

    if(traced) std::cout << "Game<gameLoop>: OUT" << std::endl;
}