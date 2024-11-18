#include <iostream>
#include <SFML/Graphics.hpp>
#include "clsCamera.h"
#include "gameFunctions.h"
#include "clsAnimation.h"
#include "clsButtonAnimation.h"
#include "clsPlayer.h"
#include "clsEnemy.h"
#include "clsSlime.h"
#include "clsMenu.h"
#include "clsGamePause.h"
#include "BarraVida.h"
#include "clsCircleCollider.h"
#include "clsGameplayData.h"

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

    GameplayData gameData;

    sf::Clock deltaClock;
    sf::Clock betaClock;

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

    sf::Texture exitTexture;
    exitTexture.loadFromFile("./Assets/Buttons/exitButtonSprite.png");
    sf::Texture pauseTexture;
    pauseTexture.loadFromFile("./Assets/Sprites/pauseSprite.png");


    sf::Texture chadsterTexture;
    chadsterTexture.loadFromFile("./Assets/Sprites/chadsterSprite.png");

    
    sf::Texture slimeTexture;
    slimeTexture.loadFromFile("./Assets/Sprites/SlimeSprite.png");

    sf::Texture elemSlimeTexture;
    elemSlimeTexture.loadFromFile("./Assets/Sprites/elemSlimeSprite.png");

    Menu mainMenu(&playTexture, &statsTexture);

    GamePause gamePause(&pauseTexture, &exitTexture, window);

    Player chadster(&chadsterTexture,sf::Vector2u(2,2), 0.2f, 125.0f, window);

    Slime slimeTemplate (&slimeTexture, sf::Vector2u(3, 3), 0.15f, 80.0f); //velocidad 0, lo uso de manequi de prueba

    Slime elemSlimeTemplate (&elemSlimeTexture, sf::Vector2u(3, 3), 0.3f, 70.0f); //velocidad 0 para usarlo de manequi de prueba
    //elemSlimeTemplate.body.setPosition(5.0f, 5.0f);

    //debug counter

    int spawnCounter = 5;
    float spawnCd = 2.0f;
    

    
    
    
    sf::RectangleShape cursor(sf::Vector2f(20.0f, 20.0f));
    cursor.setOrigin(20.0f / 2.0f, 20.0f / 2.0f);
    cursor.setFillColor(sf::Color::Red);

    /// Mapa

    sf::Texture textSuelo;
    sf::Texture textArboles;

    textSuelo.loadFromFile("./Assets/map/mapaBase.png");
    textArboles.loadFromFile("./Assets/map/mapaArboles.png");
    
    sf::Sprite mapaSuelo;
    sf::Sprite mapaArboles;

    mapaSuelo.setTexture(textSuelo);
    mapaArboles.setTexture(textArboles);

    mapaSuelo.setPosition(sf::Vector2f(-250.0f, -250.0f));
    mapaArboles.setPosition(sf::Vector2f(-250.0f, -250.0f));
    sf::Vector2f boundMapLeftTop(72.0f, 3446.0f);
    sf::Vector2f boundMapRightDown(3430.0f, 54.0f);

    ///inicializar variables

    sf::Vector2f mousePos;

    bool paused = false;
    float pauseCd = 1.0f;

    float deltaTime = 0;

    float betaTime = 0;

    ///BUCLE DE JUEGO

    while(window.isOpen())
    {
        deltaTime = deltaClock.restart().asSeconds();
        betaTime = betaClock.restart().asSeconds(); //para implementar la pausa


        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }
        }

        switch (gameState)
        {
        case MENU:              //----------------------------------------------------MENU STATE------------------------------
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


        case PLAYING:         //----------------------------------------------------PLAYING STATE------------------------------

            //aca van los updates



            if (pauseCd - betaTime <=0)
            {
                bool temp = paused;
                paused = pauseGame(paused);
                if(temp != paused)
                    pauseCd = 1.0f;
            }
            pauseCd -= betaTime;



            if (paused)
                deltaTime = 0.0f;
            
            ///spawn de slimes de prueba
            if (spawnCd - deltaTime <= 0)
            {
                gameData.spawnSlime(slimeTemplate, chadster.getPos());
                spawnCd = 2.0f;
                std::cout << "SLIME SPAWNEADO"<<std::endl;
            }
            spawnCd -= deltaTime;
            std::cout << "spawn cd: " << spawnCd << std::endl;


            currentView = camara.getView(window.getSize(), chadster.getPos());

            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            window.setView(currentView);

            for (auto& enemy : gameData.getSlimes())
            {
                enemy.Update(deltaTime, chadster.getPos());
            }

            for (auto& enemy : gameData.getSlimes())
            {
                for (auto& otherEnemy : gameData.getSlimes())
                {
                    enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
                }

            }

            gamePause.Update(mousePos, paused, betaTime, chadster.getPos());

            if (paused)
            {
                if (gamePause.getOptionPressed()== MENU)
                {
                    gameState = MENU;
                }
            }

            

            chadster.Update(deltaTime);
            //vida.update(chadster.getPos());
            cursor.setPosition(mousePos);

            window.clear(sf::Color::White);

            // dibujar cosas aca
            window.draw(mapaSuelo);
            for (auto& enemy : gameData.getSlimes())
            {
                enemy.Draw(window);
            }

            window.draw(mapaArboles);
            
            //chequeo de colisiones fin de mapa
            checkBounds(chadster.getBody(), boundMapLeftTop, boundMapRightDown);
            //

            chadster.Draw();

            gamePause.Draw(window);
            window.draw(cursor);
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
