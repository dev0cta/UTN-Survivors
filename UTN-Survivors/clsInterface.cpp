#include "clsInterface.h"
#include "clsInterface.h"
#include <iostream>

Interface::Interface(sf::Vector2f posToPj, float hpMax)
	: isProyectUpgradeVisible(false), proyectUpgradeTimer(0.0f)
{
	this->hpMax = hpMax;

		configurarRectangle(Hpbackground, sf::Vector2f(50.0f, 3.50f), sf::Color::Black, false);
		configurarRectangle(HpActualBar, sf::Vector2f(48.5f, 2.5f), sf::Color::Red, false);
		
		configurarRectangle(Expbackground, sf::Vector2f(540.0f, 10.0f), sf::Color(209, 209, 209), true);
		configurarRectangle(ExpActualBar, sf::Vector2f(530.0f, 5.0f), sf::Color::Green, true);
		configurarRectangle(levelCounterBackground, sf::Vector2f(20.0f, 20.0f), sf::Color(100, 129, 143), true);

		if (!textFont.loadFromFile("./Assets/Fonts/Minecraft.ttf")) {
			std::cout << "NO FUNCAAAAA / INTERFACECPP";
		}
		configurarText(ProyectUpgrade, textFont, "LEVEL UP", sf::Color::White, 16, -1.0f, sf::Color::Black, sf::Vector2f(0.4,0.4));
		levelNumber.setOrigin(sf::Vector2f(20.0f, 20.0f) / 2.0f);
		configurarText(levelNumber, textFont, "", sf::Color::White, 32, -1.0f, sf::Color::Black, sf::Vector2f(0.4,0.4));

}

void Interface::UpdateHpBar(float hpActual, float hpMax)
{
	float hpPercent = hpActual / hpMax;
	HpActualBar.setSize(sf::Vector2f(48.5f * hpPercent, HpActualBar.getSize().y));
	hpPercent = std::max(0.0f, std::min(hpPercent, 1.0f));
	//std::cout << "hpPercent: " << hpPercent << std::endl;

	HpActualBar.setSize(sf::Vector2f(48.5f * hpPercent, HpActualBar.getSize().y));
}

void Interface::UpdateExpBar(float expActual, float expMax)
{
	if (expMax > 0)
	{
		float expPercent = expActual / expMax;
		expPercent = std::max(0.0f, std::min(expPercent, 1.0f));

		ExpActualBar.setSize(sf::Vector2f(530.0f * expPercent, 5.0f));
	}
}

void Interface::update(sf::Vector2f posToPj, int level, float deltaTime)
{

	Hpbackground.setPosition(sf::Vector2f(posToPj.x - 25, posToPj.y + 25));
	HpActualBar.setPosition(Hpbackground.getPosition().x + 1, Hpbackground.getPosition().y + 0.5);

	Expbackground.setPosition(sf::Vector2f(posToPj.x - 10.0f, posToPj.y - 148));
	ExpActualBar.setPosition(Expbackground.getPosition().x + 4.5, Expbackground.getPosition().y + 4);

	levelCounterBackground.setPosition(sf::Vector2f(posToPj.x - 10.0f, posToPj.y - 148));
	levelNumber.setPosition(levelCounterBackground.getPosition().x + 1.5, levelCounterBackground.getPosition().y);
	levelNumber.setString(std::to_string(level));

	if (LastLevel != level ) {
		isProyectUpgradeVisible = true;
		proyectUpgradeTimer = 0.0f;
		ProyectUpgrade.setPosition(Expbackground.getPosition().x - 15, Expbackground.getPosition().y);
		LastLevel = level;
	}

	// Actualizar temporizador de ProyectUpgrade
	if (isProyectUpgradeVisible) {
		proyectUpgradeTimer += deltaTime;
		if (proyectUpgradeTimer >= timeDurationProyect) {
			isProyectUpgradeVisible = false;
		}
		else {
			// Actualizar la posición de ProyectUpgrade para que siga al jugador
			ProyectUpgrade.setPosition(posToPj.x-12.5, posToPj.y-20);
		}



	}
}

void Interface::configurarRectangle(sf::RectangleShape& rect, sf::Vector2f size, sf::Color color, bool setOrigin)
{
	rect.setSize(size);
	rect.setFillColor(color);
	if (setOrigin) {
		rect.setOrigin(size / 2.0f);
	}
}

void Interface::configurarText(sf::Text& text, const sf::Font& font, const std::string& str, sf::Color fillColor, unsigned int size, float outlineThickness, sf::Color outlineColor, sf::Vector2f scale)
{
	text.setFont(font);
	text.setFillColor(fillColor);
	text.setOutlineThickness(outlineThickness);
	text.setOutlineColor(outlineColor);
	text.setCharacterSize(size);
	text.setString(str);
	text.setScale(scale);
}

void Interface::Draw(sf::RenderWindow& window)
{
	window.draw(Hpbackground);
	window.draw(HpActualBar);
	window.draw(Expbackground);
	window.draw(ExpActualBar);
	window.draw(levelCounterBackground);
	window.draw(levelNumber);
	if (isProyectUpgradeVisible) {
		window.draw(ProyectUpgrade);
	}
}


