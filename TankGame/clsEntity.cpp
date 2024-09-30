#include "clsEntity.h"

Entity::Entity(sf::Vector2f s, sf::Vector2f pos)
{
    _body.setSize(s);
    _body.setOrigin(sf::Vector2f(s.x/2, s.y/2));
    _body.setPosition(pos);
    _body.setFillColor(sf::Color::Red);
}

void Entity::move(sf::Vector2f vec){

    vec = _position;

    _body.move(vec);

    return;

}

void Entity::Render(sf::RenderWindow &window)
{

    window.draw(_body);


}
