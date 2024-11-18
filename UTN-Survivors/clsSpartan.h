#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsEnemy.h"
#include "clsCircleCollider.h"

class Spartan: public Enemy
{

public:

	Spartan(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltaTime, sf::Vector2f target) override;

	void Draw(sf::RenderWindow& window) override;

	CircleCollider GetCollider() override;

	sf::RectangleShape& getBody();

	void setType(int type);


private:

	void moveTowardsTarget(float deltaTime);

private:

	///stats




	float speed;


	///funciones

	int type;

	sf::Vector2f target;

	sf::RectangleShape body;

	bool				faceRight;
	unsigned int		row;
	Animation			animation;
};

