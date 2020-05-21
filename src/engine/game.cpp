#include "engine/game.h"

Game::Game()
{   
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<constructor>") : nullptr;

    initWindow();
    initDisplay();
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
    std::ofstream ofs( CONFIG_PATH(window) );
    if( ofs.is_open() )
    {
        ofs << "C++ RPG GAME\n";
        ofs << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel;
        ofs << "\n250\n0\n0";
    } 
    ofs.close();

    /* Destroys dynamically alocated memory */
    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        delete (*it);
    _entitiesList.clear();

    delete _manager;
    delete _clock;
}

void Game::initWindow()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<initWindow>") : nullptr;

    /* Standard settings */
    std::string title = "None";
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int framerate_limit = 60;
    bool vertical_sync_enable = false;
    bool mouse_visible = false;

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

void Game::initDisplay()
{
    _font.loadFromFile("resources/fonts/ostrich-regular.ttf");
    _showFPS.setFont( _font );
    _showFPS.setPosition(10, 10);
    _showFPS.setFillColor(sf::Color::Red);
    _showFPS.setCharacterSize(36);
}

template<typename T>
void Game::createEntity(std::string name, std::string textFile, sf::Vector2f startPos, sf::Vector2i size)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Game<createEntity>") : nullptr;
    try
    {
        Entity* new_entity  = new T (name, AssetManager::getTexture(textFile), startPos, size);
        _entitiesList.push_back(new_entity);
    }
    catch( std::exception & e )
    {
        throw e;
    }
}

void Game::update()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<updateEntities>") : nullptr;

    updateSFMLEvents();

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->update( _clock->getDT() );

    updateDisplay();
}

void Game::updateSFMLEvents()
{
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

void Game::updateDisplay()
{   
    /* Clear ostringstream */
    _fps.clear();
    _fps.str("");

    /* Calculates FPS */
    _fps << ( 1/_clock->getDT().asSeconds() );

    /* Passes data to the sf::Text element */
    _showFPS.setString( "FPS: " + _fps.str() );
}

void Game::render()
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Game<renderEntities>") : nullptr;

    _window->clear( sf::Color::White );

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->render( _window );

    _window->draw( _showFPS );
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

template void Game::createEntity<Player>(std::string, std::string, sf::Vector2f, sf::Vector2i);