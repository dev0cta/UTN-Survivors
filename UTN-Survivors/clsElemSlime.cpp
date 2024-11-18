#include "clsElemSlime.h"
#include <cmath>


ElementalSlime::ElementalSlime(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	type = 0;
	this->speed = speed;
	row = type;
	faceRight = true;



	body.setSize(sf::Vector2f(20.0f, 20.0f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
	//--------------DESCOMENTAR PARA VER LA HITBOX-------------
	//body.setOutlineThickness(-0.1f);
	//body.setOutlineColor(sf::Color::White);
	//---------------------------------------------------------

}

void ElementalSlime::Update(float deltaTime, sf::Vector2f target)
{
	this->target = target;



	moveTowardsTarget(deltaTime);

	animation.Update(type, deltaTime, faceRight);
	body.setTextureRect(animation.getUvRect());
}

void ElementalSlime::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

CircleCollider ElementalSlime::GetCollider()
{
	return CircleCollider(body);
}

sf::RectangleShape& ElementalSlime::getBody()
{
	return body;
}

void ElementalSlime::setType(int type)
{
	this->type = type;
}







/// ----------------- FUNCIONES INTERNAS --------------------------

void ElementalSlime::moveTowardsTarget(float deltaTime)
{

	//calcula en que angulo se tiene que mover el enemigo para alcanzar al jugador

	if (target.x < body.getPosition().x)
		faceRight = false;
	else
		faceRight = true;

	float angle = atan2(target.y - body.getPosition().y, target.x - body.getPosition().x);

	this->body.move((speed * cos(angle)) * deltaTime, (speed * sin(angle)) * deltaTime);

}


