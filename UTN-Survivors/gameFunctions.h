#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include "clsStatistics.h"
#include "clsArchivoStatistics.h"
#include "clsGameplayData.h"

bool pauseGame(bool isGamePaused);

void checkBounds(sf::RectangleShape& body, sf::Vector2f boundMapLeftTop, sf::Vector2f boundMapRightDown);


void saveStatisticsData(std::string, Statistics currentMatch);

Statistics getLastRecordedStatistics();

