#include "clsStatisticsMenu.h"
#include <iostream>

StatisticsMenu::StatisticsMenu(Statistics statistics, sf::Texture* exitTexture) :
	globalStats(statistics), MenuAnimation(exitTexture)
{
	this->mouseOnPlay = false;
	this->mouseOnExit = false;

	backgroundImage.loadFromFile("./Assets/Images/StatisticsBackground.jpg");
	backgroundSprite.setTexture(backgroundImage);
	backgroundSprite.setOrigin(sf::Vector2f(backgroundImage.getSize()) / 2.0f);
	backgroundSprite.setScale(4 / 4.5f, 3 / 6.0f);


	sf::Vector2f statsSize(128.0f, 47.0f);
	MenuButton.setSize(statsSize);
	MenuButton.setScale(0.75f, 0.75f);
	MenuButton.setOrigin(statsSize / 2.0f);
	MenuButton.setPosition(sf::Vector2f(-115.0f, 110.0f));

	float scale = 0.4f;

	textFont.loadFromFile("./Assets/Fonts/Minecraft.ttf");
	timeSurvived.setFont(textFont);
	timeSurvived.setFillColor(sf::Color::White);
	timeSurvived.setOutlineThickness(-1.0f);
	timeSurvived.setOutlineColor(sf::Color::Black);
	timeSurvived.setCharacterSize(32);
	timeSurvived.setScale(sf::Vector2f(scale,scale));

	dmgTaken.setFont(textFont);
	dmgTaken.setFillColor(sf::Color::White);
	dmgTaken.setOutlineThickness(-1.0f);
	dmgTaken.setOutlineColor(sf::Color::Black);
	dmgTaken.setCharacterSize(32);
	dmgTaken.setScale(sf::Vector2f(scale, scale));
	
	dmgDealt.setFont(textFont);
	dmgDealt.setFillColor(sf::Color::White);
	dmgDealt.setOutlineThickness(-1.0f);
	dmgDealt.setOutlineColor(sf::Color::Black);
	dmgDealt.setCharacterSize(32);
	dmgDealt.setScale(sf::Vector2f(scale, scale));

	timesLeveledUpText.setFont(textFont);
	timesLeveledUpText.setFillColor(sf::Color::White);
	timesLeveledUpText.setOutlineThickness(-1.0f);
	timesLeveledUpText.setOutlineColor(sf::Color::Black);
	timesLeveledUpText.setCharacterSize(32);
	timesLeveledUpText.setScale(sf::Vector2f(scale, scale));

	gamesBeatedCountText.setFont(textFont);
	gamesBeatedCountText.setFillColor(sf::Color::White);
	gamesBeatedCountText.setOutlineThickness(-1.0f);
	gamesBeatedCountText.setOutlineColor(sf::Color::Black);
	gamesBeatedCountText.setCharacterSize(32);
	gamesBeatedCountText.setScale(sf::Vector2f(scale, scale));

	slimeText.setFont(textFont);
	slimeText.setFillColor(sf::Color::White);
	slimeText.setOutlineThickness(-1.0f);
	slimeText.setOutlineColor(sf::Color::Black);
	slimeText.setCharacterSize(32);
	slimeText.setScale(sf::Vector2f(scale, scale));
	
	elemSlimeText.setFont(textFont);
	elemSlimeText.setFillColor(sf::Color::White);
	elemSlimeText.setOutlineThickness(-1.0f);
	elemSlimeText.setOutlineColor(sf::Color::Black);
	elemSlimeText.setCharacterSize(32);
	elemSlimeText.setScale(sf::Vector2f(scale, scale));
	
	spartanText.setFont(textFont);
	spartanText.setFillColor(sf::Color::White);
	spartanText.setOutlineThickness(-1.0f);
	spartanText.setOutlineColor(sf::Color::Black);
	spartanText.setCharacterSize(32);
	spartanText.setScale(sf::Vector2f(scale, scale));
	
	reaperText.setFont(textFont);
	reaperText.setFillColor(sf::Color::White);
	reaperText.setOutlineThickness(-1.0f);
	reaperText.setOutlineColor(sf::Color::Black);
	reaperText.setCharacterSize(32);
	reaperText.setScale(sf::Vector2f(scale, scale));

	sf::Vector2f statisticsOrigin(0.0f, -70.0f);

	timeSurvived.setPosition(        statisticsOrigin + sf::Vector2f(-190.0f, 0.0f));
	dmgTaken.setPosition(            statisticsOrigin + sf::Vector2f(-190.0f, 20.0f));
	dmgDealt.setPosition(            statisticsOrigin + sf::Vector2f(-190.0f, 40.0f));
	timesLeveledUpText.setPosition(  statisticsOrigin + sf::Vector2f(-190.0f, 60.0f));
	gamesBeatedCountText.setPosition(statisticsOrigin + sf::Vector2f(-190.0f, 80.0f));

	slimeText.setPosition(           statisticsOrigin + sf::Vector2f(0.0f, 0.0f));
	elemSlimeText.setPosition(       statisticsOrigin + sf::Vector2f(0.0f, 20.0f));
	spartanText.setPosition(         statisticsOrigin + sf::Vector2f(0.0f, 40.0f));
	reaperText.setPosition(          statisticsOrigin + sf::Vector2f(0.0f, 60.0f));


	MenuButton.setTexture(exitTexture);
}

