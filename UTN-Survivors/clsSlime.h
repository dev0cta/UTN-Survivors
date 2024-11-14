#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsEnemy.h"

class Slime: public Enemy
{
public:

	Slime(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltaTime, sf::Vector2f target);

	void Draw(sf::RenderWindow& window);



private:

	void moveTowardsTarget(float deltaTime);

private:

public:
	float speed;

	sf::Vector2f target;

	sf::RectangleShape body;

	bool				faceRight;
	unsigned int		row;
	Animation			animation;

};

