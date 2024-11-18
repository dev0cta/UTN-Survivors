#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsCircleCollider.h"

class AreaAttack
{
public:

	AreaAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Update(float deltaTime);

	void Draw(sf::RenderWindow& window);

	void setPosition(sf::Vector2f position);

	float getTimeAlive();

	CircleCollider getCollider();

	int getDmg();

private:

	int dmg;
	float speed;
	float timeAlive;


	sf::RectangleShape body;
	Animation animation;
	int row;
	bool faceRight;
};