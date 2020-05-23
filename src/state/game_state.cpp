#include "state/game_state.h"

GameState::GameState(sf::RenderWindow* window): State(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<constructor>") : nullptr;

    createEntity<Player>("Player1", ANIMATION_PATH(snorlax), sf::Vector2f(200,200), sf::Vector2i(32, 32));
}

GameState::~GameState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<destructor>") : nullptr;

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        delete (*it);
    _entitiesList.clear();
}

void GameState::update(sf::Time& dt){

    /* update keybinds */
    updateInput();

    /* updates entities */
    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->update(dt);

}

void GameState::updateInput()
{

}

void GameState::render(sf::RenderTarget* target){

    if(!target)
        target = getWindow();

    for (auto it = _entitiesList.begin(); it != _entitiesList.end(); it++)
        (*it)->render( target );
}

template<typename T>
void GameState::createEntity(std::string name, std::string textFile, sf::Vector2f startPos, sf::Vector2i size)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("GameState<createEntity>") : nullptr;

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

template void GameState::createEntity<Player>(std::string, std::string, sf::Vector2f, sf::Vector2i);