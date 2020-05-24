#include "state/main_menu_state.h"

MainMenuState::MainMenuState(sf::RenderWindow* window): State(window)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("MainMenuState<constructor>") : nullptr;

    _background.setSize(sf::Vector2f( getWindow()->getSize().x, getWindow()->getSize().y ));
    _background.setFillColor( sf::Color(249, 219, 210)  );

    sf::Vector2i buttonSize = sf::Vector2i(200, 200);

    sf::Vector2f buttonStartPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );

    _playButton = new Button("play", AssetManager::getTexture(STATIC_PATH(play_button)), buttonStartPos, buttonSize);
}

MainMenuState::~MainMenuState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("MainMenuState<destructor>") : nullptr;
    delete _playButton;
}

void MainMenuState::update(sf::Time& dt){

    /* update keybinds */
    updateMousePositions();
    updateInput();
    _playButton->update(dt, _mousePosView);
}

void MainMenuState::updateInput()
{

}

void MainMenuState::render(sf::RenderTarget* target){

    if(!target)
        target = getWindow();
    
    target->draw( _background );
    _playButton->render(target);

}