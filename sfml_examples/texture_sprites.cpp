#include <SFML/Graphics.hpp>

int main()
{   
    /* Window setting */
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), "Testing sprites");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible( false );

    /* Texture setting */
    sf::Texture texture1;
    texture1.setRepeated(true);
    texture1.loadFromFile("resources/fence10.png");
    sf::Texture texture2;
    texture2.setRepeated(true);
    texture2.loadFromFile("resources/fenceRaw04.png");

    /* Sprite setting */
    sf::Sprite sprite1( texture1 );
    sprite1.setPosition( sf::Vector2f(0, 0) );
    sprite1.setTextureRect( sf::IntRect(0, 0, 16*5, 16) );
    sf::Sprite sprite2( texture2 );
    sprite2.setPosition( sf::Vector2f(0, 16) );
    sprite2.setTextureRect( sf::IntRect(0, 0, 16*5, 16) );

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
        window.draw( sprite1 );
        window.draw( sprite2 );
        window.display();
    }

    return 0;
}