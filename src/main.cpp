#include <DonkeyKong.hpp>
#include <MarioB.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    DonkeyKong pika(sf::Vector2f(200, 300), sf::Color::Red);
    MarioB pikachu(sf::Vector2f(600, 300), sf::Color::Red);
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/mapad.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
     // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("./assets/music/01. Main Theme.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

    // Cargar una fuente de texto
    sf::Font font2;
    if (!font2.loadFromFile("./assets/fonts/Jumpman.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }
    // Crear un objeto de texto LOTR
    sf::Text text2;
    text2.setFont(font2);
    text2.setString("STREET FIGHTER!");
    text2.setCharacterSize(10);
    text2.setPosition(10, 10);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Street Fighter");

    
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
            pika.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            pika.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            pika.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            pika.move(0, velocidad);
        }


         if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            pikachu.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            pikachu.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            pikachu.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            pikachu.move(0, velocidad);
        }


        


        // Actualizar animacion pikachu
        pika.update();
        pikachu.update();

        window.clear();
        window.draw(sprite);
        pika.draw(window);
        pikachu.draw(window);
        window.draw(text2);
        window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}