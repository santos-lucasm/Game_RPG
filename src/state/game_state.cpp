#include "state/game_state.h"

GameState::GameState(sf::RenderWindow* window): State()
{
    db<GameState>(TRC) << "GameState() @ " << this << "\n";

    _window = window;
    initCamera();
}

GameState::~GameState()
{
    db<GameState>(TRC) << "~GameState() @ " << this << "\n";
}

void GameState::mouseVisible(bool v)
{
    if(v)
        _window->setMouseCursorVisible(true);
    else
        _window->setMouseCursorVisible(false);
}

void GameState::initCamera()
{
    _camera = sf::View( sf::Vector2f(0, 0), sf::Vector2f(_window->getSize().x, _window->getSize().y) );
    resetCamera();
}

void GameState::resetCamera()
{
    db<GameState>(INF) << "GameState::resetCamera() @ " << this << "\n";

    _camera.setCenter( _window->getSize().x/2 , _window->getSize().y/2);
    _window->setView( _camera );
}

void GameState::lockCamera(GameObject* obj)
{
    db<GameState>(INF) << "GameState::lockCamera() @ on object" << obj << "\n";

    _camera.setCenter( obj->getGraphics()->getSprite().getPosition() );
    _window->setView( _camera );
}