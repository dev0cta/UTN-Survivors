#include "clsGamePause.h"

GamePause::GamePause(sf::Texture* pauseTexture, sf::Texture* exitTexture, sf::RenderWindow& window):
	pauseAnimation(pauseTexture, sf::Vector2u(2,1), 0.5f), exitAnimation(exitTexture)
{

	this->mouseOnExit   = false;
	this->paused		= false;

	sf::Vector2f firstCornerPos = window.mapPixelToCoords(sf::Vector2i(0, 0));
	sf::Vector2f secondCornerPos = window.mapPixelToCoords(sf::Vector2i(window.getSize()));

	screenSize = secondCornerPos - firstCornerPos;


	sf::Vector2f pauseSize(192.0f, 64.0f);
	pauseSymbol.setSize(pauseSize);
	pauseSymbol.setOrigin(pauseSize / 2.0f);
	pauseSymbol.setPosition(firstCornerPos + (secondCornerPos / 2.0f));

	pauseSymbol.setTexture(pauseTexture);
	
	sf::Vector2f exitSize(75.0f, 42.0f);
	exitButton.setSize(exitSize);
	exitButton.setOrigin(exitSize / 2.0f);
	exitButton.setPosition(firstCornerPos + (secondCornerPos / 2.0f));

	exitButton.setTexture(exitTexture);

}

void GamePause::Update(sf::Vector2f mousePos, bool paused, float betaTime, sf::Vector2f playerPos)
{
	this->paused = paused;

	sf::Vector2f screenCenter = playerPos;
	
	pauseSymbol.setPosition(screenCenter + sf::Vector2f(0.0f, -10.0f));
	exitButton.setPosition(screenCenter  + sf::Vector2f(0.0f, 50.0f));



	sf::Vector2f mousePosition = mousePos;

	bool mouseOverExit = false;



	sf::Vector2f thisPosition = exitButton.getPosition();
	sf::Vector2f thisHalfSize = exitButton.getSize() / 2.0f;

	float deltaX = mousePos.x - thisPosition.x;
	float deltaY = mousePos.y - thisPosition.y;

	float IntersectX = abs(deltaX) - (thisHalfSize.x);
	float IntersectY = abs(deltaY) - (thisHalfSize.y);

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
	{

		mouseOverExit = true;
	}

	

	this->mouseOnExit = mouseOverExit;

	exitAnimation.Update(mouseOverExit);
	exitButton.setTextureRect(exitAnimation.uvRect);

	pauseAnimation.Update(0, betaTime, true);
	pauseSymbol.setTextureRect(pauseAnimation.getUvRect());

}

void GamePause::Draw(sf::RenderWindow& window)
{

	sf::Vector2f firstCornerPos = window.mapPixelToCoords(sf::Vector2i(0, 0));
	sf::Vector2f secondCornerPos = window.mapPixelToCoords(sf::Vector2i(window.getSize()));

	screenSize = secondCornerPos - firstCornerPos;

	if (paused) {
		window.draw(pauseSymbol);

		window.draw(exitButton);
	}
}

int GamePause::getOptionPressed()
{
	
	if (mouseOnExit && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 0;
	}
	


	return -1;
	
}
