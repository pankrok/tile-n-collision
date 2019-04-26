#include <SFML/Graphics.hpp>
#include <iostream>

class Player{

private:

    float speed;
    bool pLeft, pRight, pUp, pDown;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Vector2u playerPosiotion;

public:

    Player();

    sf::Sprite getSprite();

    void moveLeft();
    void stopLeft();

    void moveRight();
    void stopRight();

    void moveUp();
    void stopUp();

    void moveDown();
    void stopDown();

    void update(float elapsedTime);

};
