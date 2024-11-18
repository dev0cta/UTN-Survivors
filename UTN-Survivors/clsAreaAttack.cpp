#include "clsAreaAttack.h"

AreaAttack::AreaAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	animation(texture, imageCount, switchTime)
{

	this->dmg = 5;
	this->speed = 1;

	this->faceRight = true;
	this->row = 0;
	this->timeAlive = 0.0f;

	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(sf::Vector2f(20.0f, 20.0f) / 2.0f);
	body.setPosition(sf::Vector2f(0.0f, 0.0f));

	body.setTexture(texture);
}

void AreaAttack::Update(float deltaTime)
{

	timeAlive += deltaTime;

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void AreaAttack::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void AreaAttack::setPosition(sf::Vector2f position)
{
	body.setPosition(position);
}



float AreaAttack::getTimeAlive()
{
	return timeAlive;
}

CircleCollider AreaAttack::getCollider()
{
	return CircleCollider(body);
}

int AreaAttack::getDmg()
{
	return dmg;
}
