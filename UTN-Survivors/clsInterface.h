#pragma once
#include <sfml/Graphics.hpp>

class Interface
{
private:

	float hpMax;
	float HpActual;
	sf::Vector2i size;
	sf::RectangleShape Hpbackground;
	sf::RectangleShape HpActualBar;

	sf::RectangleShape Expbackground;
	sf::RectangleShape ExpActualBar;
	sf::RectangleShape levelCounterBackground;
	sf::Text			levelNumber;
	sf::Font			textFont;

public:

	Interface(sf::Vector2f posToPj, float hpMax);
	void UpdateHpBar(float hpActual, float hpMax);
	void Draw(sf::RenderWindow& window);
	void update(sf::Vector2f posToPj, int level);

};


