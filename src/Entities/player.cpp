#include "Entities/player.h"
#include <iostream>
using namespace std;

Player::Player(std::string name, Position * pos, sf::Texture & text,
    int hp, int attack, int armor, int evasion): Entity(name, pos, text)
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

void Player::status()
{
    cout << "--------------------" << endl;
    cout << "| NAME: " << get_name() << endl;
    cout << "| HP  : " << get_hp() << endl;
    cout << "| ATK : " << get_attack() << endl;
    cout << "| DEF : " << get_armor() << endl;
    cout << "| EVA : " << get_evasion() << endl;
    cout << "--------------------" << endl;
}

sf::Sprite Player::render()
{
    return getSprite();
}