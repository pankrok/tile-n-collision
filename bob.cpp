
#include "bob.h"

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
    if (m_RightPressed)
    {
        oldPosition = m_Position.x;
        m_Position.x += m_Speed * elapsedTime;

        x = int((m_Position.x) / 32 );
        y = 8-((x+ 16*(int((m_Position.y)/ 32)))*(-1));

        newPosition = x + y;

        if( collision[newPosition] != 0 || x < 0 || y < 0 ) {
          m_Position.x = oldPosition;
        }
    }

    if (m_LeftPressed)
    {
        oldPosition = m_Position.x;
        m_Position.x -= m_Speed * elapsedTime;

        x = int((m_Position.x) / 32 );
        y = 8-((x+ 16*(int((m_Position.y)/ 32)))*(-1));

        newPosition = x + y;

        if( collision[newPosition] != 0 || x < 0 || y < 0 ) {
          m_Position.x = oldPosition;
        }
    }

    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }

    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }
    //std::cout << int((m_Position.y)/ 32) << std::endl;
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);

}
