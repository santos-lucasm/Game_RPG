#include "state/main_menu_state.h"

MainMenuState::MainMenuState(sf::RenderWindow* window): GameState(window)
{
    db<MainMenuState>(TRC) << "MainMenuState() @ " << this << "\n";

    mouseVisible(true);

    initBackground();
    initButtons();
}

MainMenuState::~MainMenuState()
{
    db<MainMenuState>(TRC) << "~MainMenuState() @ " << this << "\n";
    /*
    delete _playButton;
    delete _settingsButton;
    delete _saveButton;
    */
}

void MainMenuState::initBackground()
{
    _background.setSize(sf::Vector2f( _window->getSize().x, _window->getSize().y ));
    _background.setFillColor( sf::Color(249, 219, 210)  );
}

void MainMenuState::initButtons()
{
    /*
    sf::Vector2i buttonSize = sf::Vector2i(256, 256);

    sf::Vector2f playButtonPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f - buttonSize.x*3/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );

    sf::Vector2f settingsButtonPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f + buttonSize.x*3/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );

    sf::Vector2f saveButtonPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );
    
    _playButton = new Button(
        new ButtonGraphicsComponent(AssetManager::getTexture( ICON_PATH(movie) ), playButtonPos, buttonSize),
        new ButtonInputComponent(_window) );

    _settingsButton = new Button(
        new ButtonGraphicsComponent(AssetManager::getTexture( ICON_PATH(settings) ), settingsButtonPos, buttonSize),
        new ButtonInputComponent(_window) );

    _saveButton = new Button(
        new ButtonGraphicsComponent(AssetManager::getTexture( ICON_PATH(diskette) ), saveButtonPos, buttonSize),
        new ButtonInputComponent(_window) );
    */
}

void MainMenuState::update(sf::Time& dt)
{
    /*
    _playButton->update(dt);
    _settingsButton->update(dt);
    _saveButton->update(dt);
    */
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target = _window;
    
    target->draw( _background );

    /*
    _playButton->render(target);
    _settingsButton->render(target);
    _saveButton->render(target);
    */
}

void MainMenuState::goNext(Machine& fsm)
{
    /* Close MainMenu, and the application */
    if( EventManager::keyReleased( EventManager::Keybinds::ESC ) )
        fsm.exitState();

    else if( EventManager::keyReleased( EventManager::Keybinds::SPACE ) )
        fsm.setState( new RunState(_window) );

    /*
    else if( _playButton->getGraphics()->getSprite().getGlobalBounds().contains( _mousePosView ) )
        fsm.setState( new RunState(_window) );
    else if( _settingsButton->getGraphics()->getSprite().getGlobalBounds().contains( _mousePosView ) )
        fsm.setState( new SettingsMenuState(_window) );
    */
}