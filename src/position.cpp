#include <iostream>
#include "position.h"
using namespace std;

Position::Position(int x, int y, Direction dir)
{
    set_X( x );
    set_Y( y );
    set_dir( dir );
}

Position::~Position()
{
    set_X(0);
    set_Y(0);
    set_dir( Direction::NONE );
}

void Position::set_X( int x ){ _x = x; }
void Position::set_Y( int y ){ _y = y; }
void Position::set_dir( Direction dir ) { _dir = dir; }

int Position::get_X(){ return _x; }
int Position::get_Y(){ return _y; }
int Position::get_dir() { return _dir; }

void Position::printVector2D()
{
    cout << "[" << get_X() << ", " << get_Y() << "]" << endl;
}