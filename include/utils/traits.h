#ifndef _TRAITS_H
#define _TRAITS_H

#include "utils/types.h"

/*! @brief
    Forward declaration of every class that'll use a traits.
*/
class Game;
class Clock;

class AssetManager;
class Animator;

class Entity;
class Player;

class State;
class GameState;
class SettingsState;

class Tracer;

/*! @struct
    Traits is a templatized struct that defines many flags to be used
among all the defined classes.
    Each defined class can inherit from Traits<void> (or another T)
to define its own runtime parameters. This is great for specific
classes to turn debug or tracer on, for example.
*/
template<typename T>
struct Traits
{
    static const bool traced = false;
    static const bool debugged = false;
};

template<> struct Traits<Tracer>: public Traits<void>
{
    static const bool tracing_enabled = true;
    static const bool debug_enabled = false;
};

template<> struct Traits<Game>: public Traits<void>
{
    static const bool traced = true;
    static const bool debugged = true;
};

template<> struct Traits<Clock>: public Traits<void>
{
    static const bool traced = true;
};

template<> struct Traits<AssetManager>: public Traits<void>
{
    static const bool traced = true;
    static const bool debugged = true;
};

template<> struct Traits<Animator>: public Traits<void>
{
    static const bool traced = true;
    static const bool debugged = true;
};

template<> struct Traits<Entity>: public Traits<void>
{
    static const bool traced = true;
};

template<> struct Traits<Player>: public Traits<void>
{
    static const bool traced = true;
};

template<> struct Traits<State>: public Traits<void>
{
    static const bool traced = true;
};

template<> struct Traits<GameState>: public Traits<void>
{
    static const bool traced = true;
};

template<> struct Traits<SettingsState>: public Traits<void>
{
    static const bool traced = true;
};

#endif