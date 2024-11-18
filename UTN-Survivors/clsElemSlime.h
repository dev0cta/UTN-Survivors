#pragma once

#include "SFML/Graphics.hpp"
#include "clsAnimation.h"
#include "clsEnemy.h"
#include "clsCircleCollider.h"

class ElementalSlime : public Enemy
{
public:

	ElementalSlime(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltaTime, sf::Vector2f target) override;

	void Draw(sf::RenderWindow& window) override;

	CircleCollider GetCollider() override;

	sf::RectangleShape& getBody();

	void takeDmg(int dmgTaken);

	int getDmg();

	int getHealth();

	void setType(int type);

	void setLevel(int level);



private:

	void moveTowardsTarget(float deltaTime);

private:

	///stats

	int level;

	int health;
	int healthScaling; 

	int dmg;
	int dmgScaling;


	float speed;


	///funciones

	int type;

	sf::Vector2f target;

	sf::RectangleShape body;

	bool				faceRight;
	unsigned int		row;
	Animation			animation;

};

