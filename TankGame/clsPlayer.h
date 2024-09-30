#ifndef CLSPLAYER_H
#define CLSPLAYER_H

#include <SFML/Graphics.hpp>
#include "clsCollider.h"

class Player
{
    public:
        Player(sf::Vector2f size, sf::Vector2f position);

        sf::Vector2f getPosition();

        void ProcessEvent(sf::Keyboard::Key key, bool checkPressed);

        Collider getCollider();

        void resetSpeed();

        void Movement();

        void Update();

        void Render(sf::RenderWindow &window);


        //test
        float getSpeedX(){ return _speedX;}
        float getSpeedY(){ return _speedY;}
        bool getBool()   { return _up;}

    private:

        sf::RectangleShape _body;

        sf::Vector2f _position;

        float _speedX = 0.0f;
        float _speedY = 0.0f;

        float _speedCap = 25;

        float _accel = 1.0f;


        bool _up = false;
        bool _down = false;
        bool _left = false;
        bool _right = false;

//        bool _shootUp;
//        bool _shootDown;
//        bool _shootLeft;
//        bool _shootRight;



};

#endif // CLSPLAYER_H
