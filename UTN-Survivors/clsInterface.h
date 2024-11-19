#pragma once
#include <sfml/Graphics.hpp>

class Interface
{
private:

	float hpMax;
	float HpActual;
	int LastLevel=1;
	bool isProyectUpgradeVisible; //NUEVA
	float proyectUpgradeTimer; //NUEVA
	const float timeDurationProyect = 2.0f; //NUEVA
	sf::Vector2i size;
	sf::RectangleShape Hpbackground;
	sf::RectangleShape HpActualBar;

	sf::RectangleShape Expbackground;
	sf::RectangleShape ExpActualBar;
	sf::RectangleShape levelCounterBackground;
	sf::Text			levelNumber;
	sf::Font			textFont;

	sf::Text            ProyectUpgrade;
	sf::Font            textLetters;

public:

	Interface(sf::Vector2f posToPj, float hpMax);
	void UpdateHpBar(float hpActual, float hpMax);
	void UpdateExpBar(float expActual, float expMax);

	void Draw(sf::RenderWindow& window);
	void update(sf::Vector2f posToPj, int level, float deltaTime);
	void configurarRectangle(sf::RectangleShape& rect, sf::Vector2f size, sf::Color color, bool setOrigin);
	void configurarText(sf::Text& text, const sf::Font& font, const std::string& str, sf::Color fillColor, unsigned int size, float outlineThickness, sf::Color outlineColor, sf::Vector2f scale);
};


