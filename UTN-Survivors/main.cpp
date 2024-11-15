#include <iostream>
#include <SFML/Graphics.hpp>
#include "clsCamera.h"
#include "clsAnimation.h"
#include "clsPlayer.h"
#include "clsEnemy.h"
#include "clsSlime.h"
#include "BarraVida.h"
#include "SFMLOrthogonalLayer.h"

int main()
{
    ///precalculos

    srand(time(NULL));

    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1080, 820), "UTN Survivors", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


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
    
    sf::Texture slimeTexture;
    slimeTexture.loadFromFile("./Assets/Sprites/SlimeSprite.png");

    sf::Texture elemSlimeTexture;
    elemSlimeTexture.loadFromFile("./Assets/Sprites/elemSlimeSprite.png");

    Player chadster(&chadsterTexture,sf::Vector2u(2,2), 0.2f, 20.0f, window);

    Slime slime(&slimeTexture, sf::Vector2u(3, 3), 0.15f, 8.0f); //velocidad 0, lo uso de manequi de prueba

    Slime elemSlime(&elemSlimeTexture, sf::Vector2u(3, 3), 0.3f, 5.0f); //velocidad 0, lo uso de manequi de prueba
    elemSlime.body.setPosition(5.0f, 5.0f);
    sf::RectangleShape testCube(sf::Vector2f(5.0f, 7.5));
    

    /// Mapa

    tmx::Map Mapa;

    Mapa.load("./Assets/map/mapaPrueba.tmx");
    MapLayer layerCero(Mapa, 0);
    MapLayer layerUno(Mapa, 1);
    MapLayer layerDos(Mapa, 2);

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

        

        currentView = camara.getView(window.getSize(), chadster.getPos());

        window.setView(currentView);

        slime.Update(deltaTime, chadster.getPos());

        elemSlime.Update(deltaTime, chadster.getPos());

        chadster.Update(deltaTime);
        //vida.update(chadster.getPos());

        window.clear(sf::Color::White);
        
        // dibujar cosas aca
        window.draw(layerCero);
        window.draw(layerUno);
        window.draw(layerDos);

        slime.Draw(window);
        elemSlime.Draw(window);

        chadster.Draw();


        window.display();





    }

    return 0;
}
