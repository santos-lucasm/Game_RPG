#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/Graphics.hpp>
#include "utilities/tracer.h"

/*
Description:
    This class is an abstract class, every character that's displayed on map
during game execution has to inherit Entity class.
TODO:
    Entities should be destroyed when leaving a map zone ?
    Define abstract methods: update render display move
*/
class Entity
{
public:
    /*
    Description:
        Entity class constructor sets its name, sprite, and location class.
        Classes that inhetits from it should handle it on their
    own way.
    */
    Entity( std::string, sf::Texture &, sf::Vector2f );

    /*
    Description:
        Entity class destructor has to be virtual, in order to ensure
    that other inheritances are correctly destructed.
        Handle name and location destruction. Sprite is handled by AssetManager.
    */
    virtual ~Entity();
    
    std::string getName();
    sf::Vector2f getVector2D();
    sf::Sprite * getSprite();

    virtual void update(sf::Time &) = 0;
    virtual sf::Sprite render() = 0;

protected:
    /*
    Description:
        Entity class setters works in a basic way.
        Classes that inhetits from it should handle its exceptions.
    */
    void setName( std::string );
    void setVector2D( sf::Vector2f );
    void setSprite( sf::Texture & );

private:
    /* Entity name to be displayed during game execution */
    std::string _name;
    /* Entity current location */
    sf::Vector2f _vector2D;
    /* Entity pattern to be rendered. TODO: Make it a reference */
    sf::Sprite _sprite;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Entity>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Entity>::traced && Tracer::traceActive;
};

#endif