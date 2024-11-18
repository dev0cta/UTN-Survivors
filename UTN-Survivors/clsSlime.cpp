#include "clsSlime.h"
#include <cmath>


Slime::Slime(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	type = 0;
	row = type;
	faceRight = true;

	this->level = level;
	this->speed = speed;
	this->health = 100;
	this->healthScaling = 25;
	this->dmg = 10;
	this->dmgScaling = 10;


	body.setSize(sf::Vector2f(20.0f, 20.0f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
	//--------------DESCOMENTAR PARA VER LA HITBOX-------------
	//body.setOutlineThickness(-0.1f);
	//body.setOutlineColor(sf::Color::White);
	//---------------------------------------------------------

}

void Slime::Update(float deltaTime, sf::Vector2f target)
{
	this->target = target;



	moveTowardsTarget(deltaTime); 

	animation.Update(type, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void Slime::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

CircleCollider Slime::GetCollider()
{
	return CircleCollider(body);
}

sf::RectangleShape& Slime::getBody()
{
	return body;
}

void Slime::takeDmg(int dmgTaken)
{
	health -= dmgTaken;

}

int Slime::getDmg()
{
	return dmg;
}

int Slime::getHealth()
{
	return health;
}

void Slime::setType(int type)
{
	this->type = type;
}

void Slime::setLevel(int level)
{
	this->level = level;

	dmg = dmg + level * dmgScaling;
	health = health + level * healthScaling;

}







/// ----------------- FUNCIONES INTERNAS --------------------------

void Slime::moveTowardsTarget(float deltaTime)
{

	//calcula en que angulo se tiene que mover el enemigo para alcanzar al jugador

	if (target.x < body.getPosition().x)
		faceRight = false;
	else
		faceRight = true;

	float angle = atan2(target.y - body.getPosition().y, target.x - body.getPosition().x);

	this->body.move((speed * cos(angle)) * deltaTime, (speed * sin(angle)) * deltaTime);

}


