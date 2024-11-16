#include "BarraVida.h"

BarraVida::BarraVida(sf::Vector2f posToPj, float HpMax)
{
	this->HpMax = HpMax;
		background.setSize(sf::Vector2f(50.0f, 3.50f));
		background.setFillColor(sf::Color::Black);
		
		HpActualBar.setSize(sf::Vector2f(48.5f, 2.5f));
		HpActualBar.setFillColor(sf::Color::Green);
		
		
}

void BarraVida::update(sf::Vector2f posToPj)
{
	background.setPosition(sf::Vector2f(posToPj.x-25,posToPj.y+25));

	HpActualBar.setPosition(background.getPosition().x + 1, background.getPosition().y + 0.5);
}


void BarraVida::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(HpActualBar);
}


