#pragma once

#include "SFML/Graphics.hpp"
#include "clsSlime.h"
#include "clsElemSlime.h"
#include "clsSpartan.h"
#include "clsReaper.h"

class GameplayData
{
public:

	GameplayData();

	//FUNCIONES GENERALES

	void UpdateEveryEnemy(float deltaTime, sf::Vector2f playerPos);

	void CheckEverySolidCollision();

	void DrawEveryEnemy(sf::RenderWindow& window);

	//SLIME

	std::vector<Slime>& getSlimes();

	void spawnSlime(Slime slime, sf::Vector2f playerPos);

	int howManySlimes();
	

	//ELEMENTAL SLIME

	std::vector<ElementalSlime>& getElemSlimes();

	void spawnElementalSlime(ElementalSlime elemSlimeTemplate, sf::Vector2f playerPos);

	int howManyElemSlimes();
	
	//SPARTAN

	std::vector<Spartan>& getSpartans();

	void spawnSpartan(Spartan spartanTemplate, sf::Vector2f playerPos);

	int howManySpartans();
	
	//REAPER

	std::vector<Reaper>& getReapers();

	void spawnReaper(Reaper reaperTemplate, sf::Vector2f playerPos);

	int howManyReapers();

private:

	std::vector<Slime> spawnedSlimes;

	std::vector<ElementalSlime> spawnedElemSlimes;

	std::vector<Spartan> spawnedSpartans;

	std::vector<Reaper> spawnedReapers;





};

