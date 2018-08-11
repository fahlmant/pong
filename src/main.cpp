#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdio.h>
#include <utility>

#include "ball.h"
#include "paddle.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define LEFT_PADDLE_X 50
#define RIGHT_PADDLE_X 740
using namespace sf;

int main() {


    //Declare window and shapes
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong");
    sf::RectangleShape rightPaddle(Vector2f(10,100));

    //Set left paddle properties
    Paddle leftPaddle(LEFT_PADDLE_X, (WIN_HEIGHT)/2-50);

    //Set right paddle properties 
    rightPaddle.setFillColor(sf::Color::White);
    int rightPaddleY = (WIN_HEIGHT)/2-50;
    rightPaddle.setPosition(Vector2f(RIGHT_PADDLE_X, rightPaddleY));

    //Set "ball" properties
    Ball ball((WIN_WIDTH/2)-5, (WIN_HEIGHT/2)-5);

    //Game loop
    while (window.isOpen())
    {
        //Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                }
                //Handle player input
                case sf::Event::KeyPressed:
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                        leftPaddle.moveUp();
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                        leftPaddle.moveUp();
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        rightPaddleY -= 10;
                        rightPaddle.setPosition(Vector2f(RIGHT_PADDLE_X, rightPaddleY));
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        rightPaddleY += 10;
                        rightPaddle.setPosition(Vector2f(RIGHT_PADDLE_X, rightPaddleY));
                    }
                }
            }
        }

        leftPaddle.update();

        //Handle the screen stuff
        window.clear();
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}
