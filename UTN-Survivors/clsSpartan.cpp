#include "clsSpartan.h"
#include <cmath>


Spartan::Spartan(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	type = 0;
	row = type;
	faceRight = true;

	this->level = level;
	this->speed = speed;
	this->health = 100;
	this->healthScaling = 45;
	this->dmg = 10;
	this->dmgScaling = 10;


	body.setSize(sf::Vector2f(20.0f, 40.0f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
	//--------------DESCOMENTAR PARA VER LA HITBOX-------------
	//body.setOutlineThickness(-0.1f);
	//body.setOutlineColor(sf::Color::White);
	//---------------------------------------------------------

}

void Spartan::Update(float deltaTime, sf::Vector2f target)
{
	this->target = target;



	moveTowardsTarget(deltaTime);

	animation.Update(type, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void Spartan::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

CircleCollider Spartan::GetCollider()
{
	return CircleCollider(body);
}

sf::RectangleShape& Spartan::getBody()
{
	return body;
}

void Spartan::takeDmg(int dmgTaken)
{
	health -= dmgTaken;
}

int Spartan::getDmg()
{
	return dmg;
}

int Spartan::getHealth()
{
	return health;
}






void Spartan::setType(int type)
{
	this->type = type;
}

void Spartan::setLevel(int level)
{
	this->level = level;

	dmg = dmg + level * dmgScaling;
	health = health + level * healthScaling;

}







/// ----------------- FUNCIONES INTERNAS --------------------------

void Spartan::moveTowardsTarget(float deltaTime)
{

	//calcula en que angulo se tiene que mover el enemigo para alcanzar al jugador

	if (target.x < body.getPosition().x)
		faceRight = false;
	else
		faceRight = true;

	float angle = atan2(target.y - body.getPosition().y, target.x - body.getPosition().x);

	this->body.move((speed * cos(angle)) * deltaTime, (speed * sin(angle)) * deltaTime);

}


