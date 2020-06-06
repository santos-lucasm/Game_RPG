#include "engine/game.h"

Game::Game()
{   
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<constructor>") : nullptr;

    _manager = new AssetManager();
    _clock = new Clock();

    initWindow();
    _fsm = new Machine(_window);
}

Game::~Game()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<destructor>") : nullptr;
    
    /* Get current settings */
    sf::VideoMode desktop;
    desktop.width = _window->getSize().x;
    desktop.height = _window->getSize().y;
    
    /* Save current settings on config file */ 
    std::ofstream ofs( CONFIG_PATH(window) );
    if( ofs.is_open() )
    {
        ofs << "C++ RPG GAME\n";
        ofs << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel;
        ofs << "\n250\n0\n1";
    } 
    ofs.close();

    delete _fsm;
    delete _clock;
    delete _manager;
    delete _window;
}

void Game::initWindow()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<initWindow>") : nullptr;

    /* Standard settings */
    std::string title = "None";
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int framerate_limit = 60;
    bool vertical_sync_enable = false;
    bool mouse_visible = true;

    /* Try to get last settings used (saved on config file) */ 
    std::ifstream ifs( CONFIG_PATH(window) );
    if( ifs.is_open() )
    {
        if(debugged) tmp->debug("Successfully opened window.ini file, using last screen settings.");
        std::getline(ifs, title);
        ifs >> desktop.width >> desktop.height >> desktop.bitsPerPixel;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enable;
        ifs >> mouse_visible;
    }
    else
    {
        if(debugged) tmp->debug("Couldn't open window.ini file, using standard screen settings.");
    }
    ifs.close();

    /* Open window with standard or last used settings */
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _window->setFramerateLimit( framerate_limit );
    _window->setVerticalSyncEnabled( vertical_sync_enable );
    _window->setMouseCursorVisible( mouse_visible );
}

void Game::update()
{

    /* Update IO general game Events, like pressing X on top left corner */
    updateSFMLEvents();

    /* Update current State */
    if(!_fsm->isEmpty())
        _fsm->getState()->update( _clock->getDT() );

    /* Closes game if every State is closed */
    else
        _window->close();
}

void Game::updateSFMLEvents()
{
    while( _window->pollEvent(_event) )
    {
        switch( _event.type )
        {
            case sf::Event::EventType::Closed :
                _window->close(); break;
            case sf::Event::EventType::KeyReleased:
                notify(); break;
            case sf::Event::EventType::MouseButtonPressed:
                notify(); break;
            default :
                break;
        }            
    }
}

void Game::notify()
{
    _fsm->onNotify(*_fsm, _event);
}

void Game::render()
{
    _window->clear( sf::Color::White );

    /* Render current State */
    if(!_fsm->isEmpty())
        _fsm->getState()->render();

    _window->display();
}

void Game::gameLoop()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<gameLoop>") : nullptr;

    while( _window->isOpen() )
    {   
        _clock->updateDt();

        update();

        _clock->updateElapsed();

        render();
    }
}