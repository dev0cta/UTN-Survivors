#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

class Animation

{
public:

	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Update(int row, float deltaTime, bool faceRight);

	sf::Texture* getTexture();

	sf::IntRect getUvRect();

public:


private:
	sf::IntRect uvRect;
	sf::Vector2u currentImage;
	sf::Texture texture;
	sf::Vector2u imageCount;

	float totalTime;
	float switchTime;

};

