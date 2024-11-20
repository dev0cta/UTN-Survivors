#include "clsGameOver.h"
#include <iostream>

GameOver::GameOver(sf::Texture* playAgainTexture, sf::Texture* menuTexture) :
	playAgainAnimation(playAgainTexture), MenuAnimation(menuTexture)
{
	this->mouseOnPlay = false;
	this->mouseOnExit = false;

	backgroundImage.loadFromFile("./Assets/Images/gameOverBackground.jpg");
	backgroundSprite.setTexture(backgroundImage);
	backgroundSprite.setOrigin(sf::Vector2f(backgroundImage.getSize()) / 2.0f);
	backgroundSprite.setPosition(sf::Vector2f(-10.0f, -30.0f));
	backgroundSprite.setScale(16 / 15.5f, 9 / 8.6f);


	sf::Vector2f playSize= sf::Vector2f(71.0f, 23.0f) * 1.75f;
	playAgainButton.setSize(playSize);
	playAgainButton.setOrigin(playSize / 2.0f);
	playAgainButton.setPosition(sf::Vector2f(-80.0f, 100.0f));

	playAgainButton.setTexture(playAgainTexture);


	sf::Vector2f statsSize(128.0f, 47.0f);
	MenuButton.setSize(statsSize);
	MenuButton.setScale(0.75f, 0.75f);
	MenuButton.setOrigin(statsSize / 2.0f);
	MenuButton.setPosition(sf::Vector2f(80.0f, 100.0f));

	MenuButton.setTexture(menuTexture);
}

void GameOver::Update(sf::Vector2f mousePos)
{
	sf::Vector2f mousePosition = mousePos;

	bool mouseOverPlay = false;
	bool mouseOverExit = false;


	sf::Vector2f thisPosition = playAgainButton.getPosition();
	sf::Vector2f thisHalfSize = playAgainButton.getSize() / 2.0f;

	float deltaX = mousePos.x - thisPosition.x;
	float deltaY = mousePos.y - thisPosition.y;

	float IntersectX = abs(deltaX) - (thisHalfSize.x);
	float IntersectY = abs(deltaY) - (thisHalfSize.y);

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
	{

		mouseOverPlay = true;
	}

	thisPosition = MenuButton.getPosition();
	thisHalfSize = MenuButton.getSize() / 2.0f;

	deltaX = mousePos.x - thisPosition.x;
	deltaY = mousePos.y - thisPosition.y;

	IntersectX = abs(deltaX) - (thisHalfSize.x);
	IntersectY = abs(deltaY) - (thisHalfSize.y);

	//std::cout << "intersectX: " << IntersectX << std::endl << "IntersectY: " << IntersectY << std::endl;

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si se tocan
	{

		mouseOverExit = true;
	}

	this->mouseOnPlay = mouseOverPlay;
	this->mouseOnExit = mouseOverExit;

	playAgainAnimation.Update(mouseOverPlay);
	playAgainButton.setTextureRect(playAgainAnimation.uvRect);

	MenuAnimation.Update(mouseOverExit);
	MenuButton.setTextureRect(MenuAnimation.uvRect);

}

void GameOver::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);

	window.draw(playAgainButton);

	window.draw(MenuButton);

}

int GameOver::getOptionPressed()
{
	if (mouseOnPlay && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 1;
	}
	if (mouseOnExit && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 0;
	}


	return -1;
}

