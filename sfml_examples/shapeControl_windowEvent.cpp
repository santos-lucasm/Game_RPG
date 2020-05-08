#include <SFML/Graphics.hpp>

void init_shape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color )
{
    shape.setFillColor(color);
    shape.setPosition(pos);
    shape.setOrigin( shape.getSize() * 0.5f );
}

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window( sf::VideoMode( desktop.width, desktop.height, desktop.bitsPerPixel), "Evasion Game!");

    window.setFramerateLimit(60);
    window.setMouseCursorVisible( false );

    sf::RectangleShape playerRect( sf::Vector2f(50, 50) );
    init_shape( playerRect, sf::Vector2f(50, 50), sf::Color::Cyan);
    sf::RectangleShape targetRect( sf::Vector2f(50, 50) );
    init_shape( targetRect, sf::Vector2f(400, 400), sf::Color::Green);
    sf::RectangleShape enemyRect( sf::Vector2f(50, 100) );
    init_shape( enemyRect, sf::Vector2f(150, 50), sf::Color::Red);
    
    while( window.isOpen() )
    {
        /* Input Handling */
        sf::Event event;
        while( window.pollEvent(event) )
        {
            switch(event.type)
            {
                case sf::Event::EventType::Closed:
                    window.close(); break;
                default:
                    break;
            }
        }

        /* Move playerRect */
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
            playerRect.move( sf::Vector2f(5, 0) );
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
            playerRect.move( sf::Vector2f(-5, 0) );
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
            playerRect.move( sf::Vector2f(0, -5) );
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
            playerRect.move( sf::Vector2f(0, 5) );

        /* Win & Lose condition */
        if(playerRect.getGlobalBounds().intersects( targetRect.getGlobalBounds() ))
            window.close();
        if(playerRect.getGlobalBounds().intersects( enemyRect.getGlobalBounds() ))
            playerRect.setPosition( sf::Vector2f(50, 50) );

        /* Render frame */
        window.clear( sf::Color::Black );
        window.draw( playerRect );
        window.draw( targetRect );
        window.draw( enemyRect );
        window.display();
    }

    return 0;
}