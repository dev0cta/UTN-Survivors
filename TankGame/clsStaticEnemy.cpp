#include "clsStaticEnemy.h"

#include <iostream>

StaticEnemy::StaticEnemy(sf::Vector2f s, sf::Vector2f pos):
    _body(s,pos),
    _collide(_body.getRectangle())

{

    Entity temp(s,pos);

    _body = temp;



}

Collider StaticEnemy::getCollider()
{
//    sf::RectangleShape temp = _body.getRectangle();

    return Collider(_collide);

}

//void StaticEnemy::update(){
//
//
//    _collide.move(movement);
//
//    return;
//
//}

void StaticEnemy::Render(sf::RenderWindow &window)
{

//    update();

    _body.Render(window);

}
