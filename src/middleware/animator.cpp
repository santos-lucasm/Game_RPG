#include "middleware/animator.h"

/* Animation struct functions definitions*/

Animator::Animation::Animation
    ( std::string const& name, std::string const& texture, sf::Time const& duration, bool loop ):
    _name(name), _textureName(texture), _duration(duration), _looping(loop) {}

void Animator::Animation::AddFrames
    ( sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int frames )
{
    sf::Vector2i current = startFrom;
    for( unsigned int i = 0; i < frames; i++)
    {
        _frames.push_back( sf::IntRect(current.x, current.y, frameSize.x, frameSize.y) );
        current.x += frameSize.x;
    }
}

/* Animator class functions definitions */

Animator::Animator(sf::Sprite& sprite):
    _sprite(sprite), _currentTime( sf::Time::Zero.asSeconds() ), _currentAnimation(nullptr)
{
}

Animator::~Animator()
{
}

Animator::Animation& Animator::createAnimation (std::string const& name, std::string const& textureName, sf::Time const& duration, bool loop)
{

    _animations.push_back( Animator::Animation(name, textureName, duration, loop) );

    /* If there's no animation running, add it as the current animation */
    if(_currentAnimation == nullptr)
    {
        
        db<Animator>(INF) << "Animator::createAnimation() @ No current animation, inserted new one as current.\n";
        switchAnimation( &_animations.back() );
    }
    
    return _animations.back();
}

void Animator::update(float const& dt)
{
    if(_currentAnimation == nullptr)
        return;
    _currentTime += dt;

    /* Get the current animation frame */
    float scaled_time = (_currentTime / _currentAnimation->_duration.asSeconds() );
    int num_frames = _currentAnimation->_frames.size();
    int current_frame = static_cast<int>( scaled_time * num_frames );

    /* If the animation is a looping one, calculate the correct frame */
    if(_currentAnimation->_looping)
        current_frame %= num_frames;
        
    /* If the animation doesnt loop, and it already ended, keep showing the last frame of it */
    else if(current_frame >= num_frames)
        current_frame = num_frames - 1;
    
    /* Set the texture rect depending on the frame */
    _sprite.setTextureRect( _currentAnimation->_frames[current_frame] );
}

bool Animator::switchAnimation(std::string const& name)
{
    auto animation = findAnimation(name);
    if(animation != nullptr)
    {
        switchAnimation(animation);
        return true;
    }
    return false;
}

void Animator::switchAnimation(Animator::Animation* animation)
{

    if(animation != nullptr)
    {   
        _sprite.setTexture( AssetManager::getTexture(animation->_textureName) );
        _currentAnimation = animation;
        _currentTime = sf::Time::Zero.asSeconds();
    }
    else
        return; /* TODO: Throws an exception here */
}

Animator::Animation* Animator::findAnimation(std::string const& name)
{
    for( auto it = _animations.begin(); it != _animations.end(); ++it)
    {
        if( it->_name == name )
            return &(*it);
    }
    return nullptr;
}

std::string Animator::getCurrentAnimationName() const
{
    if(_currentAnimation != nullptr)
        return _currentAnimation->_name;
    return "";
}
