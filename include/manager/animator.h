#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include <SFML/Graphics.hpp>
#include "utilities/tracer.h"
#include "manager/asset_manager.h"
class Animator
{
public:
    struct Animation
    {
        std::string _name;
        std::string _textureName;
        std::vector<sf::IntRect> _frames;
        sf::Time _duration;
        bool _looping;

        Animation(std::string const&, std::string const&, sf::Time const&, bool);
        void AddFrames( sf::Vector2i const&, sf::Vector2i const&, unsigned int );
    };

    Animator(sf::Sprite&);
    Animator::Animation& createAnimation(std::string const&, std::string const&, sf::Time const&, bool);
    void update(sf::Time const&);

    bool switchAnimation(std::string const&);
    std::string getCurrentAnimationName() const;

private:
    Animator::Animation* findAnimation(std::string const&);
    void switchAnimation(Animator::Animation*);

    sf::Sprite& _sprite;
    sf::Time _currentTime;
    std::list<Animator::Animation> _animations;
    Animator::Animation* _currentAnimation;
};

#endif