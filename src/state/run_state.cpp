#include "state/run_state.h"

RunState::RunState(sf::RenderWindow* window): GameState(window)
{
    db<MainMenuState>(TRC) << "RunState() @ " << this << "\n";
    mouseVisible(false);

    createGameObject<Player>(ANIMATION_PATH(snorlax), sf::Vector2f(200,200), sf::Vector2i(32, 32));
    lockCamera( *_entitiesList.begin() );
}

RunState::~RunState()
{
    db<MainMenuState>(TRC) << "~RunState() @ " << this << "\n";

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        delete (*it);
    _entitiesList.clear();
}

void RunState::update(sf::Time& dt){

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->update(dt);
}

void RunState::render(sf::RenderTarget* target){

    if(!target)
        target = _window;

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->render( target );
}

template<typename T>
inline void RunState::createGameObject(std::string textFile, sf::Vector2f startPos, sf::Vector2i size)
{
    db<MainMenuState>(INF) << "RunState::createGameObject() @ Creating at (" << startPos.x << "," << startPos.y << ")" << "\n";
    try
    {
        GameObject* new_obj  = new T(
            new PlayerGraphicsComponent( AssetManager::getTexture(textFile), startPos, size ),
            new PlayerInputComponent(),
            new PlayerPhysicsComponent(startPos)
            );
        
        _entitiesList.push_back(new_obj);
    }
    catch( std::exception & e )
    {
        throw e;
    }
}

void RunState::goNext(Machine& fsm)
{
    /* Close GameState, going back to the MainMenuScreen */
    if( EventManager::keyReleased( EventManager::Keybinds::ESC ) )
    {
        mouseVisible(true);
        resetCamera();
        fsm.exitState();
    }

    /* Open SettingsScreen */
    if( EventManager::keyReleased( EventManager::Keybinds::TAB ) )
        fsm.setState( new SettingsMenuState(_window) );
}