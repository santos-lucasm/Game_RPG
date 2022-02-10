#ifndef _TRAITS_H
#define _TRAITS_H

#include "utils/types.h"

/* Engine class forward declaration. */
class Game;
class Clock;

class AssetManager;
class Animator;
class Machine;

class InputComponent;
    class PlayerInputComponent;

class PhysicsComponent;
    class PlayerPhysicsComponent;

class GraphicsComponent;
    class PlayerGraphicsComponent;

/* Entities class forward declaration */
class GameObject;
    class Player;

/* States used on Machine forward declaration */
class State;

class GameState;
    class MainMenuState;
    class RunState;
    class SettingsMenuState;

class PlayerState;
    class StandingState;
    class WalkingState;
    class SprintingState;

class Debug;

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
    static const bool debugged = true;
};

/* This turns on or off Info and Tracing from all classes */
template<> struct Traits<Debug>: public Traits<void>
{
    static const bool info  = true;
    static const bool trace = true;
};


/* Each class specific Info and Tracing */
template<> struct Traits<Game>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<AssetManager>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Animator>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Machine>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<GameObject>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<GameState>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<MainMenuState>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<RunState>: public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<SettingsMenuState>: public Traits<void>
{
    static const bool debugged = true;
};

#endif