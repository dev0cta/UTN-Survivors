#include "clsInterface.h"
#include "clsInterface.h"
#include <iostream>

Interface::Interface(sf::Vector2f posToPj, float hpMax)
{
	this->hpMax = hpMax;
		Hpbackground.setSize(sf::Vector2f(50.0f, 3.50f));
		Hpbackground.setFillColor(sf::Color::Black);
		
		
		HpActualBar.setSize(sf::Vector2f(48.5f, 2.5f));
		HpActualBar.setFillColor(sf::Color::Green);
		
		
		Expbackground.setSize(sf::Vector2f(540.0f, 10.0f));
		Expbackground.setFillColor(sf::Color::Color(209,209,209));
		Expbackground.setOrigin(sf::Vector2f(540.0f, 10.0f) / 2.0f);
		

		ExpActualBar.setSize(sf::Vector2f(530.0f, 5.0f));
		ExpActualBar.setFillColor(sf::Color::Cyan);
		ExpActualBar.setOrigin(sf::Vector2f(520.0f, 10.0f) / 2.0f);	


		levelCounterBackground.setSize(sf::Vector2f(20.0f, 20.0f));
		levelCounterBackground.setFillColor(sf::Color::Color(100,129,143));
		levelCounterBackground.setOrigin(sf::Vector2f(20.0f, 20.0f) / 2.0f);

		textFont.loadFromFile("./Assets/Fonts/Minecraft.ttf");
		levelNumber.setOrigin(sf::Vector2f(20.0f, 20.0f) / 2.0f);
		levelNumber.setFont(textFont);
		levelNumber.setFillColor(sf::Color::White);
		levelNumber.setOutlineThickness(-1.0f);
		levelNumber.setOutlineColor(sf::Color::Black);
		levelNumber.setCharacterSize(32);
		levelNumber.setScale(sf::Vector2f(0.4, 0.4));

}

void Interface::UpdateHpBar(float hpActual, float hpMax)
{
	float hpPercent = hpActual / hpMax;
	HpActualBar.setSize(sf::Vector2f(48.5f * hpPercent, HpActualBar.getSize().y));
	hpPercent = std::max(0.0f, std::min(hpPercent, 1.0f));
	std::cout << "hpPercent: " << hpPercent << std::endl;

	HpActualBar.setSize(sf::Vector2f(48.5f * hpPercent, HpActualBar.getSize().y));
}

void Interface::update(sf::Vector2f posToPj, int level)
{
	Hpbackground.setPosition(sf::Vector2f(posToPj.x - 25, posToPj.y + 25));
	HpActualBar.setPosition(Hpbackground.getPosition().x + 1, Hpbackground.getPosition().y + 0.5);

	Expbackground.setPosition(sf::Vector2f(posToPj.x - 10.0f , posToPj.y - 148));
	ExpActualBar.setPosition(Expbackground.getPosition().x + 4.5, Expbackground.getPosition().y + 4);

	levelCounterBackground.setPosition(sf::Vector2f(posToPj.x - 10.0f , posToPj.y - 148));
	levelNumber.setPosition(levelCounterBackground.getPosition().x + 1.5, levelCounterBackground.getPosition().y);
	levelNumber.setString(std::to_string(level));


}


void Interface::Draw(sf::RenderWindow& window)
{
	window.draw(Hpbackground);
	window.draw(HpActualBar);
	window.draw(Expbackground);
	window.draw(ExpActualBar);
	window.draw(levelCounterBackground);
	window.draw(levelNumber);
}


