#include "SFML/Graphics.hpp"
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable
{

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
