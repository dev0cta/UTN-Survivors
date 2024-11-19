#include "gameFunctions.h"

bool pauseGame(bool isGamePaused)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        return !isGamePaused;
    else
        return isGamePaused;
    

    return false;
}

void checkBounds(sf::RectangleShape& body, sf::Vector2f boundMapLeftTop, sf::Vector2f boundMapRightDown)
{
    if (body.getPosition().x < boundMapLeftTop.x)
    {
        body.setPosition(boundMapLeftTop.x, body.getPosition().y);
    }


    if (body.getPosition().y > boundMapLeftTop.y)
    {
        body.setPosition(body.getPosition().x, boundMapLeftTop.y);
    }


    if (body.getPosition().x > boundMapRightDown.x)
    {
        body.setPosition(boundMapRightDown.x, body.getPosition().y);
    }


    if (body.getPosition().y < boundMapRightDown.y)
    {
        body.setPosition(body.getPosition().x, boundMapRightDown.y);
    }
}

void saveStatisticsData(std::string, Statistics currentMatch)
{
    ArchivoStatistics arc("statistics.dat");

    arc.addAndSaveRecentMatch(currentMatch);

    ///descomentar para chequear en la consola
    arc.Read().coutStatistics(arc.Read());
}

Statistics getLastRecordedStatistics()
{

    ArchivoStatistics arc("statistics.dat");

    Statistics obj(arc.Read());

    return obj;
}
