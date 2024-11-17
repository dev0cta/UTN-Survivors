#include "clsCircleCollider.h"
#include <iostream>
#include <cmath>


	
CircleCollider::CircleCollider(sf::RectangleShape& body) :
	_body(body)
{

}


void CircleCollider::move(float dx, float dy)
{
	_body.move(dx, dy);
}

bool CircleCollider::checkSolidCollision(CircleCollider other, float push)
{
	sf::Vector2f thisPosition(_body.getPosition());
	sf::Vector2f otherPosition(other.getPosition());

	float cat1 = thisPosition.x - otherPosition.x;
	float cat2 = thisPosition.y - otherPosition.y;

	float distance = sqrt((cat1 * cat1) + (cat2 * cat2));

	
	push = std::min(std::max(push, 0.0f), 1.0f);
	
	float thisHalfSize = _body.getSize().x / 2.0f;
	float otherHalfSize = other.getHalfXSize();

	if (distance < ( thisHalfSize + otherHalfSize))
	{
		float angle = atan2(otherPosition.y - thisPosition.y, otherPosition.x - thisPosition.x);

		_body.move((-push * cos(angle)), (-push * sin(angle)));

		other.move((push  * cos(angle)), (push * sin(angle)));

		
		return true;
	}


	
	return false;
}


bool CircleCollider::checkCollision(CircleCollider other)
{
	
	sf::Vector2f thisPosition(_body.getPosition());
	sf::Vector2f otherPosition(other.getPosition());

	float cat1 = abs(thisPosition.x - otherPosition.x);
	float cat2 = abs(thisPosition.y - otherPosition.y);

	float distance = sqrt((cat1 * cat1) + (cat2 * cat2));
	
	

	if (distance < ((_body.getSize().x / 2.0f) + other.getHalfXSize()))
	{
		return true;
	}

	return false;
}

CircleCollider CircleCollider::GetCollider()
{
	return CircleCollider(_body);
}

sf::Vector2f CircleCollider::getPosition()
{
	return _body.getPosition();
}

float CircleCollider::getHalfXSize()
{
	return _body.getSize().x /2.0f;
}


