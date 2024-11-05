#include <iostream>
#include <SFML/Graphics.hpp>



int main()
{
    ///precalculos



    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1080, 1080), "UTN Survivors", sf::Style::Close | sf::Style::Titlebar);


    ///inicializar sistemas

    sf::Event evento;

    sf::Clock deltaClock;

    window.setFramerateLimit(75);

    ///inicializar entidades

    float deltaTime = 0;





    ///BUCLE DE JUEGO

    while(window.isOpen())
    {
        deltaTime = deltaClock.restart().asSeconds();


        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }
            


        }


        window.clear();
        
        // dibujar cosas aca

        window.display();





    }

    return 0;
}
