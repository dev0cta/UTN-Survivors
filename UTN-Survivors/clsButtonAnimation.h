#pragma once

#include "SFML/Graphics.hpp"
#include <vector>


class ButtonAnimation
{

public:

	ButtonAnimation(sf::Texture* texture);

	void Update(bool mouseOnButton);

public:

	sf::IntRect uvRect;
	sf::Vector2u currentImage;

private:
	sf::Texture texture;
	sf::Vector2u imageCount;
};

