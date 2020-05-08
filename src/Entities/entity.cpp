#include "Entities/entity.h"
using namespace std;

Entity::Entity( string name, Position * pos, sf::Texture& texture)
{
    set_name( name );
    set_position( pos );
    setSprite( texture );
}

Entity::~Entity()
{
    set_name(nullptr);
    set_position(nullptr);
}

void Entity::set_name( string name ){ _name = name; }
void Entity::set_position( Position * pos) { _pos = pos; }
void Entity::setSprite( sf::Texture & texture ) { _sprite.setTexture( texture ); }

string Entity::get_name(){ return _name; }
Position * Entity::get_position() { return _pos; }
sf::Sprite Entity::getSprite(){ return _sprite; }