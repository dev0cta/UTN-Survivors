#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsEnemy.h"
#include "clsCircleCollider.h"

class Slime: public Enemy
{
public:

	Slime(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltaTime, sf::Vector2f target) override;

	void Draw(sf::RenderWindow& window) override;

	CircleCollider GetHitbox() override;

	CircleCollider GetCollider() override;



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

