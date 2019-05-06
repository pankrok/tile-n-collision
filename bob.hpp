#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Bob
{
    // All the private variables can only be accessed internally
private:

    // Where is Bob
    Vector2f m_Position;

    // Of course we will need a sprite
    Sprite m_Sprite;
    FloatRect m_bounds;
    // And a texture
    // Bob has been working out and he is now a bit more muscular than before
    // Furthermore, he fancies himself in lumberjack attire
    Texture m_Texture;

    // Which direction(s) is the player currently moving in
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
    // Bob's speed in pixels per second
    float m_Speed;

    //
    int oldPosition, x, y;
    int newPosition;

    // Public functions
public:

    // We will set Bob up in the constructor
    Bob();

    // Send a copy of the sprite to main
    Sprite getSprite();

    // Move Bob in a specific direction
    void moveLeft();

    void moveRight();

    // Stop Bob moving in a specific direction
    void stopLeft();

    void stopRight();

        // Move Bob in a specific direction
    void moveUp();

    void moveDown();

    // Stop Bob moving in a specific direction
    void stopUp();

    void stopDown();

    void input();

    // We will call this function once every frame
    void update(float elapsedTime, const int* collision);

};
