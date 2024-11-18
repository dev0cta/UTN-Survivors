#pragma once

#include "clsCircleCollider.h"
#include "clsAnimation.h"
#include "SFML/Graphics.hpp"
#include "clsInterface.h"
#include "clsAttack.h"

class Player
{
public:

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& window);

	void Update(float deltaTime);

	void Draw();

	sf::Vector2f getPos(); //para el target de los enemigos

	sf::RectangleShape& getBody(); // nigga i cant

	bool getFaceRight();

	CircleCollider getCollider();

	void takeDmg(int dmgTaken); //tiene cooldown

	int getHealth();

	//void attack(); //verifica los cd de las habilidades y las lanza si estan disponibles

private:
	void levelUp();


private:

	//stats

	int level;

	int dmgTakenCooldown;

	int baseHealth;
	int health;
	float HpMax;
	int healthScaling;

	int baseDmg;
	int dmg;
	int dmgScaling;


	float speed;

	//funciones

	sf::RectangleShape	body;
	sf::CircleShape		hitBox;


	Animation			animation;
	unsigned int		row;
	bool				faceRight;
	Interface			interface;
	sf::RenderWindow& window;
};

