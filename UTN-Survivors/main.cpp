#include <iostream>
#include <SFML/Graphics.hpp>
#include "clsCamera.h"
#include "clsAnimation.h"
#include "clsPlayer.h"



int main()
{
    ///precalculos



    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1080, 1080), "UTN Survivors", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


    ///inicializar sistemas

    Camera camara(70.0f);  
        //es el zoom que tiene la camara, creo que 70 es adecuado para la perspectiva de vmpire survivors
        // (respecto al tamaño de personaje que elegi (5.0f, 7.5f) ) 
    sf::View currentView;

    sf::Event evento;

    sf::Clock deltaClock;

    window.setFramerateLimit(75);

    ///inicializar entidades

    
    sf::Texture chadsterTexture;
    chadsterTexture.loadFromFile("./Assets/Sprites/chadsterSprite.png");

    Player chadster(&chadsterTexture,sf::Vector2u(2,2), 0.2f, 10.0f, window);


    sf::RectangleShape testCube(sf::Vector2f(5.0f, 7.5));
    



    ///inicializar variables

    float deltaTime = 0;

    ///BUCLE DE JUEGO

    while(window.isOpen())
    {
        deltaTime = deltaClock.restart().asSeconds();


        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }
            


        }


        //aca van los updates

        currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f,0.0f));

        window.setView(currentView);

        chadster.Update(deltaTime);

        window.clear();
        
        // dibujar cosas aca

        chadster.Draw();


        window.display();





    }

    return 0;
}
