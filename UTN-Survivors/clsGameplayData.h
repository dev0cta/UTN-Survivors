#pragma once

#include "SFML/Graphics.hpp"
#include "clsSlime.h"

class GameplayData
{
public:

	GameplayData();

	std::vector<Slime>& getSlimes();

	void spawnSlime(Slime slime, sf::Vector2f playerPos);

	int howManySlimes();


private:

	std::vector<Slime> spawnedSlimes;

	std::vector<Slime> spawnedObj; //placeholder




};

