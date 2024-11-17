#include "clsButtonAnimation.h"

ButtonAnimation::ButtonAnimation(sf::Texture* texture)
{
	imageCount = sf::Vector2u(2, 1);

	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

void ButtonAnimation::Update(bool mouseOnButton)
{
	sf::Vector2u lastRow = currentImage;

	currentImage.y = 0;

	if (currentImage.y != lastRow.y) {
		currentImage.x = 0;
	}

	if (mouseOnButton == true)
	{
		currentImage.x = 1;

	}
	else
	{
	
		currentImage.x = 0;
	
	}

	uvRect.top = currentImage.y * uvRect.height;

	uvRect.left = currentImage.x * abs(uvRect.width);
	uvRect.width = abs(uvRect.width);


}

