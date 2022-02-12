#include "engine/application.h"

Application::Application()
{   
    db<Application>(TRC) << "Game() @ " << this << "\n";

    _m_Asset = new AssetManager();
    _m_Event = new EventManager();
    _clock = new Clock();

    initWindow();
    _fsm = new Machine( new MainMenuState(_window) );
}

Application::~Application()
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
    delete _m_Asset;
    delete _m_Event;
    delete _window;
}

void Application::run()
{
    while( _window->isOpen() )
    {   
        _clock->updateDeltaTime();

        update();

        _clock->updateElapsed();

        render();
    }
}

void Application::initWindow()
{
    /* Standard settings */
    std::string title = "Application";
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int framerate_limit = 60;
    bool vertical_sync_enable = false;
    bool mouse_visible = true;

    /* Try to get last settings used (saved on config file) */ 
    std::ifstream ifs( CONFIG_PATH(window) );
    if( ifs.is_open() )
    {
        db<Application>(INF) << "Game::initWindow @ File window.ini opened with success.\n";
        std::getline(ifs, title);
        ifs >> desktop.width >> desktop.height >> desktop.bitsPerPixel;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enable;
        ifs >> mouse_visible;
    }
    else
    {
        db<Application>(INF) << "Game::initWindow @ File window.ini couldn't be opened with success.\n";
    }
    ifs.close();

    /* Open window with standard or last used settings */
    _window = new sf::RenderWindow(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), title);
    _window->setFramerateLimit( framerate_limit );
    _window->setVerticalSyncEnabled( vertical_sync_enable );
    _window->setMouseCursorVisible( mouse_visible );
}

void Application::update()
{
    /* Update IO general game Events, like pressing X on top left corner */
    auto e = _m_Event->updateEvents( _window );
    if( e )
        _fsm->goNext(*_fsm);

    /* Update current State */
    if(!_fsm->isEmpty())
        _fsm->state()->update( _clock->deltaTime() );

    /* Closes game if every State is closed */
    else
        _window->close();
}

void Application::render()
{
    _window->clear( sf::Color::White );

    /* Render current State */
    if(!_fsm->isEmpty())
        _fsm->state()->render();

    _window->display();
}