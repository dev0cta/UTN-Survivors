#pragma once
#include <sfml/Graphics.hpp>

class Interfaz
{
private:

	float HpMax;
	float HpActual;
	sf::Vector2i size;
	sf::RectangleShape Hpbackground;
	sf::RectangleShape HpActualBar;
	sf::RectangleShape Expbackground;
	sf::RectangleShape ExpActualBar;

public:

	Interfaz(sf::Vector2f posToPj, float HpMax);

	void Draw(sf::RenderWindow& window);
	void update(sf::Vector2f posToPj);

};


