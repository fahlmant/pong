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

    int playerOneScore = 0;
    int playerTwoScore = 0;

    //Declare window
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong");

    //Set left paddle properties
    Paddle leftPaddle(LEFT_PADDLE_X, (WIN_HEIGHT)/2-50);

    //Set right paddle properties 
    Paddle rightPaddle(RIGHT_PADDLE_X, (WIN_HEIGHT)/2-50);

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
                        leftPaddle.moveDown();
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        rightPaddle.moveUp();
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        rightPaddle.moveDown();
                    }
                }
            }
        }
        if(ball.getShape().getPosition().y + 10 >= WIN_HEIGHT || ball.getShape().getPosition().y <= 0){
            ball.reboundTopBottom();
        }

        if(ball.getShape().getPosition().x + 10 >= WIN_WIDTH) {
            //Player 1 scores 
        }
        if(ball.getShape().getPosition().x <= 0) {
            //Player 2 scores
        }

        leftPaddle.update();
        rightPaddle.update();
        ball.update();

        //Handle the screen stuff
        window.clear();
        window.draw(leftPaddle.getShape());
        window.draw(rightPaddle.getShape());
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}
