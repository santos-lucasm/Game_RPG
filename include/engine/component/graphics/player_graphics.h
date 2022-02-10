#ifndef _PLAYER_GRAPHICS_H
#define _PLAYER_GRAPHICS_H

#include "entities/player.h"

class PlayerGraphicsComponent: public GraphicsComponent
{
public:
    PlayerGraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    ~PlayerGraphicsComponent();

    void update(GameObject& GameObject, float& dt);

private:
    void initAnimations();

    void setStandingAnimation(unsigned int dir);
    void setWalkingAnimation(unsigned int dir);
    void setSprintingAnimation(unsigned int dir);

    void chooseAnimation(std::string name);
};

#endif