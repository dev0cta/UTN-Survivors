#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "clsCircleCollider.h"
#include "clsAnimation.h"

class MagicBall {
public:
    sf::Texture texturee;

private:
    sf::RectangleShape shape;   // Representa la bola m�gica
    CircleCollider collider;    // Collider asociado
    float angle;                // �ngulo actual de la bola en su �rbita
    float orbitRadius;          // Distancia desde el jugador
    float orbitSpeed;           // Velocidad angular de rotaci�n
    int damage;                 // Da�o que inflige a los enemigos
    Animation animation;        // Animaci�n para la bola m�gica


public:
    // Constructor para MagicBall
    MagicBall(float radius, float orbitRadius, float orbitSpeed, int damage,
        sf::Vector2u imageCount, float switchTime, sf::Texture* texture);


    MagicBall(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float radius, float orbitRadius, float orbitSpeed, int damage);
    // Actualiza la posici�n y el collider de la bola
    void update(const sf::Vector2f& playerPosition, float deltaTime);

    // Detecta colisi�n usando el CircleCollider
    bool checkCollision(CircleCollider& enemyCollider);

    // Dibuja la bola en la ventana
    void draw(sf::RenderWindow& window);

    // Incrementa el da�o de la bola
    void increaseDamage(int increment);
    void setPosition(sf::Vector2f position);
    // Incrementa el tama�o de la bola
    void increaseSize(float scaleFactor);

    // Obtiene el da�o actual
    int getDmg() const;

    // Obtiene el collider
    CircleCollider getCollider();

    // Crea una nueva bola m�gica si no se ha alcanzado el l�mite
    static void addMagicBall(float radius, float orbitRadius, float orbitSpeed, int damage,
        sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

    // Obtiene el n�mero de bolas m�gicas activas
    static int getMagicBallCount();
};
