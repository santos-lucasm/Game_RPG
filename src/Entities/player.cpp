#include "Entities/player.h"

Player::Player(std::string name, sf::Texture & tex, sf::Vector2f startPos, Location::Direction dir,
int hp, int attack, int armor, int evasion):
Entity(name, tex, startPos, dir)
{
    if(traced) Tracer("Player<constructor>");

    set_hp( hp );
    set_attack( attack );
    set_armor( armor );
    set_evasion( evasion );
}

Player::~Player()
{
    if(traced) Tracer("Player<destructor>");
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

void Player::update( sf::Time & dt )
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        walk( Location::Direction::RIGHT, dt );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        walk( Location::Direction::LEFT, dt );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        walk( Location::Direction::UP, dt );
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        walk( Location::Direction::DOWN, dt );
}

void Player::walk( Location::Direction dir, sf::Time & dt )
{   
    /* TODO: Define a speed for each entity, to use here at move method
        speed attribute: to be multiplied by delta time and get distance
    */
    float time = dt.asSeconds();
    switch (dir)
    {
    case Location::Direction::RIGHT:
        getSprite()->move(60 * time, 0); break;
    case Location::Direction::LEFT:
        getSprite()->move(-60 * time, 0); break;
    case Location::Direction::UP:
        getSprite()->move(0, -60 * time); break;
    case Location::Direction::DOWN:
        getSprite()->move(0, 60 * time); break;
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