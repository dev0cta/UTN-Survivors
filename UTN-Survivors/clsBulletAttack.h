#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsCircleCollider.h"

class BulletAttack
{
public:

	BulletAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Update(float deltaTime);

	void Draw(sf::RenderWindow& window);

	void setPosition(sf::Vector2f position);

	void setAngle(float angle);

	float getTimeAlive();

	CircleCollider getCollider();

	int getDmg();

private:

	int dmg;

	float timeAlive;
	float speed;
	float angle;

	sf::RectangleShape body;
	Animation animation;
	int row;
	bool faceRight;
};

