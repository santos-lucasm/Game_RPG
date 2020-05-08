#include "Entities/player.h"
#include "Manager/asset_manager.h"
#include "location.h"

int main()
{
    /* Window setting */
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), "Testing sprites");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible( false );

    AssetManager manager;
    Location loc( sf::Vector2f( 50, 50), Location::Direction::UP);
    Player * protag = new Player("Sevothart", &loc, manager.getTexture("resources/sensei.png"));

    /* Game loop */
    while( window.isOpen() )
    {   
        sf::Event event;
        while( window.pollEvent(event) )
        {
            if( event.type == sf::Event::EventType::Closed )
                window.close();
        }
        
        protag->update();

        window.clear( sf::Color::Black );
        window.draw( protag->render() );
        window.display();
    }
    
    delete protag;
    return 0;
}