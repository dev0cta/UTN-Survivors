#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "clsLevelingSystem.h"
#include "clsPlayer.h"

#include "clsBulletAttack.h"
#include "clsAreaAttack.h"

#include "clsSlime.h"
#include "clsElemSlime.h"
#include "clsSpartan.h"
#include "clsReaper.h"
#include "MagicBall.h"

class GameplayData
{
public:

	GameplayData();
	
	/// FUNCIONES CLAVE

	void ResetGameData(sf::RectangleShape& characterBody);

	void randomSpawn(sf::Vector2f playerPos, float deltaTime, Slime slimeTemplate, ElementalSlime elemSlimeTemplate, Spartan spartanTemplate, Reaper reaperTemplate);

	//FUNCIONES GENERALES

	void UpdateEveryEnemy(float deltaTime, sf::Vector2f playerPos);

	void checkPlayerCollision(CircleCollider playerCollider, Player& player, float deltaTime);

	void CheckEverySolidCollision();
	
	void dyingEnemies();

	void DrawEveryEnemy(sf::RenderWindow& window);

	float getNearestEnemyAngle(sf::Vector2f playerPos);

	void CheckDamageEnemy(Player& player, int dmgTaken);
	

	///FUNCIONES PARA LAS SKILLS

	void createTornado(BulletAttack bulletTemplate, sf::Vector2f playerPos);

	void createAreaAttack(AreaAttack areaTemplate, sf::Vector2f playerPos);

	void UpdateEverySkill(sf::Vector2f playerpos, float deltaTime);

	void DrawEverySkill(sf::RenderWindow& window);

	void checkDmgCollision(float deltaTime, int playerDmg);




	void createBall(MagicBall magicBallTemplate, sf::Vector2f playerpos);
	void addMagicBall(const MagicBall& newBall);



	///FUNCIONES PARA EL PLAYER	

	int getLevel();

	void checkLevelUp();


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

	///LEVELING SYSTEM

	float gameTime;
	
	LevelingSystem levelingSystem;


	///ATAQUES DEL JUGADOR


	std::vector <MagicBall> spawnedBalls;


	float ballDmgCd;
	int ballAttackDmg = 15;


	std::vector<BulletAttack> tornadosSpawned;
	float tornadoCd;
	float tornadoDmgCd;

	std::vector<AreaAttack> areaAttacksSpawned;
	float areaCd;
	float areaDmgCd;


	float dmgTakenCd;

	///VARIABLES PARA ENEMIGOS

	int enemyLevel;

	///VECTORES DE ENEMIGOS
	std::vector<Slime> spawnedSlimes;

	std::vector<ElementalSlime> spawnedElemSlimes;

	std::vector<Spartan> spawnedSpartans;

	std::vector<Reaper> spawnedReapers;





};

