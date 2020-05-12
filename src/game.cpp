#include "game.h"
#include <assert.h>

Game::Game(std::string title)
{   
    if(traced) Tracer("Game<constructor>");
    assert( !title.empty() );

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _manager = new AssetManager();
}

Game::~Game()
{
    if(traced) Tracer("Game<destructor>");

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        delete (*it);
    _entities_queue.clear();
    delete _manager;
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
        Entity* tmp_entity  = new Player("Sevothart", AssetManager::getTexture("resources/sensei.png"),
        sf::Vector2f(0, 0), Location::Direction::DOWN);
        _entities_queue.push_back(tmp_entity);
    }
    catch( std::exception & e )
    {
        throw e;
    }
}

void Game::updateEntities( sf::Time& dt )
{
    if(traced) Tracer("Game<updateEntities>");
    assert(dt.asMicroseconds() < 0);

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
        sf::Time dt = _clock.restart();

        sf::Event event;
        eventHandler( event );
        
        _elapsedTime += dt;
        updateEntities(dt);

        _window->clear( sf::Color::Black );
        renderEntities();
        _window->display();
    }
}