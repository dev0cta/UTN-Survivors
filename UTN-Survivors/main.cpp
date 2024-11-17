#include <iostream>
#include <SFML/Graphics.hpp>
#include "clsCamera.h"
#include "clsAnimation.h"
#include "clsButtonAnimation.h"
#include "clsPlayer.h"
#include "clsEnemy.h"
#include "clsSlime.h"
#include "clsMenu.h"
#include "BarraVida.h"
#include "clsCircleCollider.h"
#include "SFMLOrthogonalLayer.h"

int main()
{
    ///precalculos

    srand(time(NULL));

    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1280, 720), "UTN Survivors", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


    ///inicializar sistemas

    Camera camara(300.0f);  
        //es el zoom que tiene la camara, creo que 70 es adecuado para la perspectiva de vmpire survivors
        // (respecto al tamaño de personaje que elegi (5.0f, 7.5f) ) 
    sf::View currentView;

    sf::Event evento;

    sf::Clock deltaClock;

    window.setFramerateLimit(75);

    ///inicializar entidades

    enum GAMESTATE {
        MENU,
        PLAYING,
        STATS,
        GAMEOVER
    };

    enum GAMESTATE  gameState = MENU;
    
    sf::Texture playTexture;
    playTexture.loadFromFile("./Assets/Buttons/playButtonSprite.png");
    sf::Texture statsTexture;
    statsTexture.loadFromFile("./Assets/Buttons/statsButtonSprite.png");
    sf::Texture backgroundTexture;
    statsTexture.loadFromFile("./Assets/Buttons/statsButtonSprite.png");


    sf::Texture chadsterTexture;
    chadsterTexture.loadFromFile("./Assets/Sprites/chadsterSprite.png");

    
    sf::Texture slimeTexture;
    slimeTexture.loadFromFile("./Assets/Sprites/SlimeSprite.png");

    sf::Texture elemSlimeTexture;
    elemSlimeTexture.loadFromFile("./Assets/Sprites/elemSlimeSprite.png");

    Menu mainMenu(&playTexture, &statsTexture);

    Player chadster(&chadsterTexture,sf::Vector2u(2,2), 0.2f, 125.0f, window);

    std::vector<Slime> spawnedEnemies;

    Slime slimeTemplate (&slimeTexture, sf::Vector2u(3, 3), 0.15f, 80.0f); //velocidad 0, lo uso de manequi de prueba

    Slime elemSlimeTemplate (&elemSlimeTexture, sf::Vector2u(3, 3), 0.3f, 70.0f); //velocidad 0 para usarlo de manequi de prueba
    //elemSlimeTemplate.body.setPosition(5.0f, 5.0f);



    spawnedEnemies.push_back(slimeTemplate);
    spawnedEnemies.push_back(elemSlimeTemplate);
    
    
    sf::RectangleShape cursor(sf::Vector2f(20.0f, 20.0f));
    cursor.setOrigin(20.0f / 2.0f, 20.0f / 2.0f);
    cursor.setFillColor(sf::Color::Red);

    /// Mapa

    tmx::Map Mapa;

    Mapa.load("./Assets/map/mapaPrueba.tmx");
    MapLayer layerCero(Mapa, 0);
    MapLayer layerUno(Mapa, 1);
    MapLayer layerDos(Mapa, 2);

    ///inicializar variables

    sf::Vector2f mousePos;

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

        switch (gameState)
        {
        case MENU:
            //window.setSize();
            
            //UPDATE MENU

            currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f,0.0f));

            window.setView(currentView);

            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            cursor.setPosition(mousePos);


            mainMenu.Update(mousePos);

            //SALIR DEL MENU
            //gameState = PLAYING o STATS

            if (mainMenu.getOptionPressed() == PLAYING)
            {
                gameState = PLAYING;
            }
            if (mainMenu.getOptionPressed() == STATS) 
            {
                gameState = STATS;
            }


            //DRAW MENU
            window.clear();

            mainMenu.Draw(window);

            window.draw(cursor);

            //drawButtons
            window.display();

            break;


        case PLAYING:

            //aca van los updates

            currentView = camara.getView(window.getSize(), chadster.getPos());

            window.setView(currentView);

            for (auto& enemy : spawnedEnemies)
            {
                enemy.Update(deltaTime, chadster.getPos());
            }

            for (auto& enemy : spawnedEnemies)
            {
                for (auto& otherEnemy : spawnedEnemies)
                {
                    enemy.GetHitbox().checkSolidCollision(otherEnemy.GetCollider(), 0.75f);
                }

            }



            chadster.Update(deltaTime);
            //vida.update(chadster.getPos());

            window.clear(sf::Color::White);

            // dibujar cosas aca
            window.draw(layerCero);
            window.draw(layerUno);
            window.draw(layerDos);

            for (auto& enemy : spawnedEnemies)
            {
                enemy.Draw(window);
            }

            chadster.Draw();


            window.display();

            break;


        case STATS:
            break;


        case GAMEOVER:
            break;


        default:
            std::cout << "ESTO NO DEBERIA PASAR... FATAL ERROR" << std::endl;
            window.close();
            break;
        }


        

        







    }

    return 0;
}
