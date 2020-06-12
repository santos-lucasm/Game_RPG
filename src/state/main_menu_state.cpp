#include "state/main_menu_state.h"

MainMenuState::MainMenuState(sf::RenderWindow* window): GameState(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("MainMenuState<constructor>") : nullptr;

    _window->setMouseCursorVisible(true);

    /* initBackground */
    _background.setSize(sf::Vector2f( getWindow()->getSize().x, getWindow()->getSize().y ));
    _background.setFillColor( sf::Color(249, 219, 210)  );

    initButtons();
}

MainMenuState::~MainMenuState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("MainMenuState<destructor>") : nullptr;
    /*
    delete _playButton;
    delete _settingsButton;
    delete _saveButton;
    */
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

void MainMenuState::update(sf::Time& dt){
    updateMousePositions();
    /*
    _playButton->update(dt);
    _settingsButton->update(dt);
    _saveButton->update(dt);
    */
}

void MainMenuState::render(sf::RenderTarget* target){

    if(!target)
        target = getWindow();
    
    target->draw( _background );
    /*
    _playButton->render(target);
    _settingsButton->render(target);
    _saveButton->render(target);
    */
}

void MainMenuState::onNotify(Machine& fsm, sf::Event& event)
{
    /* Close MainMenu, and the application */
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        fsm.exitState();

    else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
        fsm.setState( new RunState(_window) );

    /*
    else if( _playButton->getGraphics()->getSprite().getGlobalBounds().contains( _mousePosView ) )
        _states->push( new GameState(_window, _states) );
    else if( _settingsButton->getGraphics()->getSprite().getGlobalBounds().contains( _mousePosView ) )
        _states->push( new SettingsMenuState(_window, _states) );
    */
}