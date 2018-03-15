
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

const int tile_size = 80;
const int border_size = 2;

sf::Color white = sf::Color::White;


int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(640, 640), "Chess");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);



    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                const int tile_x = col * tile_size, tile_y = row * tile_size;
                sf::RectangleShape tile;
                tile.setSize(sf::Vector2f(tile_size - border_size, tile_size - border_size));
                tile.setFillColor(white);
                tile.setPosition(tile_x + border_size / 2.0, tile_y + border_size / 2.0);
                
                window.draw(tile);
            }
        }
        
        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
