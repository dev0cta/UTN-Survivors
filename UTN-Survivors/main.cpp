#include <iostream>
#include <SFML/Graphics.hpp>
#include "clsCamera.h"
#include "gameFunctions.h"
#include "clsAnimation.h"
#include "clsButtonAnimation.h"
#include "clsPlayer.h"
#include "clsEnemy.h"
#include "clsSlime.h"
#include "clsElemSlime.h"
#include "clsSpartan.h"
#include "clsReaper.h"
#include "clsMenu.h"
#include "clsGameOver.h"
#include "clsGamePause.h"
#include "clsInterface.h"
#include "clsCircleCollider.h"
#include "clsGameplayData.h"
#include "clsBulletAttack.h"
#include "clsAreaAttack.h"


int main()
{
    ///precalculos

    srand(time(NULL));

    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1280, 720), "UTN Survivors", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


    ///inicializar sistemas

    Camera camara(300.0f);  
        //es el zoom que tiene la camara, creo que 70 es adecuado para la perspectiva de vmpire survivors
        // (respecto al tama�o de personaje que elegi (5.0f, 7.5f) ) 
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

    enum GAMESTATE  gameState = GAMEOVER;
    
    ///------------------- MENU TEXTURES ------------------------------------
    sf::Texture playTexture;
    playTexture.loadFromFile("./Assets/Buttons/playButtonSprite.png");
    sf::Texture statsTexture;
    statsTexture.loadFromFile("./Assets/Buttons/statsButtonSprite.png");
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./Assets/images/mainMenuBackground.jpg");

    sf::Texture exitTexture;
    exitTexture.loadFromFile("./Assets/Buttons/exitButtonSprite.png");
    sf::Texture pauseTexture;
    pauseTexture.loadFromFile("./Assets/Sprites/pauseSprite.png");

    //gameover

    sf::Texture gameOverBackgroundTexture;
    gameOverBackgroundTexture.loadFromFile("./Assets/Buttons/statsButtonSprite.png");
    sf::Texture menuTexture;
    menuTexture.loadFromFile("./Assets/Buttons/exitButtonSprite.png");



    ///------------------- CHARACTER TEXTURES ------------------------------------
    sf::Texture chadsterTexture;
    chadsterTexture.loadFromFile("./Assets/Sprites/chadsterSprite.png");

    ///------------------- ATTACK TEXTURES ------------------------------------

    sf::Texture blueTornadoTexture;
    blueTornadoTexture.loadFromFile("./Assets/Sprites/blueTornadoSprite.png");
    sf::Texture purpleAreaTexture;
    purpleAreaTexture.loadFromFile("./Assets/Sprites/purpleAreaSprite.png");
    
    ///------------------- ENEMY TEXTURES ------------------------------------
    sf::Texture slimeTexture;
    slimeTexture.loadFromFile("./Assets/Sprites/SlimeSprite.png");

    sf::Texture elemSlimeTexture;
    elemSlimeTexture.loadFromFile("./Assets/Sprites/elemSlimeSprite.png");
    
    sf::Texture spartanTexture;
    spartanTexture.loadFromFile("./Assets/Sprites/spartanSprite.png");
    
    sf::Texture reaperTexture;
    reaperTexture.loadFromFile("./Assets/Sprites/reaperSprite.png");

    Menu mainMenu(&playTexture, &statsTexture);

    GameOver gameOver(&playTexture, &menuTexture);

    GamePause gamePause(&pauseTexture, &exitTexture, window);

    Player chadster(&chadsterTexture,sf::Vector2u(2,2), 0.2f, 100.0f, window);

    Slime slimeTemplate (&slimeTexture, sf::Vector2u(3, 3), 0.15f, 60.0f); //velocidad 0, lo uso de manequi de prueba

    ElementalSlime elemSlimeTemplate (&elemSlimeTexture, sf::Vector2u(3, 3), 0.3f, 50.0f); //velocidad 0 para usarlo de manequi de prueba

    Spartan spartanTemplate (&spartanTexture, sf::Vector2u(4,1), 0.3f, 55.0f);
    
    Reaper reaperTemplate (&reaperTexture, sf::Vector2u(6,1), 0.3f, 65.0f);


    BulletAttack tornadoTemplate (&blueTornadoTexture, sf::Vector2u(5,1), 0.3f);
    AreaAttack areaTemplate (&purpleAreaTexture, sf::Vector2u(6,1), 0.3f);



    //debug counter

    float spawnCd = 0.25f;
    

    
    
    
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



            ///CHECK PAUSA
            if (pauseCd - betaTime <= 0)
            {
                bool temp = paused;
                paused = pauseGame(paused);
                if (temp != paused)
                    pauseCd = 1.0f;
            }
            pauseCd -= betaTime;


            if (paused)
                deltaTime = 0.0f;

            gamePause.Update(mousePos, paused, betaTime, chadster.getPos());

            if (paused == true) {
                if (gamePause.getOptionPressed() == MENU)
                {
                    gameState = MENU;
                }
            }


            ///SPAWN ENEMIGOS DE PRUEBA
            if (spawnCd - deltaTime <= 0)
            {
                int random = rand() % 4;
                std::cout << "random: " << random << std::endl;
                switch (random)
                {
                case 0:
                    gameData.spawnSlime(slimeTemplate, chadster.getPos());
                    spawnCd = 2.0f;
                    std::cout << "SLIME SPAWNEADO" << std::endl;
                    break;
                case 1:
                    gameData.spawnElementalSlime(elemSlimeTemplate, chadster.getPos());
                    spawnCd = 2.0f;
                    std::cout << "SLIME ELEMENTAL SPAWNEADO" << std::endl;
                    break;
                case 2:
                    gameData.spawnSpartan(spartanTemplate, chadster.getPos());
                    spawnCd = 2.0f;
                    std::cout << "SPARTAN SPAWNEADO" << std::endl;
                    break;
                case 3:
                    gameData.spawnReaper(reaperTemplate, chadster.getPos());
                    spawnCd = 2.0f;
                    std::cout << "REAPER SPAWNEADO" << std::endl;
                    break;

                default:
                    break;
                }
            }
            spawnCd -= deltaTime;


            



            //std::cout << "deltaTime: " << deltaTime << std::endl;

            ///GET VIEW AND MOUSE POSITION
            currentView = camara.getView(window.getSize(), chadster.getPos());
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            window.setView(currentView);

            chadster.Update(deltaTime);

            ///UPDATE Y CHEQUEO DE HABILIDADES
            gameData.createTornado(tornadoTemplate, chadster.getPos());
            gameData.createAreaAttack(areaTemplate, chadster.getPos());
            gameData.UpdateEverySkill(deltaTime);

            ///CHEQUEO DE DA�O A ENEMIGOS Y MUERTES
            gameData.checkDmgCollision(deltaTime, chadster.getDmg());
            gameData.dyingEnemies();

            gameData.UpdateEveryEnemy(deltaTime, chadster.getPos());
            gameData.checkPlayerCollision(chadster.getCollider());
            gameData.CheckEverySolidCollision();
            

            cursor.setPosition(mousePos);

            //chequeo de colisiones fin de mapa
            checkBounds(chadster.getBody(), boundMapLeftTop, boundMapRightDown);

            window.clear(sf::Color::White);

            // dibujar cosas aca
            window.draw(mapaSuelo);

            gameData.DrawEveryEnemy(window);

            gameData.DrawEverySkill(window);

            window.draw(mapaArboles);

            chadster.Draw();


            gamePause.Draw(window);
            window.draw(cursor);
            window.display();

            break;


        case STATS:
            break;


        case GAMEOVER:

            currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f, 0.0f));

            window.setView(currentView);

            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            cursor.setPosition(mousePos);

            gameOver.Update(mousePos);

            window.clear();

            gameOver.Draw(window);

            window.draw(cursor);

            window.display();


            break;


        default:
            std::cout << "ESTO NO DEBERIA PASAR... FATAL ERROR" << std::endl;
            window.close();
            break;
        }


        

        







    }

    return 0;
}
