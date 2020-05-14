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
    sf::Vector2f size(24, 24);
    sf::Sprite girl(AssetManager::getTexture("resources/mani-idle-run.png"));
    girl.setPosition(50, 50);
    girl.setScale(3, 3);
    int frames_num = 7;
    float anim_duration = 0.75;

    sf::Time elapsed;
    sf::Clock clock;

    /* Game loop */
    while( window.isOpen() )
    {   

        sf::Time dt = clock.restart();

        sf::Event event;
        while( window.pollEvent(event) )
        {
            if( event.type == sf::Event::EventType::Closed )
                window.close();
        }

        elapsed += dt;
        int anim_frame = static_cast<int>( (elapsed.asSeconds()/anim_duration) * frames_num ) % frames_num;
        girl.setTextureRect( sf::IntRect( anim_frame*size.x, 0, size.x, size.y) );

        window.clear( sf::Color::Black );
        window.draw( girl );
        window.display();
    }

    return 0;
}