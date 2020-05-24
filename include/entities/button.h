#ifndef _BUTTON_H
#define _BUTTON_H

#include "entities/entity.h"

/*! @class
    Button class inherits from Entity, so it needs to define
update and render methods.
    It represents the player that's being controlled around
by the game user.
*/
class Button: public Entity
{
public:
    /*! @brief
        Button constructor invoked in createEntity methods in Game (or Map).
    Sets additional parameters to the sprite that are not trated on Entity constructor.
    @param name     Button name
    @param texture  Button texture assigned to the Sprite
    @param startPos Button sprite start position
    @param size     Button sprite size
    @param speed    Button speed
    */
    Button(std::string name, sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i size);

    /*! @brief
        Destroys possible objects created by it (like projectiles or clones).
        AssetManager handles Texture destruction.
        So, for now Button class just resets speed and spriteSize stat.
    */
    ~Button();

    /*! @brief
        Should be called every frame to update (move) player around.
    @param dt   Time passed since last frame
    */
    void update(sf::Time &dt);
    void update(sf::Time & dt, const sf::Vector2f mousePos);
    void updateMouse(const sf::Vector2f mousePos);

    /*! @brief
        Should be called every frame to render (draw) Entity on screen.
    @param  target      Where the Button should be drawed
    */
    void render(sf::RenderTarget* target);

protected:
    void setSize(sf::Vector2i size);
    sf::Vector2i getSpriteSize();

private:
    /*! @brief
        Creates every animation that will be used by
    the player Animator.
    */
    void initAnimations();

    sf::Color _color;

    /*! @property
    Size of the Entity on x and y axis. */
    sf::Vector2i _spriteSize;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Button>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Button>::traced && Tracer::traceActive;
};

#endif