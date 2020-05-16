#ifndef _PLAYER_H
#define _PLAYER_H

#include "entities/entity.h"

/*! @class
    Player class inherits from Entity, so it needs to define
update and render methods.
    It represents the player that's been controlled around
by the game user.
*/
class Player: public Entity
{
public:
    /*! @brief
        Player constructor invoked in createEntity methods in Game (or Map)
    @param string   Entity name
    @param Texture  Entity texture assigned to the Sprite
    @param int      Entity speed
    */
    Player(std::string, sf::Texture &, sf::Vector2f , int = 40);

    /*! @brief
        Player inherits Entity base class, that handles Name and vector2D.
    AssetManager handle Texture destruction. So Player class just resets speed stat.
    */
    ~Player();

    /*! @brief
    @return Returns entity speed stat
    */
    int getSpeed();

    /*! @brief
    @param int New speed stat
    */
    void setSpeed( int );

    /*! @brief
        Should be called every frame to update (move) Entities around.
    @param Time Time passed since last frame
    */
    void update(sf::Time &);

    /*! @brief
        Should be called every frame to render (draw) Entity on screen.
    @return Returns the sprite to be draw.
    */
    sf::Sprite render();

private:
    /*! @property
    Speed stat.
    TODO: Make speed be a lower number, i.e, 3. Involve some calcutions when moving Entity
    around, like terrain or buffs (from spells or equipment).
    */
    int _speed;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Player>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Player>::traced && Tracer::traceActive;
};

#endif