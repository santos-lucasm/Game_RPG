#include <assert.h>
#include <memory.h>
#include "game.h"

Game::Game()
{   
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<constructor>") : nullptr;

    initWindow();
    _manager = new AssetManager();
    _clock = new Clock();
}

Game::~Game()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<destructor>") : nullptr;

    /* Get current settings */
    sf::VideoMode desktop;
    desktop.width = _window->getSize().x;
    desktop.height = _window->getSize().y;
    
    /* Save current settings on config file */ 
    std::ofstream ofs("resources/config/window.ini");
    if( ofs.is_open() )
    {
        ofs << "C++ RPG GAME\n";
        ofs << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel;
        ofs << "\n60\n0\n0";
    } 
    ofs.close();

    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        delete (*it);
    _entities_queue.clear();

    delete _manager;
    delete _clock;
}

void Game::initWindow()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<initWindow>") : nullptr;

    /* Standard settings */
    std::string title = "None";
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int framerate_limit = 60;
    bool vertical_sync_enable = false;
    bool mouse_visible = false;

    /* Try to get last settings used (saved on config file) */ 
    std::ifstream ifs("resources/config/window.ini");
    if( ifs.is_open() )
    {
        std::getline(ifs, title);
        ifs >> desktop.width >> desktop.height >> desktop.bitsPerPixel;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enable;
        ifs >> mouse_visible;
    } 
    ifs.close();

    /* Open window with standard or last used settings */
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _window->setFramerateLimit( framerate_limit );
    _window->setVerticalSyncEnabled( vertical_sync_enable );
    _window->setMouseCursorVisible( mouse_visible );
}

template<typename T>
void Game::createEntity(std::string name, std::string textFile, sf::Vector2f startPos)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<createEntity>") : nullptr;
    try
    {
        Entity* new_entity  = new T (name, AssetManager::getTexture(textFile), startPos);
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

void Game::render()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<renderEntities>") : nullptr;

    _window->clear( sf::Color::Black );
    for (iterator it = _entities_queue.begin(); it != _entities_queue.end(); it++)
        _window->draw( (*it)->render() );
    _window->display();
}

void Game::eventHandler()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<eventHandler>") : nullptr;

    while( _window->pollEvent(_event) )
    {
        switch( _event.type )
        {
            case sf::Event::EventType::Closed :
                _window->close();
                break;
            case sf::Event::KeyReleased :
                if(_event.key.code == sf::Keyboard::Escape)
                    _window->close();
                break;
            default :
                break;
        }            
    }
}

void Game::gameLoop()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<gameLoop>") : nullptr;

    while( _window->isOpen() )
    {   
        _clock->updateDt();

        eventHandler();
        _clock->updateElapsed();
        updateEntities( _clock->getDT() );

        render();
    }
}

template void Game::createEntity<Player>(std::string, std::string, sf::Vector2f);
