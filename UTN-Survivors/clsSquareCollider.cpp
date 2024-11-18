#include "clsSquareCollider.h"

SquareCollider::SquareCollider(sf::RectangleShape& body) :
    _body(body)
{
    //ctor
}

bool SquareCollider::checkSolidCollision(SquareCollider other, float push)
{
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();

    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();

    float deltaX = thisPosition.x - otherPosition.x;
    float deltaY = thisPosition.y - otherPosition.y;

    float IntersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float IntersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
    {
        /// empujar al objeto para que no atraviese

        push = std::min(std::max(push, 0.0f), 1.0f);

        if (IntersectX > IntersectY)
        {
            if (deltaX < 0.0f)
            {
                move(IntersectX * (1.0f - push), 0.0f);         //empuja al personaje
                other.move(-IntersectX * push, 0.0f);         //empuja al objeto
            }
            else
            {
                move(-IntersectX * (1.0f - push), 0.0f);         //empuja al personaje
                other.move(IntersectX * push, 0.0f);           //empuja al objeto
            }


        }
        else
        {
            if (deltaY < 0.0f)
            {
                move(0.0f, IntersectY * (1.0f - push));         //empuja al personaje
                other.move(0.0f, -IntersectY * push);         //empuja al objeto
            }
            else
            {
                move(0.0f, -IntersectY * (1.0f - push));         //empuja al personaje
                other.move(0.0f, IntersectY * push);
            }
        }


        return true;
    }


    return false;

}

bool SquareCollider::checkCollision(SquareCollider other)
{
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();

    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float IntersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float IntersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);

    if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
    {

        return true;
    }


    return false;

}

///TODO: encapsular e implementar al main




sf::Vector2f SquareCollider::getPosition() {

    return _body.getPosition();

}

sf::Vector2f SquareCollider::getHalfSize() {

    return _body.getSize() / 2.0f;


}

void SquareCollider::move(float dx, float dy) {

    _body.move(dx, dy);

}