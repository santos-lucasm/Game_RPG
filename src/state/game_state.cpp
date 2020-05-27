#include "state/game_state.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states): State(window, states)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<constructor>") : nullptr;

    _window->setMouseCursorVisible(false);
    createGameObject<Player>(ANIMATION_PATH(snorlax), sf::Vector2f(200,200), sf::Vector2i(32, 32));
}

GameState::~GameState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<destructor>") : nullptr;

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        delete (*it);
    _entitiesList.clear();
}

void GameState::update(sf::Time& dt){

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->update(dt);

}

void GameState::render(sf::RenderTarget* target){

    if(!target)
        target = getWindow();

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->render( target );
}

template<typename T>
void GameState::createGameObject(std::string textFile, sf::Vector2f startPos, sf::Vector2i size)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<createGameObject>") : nullptr;

    try
    {
        GameObject* new_GameObject  = new T(
            new PlayerGraphicsComponent( AssetManager::getTexture(textFile), startPos, size ),
            new PlayerInputComponent() );
        
        _entitiesList.push_back(new_GameObject);
    }
    catch( std::exception & e )
    {
        throw e;
    }
}

void GameState::onNotify(sf::Event& event)
{
    /* Close GameState, going back to the MainMenuScreen */
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        delete _states->top();
        _states->pop();
        getWindow()->setMouseCursorVisible(true);
    }

    /* Open SettingsScreen */
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Tab)
    {
        _states->push( new SettingsMenuState(_window, _states) );
    }
}

template void GameState::createGameObject<Player>(std::string, sf::Vector2f, sf::Vector2i);