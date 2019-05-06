#include "SFML/Graphics.hpp"
#include <iostream>
#include "bob.hpp"
#include "tilemap.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // define the level with an array of tile indices
const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 19, 8))
        return -1;

    Bob h_Bob;

    sf::Clock clock;
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        h_Bob.input();
        h_Bob.update(dtAsSeconds, level);


       // window.setView(view);

        // draw the map
        window.clear();
        window.draw(map);
        window.draw(h_Bob.getSprite());


        //view



        window.display();
    }

    return 0;
}
