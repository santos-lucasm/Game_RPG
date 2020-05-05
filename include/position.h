#ifndef _POSITION_H
#define _POSITION_H

#include "types.h"

/* Should I name it Vector2D ? */
class Position
{
public:
    enum
    {
        UP      = 0,
        DOWN    = 1,
        LEFT    = 2,
        RIGHT   = 3,
        NONE    = -1
    }typedef Direction;

public:
    Position( int x, int y, Direction dir );
    ~Position();

    int get_X();
    int get_Y();
    int get_dir();

    void printVector2D();

private:
    void set_X( int );
    void set_Y( int );
    void set_dir( Direction );

private:
    int _x;
    int _y;
    Direction _dir;
};

#endif