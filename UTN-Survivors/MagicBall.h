#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "clsCircleCollider.h"
#include "clsAnimation.h"

class MagicBall {
public:
    sf::Texture texturee;

private:
    sf::RectangleShape shape;   // Representa la bola mágica
    CircleCollider collider;    // Collider asociado
    float angle;                // Ángulo actual de la bola en su órbita
    float orbitRadius;          // Distancia desde el jugador
    float orbitSpeed;           // Velocidad angular de rotación
    int damage;                 // Daño que inflige a los enemigos
    Animation animation;        // Animación para la bola mágica


public:
    // Constructor para MagicBall
    MagicBall(float radius, float orbitRadius, float orbitSpeed, int damage,
        sf::Vector2u imageCount, float switchTime, sf::Texture* texture);


    MagicBall(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float radius, float orbitRadius, float orbitSpeed, int damage);
    // Actualiza la posición y el collider de la bola
    void update(const sf::Vector2f& playerPosition, float deltaTime);

    // Detecta colisión usando el CircleCollider
    bool checkCollision(CircleCollider& enemyCollider);

    // Dibuja la bola en la ventana
    void draw(sf::RenderWindow& window);

    // Incrementa el daño de la bola
    void increaseDamage(int increment);
    void setPosition(sf::Vector2f position);
    // Incrementa el tamaño de la bola
    void increaseSize(float scaleFactor);

    // Obtiene el daño actual
    int getDmg() const;

    // Obtiene el collider
    CircleCollider getCollider();

    // Crea una nueva bola mágica si no se ha alcanzado el límite
    static void addMagicBall(float radius, float orbitRadius, float orbitSpeed, int damage,
        sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

    // Obtiene el número de bolas mágicas activas
    static int getMagicBallCount();
};
