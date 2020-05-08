#include "Entities/player.h"
#include "position.h"
#include "Manager/asset_manager.h"

int main()
{
    /* Window setting */
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), "Testing sprites");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible( false );

    AssetManager manager;
    Position pos(0, 0, Position::Direction::UP);
    Player * protag = new Player("Sevothart", &pos, manager.getTexture("resources/sensei.png"));

    /* Game loop */
    while( window.isOpen() )
    {   
        sf::Event event;
        while( window.pollEvent(event) )
        {
            if( event.type == sf::Event::EventType::Closed )
                window.close();
        }    
        window.clear( sf::Color::Black );
        window.draw( protag->render() );
        window.display();
    }
    return 0;
}