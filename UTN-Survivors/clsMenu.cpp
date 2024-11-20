#include "clsMenu.h"
#include <iostream>

Menu::Menu(sf::Texture* playTexture, sf::Texture* statsTexture):
	playAnimation(playTexture), statsAnimation(statsTexture)
{
	this->mouseOnPlay = false;
	this->mouseOnStats = false;

	backgroundImage.loadFromFile("./Assets/Images/mainMenuBackground.jpg");
	background.setTexture(backgroundImage);
	background.setOrigin(sf::Vector2f(backgroundImage.getSize()) / 2.0f);
	background.setPosition(sf::Vector2f(80.0f,0.0f));
	background.setScale(16 / 15.5f, 9 / 8.6f);


	sf::Vector2f playSize(128.0f, 64.0f);
	playButton.setSize(playSize);
	playButton.setOrigin(playSize /2.0f );
	playButton.setPosition(sf::Vector2f(100.0f, 0.0f));

	playButton.setTexture(playTexture);
	

	sf::Vector2f statsSize(128.0f, 47.0f);
	statsButton.setSize(statsSize);
	statsButton.setScale(0.75f, 0.75f);
	statsButton.setOrigin(statsSize /2.0f );
	statsButton.setPosition(sf::Vector2f(110.0f, 60.0f));

	statsButton.setTexture(statsTexture);
}

void Menu::Update(sf::Vector2f mousePos)
{
	sf::Vector2f mousePosition = mousePos;
	
	bool mouseOverPlay  = false;
	bool mouseOverStats = false;


	sf::Vector2f thisPosition = playButton.getPosition();
	sf::Vector2f thisHalfSize = playButton.getSize() / 2.0f;

	float deltaX = mousePos.x - thisPosition.x;
	float deltaY = mousePos.y - thisPosition.y;

	float IntersectX = abs(deltaX) - (thisHalfSize.x);
	float IntersectY = abs(deltaY) - (thisHalfSize.y);

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
	{

		mouseOverPlay = true;
	}

	thisPosition = statsButton.getPosition();
	thisHalfSize = statsButton.getSize() / 2.0f;

	deltaX = mousePos.x - thisPosition.x;
	deltaY = mousePos.y - thisPosition.y;

	IntersectX = abs(deltaX) - (thisHalfSize.x);
	IntersectY = abs(deltaY) - (thisHalfSize.y);

	//std::cout << "intersectX: " << IntersectX << std::endl << "IntersectY: " << IntersectY << std::endl;

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si se tocan
	{

		mouseOverStats = true;
	}
	
	this->mouseOnPlay  = mouseOverPlay;
	this->mouseOnStats = mouseOverStats;

	playAnimation.Update(mouseOverPlay);
	playButton.setTextureRect(playAnimation.uvRect);
	
	statsAnimation.Update(mouseOverStats);
	statsButton.setTextureRect(statsAnimation.uvRect);

}

void Menu::Draw(sf::RenderWindow& window)
{
		window.draw(background);

		window.draw(playButton);

		window.draw(statsButton);

}

int Menu::getOptionPressed()
{
	if (mouseOnPlay && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 1;
	}
	if (mouseOnStats && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 2;
	}


	return -1;
}

