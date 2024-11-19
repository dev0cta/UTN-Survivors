#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsCircleCollider.h"

class Enemy
{
public:


	virtual void Update(float deltaTime, sf::Vector2f target) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;

	virtual CircleCollider GetCollider() = 0;

private:
	int dmg = 1;
};

