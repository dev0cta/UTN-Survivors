#include "clsSlime.h"
#include <cmath>


Slime::Slime(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{

	this->speed = speed;
	int random = rand() % 3;
	row = random;
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

void Slime::Update(float deltaTime, sf::Vector2f target)
{
	this->target = target;



	moveTowardsTarget(deltaTime); 

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
}

void Slime::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

CircleCollider Slime::GetHitbox()
{
	return CircleCollider(body);	
}

CircleCollider Slime::GetCollider()
{
	return CircleCollider(body);
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


