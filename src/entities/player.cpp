#include "entities/player.h"

Player::Player(std::string name, sf::Texture & tex, sf::Vector2f vector,
int hp, int attack, int armor, int evasion):
Entity(name, tex, vector)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<constructor>") : nullptr;

    set_hp( hp );
    set_attack( attack );
    set_armor( armor );
    set_evasion( evasion );
}

Player::~Player()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("Player<destructor>") : nullptr;
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
    /* TODO: Define a speed for each entity, to use here at move method
        speed attribute: to be multiplied by delta time and get distance
    */
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("Player<update>") : nullptr;
    float time = dt.asSeconds();

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        getSprite()->move(60 * time, 0);
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        getSprite()->move(-60 * time, 0);
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        getSprite()->move(0, -60 * time);
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        getSprite()->move(0, 60 * time);
}

sf::Sprite Player::render()
{
    return *getSprite();
}