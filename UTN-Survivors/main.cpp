#include <iostream>
#include <SFML/Graphics.hpp>
#include "clsCamera.h"
#include "clsAnimation.h"



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

    sf::Texture playerTexture;
    playerTexture.loadFromFile("./Assets/Sprites/testCharacter.png");

    Animation playerAnimation(&playerTexture,sf::Vector2u(4,6), 0.3f);

    sf::RectangleShape testCube(sf::Vector2f(5.0f, 7.5));

    testCube.setOrigin(testCube.getSize() / 2.0f);
    testCube.setTexture(&playerTexture);
    



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

        playerAnimation.Update(5, deltaTime, true);
        testCube.setTextureRect(playerAnimation.uvRect);

        window.clear();
        
        // dibujar cosas aca

        window.draw(testCube);


        window.display();





    }

    return 0;
}
