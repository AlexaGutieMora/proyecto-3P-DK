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
    
    return 0;
}