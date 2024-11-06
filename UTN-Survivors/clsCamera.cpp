#include "clsCamera.h"
#include <iostream>

Camera::Camera(float zoomLevel)
	:zoomLevel(zoomLevel)
{
}

sf::View Camera::getView(sf::Vector2u windowSize, sf::Vector2f target)
{
	_targetPos = target;

	float aspect = (float)windowSize.x / (float)windowSize.y;
	sf::Vector2f size;

	//relacion de aspecto si el ancho es menor que el alto
	if (aspect < 1.0f) {
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	}
	//relacion de aspecto si el alto es menor que el ancho
	else {
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);
	}


	return sf::View(target, size);
}

