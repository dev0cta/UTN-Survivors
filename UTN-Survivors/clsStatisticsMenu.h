#pragma once

#include "SFML/Graphics.hpp"
#include "clsButtonAnimation.h"
#include "clsStatistics.h"
#include <string>

class StatisticsMenu
{
public:
	StatisticsMenu(Statistics statistics, sf::Texture* exitTexture);

	void setStatistics(Statistics statistics);

	void Update(sf::Vector2f mousePos);

	void Draw(sf::RenderWindow& window);

	int getOptionPressed();


private:

	Statistics globalStats;

	bool mouseOnPlay;
	bool mouseOnExit;

	sf::Texture			backgroundImage;
	sf::Sprite			backgroundSprite;

	sf::Font			textFont;

	sf::Text			timeSurvived;
	sf::Text			dmgTaken;
	sf::Text			dmgDealt;
	sf::Text			slimeText;
	sf::Text			elemSlimeText;
	sf::Text			spartanText;
	sf::Text			reaperText;
	sf::Text			timesLeveledUpText;
	sf::Text			gamesBeatedCountText;


	sf::RectangleShape MenuButton;
	ButtonAnimation MenuAnimation;
};
