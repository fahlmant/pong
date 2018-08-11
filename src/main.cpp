#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdio.h>
#include <utility>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define LEFT_PADDLE_X 50
#define RIGHT_PADDLE_X 740
using namespace sf;


int main() {

    //Declare window and shapes
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong");
    sf::RectangleShape leftPaddle(Vector2f(10,100));
    sf::RectangleShape rightPaddle(Vector2f(10,100));
    sf::RectangleShape ball(Vector2f(10,10));

    //Set left paddle properties
    leftPaddle.setFillColor(sf::Color::White);
    int leftPaddleY = (WIN_HEIGHT)/2-50;
    leftPaddle.setPosition(Vector2f(LEFT_PADDLE_X, leftPaddleY));


    //Set right paddle properties 
    rightPaddle.setFillColor(sf::Color::White);
    int rightPaddleY = (WIN_HEIGHT)/2-50;
    rightPaddle.setPosition(Vector2f(RIGHT_PADDLE_X, rightPaddleY));

    //Set "ball" properties
    ball.setFillColor(sf::Color::White);
    int ballX = (WIN_WIDTH/2) - 5;
    int ballY = (WIN_HEIGHT/2) - 5;
    ball.setPosition(Vector2f(ballX, ballY));

    //Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                }
                case sf::Event::KeyPressed:
                {
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                        leftPaddleY -= 10;
                        leftPaddle.setPosition(Vector2f(LEFT_PADDLE_X, leftPaddleY));
					}
					else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                        leftPaddleY += 10;
                        leftPaddle.setPosition(Vector2f(LEFT_PADDLE_X, leftPaddleY));
					}
				}
            }
        }

        //Handle the screen stuff
        window.clear();
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}
