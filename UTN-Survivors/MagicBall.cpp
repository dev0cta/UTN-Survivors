#include "MagicBall.h"

// Constructor para MagicBall


MagicBall::MagicBall(float radius, float orbitRadius, float orbitSpeed, int damage, sf::Vector2u imageCount, float switchTime, sf::Texture* texture)
    : animation(texture, imageCount, switchTime), // Inicializa el objeto de animaci�n
    shape(sf::Vector2f(radius * 2, radius * 2)), // Inicializa el shape con un tama�o doble al radio (para representar un c�rculo)
    collider(shape), // Inicializa el colisionador, asumiendo que es una clase que toma un shape
    orbitRadius(orbitRadius),
    orbitSpeed(orbitSpeed),
    damage(damage),
    angle(0) // Inicializa el �ngulo de la �rbita a 0
{
    shape.setOrigin(radius, radius); // Coloca el origen del shape en su centro
    shape.setTexture(texture); // Aplica la textura al shape
}
// Actualiza la posici�n y el collider de la bola
void MagicBall::update(const sf::Vector2f& playerPosition, float deltaTime) {
    angle += orbitSpeed * deltaTime; // Incrementa el �ngulo
    if (angle > 360) angle -= 360;  // Mant�n el �ngulo dentro del rango [0, 360]
    float radianAngle = angle * 3.14159 / 180.0f; // Convierte a radianes

    // Calcula la posici�n orbital alrededor del jugador
    float x = playerPosition.x + orbitRadius * std::cos(radianAngle);
    float y = playerPosition.y + orbitRadius * std::sin(radianAngle);
    shape.setPosition(x, y);

    animation.Update(0, deltaTime, true);
    shape.setTextureRect(animation.getUvRect());
}

// Detecta colisi�n usando el CircleCollider
bool MagicBall::checkCollision(CircleCollider& enemyCollider) {
    return collider.checkCollision(enemyCollider);
}

// Dibuja la bola en la ventana
void MagicBall::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Incrementa el da�o de la bola
void MagicBall::increaseDamage(int increment) {
    damage += increment;
}

// Incrementa el tama�o de la bola
void MagicBall::increaseSize(float scaleFactor) {
    shape.setScale(scaleFactor, scaleFactor);
}

// Obtiene el da�o actual
int MagicBall::getDmg() const {
    return damage;
}

// Obtiene el collider
CircleCollider MagicBall::getCollider() {
    return CircleCollider(shape);
}

void MagicBall::setPosition(sf::Vector2f position)
{
    shape.setPosition(position);
}