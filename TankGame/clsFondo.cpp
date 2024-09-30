#include "clsFondo.h"

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


Fondo::Fondo(std::string fileLink)
{

    if (!_textura.loadFromFile(fileLink)){
        std::cout<<"NO SE PUDO CARGAR EL ARCHIVO"<<std::endl;
    }

    _fondo.setTexture(_textura);

    return;
}



void Fondo::escalarFondo(sf::RenderWindow &window)
{

    sf::Vector2u imageSize = _textura.getSize();  // Tamaño de la imagen (1280x720)

    sf::Vector2u windowSize = window.getSize();  // Tamaño de la ventana (1920x1080)


    float scaleX = float(windowSize.x) / imageSize.x;  // Escala horizontal
    float scaleY = float(windowSize.y) / imageSize.y;  // Escala vertical


    _fondo.setScale(scaleX, scaleY);


}

void Fondo::Render(sf::RenderWindow &window)
{

    window.draw(_fondo);


}
