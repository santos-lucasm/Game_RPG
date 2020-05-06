#include <SFML/Window.hpp>

#include "player.h"
#include "position.h"
using namespace std;

int main()
{

    sf::Window window( sf::VideoMode(300, 200), "NEW WINDOW!" );
    sf::sleep( sf::seconds(3) );

    return 0;
}