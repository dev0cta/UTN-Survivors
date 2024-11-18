#include "clsInterface.h"

Interface::Interface(sf::Vector2f posToPj, float HpMax)
{
	this->HpMax = HpMax;
		Hpbackground.setSize(sf::Vector2f(50.0f, 3.50f));
		Hpbackground.setFillColor(sf::Color::Black);
		
		
		HpActualBar.setSize(sf::Vector2f(48.5f, 2.5f));
		HpActualBar.setFillColor(sf::Color::Green);
		
		
		Expbackground.setSize(sf::Vector2f(540.0f, 10.0f));
		Expbackground.setFillColor(sf::Color::Color(209,209,209));
		Expbackground.setOrigin(sf::Vector2f(520.0f, 10.0f) / 2.0f);

		ExpActualBar.setSize(sf::Vector2f(530.0f, 5.0f));
		ExpActualBar.setFillColor(sf::Color::Cyan);
		ExpActualBar.setOrigin(sf::Vector2f(520.0f, 10.0f) / 2.0f);		
}

void Interface::update(sf::Vector2f posToPj)
{
	Hpbackground.setPosition(sf::Vector2f(posToPj.x - 25, posToPj.y + 25));
	HpActualBar.setPosition(Hpbackground.getPosition().x + 1, Hpbackground.getPosition().y + 0.5);

	Expbackground.setPosition(sf::Vector2f(posToPj.x - 10.0f , posToPj.y - 148));
	ExpActualBar.setPosition(Expbackground.getPosition().x + 4.5, Expbackground.getPosition().y + 2);


}


void Interface::Draw(sf::RenderWindow& window)
{
	window.draw(Hpbackground);
	window.draw(HpActualBar);
	window.draw(Expbackground);
	window.draw(ExpActualBar);

}


