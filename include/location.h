#ifndef _LOCATION_H
#define _LOCATION_H

#include <SFML/Graphics.hpp>

/*
Description:
    Location class holds information about the current 2D Location of entities.
    Also holds the direction which entities are looking, currently supporting
four looking Locations.
*/
class Location
{
public:

    /*
    Description:
        Used to recognize different Sprite looking Locations on Entities
    derivated classes.
        When an entity is destroyed, its Location::Direction is set to NONE.
    */
    enum
    {
        UP      = 0,
        DOWN    = 1,
        LEFT    = 2,
        RIGHT   = 3,
        NONE    = -1
    }typedef Direction;

public:
    /*
    Description:
        Location class constructor initializes the Vector2D and Direction
    to the Entity standard values.
    */
    Location( sf::Vector2f, Direction );

    /*
    Description:
        Set direction attribute to NONE.
    TODO:
        Should I save NPC's last Location to when returning to a map zone ?
    */
    ~Location();

    /*
    Description:
        Standard way of getting information about the private attributes.
    */
    sf::Vector2f getVector2D();
    int getDirection();

    /*
    Description:
        Standard way of setting class attributes, here are applied
    constraints.
    setPos:
        TODO: sf::Vector2i must be whithin window display size.
    setDir:
        Direction must has value defined on Location::Direction enum.
    */
    void setVector2D( sf::Vector2f );
    void setDirection( Direction );

private:
    /* x and y axis values */
    sf::Vector2f _vector;
    /* looking direction */
    Direction _direction;
    /* Toggle entry fuction points to debugging */
    bool traced;
};

#endif