#include "SFML/Graphics.hpp"
#include <iostream>

class Collision

{

private:

    sf::FloatRect tileCollision;
    sf::FloatRect tileCollision2;
    sf::Vector2f m_vertices;
    int x, y;



public:

    bool check(sf::Vector2f tileSize, const int* tiles, unsigned int width, unsigned int height, sf::Vector2f playerPosition);

};
