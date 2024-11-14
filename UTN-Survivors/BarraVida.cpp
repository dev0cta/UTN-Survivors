#include "BarraVida.h"

BarraVida::BarraVida(sf::Vector2f posToPj, float HpMax)
{
	this->HpMax = HpMax;
		background.setSize(sf::Vector2f(10.0f, 0.75f));
		background.setFillColor(sf::Color::Black);
		
		HpActualBar.setSize(sf::Vector2f(9.75f, 0.65f));
		HpActualBar.setFillColor(sf::Color::Green);
		
		
}

void BarraVida::update(sf::Vector2f posToPj)
{
	background.setPosition(sf::Vector2f(posToPj.x-5,posToPj.y-5));

	HpActualBar.setPosition(background.getPosition().x + 0.10, background.getPosition().y + 0.05);
}


void BarraVida::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(HpActualBar);
}


