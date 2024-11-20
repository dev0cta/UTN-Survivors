#include "BarraVida.h"

Interfaz::Interfaz(sf::Vector2f posToPj, float HpMax)
{
	this->HpMax = HpMax;
		Hpbackground.setSize(sf::Vector2f(50.0f, 3.50f));
		Hpbackground.setFillColor(sf::Color::Black);
		HpActualBar.setSize(sf::Vector2f(48.5f, 2.5f));
		HpActualBar.setFillColor(sf::Color::Green);
		
		Expbackground.setSize(sf::Vector2f(500.0f, 20.0f));
		Expbackground.setFillColor(sf::Color::White);
		ExpActualBar.setSize(sf::Vector2f(490.0f, 15.0f));
		ExpActualBar.setFillColor(sf::Color::Cyan);
}

void Interfaz::update(sf::Vector2f posToPj)
{
	Hpbackground.setPosition(sf::Vector2f(posToPj.x-25,posToPj.y+25));
	HpActualBar.setPosition(Hpbackground.getPosition().x + 1, Hpbackground.getPosition().y + 0.5);

	Expbackground.setPosition(sf::Vector2f(posToPj.x-245, posToPj.y - 149));
	ExpActualBar.setPosition(Expbackground.getPosition().x + 4.5, Expbackground.getPosition().y+2);


}


void Interfaz::Draw(sf::RenderWindow& window)
{
	window.draw(Hpbackground);
	window.draw(HpActualBar);
	window.draw(Expbackground);
	window.draw(ExpActualBar);
}


