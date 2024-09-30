#ifndef CLSSTATICENEMY_H
#define CLSSTATICENEMY_H

#include <SFML/Graphics.hpp>
#include "clsEntity.h"
#include "clsCollider.h"
//#include "clsMovePattern.h"

class StaticEnemy
{
    public:
        StaticEnemy(sf::Vector2f s, sf::Vector2f pos);


        Collider getCollider();

        void update();

        void Render(sf::RenderWindow &window);

    private:

//        sf::RectangleShape;  ///textura

        Entity _body;

        sf::Vector2f position;

        sf::RectangleShape _collide;

};

#endif // CLSSTATICENEMY_H
