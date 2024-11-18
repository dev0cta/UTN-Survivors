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

	void checkPlayerCollision(CircleCollider playerCollider);

	void CheckEverySolidCollision();

	void DrawEveryEnemy(sf::RenderWindow& window);

	sf::Vector2f getNearestEnemy(sf::Vector2f playerPos);

	///FUNCIONES PARA EL PLAYER

	


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

	float getDistance(sf::Vector2f pos1, sf::Vector2f pos2);

private:

	///ATAQUES DEL JUGADOR




	///SISTEMA DE NIVELES

	int currentExp;
	int expUntilNextLevel[15];  //tamaño = nivel maximo del player



	///VARIABLES PARA ENEMIGOS

	int enemyLevel;

	///VECTORES DE ENEMIGOS
	std::vector<Slime> spawnedSlimes;

	std::vector<ElementalSlime> spawnedElemSlimes;

	std::vector<Spartan> spawnedSpartans;

	std::vector<Reaper> spawnedReapers;





};

