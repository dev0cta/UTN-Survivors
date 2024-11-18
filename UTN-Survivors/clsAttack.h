#pragma once

#include "clsSquareCollider.h"
#include "SFML/Graphics.hpp"
#include "clsEnemy.h"

class clsAttack
{
public:	

	clsAttack(sf::Vector2f pos, sf::Vector2f tam, int dmg);

	void update(float deltaTime);

	SquareCollider getCollider();

	int applyDmg();

	sf::RectangleShape& getBody();
	
	void dibujar(sf::RenderWindow& ventana);




private:


	float tiempovida;
	int dmg;
	sf::RectangleShape body;
	bool activo;
	bool faceRight;

};