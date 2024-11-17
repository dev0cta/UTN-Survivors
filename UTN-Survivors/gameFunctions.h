#pragma once

#include "SFML/Graphics.hpp"

bool pauseGame(bool isGamePaused);

void checkBounds(sf::RectangleShape& body, sf::Vector2f boundMapLeftTop, sf::Vector2f boundMapRightDown);



//spawn enemies (no se ni por donde empezar esto)

void spawnSlime(sf::Texture* texture);