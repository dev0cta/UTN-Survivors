#pragma once

#include "clsAnimation.h"
#include "SFML/Graphics.hpp"
#include "BarraVida.h"

class Player
{
public:

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& window);


	void Update(float deltaTime);

	void Draw();


	sf::Vector2f getPos(); //para el target de los enemigos

	void takeDmg(); //tiene cooldown

	void attack(); //verifica los cd de las habilidades y las lanza si estan disponibles

private:

	//stats

	float speed;

	//funciones

	sf::RectangleShape	body;

	Animation			animation;
	unsigned int		row;
	bool				faceRight;
	BarraVida			BarraHp;
	sf::RenderWindow& window;
	float HpMax = 200;
};

