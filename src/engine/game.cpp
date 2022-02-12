#include "engine/game.h"

Game::Game()
{   
    db<Game>(TRC) << "Game() @ " << this << "\n";

    m_Asset = new AssetManager();
    m_Event = new EventManager();
    _clock = new Clock();

    initWindow();
    _fsm = new Machine( new MainMenuState(_window) );
}

Game::~Game()
{
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
    delete m_Asset;
    delete m_Event;
    delete _window;
}

void Game::initWindow()
{
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
        db<Game>(INF) << "Game::initWindow @ File window.ini opened with success.\n";
        std::getline(ifs, title);
        ifs >> desktop.width >> desktop.height >> desktop.bitsPerPixel;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enable;
        ifs >> mouse_visible;
    }
    else
    {
        db<Game>(INF) << "Game::initWindow @ File window.ini couldn't be opened with success.\n";
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
    auto e = m_Event->updateEvents( _window );
    if( e )
        _fsm->goNext(*_fsm);

    /* Update current State */
    if(!_fsm->isEmpty())
        _fsm->getState()->update( _clock->getDT() );

    /* Closes game if every State is closed */
    else
        _window->close();
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
    while( _window->isOpen() )
    {   
        _clock->updateDt();

        update();

        _clock->updateElapsed();

        render();
    }
}