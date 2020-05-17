#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/Graphics.hpp>
#include "utilities/tracer.h"

/*! @brief
    This class is an abstract class, every character that's displayed on map
during game execution has to inherit Entity class.
TODO:
    Entities should be destroyed when leaving a map zone ?
*/
class Entity
{
public:
    /*! @brief
        Entity class constructor, helps on code reusability to other classes
    that inherit from Entity.
    @param string   Entity's name
    @param Texture  Entity's texture reference, passed to the sprite
    @param Vector2f Entity's position reference, a 2D vector
    */
    Entity( std::string, sf::Texture &, sf::Vector2f );

    /*! @brief
        Entity class destructor has to be virtual, in order to ensure
    that other inheritances are correctly destructed.
        Handle name and vector values. Sprite is handled by AssetManager.
    */
    virtual ~Entity();

    /*! @brief
        Virtual method to be implemented by every Entity. Should be called
    every frame to update (move) Entities around.
    @param Time Time passed since last frame
    */
    virtual void update(sf::Time &) = 0;

    /*! @brief
        Virtual method to be implemented by every Entity. Should be called
    every frame to render (draw) Entity on screen.
    @return
        Returns the sprite to be draw.
    */
    virtual sf::Sprite render() = 0;

protected:
    /*! @brief
        Changes Entity's name property
    @param string   New name
    */
    void setName( std::string );

    /*! @brief
        Changes Entity's vector2f property
    @param vector2f   New position
    */
    void setVector2D( sf::Vector2f );

    /*! @brief
        Changes Entity's sprite
    @param Texture New texture to be assigned to sprite
    */
    void setSprite( sf::Texture & );

    /*! @brief
    @return Returns current Entity name.
    */
    std::string getName();

    /*! @brief
    @return Returns current Entity position vector.
    */
    sf::Vector2f getVector2D();

    /*! @brief
    @return Returns current Entity sprite.
    */
    sf::Sprite * getSprite();

private:
    /*! @property
    Entity name to be displayed during game execution. */
    std::string _name;

    /*! @property
    Entity current location. */
    sf::Vector2f _vector2D;

    /*! @property
    Entity pattern to be rendered. */
    sf::Sprite _sprite;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Entity>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Entity>::traced && Tracer::traceActive;
};

#endif