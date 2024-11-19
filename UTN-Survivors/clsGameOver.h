#pragma once

#include "SFML/Graphics.hpp"
#include "clsButtonAnimation.h"

class GameOver
{
public:
	GameOver(sf::Texture* playAgainTexture, sf::Texture* menuTexture);

	void Update(sf::Vector2f mousePos);

	void Draw(sf::RenderWindow& window);

	int getOptionPressed();


private:

	bool mouseOnPlay;
	bool mouseOnExit;

	sf::Texture			backgroundImage;
	sf::Sprite			backgroundSprite;

	sf::RectangleShape playAgainButton;
	ButtonAnimation playAgainAnimation;
	sf::RectangleShape MenuButton;
	ButtonAnimation MenuAnimation;
};

