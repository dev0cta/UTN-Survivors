#include "gameFunctions.h"

bool pauseGame(bool isGamePaused)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        return !isGamePaused;
    else
        return isGamePaused;
    

    return false;
}
