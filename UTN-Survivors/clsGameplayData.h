#pragma once

#include "SFML/Graphics.hpp"
#include "clsCircleCollider.h"
#include "clsSlime.h"

class GameplayData
{
public:

	GameplayData();

<<<<<<< Updated upstream
=======
	//FUNCIONES GENERALES

	void UpdateEveryEnemy(float deltaTime, sf::Vector2f playerPos);

	void checkPlayerSolidCollision(CircleCollider playerCollider);

	void CheckEverySolidCollision();

	void DrawEveryEnemy(sf::RenderWindow& window);

	//SLIME

>>>>>>> Stashed changes
	std::vector<Slime>& getSlimes();

	void spawnSlime(Slime slime, sf::Vector2f playerPos);

	int howManySlimes();


private:

	std::vector<Slime> spawnedSlimes;

	std::vector<Slime> spawnedObj; //placeholder




};

