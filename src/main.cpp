#include<Donkey.hpp>
#include<MarioB.hpp>
#include<Barril.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/mapad.png"))
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
    text2.setString("DONKEY KONG");
    text2.setCharacterSize(90);
    text2.setPosition(110, 100);

    sf::RenderWindow window(sf::VideoMode(800, 600), "DK ARCADE");

    Donkey donk(sf::Vector2f(100, 300), sf::Color::Red);
    MarioB mario(sf::Vector2f(700, 300), sf::Color::Red);
   // Barril barr(sf::Vector2f(600, 300), sf::Color::Red);

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
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            donk.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            donk.move(velocidad, 0);
        }
         // if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
       // {
         //   barr.move(velocidad, 0);
       // }

        donk.update();
        mario.update();
      //  barr.update();

        window.clear();
        window.draw(sprite);

        donk.draw(window);
        mario.draw(window);

        window.draw(text2);
        window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}