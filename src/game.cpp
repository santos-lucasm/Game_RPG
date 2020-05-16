#include <assert.h>
#include "game.h"

Game::Game(std::string title)
{   
    if(traced) Tracer("Game<constructor>");
    assert( !title.empty() );

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _manager = new AssetManager();
    _clock = new Clock();
}

Game::~Game()
{
    if(traced) Tracer("Game<destructor>");

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        delete (*it);
    _entities_queue.clear();
    delete _manager;
    delete _clock;
}

void Game::windowConfig()
{
    if(traced) Tracer("Game<windowConfig>");

    _window->setFramerateLimit(60);
    _window->setMouseCursorVisible( false );
}

void Game::createEntity()
{
    if(traced) Tracer("Game<createEntity>");

    try
    {
        Entity* new_entity  = new Player
        ("Sevothart", AssetManager::getTexture("resources/tilesets/fenceRaw04.png"), sf::Vector2f(0, 0));

        _entities_queue.push_back(new_entity);
    }
    catch( std::exception & e )
    {
        throw e;
    }
}

void Game::updateEntities( sf::Time& dt )
{
    if(traced) Tracer("Game<updateEntities>");
    assert(dt.asMicroseconds() > 0);

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        (*it)->update(dt);
}

void Game::renderEntities()
{
    if(traced) Tracer("Game<renderEntities>");

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        _window->draw( (*it)->render() );
}

void Game::eventHandler( sf::Event& event )
{
    if(traced) Tracer("Game<eventHandler>");

    while( _window->pollEvent(event) )
    {
        if( event.type == sf::Event::EventType::Closed )
            _window->close();
    }
}

void Game::gameLoop()
{
    if(traced) Tracer("Game<gameLoop>");

    while( _window->isOpen() )
    {   
        _clock->frameStart();

        sf::Event event;
        eventHandler( event );
        
        _clock->setElapsedTime();
        updateEntities( _clock->getDT() );

        _window->clear( sf::Color::Black );
        renderEntities();
        _window->display();
    }
}