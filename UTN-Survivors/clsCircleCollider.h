#pragma once

#include "SFML/Graphics.hpp"

class CircleCollider
{
public:
	CircleCollider(sf::RectangleShape& body);

	void move(float dx, float dy);

	bool checkSolidCollision(CircleCollider other, float push);

	bool checkCollision(CircleCollider other);

	CircleCollider GetCollider();

	sf::Vector2f getPosition();
	float getHalfXSize();

private:

	sf::RectangleShape& _body;
};

