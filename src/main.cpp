#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdio.h>
#include <utility>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

using namespace sf;


int main() {

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong");
    sf::RectangleShape leftPaddle(Vector2f(10,100));

    leftPaddle.setFillColor(sf::Color::White);
    leftPaddle.setPosition(Vector2f(50,50));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(leftPaddle);
        window.display();
    }

    return 0;
}
