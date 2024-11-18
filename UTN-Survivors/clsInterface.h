#pragma once
#include <sfml/Graphics.hpp>

class Interface
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

	Interface(sf::Vector2f posToPj, float HpMax);

	void Draw(sf::RenderWindow& window);
	void update(sf::Vector2f posToPj);

};


