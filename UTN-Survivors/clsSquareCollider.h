#pragma once

#include "SFML/Graphics.hpp"

class SquareCollider
{
public:
    SquareCollider(sf::RectangleShape& body);


    void move(float dx, float dy);

    bool checkSolidCollision(SquareCollider other, float push);

    bool checkCollision(SquareCollider other);



    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();


private:

    sf::RectangleShape& _body;
};
