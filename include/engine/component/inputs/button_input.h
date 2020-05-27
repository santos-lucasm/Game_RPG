#ifndef _BUTTON_INPUT_H
#define _BUTTON_INPUT_H

#include "engine/component/inputs/player_input.h"

class ButtonInputComponent: public InputComponent
{
public:
    ButtonInputComponent(sf::RenderWindow* window);
    ~ButtonInputComponent();
    void update(GameObject& gameObject);

    Command* handleInput(GameObject& gameObject);
private:
    void initButtons();
    void updateMousePositions();

    sf::RenderWindow* _window;
    Command* _mouseLeftButton;

    sf::Vector2i _mousePosWindow;
    sf::Vector2i _mousePosScreen;
    sf::Vector2f _mousePosView;
};

#endif