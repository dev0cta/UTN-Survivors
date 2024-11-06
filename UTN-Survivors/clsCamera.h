#pragma once

#include "SFML/Graphics.hpp"


class Camera
{
public:
	Camera(float zoomLevel = 5.0f);

	sf::View getView(sf::Vector2u windowSize, sf::Vector2f target);

	sf::Vector2f getTargetPos() { return _targetPos; }
	float getZoomLevel() { return zoomLevel; }


private:
	float zoomLevel;
	sf::Vector2f _targetPos;

};
