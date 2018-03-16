
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
#include <iostream>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Chess.hpp"

const int tile_size = 70;
const int border_size = 2;

sf::Color white = sf::Color::White;
sf::Color black = sf::Color::Black;
sf::Color gray = sf::Color(100, 100, 100);
sf::Color red = sf::Color::Red;





int main(int, char const**)
{
    
    Chess* game = new Chess();
    
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(640, 640), "Chess");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    // Set the Icon
   
    sf::Texture black_king;        if (!black_king.loadFromFile(resourcePath() + "Chess_kdt60.png")) {return EXIT_FAILURE;}
    sf::Sprite black_king_image;
    black_king_image.setTexture(black_king);
    black_king_image.setOrigin(30, 30);
    
    black_king_image.setPosition(35, 35);

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
                
                sf::Color color;
                if (row % 2 == 0)
                {
                    if (col % 2 == 0)
                    {
                        color = white;
                    }
                    else
                        color = gray;
                }
                else if (col % 2 == 0)
                {
                    color = gray;
                }
                else
                {
                    color = white;
                }
                
                tile.setFillColor(color);
                
                
                tile.setPosition(tile_x + border_size / 2.0, tile_y + border_size / 2.0);
                
                window.draw(tile);
            }
        }
    
        // Draw the string
        // window.draw(text);
        
        //game->list_all_pieces();
        
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (!game->is_piece_nullptr(row, col) && game->is_piece(row, col, Color::Black, Chess_piece::King))
                {
                    cout << "Position: row " << row << ", col " << col << endl;
                    black_king_image.setPosition(col * tile_size + tile_size / 2.0, (7 - row) * tile_size + tile_size / 2.0);
                }
            }
        }
        
        window.draw(black_king_image);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
