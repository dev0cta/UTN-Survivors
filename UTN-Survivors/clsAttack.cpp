#include "clsAttack.h"
clsAttack::clsAttack(sf::Vector2f playerPos, sf::Vector2f tam, int dmg) : tiempovida(5.0f), activo(true)
{
	body.setSize(tam);
	body.setFillColor(sf::Color::Red);

	if (faceRight)
	{
		body.setPosition(playerPos + sf::Vector2f(30.0f, 0.0f));
	}
	else
	{
		body.setPosition(playerPos - sf::Vector2f(body.getSize().x + 30, 0.0f));
	}
}

void clsAttack::update(float deltaTime)
{
	if (!activo)
	{
		return;
	}
	tiempovida -= deltaTime;

	if (tiempovida <= 0)
	{
		activo = false;
	}
}

void clsAttack::dibujar(sf::RenderWindow& ventana)
{
	if (activo)
	{
		ventana.draw(body);
	}
}


sf::RectangleShape& clsAttack::getBody()
{
	return body;
}

SquareCollider clsAttack::getCollider()
{
	return SquareCollider(body);
}

int clsAttack::applyDmg()
{
	return dmg;
}