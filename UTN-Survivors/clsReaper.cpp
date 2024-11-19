#include "clsReaper.h"
#include <cmath>


Reaper::Reaper(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	type = 0;
	faceRight = true;
	row = type;

	this->level = level;
	this->speed = speed;
	this->health = 100;
	this->healthScaling = 55;
	this->dmg = 10;
	this->dmgScaling = 10;


	body.setSize(sf::Vector2f(20.0f, 25.0f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
	//--------------DESCOMENTAR PARA VER LA HITBOX-------------
	//body.setOutlineThickness(-0.1f);
	//body.setOutlineColor(sf::Color::White);
	//---------------------------------------------------------

}

void Reaper::Update(float deltaTime, sf::Vector2f target)
{
	this->target = target;



	moveTowardsTarget(deltaTime);

	animation.Update(type, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void Reaper::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

CircleCollider Reaper::GetCollider()
{
	return CircleCollider(body);
}

sf::RectangleShape& Reaper::getBody()
{
	return body;
}

void Reaper::takeDmg(int dmgTaken)
{
	health -= dmgTaken;
}

int Reaper::getDmg()
{
	return dmg;
}

int Reaper::getHealth()
{
	return health;
}

void Reaper::setType(int type)
{
	this->type = type;
}

void Reaper::setLevel(int level)
{
	this->level = level;

	dmg = dmg + level * dmgScaling;
	health = health + level * healthScaling;

}







/// ----------------- FUNCIONES INTERNAS --------------------------

void Reaper::moveTowardsTarget(float deltaTime)
{

	//calcula en que angulo se tiene que mover el enemigo para alcanzar al jugador

	if (target.x < body.getPosition().x)
		faceRight = false;
	else
		faceRight = true;

	float angle = atan2(target.y - body.getPosition().y, target.x - body.getPosition().x);

	this->body.move((speed * cos(angle)) * deltaTime, (speed * sin(angle)) * deltaTime);

}


