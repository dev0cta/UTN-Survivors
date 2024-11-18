#include "clsPlayer.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& window):
	animation(texture, imageCount, switchTime), window(window), interface(Player::getPos(), HpMax)
{

	this->speed = speed;

	row = 0;
	faceRight = true;

	hitBox.setRadius(25.0f / 2.0f);
	hitBox.setOrigin(sf::Vector2f(12.5f, 12.5f));

	body.setSize(sf::Vector2f(12.5f, 25.0f));

	body.setPosition(sf::Vector2f(250.0f, 250.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
	//--------------DESCOMENTAR PARA VER LA HITBOX-------------
	body.setOutlineThickness(-0.25f);
	body.setOutlineColor(sf::Color::Red);
	//---------------------------------------------------------
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;


	//si esta quieto,     animacion idle
	//si esta moviendose, animacion de movimiento
	if (movement.x == 0.0f && movement.y == 0.0f)
		row = 1;
	else
		row = 0;

	if (movement.x > 0.0f)
		faceRight = true;
	else if (movement.x == 0)
		;
	else
		faceRight = false;

	animation.Update(row, deltaTime, faceRight);
	interface.update(getPos());
	body.setTextureRect(animation.getUvRect());
	body.move(movement);
}

void Player::Draw()
{
	window.draw(body);
	interface.Draw(window);

}

sf::Vector2f Player::getPos()
{
	return body.getPosition();
}

sf::RectangleShape& Player::getBody()
{
	return body;
}

CircleCollider Player::getCollider()
{
	return CircleCollider(body);
}

void Player::takeDmg()
{
}

void Player::attack()
{
}

