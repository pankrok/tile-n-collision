#include "bob.h"

void Bob::input()
{

    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        moveLeft();
    }
    else
    {
        stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        moveRight();
    }
    else
    {
        stopRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        moveUp();
    }
    else
    {
        stopUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        moveDown();
    }
    else
    {
        stopDown();
    }

}
