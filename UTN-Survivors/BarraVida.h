#pragma once
#include <sfml/Graphics.hpp>

class BarraVida
{
private:

	float HpMax;
	float HpActual;
	sf::Vector2i size;
	sf::RectangleShape background;
	sf::RectangleShape HpActualBar;

public:

	BarraVida(sf::Vector2f posToPj, float HpMax);

	void Draw(sf::RenderWindow& window);
	void update(sf::Vector2f posToPj);

};


