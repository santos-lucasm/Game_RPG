#include "Entities/player.h"
#include <iostream>

Player::Player(std::string name, Location * loc, sf::Texture & text,
    int hp, int attack, int armor, int evasion): Entity(name, loc, text)
{
    set_hp( hp );
    set_attack( attack );
    set_armor( armor );
    set_evasion( evasion );
}

Player::~Player()
{
    set_hp(0);
    set_attack(0);
    set_armor(0);
    set_evasion(0);
}

void Player::set_hp( int hp ){ _hp = hp; }
void Player::set_attack( int attack ){ _attack = attack; }
void Player::set_armor( int armor ){ _armor = armor; }
void Player::set_evasion( int evasion ){ _evasion = evasion; }

int Player::get_hp(){ return _hp; }
int Player::get_attack(){ return _attack; }
int Player::get_armor(){ return _armor; }
int Player::get_evasion(){ return _evasion; }

void Player::update()
{
    /* TODO: something here with delta time */
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        walk( Location::Direction::RIGHT );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        walk( Location::Direction::LEFT );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        walk( Location::Direction::UP );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        walk( Location::Direction::DOWN );
}

void Player::walk( Location::Direction dir )
{   
    switch (dir)
    {
    case Location::Direction::RIGHT:
        getSprite()->move(1, 0); break;
    case Location::Direction::LEFT:
        getSprite()->move(-1, 0); break;
    case Location::Direction::UP:
        getSprite()->move(0, -1); break;
    case Location::Direction::DOWN:
        getSprite()->move(0, 1); break;
    case Location::Direction::NONE:
        /* TODO: throw a exception */ break;
    default:
        /* TODO: throw a exception */ break;
    }
}

sf::Sprite Player::render()
{
    return *getSprite();
}