void StatisticsMenu::setStatistics(Statistics statistics)
{
	this->globalStats = statistics;
}

void StatisticsMenu::Update(sf::Vector2f mousePos)
{
	sf::Vector2f mousePosition = mousePos;

	bool mouseOverPlay = false;
	bool mouseOverExit = false;


	sf::Vector2f thisPosition = MenuButton.getPosition();
	sf::Vector2f thisHalfSize = MenuButton.getSize() / 2.0f;

	float deltaX = mousePos.x - thisPosition.x;
	float deltaY = mousePos.y - thisPosition.y;

	float IntersectX = abs(deltaX) - (thisHalfSize.x);
	float IntersectY = abs(deltaY) - (thisHalfSize.y);

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
	{

		mouseOverExit = true;
	}

	this->mouseOnPlay = mouseOverPlay;
	this->mouseOnExit = mouseOverExit;


	timeSurvived.setString("Time Survived: " + std::to_string(int(globalStats.getTimeSurvived())));
	dmgTaken.setString("Total dmg Taken: " + std::to_string(globalStats.getDmgTaken()));
	dmgDealt.setString("Total dmg Dealt " + std::to_string(globalStats.getDmgDealt()));
	slimeText.setString("Total Slimes Defeated: " + std::to_string(globalStats.getSlimesDefeated()));
	elemSlimeText.setString("Total Elem. Slime Defeated: " + std::to_string(globalStats.getElementalSlimesDefeated()));
	spartanText.setString("Total Spartan Defeated: " + std::to_string(globalStats.getSpartansDefeated()));
	reaperText.setString("Total Reaper Defeated: " + std::to_string(globalStats.getReapersDefeated()));
	timesLeveledUpText.setString("Times leveled up: " + std::to_string(globalStats.getTimesLeveledUp()));
	gamesBeatedCountText.setString("Game Beated Counter: " + std::to_string(globalStats.getGameBeatedCounter()));


	MenuAnimation.Update(mouseOverExit);
	MenuButton.setTextureRect(MenuAnimation.uvRect);

}

void StatisticsMenu::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);

	window.draw(timeSurvived);
	window.draw(dmgTaken);
	window.draw(dmgDealt);
	window.draw(slimeText);
	window.draw(elemSlimeText);
	window.draw(spartanText);
	window.draw(reaperText);
	window.draw(timesLeveledUpText);
	window.draw(gamesBeatedCountText);

	window.draw(MenuButton);

}

int StatisticsMenu::getOptionPressed()
{

	if (mouseOnExit && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 0;
	}


	return -1;
}

