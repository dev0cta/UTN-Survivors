#include <iostream>
#include <SFML/Graphics.hpp>

#include "clsFondo.h"
#include "clsEntity.h"
#include "clsPlayer.h"
#include "clsStaticEnemy.h"


int main()
{
    ///precalculos



    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1080, 1080), "SFML TAB", sf::Style::Close | sf::Style::Titlebar);


    ///inicializar sistemas
    sf::Event evento;

    sf::Clock reloj;

    window.setFramerateLimit(50);

    ///inicializar entidades

    Player jugador(sf::Vector2f(100,100), sf::Vector2f(25,25));

    StaticEnemy Turret(sf::Vector2f(100,100), sf::Vector2f(500,500));


    ///fondo

    Fondo fondo("External/img/pxfuel.jpg");

    fondo.escalarFondo(window);


    ///BUCLE DE JUEGO

    while(window.isOpen())
    {



        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }
            if(evento.type == sf::Event::EventType::KeyPressed)
                {
                jugador.ProcessEvent(evento.key.code, true);
                }
            if(evento.type == sf::Event::EventType::KeyReleased)
                {
                jugador.ProcessEvent(evento.key.code, false);
                }


        }


        if(Turret.getCollider().checkSolidCollision(jugador.getCollider(), 1.0f))
            {
            jugador.resetSpeed();
            }


        window.clear();

        fondo.Render(window);

        jugador.Render(window);

        Turret.Render(window);

        window.display();

        std::cout<<reloj.getElapsedTime().asMilliseconds()<<std::endl;
        std::cout<<"VELOCIDAD X: "<<jugador.getSpeedX()<<std::endl;
        std::cout<<"BOOL up:  "<<jugador.getBool()<<std::endl;
        std::cout<<"VELOCIDAD Y: "<<jugador.getSpeedY()<<std::endl;
//        std::cout<<<<std::endl;
//        std::cout<<<<std::endl;


    }

    return 0;
}
