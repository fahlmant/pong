#include "paddle.h"

Paddle::Paddle(float startX, float startY){
    
    position.x = startX;
    position.y = startY;

    paddleShape.setSize(sf::Vector2f(10, 100));
    paddleShape.setPosition(position);
}

FloatRect Paddle::getPosition(){

    return paddleShape.getGlobalBounds();
}

RectangleShape Paddle::getShape(){

    return paddleShape;
}

void Paddle::moveUp(){

    position.y -= 10;
}

void Paddle::moveDown(){

    position.y += 10;
}

void Paddle::update(){
    paddleShape.setPosition(position);
}


