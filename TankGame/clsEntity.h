#ifndef CLSENTITY_H
#define CLSENTITY_H

    #include <SFML/Graphics.hpp>

class Entity
{
    public:

        Entity(sf::Vector2f s, sf::Vector2f pos);

        void move(sf::Vector2f vec);

        void Render(sf::RenderWindow &window);

        sf::RectangleShape getRectangle(){ return _body;}

        sf::Vector2f getPos() {return _position;}

    private:


        sf::RectangleShape  _body;

        sf::Vector2f        _size;
        sf::Vector2f        _position;


};

#endif // CLSENTITY_H
