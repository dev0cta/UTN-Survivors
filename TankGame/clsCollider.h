#ifndef CLSSOLIDCOLLISION_H
#define CLSSOLIDCOLLISION_H

#include <SFML/Graphics.hpp>
#include "clsEntity.h"



class Collider
{
    public:
        Collider(sf::RectangleShape& body);


        void move(float dx, float dy);

        bool checkSolidCollision(Collider other, float push);

        bool checkCollision(Collider other);



        sf::Vector2f getPosition();
        sf::Vector2f getHalfSize();


    private:

        sf::RectangleShape& _body;
};

#endif // CLSSOLIDCOLLISION_H
