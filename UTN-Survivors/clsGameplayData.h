#pragma once

#include "SFML/Graphics.hpp"

#include "clsBulletAttack.h"
#include "clsAreaAttack.h"

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
	
	void dyingEnemies();

	void DrawEveryEnemy(sf::RenderWindow& window);

	float getNearestEnemyAngle(sf::Vector2f playerPos);

	///FUNCIONES PARA LAS SKILLS

	void createTornado(BulletAttack bulletTemplate, sf::Vector2f playerPos);

	void createAreaAttack(AreaAttack areaTemplate, sf::Vector2f playerPos);

	void UpdateEverySkill(float deltaTime);

	void DrawEverySkill(sf::RenderWindow& window);
	

	void checkDmgCollision(float deltaTime, int playerDmg);


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

	std::vector<BulletAttack> tornadosSpawned;
	float tornadoCd;
	float tornadoDmgCd;

	std::vector<AreaAttack> areaAttacksSpawned;
	float areaCd;
	float areaDmgCd;


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

