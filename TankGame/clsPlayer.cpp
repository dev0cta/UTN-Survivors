#include "clsPlayer.h"
#include <iostream>

Player::Player(sf::Vector2f size, sf::Vector2f position)
{
    _body.setSize(size);
    _body.setOrigin(sf::Vector2f(size.x/2, size.y/2));
    _body.setFillColor(sf::Color::Blue);

    _position = position;
}

sf::Vector2f Player::getPosition()
{

    return _position;

}

void Player::ProcessEvent(sf::Keyboard::Key key, bool checkPressed)
{

    if(key == sf::Keyboard::W)
        {
        _up = checkPressed;
        }

    if(key == sf::Keyboard::A)
        {
        _left = checkPressed;
        }

    if(key == sf::Keyboard::S)
        {
        _down = checkPressed;
        }

    if(key == sf::Keyboard::D)
        {
        _right = checkPressed;
        }


//    if(key == sf::Keyboard::Up){
//        _shootUp = checkPressed;
//    }
//    if(key == sf::Keyboard::Down){
//        _shootDown = checkPressed;
//    }
//    if(key == sf::Keyboard::Left){
//        _shootLeft = checkPressed;
//    }
//    if(key == sf::Keyboard::Right){
//        _shootRight = checkPressed;
//    }

}

void Player::Movement()
{

        ///DERECHA

    if(abs(_speedX) < _speedCap)        //peso
        {
            if(_right)
                {
                 _speedX = _speedX + _accel;


                }
        }
    if(_speedX > 0 && !_right)          //contrapeso
                {
                _speedX -= _accel;

                }

        ///IZQUIERDA
    if(abs(_speedX) < _speedCap)
        {
            if(_left)
                {
                 _speedX = _speedX - _accel;


                }
        }
    if(_speedX < 0 && !_left)
                {
                _speedX += _accel;

                }



                ///ARRIBA
    if(abs(_speedY) < _speedCap)
        {
            if(_up)
                {
                 _speedY = _speedY - _accel;
//                 std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<_speedY<<std::endl;

                }
        }
    if(_speedY < 0 && !_up)
                {
                _speedY += _accel;   //aca

                }

                ///ABAJO
    if(abs(_speedY) < _speedCap)            ///peso
        {
            if(_down)
                {
                 _speedY = _speedY + _accel;
//                 std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<std::endl;

                }
        }
    if(_speedY > 0 && !_down)               ///contrapeso
                {
                _speedY -= _accel;


                }

    return;
}

void Player::Update()
{
    Movement();

    sf::Vector2f movimiento;

    movimiento.x += _speedX;


    movimiento.y += _speedY;

    _body.move(movimiento);


    return;
}

void Player::Render(sf::RenderWindow &window)
{
    Update();

    window.draw(_body);

}

void Player::resetSpeed()
{
    _speedX = 0;
    _speedY = 0;

}

Collider Player::getCollider()
{
    return Collider(_body);
}
