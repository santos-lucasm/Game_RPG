#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "manager/asset_manager.h"

/*! @class
    Used by Entities to manage its animations.
Every GameObject that is not static on the Game will
have it has a private property, to be used with
the GameObject's sprite.
*/
class Animator
{
public:
    /*! @struct
        This struct is the base for any animation that'll be created by
    the Animator class.
    */
    struct Animation
    {
        std::string _name;
        std::string _textureName;
        std::vector<sf::IntRect> _frames;
        sf::Time _duration;
        bool _looping;

        /*! @brief
            Constructor to initialize the many Animation parameters.
        @param  name            Name of the animation, to search for it
        @param  textureName     Name of the texture called by AssetManager
        @param  duration        How long the animation lasts
        @param  looping         If the animation occurs just once or not
        */
        Animation(std::string const& name, std::string const& texture, sf::Time const& duration, bool loop);

        /*! @brief
            Using the texture passed on constructor, loops in the horizontal section of the
        spritesheet starting on the first parameter, going through the texture number of frames
        times of size X, and add the section to the animation.
        @param  startFrom       Starting X and Y position of the first frame on the texture
        @param  frameSize       Size of each frame that'll be added
        @param  frames          How many frames of size equals to frameSize will be added
        */
        void AddFrames( sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int frames);
    };

    /*! @brief
        Class constructor, sets sprite, currentAnimation to NULL
    and resets the current animation time.
    @param  sprite  Sprite in which the animator will operate
    */
    Animator(sf::Sprite& sprite);

    ~Animator();

    /*! @brief
        Creates an animation object using the parameters and
    add it to a private list of animations.
        If there's no animation playing, the created one is set
    has the current animation to the sprite.
    @param  name            Name of the animation, to search for it
    @param  textureName     Name of the texture called by AssetManager
    @param  duration        How long the animation lasts
    @param  looping         If the animation occurs just once or not
    @return
        A reference to the created animation, useful for the user
    add frames to it right away, without having to search on the list
    for the name of animation right after created it.
    */
    Animator::Animation& createAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool loop);

    /*! @brief
        Updates the current animation playing accordingly
    to the current deltatime and current time of the animation.
        Changing between frames and looping animation if its a looping
    one. Keeps showing last animation frame if the current animation
    of the GameObject does not loops.
    */
    void update(float const& dt);

    /*! @brief
        Calls findAnimation method to see if exists an animation
    with the passed name. If it finds one, it calls switchAnimation
    private method to work with the texture setting.
    @param  name    Name of the animation to be passed to findAnimation
    @return
        If there's an animation with the requested name, returns true.
        Else, returns false.
    */
    bool switchAnimation(std::string const& name);

    /*! @brief
        Returns the current GameObject's playing animation
    name, if it exists.
    @return
        If there's an current animation, returns its name.
        Else, returns an empty string.
    */
    std::string getCurrentAnimationName() const;

private:
    /*! @brief
        If the passed animation exists, sets the texture of the sprite to the
    texture of the animation using AssetManager. Then assigns animation to the
    current animation and resets the time.
        Else, throws an exception.
    @param animation    Animation on the list of GameObject's animation to be switched in
    */
    void switchAnimation(Animator::Animation* animation);

    /*! @brief
        Tries to find the animation corresponding
    to the passed string on the list of animations.
    @param  name    Name of the animation to be searched on the list.
    @return
        If an corresponding animation is found, returns a reference to it.
        Else, returns false.
    */
    Animator::Animation* findAnimation(std::string const& name);

    /*! @property
    Sprite that's changed by the animator. */
    sf::Sprite& _sprite;

    /*! @property
    Time since the current animation starts to play. */
    float _currentTime;

    /*! @property
    List of created animations related to this sprite. */
    std::list<Animator::Animation> _animations;

    /*! @property
    Current animation beeing played in this sprite. */
    Animator::Animation* _currentAnimation;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Animator>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Animator>::traced && Tracer::traceActive;
};

#endif