#pragma once

#include "SFML/Graphics.hpp"
#include "clsButtonAnimation.h"

class Menu
{
public:
	Menu(sf::Texture* playTexture, sf::Texture* statsTexture);

	void Update(sf::Vector2f mousePos);

	void Draw(sf::RenderWindow& window);

	int getOptionPressed();


private:

	bool mouseOnPlay;
	bool mouseOnStats;

	sf::Texture        backgroundImage;
	sf::Sprite background;

	sf::RectangleShape playButton;
	ButtonAnimation playAnimation;
	sf::RectangleShape statsButton;
	ButtonAnimation statsAnimation;

};

