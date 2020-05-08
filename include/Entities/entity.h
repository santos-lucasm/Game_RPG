#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/Graphics.hpp>
#include "location.h"

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
        Entity class constructor sets its name, location class
    and sprite in a basic way.
        Classes that inhetits from it should handle it on their
    own way.
    */
    Entity( std::string, Location *, sf::Texture & );

    /*
    Description:
        Entity class destructor has to be virtual, in order to ensure
    that other inheritances are correctly destructed.
        Sets name, location and sprite to a correct value;
    */
    virtual ~Entity();
    
    std::string getName();
    Location * getLocation();
    sf::Sprite * getSprite();

    virtual void update() = 0;
    virtual void walk( Location::Direction ) = 0;
    virtual sf::Sprite render() = 0;

protected:
    /*
    Description:
        Entity class setters works in a basic way.
        Classes that inhetits from it should handle its exceptions.
    */
    void setName( std::string );
    void setLocation( Location * );
    void setSprite( sf::Texture & );

private:
    /* Entity name to be displayed during game execution */
    std::string _name;
    /* Entity current location */
    Location * _location;
    /* Entity pattern to be rendered. TODO: Make it a reference */
    sf::Sprite _sprite;
};

#endif