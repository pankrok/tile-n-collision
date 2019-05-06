#include "collision.hpp"

bool Collision::check(sf::Vector2f tileSize, const int* tiles, unsigned int width, unsigned int height, sf::Vector2f playerPosition)
{
        x = int(playerPosition.x/32);
        y = int(playerPosition.y)/32;
        if(y < 2) y = 2;
        if(x < 2) x = 2;
        tileCollision.top = playerPosition.x+4;
        tileCollision.left = playerPosition.y+4;
        tileCollision.height = 24;
        tileCollision.width = 24;
        bool test = false;

        // populate the vertex array, with one quad per tile
        for (unsigned int i = x-2; i < x+2; ++i)
            for (unsigned int j = y-2; j < y+2; ++j)
            {
        int tileNumber = tiles[i + j * width];

        tileCollision2.left = j*32;
        tileCollision2.top = i*32;

        tileCollision2.height = 32;
        tileCollision2.width = 32;

        if(tileNumber != 0 && tileNumber != 2){
        test = tileCollision.intersects(tileCollision2);

               if(test == true)
               {
                   return test;
               }
            }
        }

        return test;
}


