#include<Donkey.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DinoChrome");

    Donkey donk(sf::Vector2f(400, 300), sf::Color::Red);

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
    }
    sf::RenderWindow window(sf::VideoMode(800, 600), "DinoChrome");

    MarioB mario(sf::Vector2f(400, 300), sf::Color::Red);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mario.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mario.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            mario.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            mario.move(0, velocidad);
        }

        // Actualizar animacion pikachu
        mario.update();

        mario.clear();
        mario.draw(window);
        window.display();
    }


    sf::RenderWindow window(sf::VideoMode(800, 600), "Reproductor de musica");

    sf::Music music;
    if (!music.openFromFile("./assets/music/musica.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

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

        window.clear();
        // Dibujar elementos adicionales en la ventana si es necesario
        window.display();

        // Esperar hasta que la música termine
        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }
        // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Image");

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/pikachu.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    // Bucle principal
    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Cerrar la ventana si se recibe el evento de cerrar
                window.close();
            }
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el sprite en la ventana
        window.draw(sprite);

        // Mostrar la ventana
        window.display();
    }
    
    return 0;
}