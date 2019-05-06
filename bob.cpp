#include "collision.hpp"
#include "bob.hpp"

Bob::Bob()
{
    // How fast does Bob move?
    m_Speed = 100;

    // Associate a texture with the sprite
    m_Texture.loadFromFile("player.png");
    m_Sprite.setTexture(m_Texture);

    // Set the Bob's starting position
    m_Position.x = 64;
    m_Position.y = 64;

}

// Make the private spite available to the draw() function
Sprite Bob::getSprite()
{
    return m_Sprite;
}

void Bob::moveLeft()
{
    m_LeftPressed = true;
}

void Bob::moveRight()
{
    m_RightPressed = true;
}

void Bob::stopLeft()
{
    m_LeftPressed = false;
}

void Bob::stopRight()
{
    m_RightPressed = false;
}

// ---------------------

void Bob::moveUp()
{
    m_UpPressed = true;
}

void Bob::moveDown()
{
    m_DownPressed = true;
}

void Bob::stopUp()
{
    m_UpPressed = false;
}

void Bob::stopDown()
{
    m_DownPressed = false;
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Bob::update(float elapsedTime, const int* collision)
{
    Collision m_collision;
    m_bounds = m_Sprite.getGlobalBounds();

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

    if (m_RightPressed)
    {
        oldPosition = m_Position.x;
        m_Position.x += m_Speed * elapsedTime;
        if( m_bounds.contains(512, m_Position.y) ) {
          m_Position.x = oldPosition;
        }
        if(m_collision.check(sf::Vector2f(32, 32), level, 19, 8, sf::Vector2f(m_Position.x, m_Position.y)))
        {
          m_Position.x = oldPosition;
        }


    }

    if (m_LeftPressed)
    {
        oldPosition = m_Position.x;
        m_Position.x -= m_Speed * elapsedTime;

        newPosition = x + y;

        if( m_bounds.contains(0, m_Position.y) ) {
          m_Position.x = oldPosition;
        }
        if(m_collision.check(sf::Vector2f(32, 32), level, 19, 8, sf::Vector2f(m_Position.x, m_Position.y)))
        {
          m_Position.x = oldPosition;
        }

    }

    if (m_DownPressed)
    {
        oldPosition = m_Position.y;
        m_Position.y += m_Speed * elapsedTime;
        if( m_bounds.contains(m_Position.x, 256) ) {
          m_Position.y = oldPosition;
        }
                if(m_collision.check(sf::Vector2f(32, 32), level, 19, 8, sf::Vector2f(m_Position.x, m_Position.y)))
        {
          m_Position.y = oldPosition;
        }

    }

    if (m_UpPressed)
    {
        oldPosition = m_Position.y;
        m_Position.y -= m_Speed * elapsedTime;
        if( m_bounds.contains(m_Position.x, 0) ) {
          m_Position.y = oldPosition;
        }
        if(m_collision.check(sf::Vector2f(32, 32), level, 19, 8, sf::Vector2f(m_Position.x, m_Position.y)))
        {
          m_Position.y = oldPosition;
        }
    }
    //std::cout << int((m_Position.y)/ 32) << std::endl;
    // Now move the sprite to its new position

    m_Sprite.setPosition(m_Position);

}

