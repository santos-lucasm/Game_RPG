#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "position.h"

/*
TODO: Define abstract methods: update render display move
*/
class Entity
{
public:
    Entity( std::string, Position *, sf::Texture & );
    virtual ~Entity();
    
    std::string get_name();
    Position * get_position();
    sf::Sprite getSprite();

    virtual sf::Sprite render() = 0;

protected:
    void set_name( std::string );
    void set_position( Position * );
    void setSprite( sf::Texture & );

private:
    std::string _name;
    Position * _pos;
    sf::Sprite _sprite;
};

#endif