#ifndef _POSITION_H
#define _POSITION_H

#include <SFML/Graphics.hpp>

/*
Description:
    Position class holds information about the current 2D position of entities.
    Also holds the direction which entities are looking, currently supporting
four looking positions.
*/
class Position
{
public:

    /*
    Description:
        Used to recognize different Sprite looking positions on Entities
    derivated classes.
        When an entity is destroyed, its Position::Direction is set to NONE.
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
        Position class constructor initializes the Vector2D and Direction
    to the Entity standard values.
    */
    Position( sf::Vector2i, Direction );

    /*
    Description:
        Set direction attribute to NONE.
    TODO:
        Should I save NPC's last position to when returning to a map zone ?
    */
    ~Position();

    /*
    Description:
        Standard way of getting information about the private attributes.
    */
    sf::Vector2i getPosition();
    int getDirection();

protected:
    /*
    Description:
        Standard way of setting class attributes, here are applied
    constraints.
    setPos:
        TODO: sf::Vector2i must be whithin window display size.
    setDir:
        Direction must has value defined on Position::Direction enum.
    */
    void setPosition( sf::Vector2i );
    void setDirection( Direction );

private:
    /* x and y axis values */
    sf::Vector2i _vector;
    /* looking direction */
    Direction _direction;
};

#endif