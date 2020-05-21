#ifndef _ENTITY_H
#define _ENTITY_H

#include "manager/animator.h"

/*! @class
    This class is an abstract class, every character that's displayed on map
during game execution must to inherit Entity class.
TODO:
    Entities should be destroyed when leaving a map zone ?
*/
class Entity
{
public:
    /*! @enum
        This enumeration helps on Entity's inheritances
    to manage the correct switch between animations.
    Here, are defined Entity states for each walking
    possible direction and if they are moving or idle
    looking on that direction.
    */
    enum
    {
        RIGHT_MOVE = 1,
        RIGHT_IDLE = 2,

        LEFT_MOVE  = 3,
        LEFT_IDLE  = 4,
        
        UP_MOVE    = 5,
        UP_IDLE    = 6,

        DOWN_MOVE  = 7,
        DOWN_IDLE  = 8,

        NONE  = -1
    }typedef Direction;

    /*! @brief
        Entity class constructor, helps on code reusability to other classes
    that inherit from Entity.
    @param string   Entity's name
    @param Texture  Entity's texture reference, passed to the sprite
    @param Vector2f Entity's sprite starting position, a 2D vector
    */
    Entity(std::string name, sf::Texture &texture, sf::Vector2f startPos);

    /*! @brief
        Entity class destructor has to be virtual, in order to ensure
    that other inheritances are correctly destructed.
        Handle name and deletes animator. Sprite is handled by AssetManager.
    */
    virtual ~Entity();

    /*! @brief
        Virtual method to be implemented by every Entity. Should be called
    every frame to update (move) Entities around.
    @param Time Time passed since last frame
    */
    virtual void update(sf::Time &dt) = 0;

    /*! @brief
        Virtual method to be implemented by every Entity. Should be called
    every frame to render (draw) Entity on screen.
    @param target   Where the entity is going to be draw.
    */
    virtual void render(sf::RenderTarget *target) = 0;

protected:
    void setName(std::string name);
    void setDirection(Direction dir);
    std::string getName();
    Direction getDirection();
    sf::Sprite & getSprite();
    Animator * getAnimator();

private:
    /*! @brief
        Initializes the texture and the starting position for every Entity.
    Any other parameter like, size or scale has to be handled by each
    class that inherits from Entity.
    @param texture      New texture assigned to the sprite
    @param startPos     Starting position of the sprite
    */
    void initSprite(sf::Texture &texture, sf::Vector2f startPos);

    /*! @property
    Entity name to be displayed or used to search in an Entities list. */
    std::string _name;

    /*! @property
    Entity pattern to be rendered. */
    sf::Sprite _sprite;

    /*! @property
    Entity animator resposable for creating and managing animations used on _sprite. */
    Animator * _animator;

    /*! @property
    Entity's looking direction, helps on animations choose process. */
    Direction _dir;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Entity>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Entity>::traced && Tracer::traceActive;
};

#endif