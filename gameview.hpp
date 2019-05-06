#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class GameView
{

private:

    View view;
    FloatRect viewRect;
    Vector2f viewPosition;


public:

    GameView();

    View getView();

    void update();


};
