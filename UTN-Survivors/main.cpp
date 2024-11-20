#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
#include "clsWinMenu.h"
#include "clsStatisticsMenu.h"
#include "clsInterface.h"
#include "clsCircleCollider.h"
#include "clsGameplayData.h"
#include "clsBulletAttack.h"
#include "clsAreaAttack.h"
#include "MagicBall.h"

int main()
{
    ///precalculos

    srand(time(NULL));

    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(800, 600), "UTN Survivors", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

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
        GAMEOVER,
        WIN
    };

    enum GAMESTATE  gameState = MENU;
    
    ///------------------- MENU TEXTURES ------------------------------------
    sf::Texture playTexture;
    playTexture.loadFromFile("./Assets/Buttons/playButtonSprite.png");
    sf::Texture statsTexture;
    statsTexture.loadFromFile("./Assets/Buttons/statsButtonSprite.png");

    sf::Texture exitTexture;
    exitTexture.loadFromFile("./Assets/Buttons/exitButtonSprite.png");
    sf::Texture pauseTexture;
    pauseTexture.loadFromFile("./Assets/Sprites/pauseSprite.png");

    sf::Texture playAgainTexture;
    playAgainTexture.loadFromFile("./Assets/Buttons/playAgainButtonSprite.png");

    ///------------------- CHARACTER TEXTURES ------------------------------------
    sf::Texture chadsterTexture;
    chadsterTexture.loadFromFile("./Assets/Sprites/chadsterSprite.png");

    ///------------------- ATTACK TEXTURES ------------------------------------

    sf::Texture blueTornadoTexture;
    blueTornadoTexture.loadFromFile("./Assets/Sprites/blueTornadoSprite.png");
    sf::Texture purpleAreaTexture;
    purpleAreaTexture.loadFromFile("./Assets/Sprites/purpleAreaSprite.png");
    sf::Texture magicBallTexture;
    magicBallTexture.loadFromFile("./Assets/Sprites/fireSpin.png");
    ///------------------- ENEMY TEXTURES ------------------------------------
    sf::Texture slimeTexture;
    slimeTexture.loadFromFile("./Assets/Sprites/SlimeSprite.png");

    sf::Texture elemSlimeTexture;
    elemSlimeTexture.loadFromFile("./Assets/Sprites/elemSlimeSprite.png");
    
    sf::Texture spartanTexture;
    spartanTexture.loadFromFile("./Assets/Sprites/spartanSprite.png");
    
    sf::Texture reaperTexture;
    reaperTexture.loadFromFile("./Assets/Sprites/reaperSprite.png");
    
    sf::Texture dirubinTexture;
    dirubinTexture.loadFromFile("./Assets/Sprites/dirubinSprite.png");

    Menu mainMenu(&playTexture, &statsTexture);

    GameOver gameOver(&playAgainTexture, &exitTexture);

    GamePause gamePause(&pauseTexture, &exitTexture, window);

    WinMenu winMenu(&playAgainTexture, &exitTexture);

    StatisticsMenu statisticsMenu(getLastRecordedStatistics(), &exitTexture);

    Player chadster(&chadsterTexture,sf::Vector2u(2,2), 0.2f, 80.0f, window);

    Slime slimeTemplate (&slimeTexture, sf::Vector2u(3, 3), 0.15f, 60.0f); //velocidad 0, lo uso de manequi de prueba

    ElementalSlime elemSlimeTemplate (&elemSlimeTexture, sf::Vector2u(3, 3), 0.3f, 50.0f); //velocidad 0 para usarlo de manequi de prueba

    Spartan spartanTemplate (&spartanTexture, sf::Vector2u(4,1), 0.3f, 55.0f);
    
    Reaper reaperTemplate (&reaperTexture, sf::Vector2u(6,1), 0.3f, 65.0f);

    Dirubin dirubinTemplate (&dirubinTexture, sf::Vector2u(4,1), 0.3f, 65.0f);


    BulletAttack tornadoTemplate (&blueTornadoTexture, sf::Vector2u(5,1), 0.3f);
    AreaAttack areaTemplate (&purpleAreaTexture, sf::Vector2u(6,1), 0.3f);

    MagicBall magicBallTemplate(15.0f, 60.0f, 100.0f, 50, sf::Vector2u(6, 1), 0.1f, &magicBallTexture);   //radio, radioOrbita, velocidad, daño,----  lo demas no se toca

    ///----------------------- MUSIC TEXTURES ---------------------------

    sf::Music backgroundMusic;
    sf::Music playingMusic;
    sf::Music winMusic;
    sf::Music endMusic;

    bool isMusicPlaying = false;

    //debug counter
    
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
            
            if (!isMusicPlaying) {
                setMusic(backgroundMusic, "./Assets/Sounds/backgroundMusic/aboard-a-aurora-game-menu-pulse-203549.ogg", 60, true);
                isMusicPlaying = true;
            }

            //UPDATE MENU

            currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f,0.0f));
            window.setView(currentView);
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            cursor.setPosition(mousePos);
            mainMenu.Update(mousePos);

            //SALIR DEL MENU
            if (mainMenu.getOptionPressed() == PLAYING)
            {
                chadster.Reset();
                gameData.ResetGameData(chadster.getBody());
                backgroundMusic.stop();
                isMusicPlaying = false;
                gameState = PLAYING;
            }
            if (mainMenu.getOptionPressed() == STATS) 
            {
                statisticsMenu.setStatistics(getLastRecordedStatistics());
                gameState = STATS;
            }

            //DRAW MENU
            window.clear();
            mainMenu.Draw(window);
            window.draw(cursor);
            window.display();

            break;


        case PLAYING:         //----------------------------------------------------PLAYING STATE------------------------------

            //aca van los updates

            if (!isMusicPlaying) {
                setMusic(playingMusic, "./Assets/Sounds/backgroundMusic/2-03 Skyway Octane (Mirage Saloon Zone - Act 1 ST Mix).ogg", 60, true);
                isMusicPlaying = true;
            }

            if (chadster.getHealth() <= 0.0f) {
                //GUARDAR DATOS DE LA PARTIDA EN UN OBJ TODO:
                gameData.saveSomeData();
                saveStatisticsData("statistics.dat", gameData.getGameStatistics());
                chadster.Reset();
                gameData.ResetGameData(chadster.getBody());
                playingMusic.stop();
                isMusicPlaying = false;
                gameState = GAMEOVER;
            }

            if (gameData.isGameBeaten()) {
                //GUARDAR DATOS DE LA PARTIDA EN UN OBJ TODO:
                gameData.saveSomeData();
                saveStatisticsData("statistics.dat", gameData.getGameStatistics());
                chadster.Reset();
                gameData.ResetGameData(chadster.getBody());
                playingMusic.stop();
                isMusicPlaying = false;
                gameState = WIN;
            }
            //std::cout << chadster.getHealth()<<std::endl;

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
                    gameData.saveSomeData();
                    saveStatisticsData("statistics.dat", gameData.getGameStatistics());
                    chadster.Reset();
                    gameData.ResetGameData(chadster.getBody());
                    paused = false;

                    playingMusic.stop();
                    isMusicPlaying = false;
                    gameState = MENU;
                }
            }


            ///SPAWN ENEMIGOS DE PRUEBA

            gameData.randomSpawn(chadster.getPos(), deltaTime, slimeTemplate, elemSlimeTemplate, spartanTemplate, reaperTemplate, dirubinTemplate);

            ///GET VIEW AND MOUSE POSITION
            currentView = camara.getView(window.getSize(), chadster.getPos());
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            window.setView(currentView);

            gameData.checkLevelUp();
            chadster.Update(deltaTime, gameData.getLevel(), gameData.getCurrentExp(), gameData.getExpNeeded());

            ///UPDATE Y CHEQUEO DE HABILIDADES

            gameData.createTornado(tornadoTemplate, chadster.getPos());

            if (gameData.getLevel() >= 5)
            gameData.createAreaAttack(areaTemplate, chadster.getPos());
            
            if (gameData.getLevel() >= 10) 
            gameData.createBall(magicBallTemplate, chadster.getPos());
            

            gameData.UpdateEverySkill(chadster.getPos(), deltaTime);;

            ///CHEQUEO DE DAÑO A ENEMIGOS Y MUERTES
            gameData.checkDmgCollision(deltaTime, chadster.getDmg());
            gameData.dyingEnemies();

            gameData.UpdateEveryEnemy(deltaTime, chadster.getPos());
            gameData.checkPlayerCollision(chadster.getCollider(), chadster, deltaTime);
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

            currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f, 0.0f));

            window.setView(currentView);

            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            cursor.setPosition(mousePos);

            statisticsMenu.Update(mousePos);

            //SALIR DEL MENU
            if (statisticsMenu.getOptionPressed() == MENU)
            {
                chadster.Reset();
                gameData.ResetGameData(chadster.getBody());
                gameState = MENU;
            }
            

            //DRAW MENU
            window.clear();

            statisticsMenu.Draw(window);

            window.draw(cursor);

            //drawButtons
            window.display();


            break;


        case GAMEOVER:

            if (!isMusicPlaying) {
                setMusic(endMusic, "./Assets/Sounds/backgroundMusic/2-26 Game Over.ogg", 60, false);
                isMusicPlaying = true;
            }

            currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f, 0.0f));

            window.setView(currentView);

            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            cursor.setPosition(mousePos);

            gameOver.Update(mousePos);

            if (gameOver.getOptionPressed() == PLAYING) {

                chadster.Reset();
                gameData.ResetGameData(chadster.getBody());

                endMusic.stop();
                isMusicPlaying = false;
                gameState = PLAYING;
            }

            /////--------SAVE STATISTICS ACA NO TESTEADO
            if (gameOver.getOptionPressed() == MENU) {
                endMusic.stop();
                isMusicPlaying = false;

                gameState = MENU;
            }

            window.clear();

            gameOver.Draw(window);

            window.draw(cursor);

            window.display();


            break;

        case WIN:

            if (!isMusicPlaying) {
                setMusic(endMusic, "./Assets/Sounds/backgroundMusic/2-02-Results-Screen.ogg", 60, false);
                isMusicPlaying = true;
            }

            currentView = camara.getView(window.getSize(), sf::Vector2f(0.0f, 0.0f));

            window.setView(currentView);

            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            cursor.setPosition(mousePos);

            winMenu.Update(mousePos);

            if (gameOver.getOptionPressed() == PLAYING) {

                chadster.Reset();
                gameData.ResetGameData(chadster.getBody());
                endMusic.stop();
                isMusicPlaying = false;
                gameState = PLAYING;
            }

            /////--------SAVE STATISTICS ACA NO TESTEADO
            if (gameOver.getOptionPressed() == MENU) {
                endMusic.stop();
                isMusicPlaying = false;

                gameState = MENU;
            }

            window.clear();
            winMenu.Draw(window);
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
