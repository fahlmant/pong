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
    sf::RectangleShape rightPaddle(Vector2f(10,100));
    sf::RectangleShape ball(Vector2f(10,10));

    leftPaddle.setFillColor(sf::Color::White);
    leftPaddle.setPosition(Vector2f(50,(WIN_HEIGHT)/2-50));

    rightPaddle.setFillColor(sf::Color::White);
    rightPaddle.setPosition(Vector2f(740,(WIN_HEIGHT)/2-50));

    ball.setFillColor(sf::Color::White);
    ball.setPosition(Vector2f((WIN_WIDTH/2)-5, (WIN_HEIGHT/2)-5));

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
        window.draw(rightPaddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}
