#include <assert.h>
#include <memory.h>
#include "game.h"

Game::Game(std::string title)
{   
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<constructor>") : nullptr;
    assert( !title.empty() );

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _manager = new AssetManager();
    _clock = new Clock();
}

Game::~Game()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<destructor>") : nullptr;

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        delete (*it);
    _entities_queue.clear();
    delete _manager;
    delete _clock;
}

void Game::windowConfig()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<windowConfig>") : nullptr;

    _window->setFramerateLimit(60);
    _window->setMouseCursorVisible( false );
}

template<typename T>
void Game::createEntity()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<createEntity>") : nullptr;
    try
    {
        Entity* new_entity  = new T ("Sevothart", AssetManager::getTexture("resources/tilesets/fenceRaw04.png"), sf::Vector2f(0, 0));
        _entities_queue.push_back(new_entity);
    }
    catch( std::exception & e )
    {
        throw e;
    }
}

void Game::updateEntities( sf::Time& dt )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<updateEntities>") : nullptr;
    assert(dt.asMicroseconds() > 0);

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        (*it)->update(dt);
}

void Game::renderEntities()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<renderEntities>") : nullptr;

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        _window->draw( (*it)->render() );
}

void Game::eventHandler( sf::Event& event )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<eventHandler>") : nullptr;

    while( _window->pollEvent(event) )
    {
        if( event.type == sf::Event::EventType::Closed )
            _window->close();
    }
}

void Game::gameLoop()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<gameLoop>") : nullptr;

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

template void Game::createEntity<Player>();

/*! @brief
    Why is this here ?
    This exists to make possible to define createEntity,
a templatized function, on a different place then its declaration.
    Without this, linker can not find a template function without
its definition together.

void LinkingFunction()
{
    Game g("oi");
    g.createEntity<Player>();
}
*/