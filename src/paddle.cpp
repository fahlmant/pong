#include "paddle.h"

Paddle::Paddle(float startX, float startY){
    
    position.x = startX;
    position.y = startY;

    paddleSpeed = .3f;

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

    position.y -= paddleSpeed;
}

void Paddle::moveDown(){

    position.y += paddleSpeed;
}

void Paddle::update(){
    paddleShape.setPosition(position);
}


