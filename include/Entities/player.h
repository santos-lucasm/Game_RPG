#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entities/entity.h"
#include "location.h"

class Player: public Entity
{
public:
    Player(std::string name, sf::Texture & tex, sf::Vector2f startPos, Location::Direction dir,
        int hp = 100, int attack = 20, int armor = 10, int evasion = 3);
    ~Player();

    int get_hp();
    int get_attack();
    int get_armor();
    int get_evasion();

    void update(sf::Time &);
    void walk( Location::Direction, sf::Time & );
    sf::Sprite render();

private:
    void set_hp( int );
    void set_attack( int );
    void set_armor( int );
    void set_evasion( int );

private:
    int _hp;
    int _attack;
    int _armor;
    int _evasion;

    /* Traits flag that allow debug */
    static const bool debugged = Traits<Player>::debugged;
    /* Traits flag that allow tracing if debug and tracer is active */
    static const bool traced = debugged && Tracer::enable;
};

#endif