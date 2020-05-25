#ifndef _TYPES_H
#define _TYPES_H

/* Stream HEADERS */
#include <iostream>
#include <fstream>
#include <sstream>

/* Container HEADERS */
#include <vector>
#include <list>
#include <stack>
#include <map>

/* Debug HEADERS*/
#include <assert.h>
#include <memory.h>

/* SFML LIBS */
#include <SFML/Graphics.hpp>

/* Resources MACROS */
#define ANIMATION_PATH(x)       "assets/images/animations/" #x ".png"
#define ICON_PATH(x)            "assets/images/icons/" #x ".png"
#define TILESET_PATH(x)         "assets/images/tilesets/" #x ".png"
#define CONFIG_PATH(x)          "assets/config/" #x ".ini"
#define FONTS_PATH(x)           "assets/fonts/" #x ".ttf"

/* Global enums, FOR NOW, only util Entities State class exists */
enum
{
    /* Player */
    RIGHT_MOVE,
    RIGHT_IDLE,
    LEFT_MOVE,
    LEFT_IDLE,
    UP_MOVE,
    UP_IDLE,
    DOWN_MOVE,
    DOWN_IDLE,

    /* Button */
    IDLE,
    HOVER,
    PRESSED,

    NONE  = -1
}typedef EntityState;

#endif