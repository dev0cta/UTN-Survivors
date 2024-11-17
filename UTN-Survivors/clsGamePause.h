#pragma once

#include "SFML/Graphics.hpp"
#include "clsButtonAnimation.h"
#include "clsAnimation.h"
#include <iostream>

class GamePause
{
public:
	GamePause(sf::Texture* pauseTexture, sf::Texture* exitTexture, sf::RenderWindow& window);

	void Update(sf::Vector2f mousePos, bool paused, float betaTime, sf::Vector2f playerPos);

 	void Draw(sf::RenderWindow& window);

	int getOptionPressed();


private:

	bool paused;
	bool mouseOnExit;

	sf::RectangleShape	pauseSymbol;
	Animation			pauseAnimation;

	sf::RectangleShape	exitButton;
	ButtonAnimation		exitAnimation;

	sf::Vector2f screenSize;



};

