#include "clsBulletAttack.h"

BulletAttack::BulletAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
		animation(texture, imageCount, switchTime)
{

	this->dmg = 15;
	this->speed = 50.0f;
	this->angle = -2;

	this->faceRight = true;
	this->row = 0;
	this->timeAlive = 0.0f;

	body.setSize(sf::Vector2f(20.0f, 20.0f));
	body.setOrigin(sf::Vector2f(20.0f, 20.0f) /2.0f);
	body.setPosition(sf::Vector2f(0.0f, 0.0f));

	body.setTexture(texture);
}

void BulletAttack::Update(float deltaTime)
{

	timeAlive += deltaTime;

	this->body.move((speed * cos(angle)) * deltaTime, (speed * sin(angle)) * deltaTime);

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void BulletAttack::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void BulletAttack::setPosition(sf::Vector2f position)
{
	body.setPosition(position);
}

void BulletAttack::setAngle(float angle)
{

		this->angle = angle;

		return;
}

float BulletAttack::getTimeAlive()
{
	return timeAlive;
}

CircleCollider BulletAttack::getCollider()
{
	return CircleCollider(body);
}

int BulletAttack::getDmg()
{
	return dmg;
}
