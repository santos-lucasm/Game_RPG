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
#define ANIMATION_PATH(x)       "resources/assets/animations/" #x ".png"
#define STATIC_PATH(x)          "resources/assets/static/" #x ".png"
#define TILESET_PATH(x)         "resources/assets/tilesets/" #x ".png"
#define CONFIG_PATH(x)          "resources/config/" #x ".ini"

#endif