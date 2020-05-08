#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/Graphics.hpp>
#include "position.h"

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
        Entity class constructor sets its name, position class
    and sprite in a basic way.
        Classes that inhetits from it should handle it on their
    own way.
    */
    Entity( std::string, Position *, sf::Texture & );

    /*
    Description:
        Entity class destructor has to be virtual, in order to ensure
    that other inheritances are correctly destructed.
        Sets name, position and sprite to a correct value;
    */
    virtual ~Entity();
    
    std::string get_name();
    Position * get_position();
    sf::Sprite getSprite();

    virtual sf::Sprite render() = 0;

protected:
    /*
    Description:
        Entity class setters works in a basic way.
        Classes that inhetits from it should handle its exceptions.
    */
    void set_name( std::string );
    void set_position( Position * );
    void setSprite( sf::Texture & );

private:
    /* Entity name to be displayed during game execution */
    std::string _name;
    /* Entity current position */
    Position * _pos;
    /* Entity pattern to be rendered. TODO: Make it a reference */
    sf::Sprite _sprite;
};

#endif