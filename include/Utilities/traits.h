#ifndef _TRAITS_H
#define _TRAITS_H

/* Declare system */
class Game;

/* Declare managers */
class AssetManager;
class Animator;
struct Animation;

/* Declare entities */
class Entity;
class Player;

/* Declare utilities */
class Tracer;
class Location;

/*
DESCRIPTION:
    Traits is a templatized class that defines many flags to be used
among all the defined classes.
    Each defined class can inherit from Traits<void> (or another T)
to define its own runtime parameters. This is great for specific
classes to turn debug or tracer on, for example.
*/
template<typename T>
struct Traits
{
    static const bool traced = true;
    static const bool debugged = false;
};

template<> struct Traits<Game>: public Traits<void>
{
    static const bool debugged = false;
};

template<> struct Traits<AssetManager>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Animator>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Animation>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Entity>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Player>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Location>: public Traits<void>
{
    static const bool debugged = true;
};
#endif