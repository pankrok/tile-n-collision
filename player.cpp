
#include "player.h"

class Player
{

    Player::Player()
    {

        speed = 100;

        playerTexture.loadFromFile("player.png");
        playerSprite.setTexture(playerTexture);

        playerPosiotion.x = 50;
        playerPosiotion.y = 50;

    }

    sf::Sprite Player::getSprite()
    {
        return playerSprite;
    }

    void Player::moveLeft()
    {
        pLeft = true;
    }
    void Player::stopLeft()
    {
        pLeft = false;
    }

    void Player::moveRight()
    {
        pRight = true;
    }
    void Player::stopRight()
    {
        pRight = false;
    }

    void Player::moveUp()
    {
        pUp = true;
    }
    void Player::stopUp()
    {
        pUp = false;
    }

    void Player::moveDown()
    {
        pDown = true;
    }
    void Player::stopDown()
    {
        pDown = false;
    }

    void Player::update(float elapsedTime)
    {

        if(pLeft)
        {
            playerPosiotion.x -= speed * elapsedTime;
        }
        if(pRight)
        {
            playerPosiotion.x += speed * elapsedTime;
        }
        if(pUp)
        {
            playerPosiotion.y -= speed * elapsedTime;
        }
        if(pDown)
        {
            playerPosiotion.y += speed * elapsedTime;
        }

        playerSprite.setPosition(playerPosiotion);
    }



};
