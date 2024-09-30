#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <SFML/Graphics.hpp>
#include <string.h>

class Fondo
{
    public:
        Fondo(std::string fileLink);

        void escalarFondo(sf::RenderWindow &window);

        void Render(sf::RenderWindow &window);

    private:

        sf::Texture _textura;
        sf::Sprite _fondo;



};

#endif // CLSFONDO_H
