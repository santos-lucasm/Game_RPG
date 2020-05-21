#ifndef _PLAYER_H
#define _PLAYER_H

#include "entities/entity.h"

/*! @class
    Player class inherits from Entity, so it needs to define
update and render methods.
    It represents the player that's being controlled around
by the game user.
*/
class Player: public Entity
{
public:
    /*! @brief
        Player constructor invoked in createEntity methods in Game (or Map).
    Sets additional parameters to the sprite that are not trated on Entity constructor.
    @param name     Player name
    @param texture  Player texture assigned to the Sprite
    @param startPos Player sprite start position
    @param size     Player sprite size
    @param speed    Player speed
    */
    Player(std::string name, sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i size,int speed = 40);

    /*! @brief
        Destroys possible objects created by it (like projectiles or clones).
        AssetManager handles Texture destruction.
        So, for now Player class just resets speed and spriteSize stat.
    */
    ~Player();

    /*! @brief
        Should be called every frame to update (move) player around.
    @param dt   Time passed since last frame
    */
    void update(sf::Time &dt);

    /*! @brief
        Should be called every frame to render (draw) Entity on screen.
    @param  target      Where the Player should be drawed
    */
    void render(sf::RenderTarget* target);

protected:
    void setSpeed(int speed);
    void setSize(sf::Vector2i size);
    int getSpeed();
    sf::Vector2i getSpriteSize();

private:
    /*! @brief
        Creates every animation that will be used by
    the player Animator.
    */
    void initAnimations();

    /*! @property
    Speed stat, used on move method. */
    int _speed;

    /*! @property
    Size of the Entity on x and y axis. */
    sf::Vector2i _spriteSize;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Player>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Player>::traced && Tracer::traceActive;
};

#endif