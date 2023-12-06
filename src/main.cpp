#include<Donkey.hpp>
#include<MarioB.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{

    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/mapa.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);
    sf::Music music;
    if (!music.openFromFile("./assets/music/MainTheme.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();
    sf::RenderWindow window(sf::VideoMode(800, 600), "DONKEY KONG ARCADE");
    Donkey donk(sf::Vector2f(400, 15), sf::Color::Red);
    MarioB mario(sf::Vector2f(0, 0), sf::Color::Red); 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        // Limpiar la ventana
        window.clear();

        // Dibujar el sprite en la ventana
        window.draw(sprite);

        // Mostrar la ventana
        window.display();

      //   window.clear();
        // Dibujar elementos adicionales en la ventana si es necesario
     //   window.display();

        // Esperar hasta que la música termine
        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            donk.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            donk.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            donk.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            donk.move(0, velocidad);
        }

        // Actualizar animacion pikachu
        donk.update();

        window.clear();
        donk.draw(window);
        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mario.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mario.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            mario.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
        {
            mario.move(0, velocidad);
        }

        // Actualizar animacion pikachu
        mario.update();

        window.clear();
        mario.draw(window);
        window.display();
    }

        
    return 0;
}