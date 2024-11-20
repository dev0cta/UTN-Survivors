#include "clsDirubin.h"


Dirubin::Dirubin(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	type = 0;
	faceRight = true;
	row = type;

	this->level = level;
	this->speed = speed;
	this->health = 40000;
	this->healthScaling = 1;
	this->dmg = 50;
	this->dmgScaling = 1;


	body.setSize(sf::Vector2f(75.0f, 75.0f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
	//--------------DESCOMENTAR PARA VER LA HITBOX-------------
	//body.setOutlineThickness(-0.1f);
	//body.setOutlineColor(sf::Color::White);
	//---------------------------------------------------------

}

void Dirubin::Update(float deltaTime, sf::Vector2f target)
{
	this->target = target;



	moveTowardsTarget(deltaTime);

	animation.Update(type, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void Dirubin::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

CircleCollider Dirubin::GetCollider()
{
	return CircleCollider(body);
}

sf::RectangleShape& Dirubin::getBody()
{
	return body;
}

void Dirubin::takeDmg(int dmgTaken)
{
	health -= dmgTaken;
}

int Dirubin::getDmg()
{
	return dmg;
}

int Dirubin::getHealth()
{
	return health;
}

void Dirubin::setType(int type)
{
	this->type = type;
}

void Dirubin::setLevel(int level)
{
	this->level = level;

	dmg = dmg + level * dmgScaling;
	health = health + level * healthScaling;

}







/// ----------------- FUNCIONES INTERNAS --------------------------

void Dirubin::moveTowardsTarget(float deltaTime)
{

	//calcula en que angulo se tiene que mover el enemigo para alcanzar al jugador

	if (target.x < body.getPosition().x)
		faceRight = false;
	else
		faceRight = true;

	float angle = atan2(target.y - body.getPosition().y, target.x - body.getPosition().x);

	this->body.move((speed * cos(angle)) * deltaTime, (speed * sin(angle)) * deltaTime);

}


